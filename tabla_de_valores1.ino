int pot_pin = A0;//pin potenciometro
int pot_val = 0; //valor inicial del potenciometro

int pulsador1 =D8;//pin pulsador1
int pulsador2 =D1;//pin pulsador 2


int rojo = D7; //declarar pin color rojo
int verde = D2; //declarar pin color verdad
int azul = D4; //declarar pin color azul

void setup() {
  Serial.begin(9600); // velocidad de coneccion con el arduino 
pinMode(pulsador1, INPUT); // entrada Pulsador 1
pinMode(pulsador2, INPUT); //entrada Pulsador 2
}

void loop() {
 pot_val = analogRead(pot_pin); //leer valor del potenciometro
int pulsador_1 = digitalRead(pulsador1);//leer valor del pulsador 1
int pulsador_2 = digitalRead(pulsador2); //leer valor del pulsador 2
Serial.print("pulsador 1: "); 
Serial.print(pulsador_1); //Muestra el valor del pulsador 1 por la pantalla del PC           
Serial.print("---");
Serial.print("pulsador 2: "); 
Serial.print(pulsador_2); //Muestra el valor del pulsador 2 por la pantalla del PC
Serial.print("---");


//tabla de: AND,LED: Rojo
if(pot_val>=0 & pot_val<205){ 
 Serial.print("tabla de AND: ");//imprimir en pantalla el nombre de la tabla
 Serial.println(pot_val); //imprimir en pantalla el valor del potenciometro     
if((pulsador_1==1) & (pulsador_2==1)){//condiciones para que el led prenda 
  analogWrite(rojo, 0); //se escibe el valor para que el led encienda (0) o se apage (1023) dependiendo del color que uno quiera
  analogWrite(azul, 1023);
  analogWrite(verde, 1023);
  }else{                 //se crea un caso contrario para que el led no encienda en caso de que las condiciones no se cumplan 
    analogWrite(rojo, 1023);
    analogWrite(azul, 1023);
    analogWrite(verde, 1023);
  }
  }
//tabla de: OR,LED: Violeta
if(pot_val>=205 & pot_val<407){ 
   Serial.print("tabla de OR: ");//imprimir en pantalla el nombre de la tabla
  Serial.println(pot_val);       //imprimir en pantalla el valor del potenciometro  
  if(((pulsador_1==LOW) & (pulsador_2==HIGH))||((pulsador_1==HIGH) & (pulsador_2==LOW))||((pulsador_1==HIGH) && (pulsador_2==HIGH))){//condiciones para que el led prenda 
   analogWrite(rojo, 0);//se escibe el valor para que el led encienda o se apage dependiendo del color que uno quiera
  analogWrite(azul, 0);
   analogWrite(verde, 1023);
  
  }else{                    //se crea un caso contrario para que el led no encienda en caso de que las condiciones no se cumplan 
    analogWrite(rojo, 1023);
    analogWrite(azul, 1023);
    analogWrite(verde, 1023);
  }
}
//tabla de: NAND,LED: Amarillo
if(pot_val>=407 && pot_val<613){ 
Serial.print("tabla de NAND: ");//imprimir en pantalla el nombre de la tabla
Serial.println(pot_val);           //imprimir en pantalla el valor del potenciometro  
 if(((pulsador_1==LOW) && (pulsador_2==LOW))||((pulsador_1==LOW) && (pulsador_2==HIGH))||((pulsador_1==HIGH) && (pulsador_2==LOW))){//condiciones para que el led prenda 
 analogWrite(rojo, 0);   //se escibe el valor para que el led encienda o se apage dependiendo del color que uno quiera
 analogWrite(azul, 1023);
 analogWrite(verde, 0);
  }  
else{                       //se crea un caso contrario para que el led no encienda en caso de que las condiciones no se cumplan 
    analogWrite(rojo, 1023);
    analogWrite(azul, 1023);
    analogWrite(verde, 1023);
  }
}
//tabla de: NOR, LED: Azul
if(pot_val>=613 && pot_val<818){ 
    Serial.print("tabla de NOR: ");//imprimir en pantalla el nombre de la tabla
  Serial.println(pot_val);         //imprimir en pantalla el valor del potenciometro  
 if((pulsador_1==LOW) && (pulsador_2==LOW)){//condiciones para que el led prenda 
 analogWrite(rojo, 1023);//se escibe el valor para que el led encienda o se apage dependiendo del color que uno quiera
 analogWrite(azul, 0);
 analogWrite(rojo, 1023);
  }
  else{                     //se crea un caso contrario para que el led no encienda en caso de que las condiciones no se cumplan 
    analogWrite(rojo, 1023);
    analogWrite(azul, 1023);
    analogWrite(verde, 1023);
  }
  }

//tabla de: XOR,LED: Verde
if(pot_val>=818 && pot_val<=1030){ 
      Serial.print("tabla de XOR: ");//imprimir en pantalla el nombre de la tabla
       Serial.println(pot_val);       //imprimir en pantalla el valor del potenciometro  
  if(((pulsador_1==LOW) && (pulsador_2==HIGH))||((pulsador_1==HIGH) && (pulsador_2==LOW))){//condiciones para que el led prenda 
  analogWrite(rojo, 1023);//se escibe el valor para que el led encienda o se apage dependiendo del color que uno quiera
  analogWrite(azul, 1023);
  analogWrite(verde, 0);
  } 
else{                     //se crea un caso contrario para que el led no encienda en caso de que las condiciones no se cumplan 
    analogWrite(rojo, 1023);
    analogWrite(azul, 1023);
    analogWrite(verde, 1023);
  }
}
}
