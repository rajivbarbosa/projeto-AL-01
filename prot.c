/* primeira versão do protótipo de um controlador utilizado em ua maquina de lavar industrial*/
/*Poli Junior Engenharia*/
/*pre procesamento>>>>>>>neste fase é definido os tempos de operção das etapas */
/*etapas de lavagem*/
/*finalização*/
#define nivel 8

#define molho 4
#define saida 7
#define entrada 6
#define bater 5

long previousMillis = 0;        // Variável de controle do tempo
long previousMillisbater = 0;        // Variável de controle do tempo de bater
long redLedInterval = 3000;     // Tempo em ms do molho a ser executado
long redLedIntervalbater = 2000; // Tempo em ms do bater a ser executado
int fase;
boolean moolho;
boolean baater;
void setup() 
{
  
  pinMode(bater, OUTPUT);
  pinMode(saida, OUTPUT);
  pinMode(entrada, OUTPUT);
  pinMode(molho, OUTPUT);
  pinMode(nivel, INPUT);
 
}
void loop()
{
  
  int niivel;
 
  
  niivel=digitalRead(nivel);
   
  if(fase == 0)
  {
    fase=1;
  }
  
  
  if(fase == 1)
  {
    digitalWrite(entrada,1);
   
    if(niivel==1)
    {
      digitalWrite(entrada,0);
      fase = 2;
    }
  }

 if(fase==2)
  {



  unsigned long currentMillis = millis();    //Tempo atual em ms
  if(baater == 0)
  {
   baater=1;
   digitalWrite(bater, 1);  
   previousMillisbater = currentMillis;
  }
  currentMillis = millis();    //Tempo atual em ms
            //Lógica de verificação do tempo
    if (currentMillis - previousMillisbater > redLedIntervalbater) 
      { 
         baater=0;
         digitalWrite(bater, 0); 
         fase=3;
      }


    
  
  }
  if(fase==3)
  {
    unsigned long currentMillis = millis();    //Tempo atual em ms
  if(moolho == 0)
  {
   moolho=1;
   digitalWrite(molho, 1);  
   previousMillis = currentMillis;
  }
  currentMillis = millis();    //Tempo atual em ms
            //Lógica de verificação do tempo
    if (currentMillis - previousMillis > redLedInterval) 
      { 
         moolho=0;
         digitalWrite(molho, 0); 
         fase=4;
      }

   
  }




