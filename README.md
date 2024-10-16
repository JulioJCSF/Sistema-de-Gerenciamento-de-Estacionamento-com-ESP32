Componentes Utilizados
  ESP32
  Servos (2): Um para a entrada e outro para a saída.
  Display de 7 Segmentos
  Sensor Ultrassônico (HC-SR04)
  LED Verde: Indica vaga disponível.
  LED Vermelho: Indica vaga ocupada.
  Botões (2): Um para controlar a entrada e outro para a saída de veículos.

Esquema de Conexões
Pinos:
  Servos:
    Servo Entrada: GPIO 14
    Servo Saída: GPIO 15
  Display de 7 Segmentos:
    Segmentos A-G: GPIOs 5, 18, 19, 25, 33, 23, 22
    Ponto decimal: GPIO 21
  Sensor Ultrassônico:
    Trig: GPIO 13
    Echo: GPIO 12
  LEDs:
    LED Verde: GPIO 26
    LED Vermelho: GPIO 4
  Botões:
    Botão Entrada: GPIO 27
    Botão Saída: GPIO 2
    
Como Funciona
O sensor ultrassônico detecta a presença de veículos nas vagas, acendendo o LED verde quando há vagas disponíveis e o LED vermelho quando não há.
Os botões de entrada e saída controlam a contagem de veículos no estacionamento e acionam os servos para abrir ou fechar as barreiras.
O número de veículos presentes é exibido no display de 7 segmentos. A contagem varia de 0 a 9 veículos.

Como Rodar o Projeto
Requisitos
  ESP32 com a IDE Arduino configurada.
  Biblioteca ESP32Servo (instalar pela gerenciador de bibliotecas da IDE Arduino).
  Ou Wokwi
