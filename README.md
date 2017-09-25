# Seguidor-de-Linha
Controlador PID para seguir linha.

# Resumo

O objetivo deste trabalho é  mostrar a aplicação de conhecimentos adquiridos durante o curso de Engenharia de  Controle e Automação para construção de um robô seguidor de linhas utilizando controladores PID na programação. 

# Fundamentação teórica

 Controlador PID -  Controlador proporcional integral derivativo, é uma técnica de controle de processos que une as ações derivativa, integral e proporcional, fazendo assim com que o sinal de erro seja minimizado pela ação proporcional, zerado pela ação integral e obtido com uma velocidade antecipativa pela ação derivativa. 

 O algoritmo PID pode ser definido por :   
                                                  ![image1](https://user-images.githubusercontent.com/31252029/30706454-c11c1660-9ece-11e7-904c-eae7f627284a.jpg)

                                                  Figura 1- Expressão para o controlador PID

Ação proporcional 
A ação proporcional  produz um sinal de saída que é proporcional à amplitude do erro e(t), sendo Kp a constante de proporcionalidade.

Ação Integral
A ação integral produz um sinal de saída que é proporcional à magnitude e à duração do erro, ou seja, o erro acumulado. Isso fornece uma alternativa para corrigir o erro de off-set gerado pela ação integral e acelera a resposta do sistema, permitindo-o chegar ao valor de referência mais rapidamente.

Ação Derivatira 
A ação derivativa produz um sinal de saída que é proporcional à velocidade de variação do erro, fornece uma correção antecipada diminuindo o tempo de resposta e melhorando a estabilidade do sistema.



![image2](https://user-images.githubusercontent.com/31252029/30706488-e4f2ee9c-9ece-11e7-924c-ecf91b762f9f.jpg)

Figura 2 – Controlador PID

# Materiais e equipamentos necessários:
1 Arduino Duemilanove 

1 Drive ponte H

2 Motores cc 
 
1 Chassi de Carro didático 

1 Fonte 

1 Modulo sensor de linha 

Cabos para conexão 

![img_20170921_204358805](https://user-images.githubusercontent.com/31252029/30815025-4764bae4-a1e8-11e7-95c2-775de0e097e2.jpg)
![img_20170921_204403664_hdr](https://user-images.githubusercontent.com/31252029/30815036-565e111c-a1e8-11e7-9e62-f10c5ff6af5e.jpg)
![img_20170921_204408318](https://user-images.githubusercontent.com/31252029/30815047-62152fae-a1e8-11e7-93b4-485b415cbbb2.jpg)

![img_20170921_204422151](https://user-images.githubusercontent.com/31252029/30815063-70770f7c-a1e8-11e7-8855-d663feea1df7.jpg)

# Procedimentos

Primeiramente no codigo foram definitas todas as portas do arduino as quais seriam usadas, sendo as portas pwn utilizadas para as ligações com o driver de ponte H utilizado para realizar os movimentos dos motores ligados as duas rodas do carro didático. As ligações entre o arduino e o driver podem ser vista na figura abaixo:

 ![dazzling waasa-gaaris](https://user-images.githubusercontent.com/31252029/30709808-da4277aa-9ed9-11e7-8918-85f0b12c2f7d.png)

Figura 3 – Ligações do Arduino com o Driver ponte H.

A partir de testes foram encontrados valores ideais para as contantes kp, ki e kd, estas vistas no programa, definindo assim uma melhor resposta quando exigido o processamento do sensor.

As funções de movimento são definidas a partir do entendimento do driver de ponte H utilizado. Sendo cada uma dessas funções relacionadas ao movimento realizado pelos motores.

# Sensor de Linha

O sensor de linha possui 3 portas distintas uma para as posições esquerda(L), centro(C) e direita(R), sendo elas associadas a um sensor que detecta a presença da linha e manda a informação caso a linha seja encontrada.

![sku_204012_3](https://user-images.githubusercontent.com/31252029/30711190-5bf0311c-9ede-11e7-9e62-7a50112d8572.jpg)

Figura 4 – Sensor de Linha utilizado.

No caso deste projeto as portas L, C e R foram associadas as portas 12, 2 e 4 respectivamente do arduino, como pode ser visto no programa.

# Uso do Controlador PID

O uso do controlador PID se resumiu ao calculo inserido no programa, o caluclo em questão é o V = (300* l + 200 * c + 100 * r)/(l+c+r), onde as variáveis l, r e c são as referidas do sensor de linha como abordato acima. As possibilidades de resultado de cada variavel é HIGH ou LOW, resultando em um valor diferenciado para o V dependendo de qual sensor estiver ligado no momento do calculo. O V então é diminuido de um SetPoint, este definido 200 a partir de testes, para então encontrar um erro.

O erro é utilizado para o calculo das tres variaveis do controlador PID, sendo elas P, I e D. Onde nesses calculos então inseridos as constantes kp, ki e kd para o P, I e D respectivamente. 

as formulas de cada variavel são:

P = erro * kp
I += erro* dt * ki
D = (kd*(V - Va))/dt

As variaveis kp, ki e kd são definidas por testes realizados nas pistas de teste. O kp foi achado de maneira bem simples, sendo o mais fácil dos tres de se encontrar um valor adequado para o propósito. O mais difícil foram as combinações ki e kd pois os dois são complementos e se não encontrado um valor razoavel o carro tinha movimentos instáveis.

O resultado do calculo da variavel V é então subtraido do setPoint escolhido( no caso 200 ) para achar o valor do erro. Este erro encontrado será o utilizado nas equações acima para achar as variaveis P, I e D. Com os resultados definidos é realizado outro calculo para definir os valores que irão alimentar as funções definidas para cada movimento, sendo elas: frente, direita, esquerda e trás. As variaveis x e y são calculadas com os valores encontrados para P, I e D:

x = constante + (P + I + D).

y = constante - (P + I + D).

Essa constante utilizada tambem foi definida a partir de testes realizados buscando melhor otimização na hora do deslocamento realizado pelo carro.

# Conclusões

Foi possível concluir com o trabalho que para uma melhor estabilidade no robô seguidor de linha fez-se necessário o uso do controlador PID que contém as três funções. Percebemos que dependendo das constantes pode-se melhorar ou piorar a estabilidade do sistema.





