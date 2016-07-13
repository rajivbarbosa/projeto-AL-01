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
