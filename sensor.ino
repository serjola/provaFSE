int leitura;
float TempoEcho = 0;
const float velocidadeSom_mps = 340;
const float velocidadeSom_mpus = 0.000340; 
void setup() {
  
pinMode(2,OUTPUT);
digitalWrite(2,LOW);
pinMode(3,INPUT);
Serial.begin(9600);
pinMode(4,OUTPUT);

}

void loop() {
DisparaPulsoUltrassonico(); // dispara pulso ultrassonico
TempoEcho = pulseIn(3, HIGH); // mede duração do pulso HIGH de eco em
if (CalculaDistancia(TempoEcho) *100 < 5.00){
  digitalWrite(4,LOW);
  Serial.println(1);
}
else{
  digitalWrite(4,HIGH);
  Serial.println(0);
}
delay(1000);
}
void DisparaPulsoUltrassonico()
{
digitalWrite(2, HIGH); // pulso alto de Trigger
delayMicroseconds(10); // atraso de 10 milisegundos
digitalWrite(2, LOW); // pulso baixo de Trigger
}
float CalculaDistancia(float tempo_us)
{
return ((tempo_us * velocidadeSom_mpus) / 2 ); // calcula distancia em metros
}
