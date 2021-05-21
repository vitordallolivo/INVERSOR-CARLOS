#include <SoftwareSerial.h>



#include <thermistor.h>

// THEMOSISTOR

#define NTC A1

// Thermistor object
THERMISTOR thermistor(NTC,            // pino analogico
                      10000,          // resistencia a 25 ºC
                      3950,           // thermistor's beta coeficiente,
                      1000);         // Value of the series resistor

uint16_t temp; 

 // LEMBRAR DE USAR BIBLIOTECA DO THEMISTOR



// botão de inicio e parada
#define botao 13
// resistor de aquecimento
#define aquecimento 22 
//resistor leitor do aquecimento



//Relé que manda o DI1, LIGA GERAL 
#define DI1 24// 300 RPM

//Relé DI2
#define DI2 26 //800 RPM

//Relé DI3
#define DI3 28 // 1500 RPM

int liga=0;
/*
   ///////////////   DI2*DI3 = 2100 RPM /////////////
*/



void setup() {
  // put your setup code here, to run once:
      
     Serial.begin(9600);
      
      
      pinMode(botao,INPUT);
      
      pinMode(aquecimento,OUTPUT);
      pinMode(DI1,OUTPUT);
      pinMode(DI2,OUTPUT);
      pinMode(DI3,OUTPUT);
}

void loop() {
  
     
      while (digitalRead(botao)== 1) 
      {

              liga=1;
        
        }
      while(liga == 1)
      {  
        
              digitalWrite(aquecimento,HIGH); // aqueciment liga 
              digitalWrite(DI1,HIGH); // /RPM de 300 começa


      
              temp = thermistor.read();   // Read temperature
              
              
              while(botao == 1) 
              {   
                
                
                      liga=0;  // DESLIGA TUDO
                
                }



              
              if (temp>= 50 && temp<75)
              {
                
                
                      digitalWrite(DI2,HIGH);
           
                
              } // 50ºC a 75ºC

              else
              {
                      digitalWrite(DI2,LOW);
                      if(temp>=75  && temp<100)
                      {
                        
                        
                          digitalWrite(DI3,HIGH);
                        
                        
                        }
                        
                       digitalWrite(DI3,LOW);

                        
                       if(temp>100){


                         digitalWrite(DI2,HIGH);
                         digitalWrite(DI3,HIGH);
                         delay(15000);
                         digitalWrite(DI2,LOW);
                         digitalWrite(DI3,LOW);
                         liga=0;

                            
                        } // 100ºC
                        
                } // else
                
                
                
       } // liga
              
                
        
        
        
        
        
        
        
} // Tudo dentro disso
        
