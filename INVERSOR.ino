/* ALTERAÇÃO A SER FEITA:

  MELHORAR METODO DE LEITURA DAS TEMPERATURAS USANDO O MAP DO PRÓPRIO ARDUINO

*/


#define NTC A0 // TEMPERATURA POR MEIO DA RESISTÊNCIA

int temp; // TEMPERATURA


// botão de inicio e parada
#define botao 2
// resistor de aquecimento
#define aquecimento 22 
//resistor do aquecimento

//Relé que manda o DI1, LIGA GERAL 
#define DI1 52// 300 RPM

//Relé DI2
#define DI3 48//800 RPM

//Relé DI3
#define DI4 38 // 1500 RPM

int liga=0;


void setup() {
  // put your setup code here, to run once:

     Serial.begin(9600);


      pinMode(botao,INPUT);
      pinMode(NTC,INPUT); // input analogico
      pinMode(aquecimento,OUTPUT);
      pinMode(DI1,OUTPUT);
      pinMode(DI3,OUTPUT);
      pinMode(DI4,OUTPUT);
      attachInterrupt(digitalPinToInterrupt(botao),ligadesliga, RISING);
}

void ligadesliga(){ // verifica se o botão foi acionado durante o processo
  
      if(ligar==1){
        
        ligar=0;
        // desliga todos os processos
        digitalWrite(DI1,LOW);
        digitalWrite(aquecimento,LOW);  
        digitalWrite(DI3,LOW);
        digitalWrite(DI4,LOW);
  
      }
  
      else{ 
        ligar=1;    
      }
}

void loop() {
      while(liga == 1){ // caso o botão tenha cido
        temp=analogRead(NTC);
        
        if(temp>=240){
    
            Serial.println("Temperatura muito alta, espere o maquinario desaquecer");
          
        }
        else{
    
          digitalWrite(aquecimento,HIGH); // aqueciment liga
          digitalWrite(DI1,HIGH); // /RPM de 300 começa
        
        }
        
        if (temp>=154  && temp<175){
            Serial.println("50ºC");
            digitalWrite(aquecimento,HIGH); 
            digitalWrite(DI3,HIGH);
            Serial.println("Estágio dos 50ºC");
            temp=analogRead(NTC) ;
                

        } // 50ºC a 75ºC

        if (temp>=175  && temp<219){
          
              digitalWrite(DI3,LOW);
              digitalWrite(aquecimento,HIGH);  
              Serial.println("75ºC");
              Serial.println("Estágio 75ºC");
              digitalWrite(DI4,HIGH);
          
        } // 75ºC a 100ºC

       if (temp>=240){
              Serial.println("100ºC");
              Serial.println("Estágio final")
              digitalWrite(aquecimento,HIGH);     
              digitalWrite(DI3,HIGH);
              digitalWrite(DI4,HIGH);
              delay(15000); // Espera um intervalor de 15 segundos pre-estabelicido
              digitalWrite(DI1,LOW);
              digitalWrite(aquecimento,LOW);  
              digitalWrite(DI3,LOW);
              digitalWrite(DI4,LOW);
              liga=0;
                        
          } // 100ºC
       } // liga
} //VOIDLOOP
