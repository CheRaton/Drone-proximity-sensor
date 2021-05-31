lint DURACION;
int DISTANCIA;

int CALCULAR(int T, int E) //Recibe TRG & ECO
{
digitalWrite(T,HIGH);      //ULTRASONICO Mando señal
delay(1);
digitalWrite(T,LOW);       //dejo de mandar señal
  
DURACION=pulseIn(E,HIGH);  //ULTRASONICO Recibe señal  
}

void setup() 
{
   pinMode(2, OUTPUT);     //Configuro LED 2 como SALIDA
   pinMode(3, OUTPUT);     //Configuro LED 3 como SALIDA
   pinMode(4, OUTPUT);     //Configuro LED 4 como SALIDA
   for(int i=0; i<5; i=i+2)
   { 
   pinMode(i+9, OUTPUT);   //Config.  TGR 9,11,13 como SALIDAS
   pinMode(i+8, INPUT);    //Config.  ECO 8,10,12 como SALIDAS
   }
   Serial.begin(9600);     //VELOCIDAD DE COMUNICACIÓN 9600BD
}

void loop() 
{
int Y=0;  
   for(int X=0; X<5; X=X+2)
   {
        DURACION=CALCULAR(X+9,X+8); //CALCULAR TIEMPO(TGR, ECO)
        DISTANCIA=DURACION/58.2;    //Convertir a "cm"  
        delay(200);

        if(DISTANCIA <50)           //si distancia <30cm LED=ON 
        {
        digitalWrite(Y+2,HIGH);
        }
        else
        {
        digitalWrite(Y+2,LOW);
        }
        Y=Y+1;  
   }
}
