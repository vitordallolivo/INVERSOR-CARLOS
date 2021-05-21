// THEMOSISTOR
#include <Thermistor.h>

Thermistor temp(0);
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
  // put your main code here, to run repeatedly:
      while (digitalRead(botao)== 1) {

              liga=1;
        
        }
      while(liga == 1){  
        
              digitalWrite(aquecimento,HIGH); // aqueciment liga 
              digitalWrite(DI1,HIGH); // /RPM de 300 começa


      
              int temperature = temp.getTemp();  
              
              
              while(botao == 1) {   
                
                
                      liga=0;  // DESLIGA TUDO
                
                }



              
              if (temperature>= 50 && temperature<75){Serial.println("ta bom");} 

              
              
                
        
        
        
        
        
        
        
        }
        
}
