char letra; // variavel do bluetooth
#define DI1 52// 300 RPM

//Relé DI2
#define DI3 48//800 RPM

//Relé DI3
#define DI4 38 // 1500 RPM

#define aquecimento 22 
//resistor do aquecimento

void setup() {
  
    Serial.begin(9600);
    
}

void loop(){
  
          letra = Serial.read();
         Serial.println(letra);
         delay(300);
         if (letra>='A' && letra<='Z'){
         
            letra= letra+32;
         
         }
   
        
             
        if(letra == 'a'){
    
            Serial.println("LIGOU");
            digitalWrite(aquecimento,HIGH); // 300 rpm

                
        }
              
        if(letra == 'b'){
                  
            digitalWrite(DI1,HIGH); // 800 rpm
                    
                  
        }
        if(letra == 'c'){
                        
            digitalWrite(DI3,HIGH); 
                        
        }    
        if( letra == 'd') {
                            
            digitalWrite(DI4,HIGH); // 2100 rpm
                                            
        } 

        
         if (letra == 'z'){
                  Serial.println(letra);
                  digitalWrite(aquecimento,LOW);
                  digitalWrite(DI1,LOW);
                  digitalWrite(DI3,LOW);
                  digitalWrite(DI4,LOW); // 2100 rpm
          
          }
  
  

} 
