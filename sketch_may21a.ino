

// THEMOSISTOR

#define NTC A0

int temp;


// botão de inicio e parada
#define botao 13
// resistor de aquecimento
#define aquecimento 22 
//resistor leitor do aquecimento



//Relé que manda o DI1, LIGA GERAL 
#define DI1 52// 300 RPM

//Relé DI2
#define DI2  48//800 RPM

//Relé DI3
#define DI3 38 // 1500 RPM

int liga;
/*
   ///////////////   DI2*DI3 = 2100 RPM /////////////
*/



void setup() {
  // put your setup code here, to run once:
      
     Serial.begin(19200);
      
      
      pinMode(botao,INPUT);
      pinMode(NTC,INPUT); // input analogico
      pinMode(aquecimento,OUTPUT);
      pinMode(DI1,OUTPUT);
      pinMode(DI2,OUTPUT);
      pinMode(DI3,OUTPUT);
}

void loop() {

      temp=analogRead(NTC) ;
      digitalWrite(aquecimento,LOW);
      digitalWrite(DI1,LOW);
      digitalWrite(DI2,LOW);
      digitalWrite(DI3,LOW);
      Serial.println(temp);
      
      
      while (digitalRead(botao) == HIGH ) 
      {

              liga=1;
              Serial.println("liga");
        
        }
       
      
      
      while(liga == 1)
      {  
              Serial.println("liga");
              digitalWrite(aquecimento,HIGH); // aqueciment liga 
              digitalWrite(DI1,HIGH); // /RPM de 300 começa

              temp=analogRead(NTC) ;
              Serial.println(temp);
              
              
              



              
              while (temp>=154  && temp<175)
              {
                      Serial.println(temp);
                      digitalWrite(aquecimento,HIGH); 
                      digitalWrite(DI2,HIGH);
                      Serial.println("estágio dos 50");
                      temp=analogRead(NTC) ;
                      Serial.println(temp);
                       while (digitalRead (botao) == HIGH) 
                       {   
                
                
                              liga=0;  // DESLIGA TUDO
                              Serial.println("desliga");
                              
                        }
                
              } // 50ºC a 75ºC

               digitalWrite(DI2,LOW);
              
                while (temp>=175  && temp<219)
               {
                   digitalWrite(aquecimento,HIGH);  
                   Serial.println(temp);
                   digitalWrite(DI3,HIGH);
                   temp=analogRead(NTC);
                   Serial.println(temp);
                   while (digitalRead (botao) == HIGH) 
                    {   
                
                  
                        liga=0;  // DESLIGA TUDO
                        Serial.println("desliga");
                        
                    }
                        
               }
                        
               digitalWrite(DI3,LOW);

                        
               if (temp>=219){

                   while (digitalRead (botao) == HIGH) 
                   {   
                
                
                      liga=0;  // DESLIGA TUDO
                      Serial.println("desliga");
                      
                   }
                  digitalWrite(aquecimento,HIGH); 
                  temp=analogRead(NTC) ;

                  digitalWrite(DI2,HIGH);
                  digitalWrite(DI3,HIGH);
                  delay(15000); //
                  digitalWrite(DI2,LOW);
                  digitalWrite(DI3,LOW);
                  liga=0;
                  Serial.println(temp);
                            
                } // 100ºC
                        
                
               
                
       } // liga
              
                
        
        
        
        
        
        
        
} // Tudo dentro disso
        
