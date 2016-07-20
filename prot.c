#define pinnivel 8//pino a conctar o sensor de nivel one 0 = vazio e 1= cheio

#define pinmolho 4 // pino a conectar o led indicativo de molho
#define pinsaida 7//pino a conectar o rele e led  da bomba de saida de agua
#define pinentrada 6//pino a conctar o rele e led indicativo de entrada de agua
#define pinbater 5//pino a conctar o rele e led indicativo do motor de rotação do cesto da maquina

long previousMillismolho = 0;        // Variável de controle do tempo do molho
long previousMillismolho2 = 0;        // Variável de controle do tempo do molho2 
long previousMillisbater = 0;        // Variável de controle do tempo de bater
long previousMillisbater2 = 0;        // Variável de controle do tempo de bater2
long previousMillisbater3 = 0;        // Variável de controle do tempo de bater3
long previousMillisbater4 = 0;        // Variável de controle do tempo de bater4
long previousMillisbater5 = 0;        // Variável de controle do tempo de bater5

long redLedIntervalmolho = 4000;     // Tempo em ms do molho a ser executado
long redLedIntervalmolho2 = 2000;     // Tempo em ms do molho2 a ser executado
long redLedIntervalbater = 4000; // Tempo em ms do programa bater a ser executado
long redLedIntervalbater2 = 2000; // Tempo em ms do programa bater2 a ser executado
long redLedIntervalbater3 = 2000; // Tempo em ms do programa bater3 a ser executado
long redLedIntervalbater4 = 2000; // Tempo em ms do programa bater4 a ser executado
long redLedIntervalbater5 = 2000; // Tempo em ms do programa bater5 a ser executado
int fase;                          //variavel que indica a fase que a maquina esta
int nivel;                        //variavel que indica o nivel
boolean molho;                   //variavel que indica se esta em molho
boolean bater;                       //variavel que indica se a maquina esta em rotação
void setup() 
{
  
  pinMode(pinbater, OUTPUT);
  pinMode(pinsaida, OUTPUT);
  pinMode(pinentrada, OUTPUT);
  pinMode(pinmolho, OUTPUT);
  pinMode(pinnivel, INPUT);
 
}
void loop()
{
  
  
 
  
  nivel=digitalRead(pinnivel);
   
  if(fase == 0)     //inicia o programa assim que se liga o arduino(modificar para ligar apos selecionar qual programa deseja)
  {
    fase=1;
  }
  
  
  if(fase == 1) //se esta na fase 1 liga o solenoide ,se esta na fase 1 e o nivel esta cheio disliga o solenoide e finaliza a fase e vai para fase 2
  {
    digitalWrite(pinentrada,1);
   
    if(nivel==1)
    {
      digitalWrite(pinentrada,0);
      fase = 2;
    }
  }



 if(fase==2) //liga a rotação da maquina por um determinado tempo e dps passa para fase 3
  {



  unsigned long currentMillis = millis();    //Tempo atual em ms
  if(bater == 0)
  {
   bater=1;
   digitalWrite(pinbater, 1);  
   previousMillisbater = currentMillis;
  }
  currentMillis = millis();    //Tempo atual em ms
            //Lógica de verificação do tempo
    if (currentMillis - previousMillisbater > redLedIntervalbater) 
      { 
         bater=0;
         digitalWrite(pinbater, 0); 
         fase=3;
      }


    
  
  }
  
  if(fase==3) //deixa no molho por um certo tempo depois passa para fase 4
  {
    unsigned long currentMillis = millis();    //Tempo atual em ms
  if(molho == 0)
  {
   molho=1;
   digitalWrite(pinmolho, 1);  
   previousMillismolho = currentMillis;
  }
  currentMillis = millis();    //Tempo atual em ms
            //Lógica de verificação do tempo
    if (currentMillis - previousMillismolho > redLedIntervalmolho) 
      { 
         molho=0;
         digitalWrite(pinmolho, 0); 
         fase=4;
      }

   
  }
if(fase==4) //liga a rotação da maquina por um determinado tempo e dps passa para fase 5
 {



  unsigned long currentMillis = millis();    //Tempo atual em ms
  if(bater == 0)
  {
   bater=1;
   digitalWrite(pinbater, 1);  
   previousMillisbater2 = currentMillis;
  }
  currentMillis = millis();    //Tempo atual em ms
            //Lógica de verificação do tempo
    if (currentMillis - previousMillisbater2 > redLedIntervalbater2) 
      { 
         bater=0;
         digitalWrite(pinbater, 0); 
         fase=5;
      }


    
  
  }



 
  nivel=digitalRead(pinnivel); //atualiza o nivel que a maquina esta
  
  if(fase == 5) //mesma logica da fase 1 mais com o objetivo de secar a maquina
  {
    digitalWrite(pinsaida,1); // liga a bomba de saida
   
    if(nivel==0)
    {
      digitalWrite(pinsaida,0); // desliga a bomba de saida
      fase = 6;
    }
  }
