

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
  if(fase==4)
  {
  digitalWrite(bater, HIGH);  
  delay(2000);              
  digitalWrite(bater, LOW);    
  fase=5;
  }





