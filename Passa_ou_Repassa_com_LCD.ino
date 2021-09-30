

// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES de portas Arduino
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
#define botao 7
#define botao2 5
#define botaolimpa 6
//jogo
#define ledVerde 2 // Led Verde ligado na porta 2
#define ledVermelho 3 // Led Vermelho Ligado na Porta 3
#define botaoVerde 6 // Botao Verde ligado na porta 6
#define botaoVermelho 4 // botao vermelho ligado na porta 7

#define som 9 // Som ( Mini falante ) ligado na porta 9
#define ledAmarelo 8 // led amarelo ligado na porta 4
#define ledInicio 8 // ligado na porta 8

#include <Servo.h>
#define SERVO 5// porta digital 5

//lcd

//Variavel 'x,F' determina soma do botão botao2
int x=0;
int f=0;
int leiturabotaolimpa; //botão limpa tudo
int leiturabotao = 0;
int leiturabotao2 = 0;
//jogo
int estadoBotaoVerde; // Declarando funções do botao ativado ou desativado
int estadoBotaoVermelho;// Declarando funções do botao ativado ou desativado
int leituraBotaoVerde;// Declarando funções de Leitura do codigo sobre as funcões do botao
int leituraBotaoVermelho;// Declarando funções de Leitura do codigo sobre as funcões do botao
unsigned long changeTime;
int CrossTime = 400;


// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);
// jogo
Servo s; //variavel servo
int pos;//posição servo

void setup() {
  pinMode(botao,INPUT_PULLUP);// INPUT_PULLUP usado para receber dados só quando pressionado
  pinMode(botao2,INPUT_PULLUP);
  pinMode(botaolimpa,INPUT_PULLUP);
  
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("Carregando");// primeira mensagem 
  delay(1000); // DELAY DE 2 SEGUNDOS
  //lcd.setCursor(0, 0);

  // Animação carregando....
  
  lcd.print(".");
  delay(500); 
  lcd.setCursor(11, 0);
  lcd.print(".");
  delay(500); 
  lcd.setCursor(12, 0);
  lcd.print(".");
  delay(500); 
  lcd.setCursor(13, 0);  
  lcd.print(".");
  delay(500); 
  lcd.setCursor(14, 0);
  lcd.print(".");
  delay(500); 
  lcd.setCursor(15, 0);
  lcd.print(".");
  delay(500); 
  lcd.print(".");
  lcd.setCursor(16, 0);
 

  
  
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print(" *.*   Ola   ^.^ ");
  delay(4000); // DELAY DE 2 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Seja Bem Vindo");
  delay(2000); // DELAY DE 2 SEGUNDOS 
  
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

  
  lcd.print("Passa ou Repassa");
  delay(2000); // DELAY DE 5 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Boa sorte");
  delay(2000); // DELAY DE 5 SEGUNDOS

  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

  lcd.setCursor(7,1);// 'x' fixo na posição do placar
  lcd.print("x");

  // jogo
  
  // Define se é um componente de entrada ou saida

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(som, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledInicio, OUTPUT);

  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0);//inicia motor posiçao zero

  // Incio Programa ( Inicia com luz e som )


  digitalWrite(ledInicio, HIGH); // Informa que o programa foi iniciado
  delay(1000);

  delay(200); // Som de reprodução quando projeto for ligado
  tone(som, 200, 500); // criação de nota musical
  delay(110); // tempo de duração
  tone(som, 600, 300);
  delay(90);
  tone(som, 800, 350);
  delay(50);

  for ( int x = 0; x < 5; x++) { // função pisca led para informar que o programa foi iniciado

    digitalWrite(ledInicio, LOW);
    delay(100);
    digitalWrite(ledInicio, HIGH);
    delay(100);


    digitalWrite(ledInicio, LOW);

  }


}


void loop() { 

  lcd.setCursor(0, 0); // POSICIONA  O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time A");

  lcd.setCursor(10, 0); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time B");

  //leitura botões
   leiturabotao = digitalRead(botaolimpa);
 
   
     if (!digitalRead(botaolimpa)){
   
     if (leiturabotaolimpa == 0){

       x=0;
       f=0;
           
      lcd.setCursor(5,1);     
      lcd.print("0 x0");      
      delay(500); 
                           }

       }    

 
 

    //variavel soma
    if (!digitalRead(botao)){   
    
      x++; // Soma inicia em 0 e soma + 1 a cada clique.
   //ou x=x+1;
    if (x==10+1){      
        x=0;
        
        lcd.setCursor(7,1);// 'x' fixo na posição do placar
        lcd.print("x");
      }
   
      //leitura botões
   leiturabotao = digitalRead(botao);
 
   
     if (!digitalRead(botao)){
   
     if (leiturabotao == 0){      
      lcd.setCursor(5,1);     
      lcd.print(x);      
      delay(500); 
                           }

       }    
    }
    
      // variavel soma botão2 
     //lcd.setCursor(7,1);// deixa o X fixo
     //lcd.print("x");
  
      //variavel soma botao 2
    if (!digitalRead(botao2)){   
      
       f++;
       if (f==10+1){
        f=0;
        
        lcd.clear();
        lcd.setCursor(7,1);// 'x' fixo na posição do placar
        lcd.print("x");

        
      }
      
   //ou x=x+1;
   
      //leitura botão 2
   leiturabotao2 = digitalRead(botao2);
 
   
     if (!digitalRead(botao2)){
   
     if (leiturabotao2 == 0){
        
      lcd.setCursor(8,1);
      lcd.print(f);
      
       delay(500); 
        
          }
                           
       } 
     
    }


        //jogo
    // Leitura de Botões
  leituraBotaoVerde = digitalRead(botaoVerde);
  leituraBotaoVermelho = digitalRead(botaoVermelho);



  if (leituraBotaoVerde == 0 ) { // essa função acende a luz e toca a sirene


    digitalWrite(ledVerde, HIGH); //Led verde liga
    digitalWrite(ledVermelho, LOW); //Led vermelho fica desligado

    tone(som, 70, 1000); //essa é a sirene feita para buzzer e auto-falante ( onde toca musica apos apertar um dos botoes )
    delay(350);
    tone(som, 70, 500);
    delay(350);
    tone(som, 70, 1000);
    delay(350);
    tone(som, 70, 500);
    delay(350);
    tone(som, 70, 1000);
    delay(100);



    // Inicia contagem de tempo servo motor apos led verde acender

    digitalWrite(ledAmarelo, HIGH);

    {
      for (pos = 0; pos < 180; pos++)
      {
        s.write(pos);
        delay(1); // Tempo de volta ao ponto inicial
      }
      delay(500); // Tempo de espera para reiniciar contagem
      for (pos = 180; pos >=  0; pos--)
      {
        s.write(pos);
        delay(30); //Determina o tempo que a luz vermelha ficará acesa, e a velocidade do tempo do relogio ( Animação torta na cara)


      }
    }

    for ( int x = 0; x < 5; x++) { //calculo 10 piscadas para tempo de resposta

      digitalWrite(ledAmarelo, LOW); //Led Amarelo para de piscar
      delay(50);// *obrigatorio* Dertermina velocidade do led ao ligar e desligar
      digitalWrite(ledAmarelo, HIGH);//Led Amarelo para de piscar ( faz a função liga e desliga)
      delay(50);// *obrigatorio* Dertermina velocidade do led ao ligar e desligar
      digitalWrite(ledAmarelo, LOW);// Apaga led Amarelo
      // Fim da contagem


      // informa que acabou o tempo
      tone(som, 200, 500); // criação de nota musical

      delay(50); // tempo de duração
      tone(som, 600, 300);



    }



    digitalWrite(ledVerde, LOW);

    digitalWrite(ledVermelho, LOW);



    if (leituraBotaoVerde == 0) {
      leituraBotaoVermelho = true;

    } else {


    }

    delay(500);
    if (leituraBotaoVerde == 1) {
      leituraBotaoVermelho = false;
    }
  }

  if ( leituraBotaoVermelho == 0 ) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);

    tone(som, 70, 1000); 
    delay(350);
    tone(som, 70, 500);
    delay(350);
    tone(som, 70, 1000);
    delay(350);
    tone(som, 70, 500);
    delay(350);
    tone(som, 70, 1000);
    delay(100);


    // Inicia contagem de tempo servo motor apos led vermelho acende

    digitalWrite(ledAmarelo, HIGH);

    {
      for (pos = 0; pos < 180; pos++)
      {
        s.write(pos);
        delay(1); // Tempo de volta ao ponto inicial
      }
      delay(500); // Tempo de espera para reiniciar contagem
      for (pos = 180; pos >= 0; pos--)
      {
        s.write(pos);
        delay(30); // Determina o tempo que a luz vermelha ficará acesa, e a velocidade do tempo do relogio ( Animação torta na cara)


      }
    }

    for ( int x = 0; x < 5; x++) { //calculo 10 piscadas para tempo de resposta

      digitalWrite(ledAmarelo, LOW); //Led Amarelo para de piscar
      delay(50);// *obrigatorio* Dertermina velocidade do led ao ligar e desligar
      digitalWrite(ledAmarelo, HIGH);//Led Amarelo para de piscar ( faz a função liga e desliga)
      delay(50);// *obrigatorio* Dertermina velocidade do led ao ligar e desligar
      digitalWrite(ledAmarelo, LOW);// Apaga led Amarelo
      //fim contagem

      // informa que acabou o tempo
      tone(som, 200, 500); // criação de nota musical

      delay(50); // tempo de duração
      tone(som, 600, 300);


    }



    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);

    if (leituraBotaoVermelho == 0) {
      leituraBotaoVerde = true;
    }

    delay(500);
    if (leituraBotaoVermelho == 1) {
      leituraBotaoVerde = false;

    }
  }

}
    
