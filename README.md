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

