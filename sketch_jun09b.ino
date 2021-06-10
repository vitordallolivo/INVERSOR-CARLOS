

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



      while(liga == 1)
      {  
              Serial.println("liga");
              digitalWrite(aquecimento,HIGH); // aqueciment liga 
              digitalWrite(DI1,HIGH); // /RPM de 300 começa

              temp=analogRead(NTC) ;
              Serial.println(temp);







              if (temp>=154  && temp<175)
              {
                      Serial.println(temp);
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
                   Serial.println(temp);
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

                        digitalWrite(DI3,HIGH);
                        digitalWrite(DI4,HIGH);
                        delay(15000); //
                        digitalWrite(DI3,LOW);
                        digitalWrite(DI4,LOW);
                        liga=0;
                        Serial.println(temp);

                } // 100ºC




       } // liga









} // Tudo dentro disso
