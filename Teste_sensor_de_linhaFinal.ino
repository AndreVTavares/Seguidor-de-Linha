  /** Codigo Sensor de Linha
      Alunos: Jefferson Jorge e André Tavares
      Robótica 35NAB */
  
  
 //--- Definição das portas do Sensor de Linha ---//
  int L = 12;
  int C = 2;
  int R = 4;
 //--- Definição das Portas do driver de ponte H ---//
  int ENA = 3; // pwn
  int IN1 = 5;
  int IN2 = 6;
  int IN3 = 9;
  int IN4 = 10;
  int ENB = 11; // pwn
 //--- Definições das Variáveis utilizadas ---//
  int V=200;  // valor inicial de V.
  int ctn =120; // valor constante dos motores.
  int setPoint = 200; // valor inicial para obtenção do erro.
  int x;  // variavel do motor a
  int y;  // variavel do motor b
  //float kp = 1.0 , ki = 0.0005, kd = 5;  // constantes referentes ao controlador PID, sendo kp,ki e kd para P I e D respectivamente.
  float kp=2,ki=0.0015,kd=110;          // pista U 
  float kp = 2.5 , ki = 0.005, kd = 200 // pista H
  float kp=2,ki=0.0015,kd=110           // pista W
  int erro;
  int Va;  
  int t = 0, ta = 0, dt = 0;
  float P,I,D;

  
//--- inicialização das entradas utilizadas ---//

void setup() {

  


 pinMode(L, INPUT);
 pinMode(C, INPUT);
 pinMode(R, INPUT);
 pinMode(ENA, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ENB, OUTPUT);

 digitalWrite(ENA, LOW);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 digitalWrite(ENB, LOW);


 
 

 //Serial.begin(9600);
 //Serial.println("Setup feito.");

  
}
   


void loop() {
  ta = t;
  t = millis();
  dt = t - ta;
  int l = digitalRead(L); 
  int c = digitalRead(C);
  int r = digitalRead(R);
  
  Serial.println(l);
  Serial.println(c);
  Serial.println(r);
 

  if(l == 1){
    l = 0; 
  } else {          //
    l = 1;
  } 

  if(c == 1){
    c = 0;
  } else{           // inverção dos valores emitidos pelos sensores de linha para utilização no programa.
    c = 1;
  }

  if(r == 1){
    r = 0;
  } else {          //
    r = 1;
  } 

  Va = V;

  if((l+r+c)!=0){
    
   V = (300*l + 200*c + 100*r)/(l+c+r);  // calculo do valor de V
  }
    

  erro = setPoint - V;

  P = erro*kp; 
  I+= erro*dt*ki;
  D = (kd*(V - Va))/dt;

  x = ctn + (P + I + D); // adicionando valores de P I e D encontrados com a constante
  y = ctn - (P + I + D); // subtraindo  valores de P I e D encontrados com a constante 


  if(x > 255){
    x = 255;
  }
  if(y > 255){
    y = 255;
  }
  
  if(x < -180){
    x = -180;
  }
  if(y < -180){
    y = -180;
  }
  if (x>0 && y>0)
  frente(x,y);
  else if((x<0) && (y>0)){
    esquerda(-x,y);
  }else  if((x>0) && (y<0)){
    direita(x,-y);
  }



 
      
}

//--- Funções estabelecidas de movimento ---//

void esquerda(int a, int b){
  //a = (int)a*0.4;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, a+40);
  analogWrite(ENB, b);
}

void frente(int a, int b){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, a);
  analogWrite(ENB, b);
}

void tras(int a, int b){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, a);
  analogWrite(ENB, b);
  
}

void direita(int a, int b){

 digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, a);
  analogWrite(ENB, b+40);
}

void parar(){
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
}
