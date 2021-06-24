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
         if (letra>='A' && letra<='Z'){
         
            letra= letra+32;
         
         }
   
         switch (letra){
         
         
            case 'a':
    
                  digitalWrite(aquecimento,HIGH); // 300 rpm
  
            case 'b':
                              
                   digitalWrite(DI1,HIGH); // 800 rpm
                    
                  
            case 'c':
                        
                  digitalWrite(DI3,HIGH); 
                        

            case 'd':
                            
                  digitalWrite(DI4,HIGH); // 2100 rpm
                                            

            case 'e':
              
                 digitalWrite(aquecimento,LOW);
            
            case 'f':
              
                 digitalWrite(DI1,LOW);

            case 'g':
              
                digitalWrite(DI3,LOW);

            case 'h':
              
                digitalWrite(DI4,LOW);

            case 'z':
            
                Serial.println(letra);
                digitalWrite(aquecimento,LOW);
                digitalWrite(DI1,LOW);
                digitalWrite(DI3,LOW);
                digitalWrite(DI4,LOW); // 2100 rpm

            
           default:
                break;

          }
  
  

} // função bluetooth
