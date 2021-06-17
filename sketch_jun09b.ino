

// THEMOSISTOR

#define NTC A0

int temp;
char letra; // variavel do bluetooth
#include "SoftwareSerial.h"
SoftwareSerial MyBlue(0, 1);// RX | TX

// botão de inicio e parada
#define botao 13
// resistor de aquecimento
#define aquecimento 22 
//resistor leitor do aquecimento



//Relé que manda o DI1, LIGA GERAL 
#define DI1 52// 300 RPM

//Relé DI2
#define DI3  48//800 RPM

//Relé DI3
#define DI4 38 // 1500 RPM

int liga=0;
/*
   ///////////////   DI3*DI4 = 2100 RPM /////////////                                         
*/



void setup() {
  // put your setup code here, to run once:

     Serial.begin(19200);


      pinMode(botao,INPUT);
      pinMode(NTC,INPUT); // input analogico
      pinMode(aquecimento,OUTPUT);
      pinMode(DI1,OUTPUT);
      pinMode(DI3,OUTPUT);
      pinMode(DI4,OUTPUT);
}

void loop() {

      temp=analogRead(NTC) ;
      digitalWrite(aquecimento,LOW);
      digitalWrite(DI1,LOW);
      digitalWrite(DI3,LOW);
      digitalWrite(DI4,LOW);
      Serial.println(temp);


      while (digitalRead(botao) == HIGH ) 
      {

              liga=1;
              Serial.println("liga");

        }

          letra = Serial.read();
         
          if ((letra == 'z') || (letra == 'Z')) {
            
                  digitalWrite(DI1,LOW);  
                  Serial.println("off");
                  digitalWrite(DI3,LOW);
                  digitalWrite(DI4,LOW);
            
            }
            
          if ((letra == 'a') || (letra='A')) { // 


                digitalWrite(DI1,HIGH); // 300 rpm
                digitalWrite(DI3,LOW);
                digitalWrite(DI4,LOW);
            
            
            }
         else{
          
            if ((letra == 'b')|| (letra == 'B')) {
              
              
                digitalWrite(DI1,HIGH);
                digitalWrite(DI3,HIGH); // 800 rpm
                digitalWrite(DI4,LOW);
                
              
              
              }
             else {
              
                  if ((letra =='c') || (letra == 'C') ){
                    
                      digitalWrite(DI1,HIGH);
                      digitalWrite(DI3,LOW);
                      digitalWrite(DI4,HIGH); // 1500 rpm
                    
                    
                    }
                    else{ 
                      
                      if ((letra=='d') || (letra == 'D')) {
                        
                             digitalWrite(DI1,HIGH);
                             digitalWrite(DI3,HIGH);
                             digitalWrite(DI4,HIGH); // 2100 rpm
                        
                        
                        
                        }
                    
                    
                    
                    }
              
              }
          
          }
     

      while(liga == 1)
      {  
              Serial.println("liga");
              digitalWrite(aquecimento,HIGH); // aqueciment liga 
              digitalWrite(DI1,HIGH); // /RPM de 300 começa

              temp=analogRead(NTC) ;
              Serial.println(temp);







              if (temp>=154  && temp<175)
              {
                      Serial.println("50ºC");
                      digitalWrite(aquecimento,HIGH); 
                      digitalWrite(DI3,HIGH);
                      Serial.println("estágio dos 50");
                      temp=analogRead(NTC) ;
                      Serial.println(temp);
                     if (digitalRead(botao) == HIGH){  
                       delay(300);
                       while (digitalRead (botao) == HIGH) 
                         {   
                                liga=0;  // DESLIGA TUDO
                                Serial.println("desliga");

                       }
                 }

              } // 50ºC a 75ºC

               

                if (temp>=175  && temp<219)
               {
                     digitalWrite(DI3,LOW);
                     digitalWrite(aquecimento,HIGH);  
                     Serial.println("75ºC");
                     digitalWrite(DI4,HIGH);
                     temp=analogRead(NTC);
                     Serial.println(temp);
                     if (digitalRead(botao) == HIGH){  
                       delay(300);
                       while (digitalRead (botao) == HIGH) 
                         {   
  
  
                            liga=0;  // DESLIGA TUDO
                            Serial.println("desliga");
  
                         }
                    }

               }

              


                if (temp>=219){

                       if (digitalRead(botao) == HIGH){  
                           delay(300);
                           while (digitalRead (botao) == HIGH) 
                             {   


                                liga=0;  // DESLIGA TUDO
                                Serial.println("desliga");

                             }
                       }
                        digitalWrite(aquecimento,HIGH); 
                        temp=analogRead(NTC) ;
                        Serial.println("100ºC");
                        digitalWrite(DI3,HIGH);
                        digitalWrite(DI4,HIGH);
                        delay(15000); //
                        digitalWrite(DI3,LOW);
                        digitalWrite(DI4,LOW);
                        liga=0;
                        

                } // 100ºC




       } // liga









} // Tudo dentro disso
