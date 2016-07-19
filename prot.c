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



