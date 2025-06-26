const int AOUTpin = 0;//pin analogico A0
const int DOUTpin = 8;//pin digitale D8

int limit;
int value;

void setup() {
  
Serial.begin(115200); //baud rate
pinMode(DOUTpin, INPUT); //DOUT input
}

void loop()
{
value= analogRead(AOUTpin);//Leggi il valore del pin analogico A0, è il valore dell'alcool nell'ambiente
limit= digitalRead(DOUTpin);//Leggi il valore del pin digitale D8 (non ho ancora capito bene a cosa serva)
Serial.print("Valore Alcool: ");
Serial.println(value); //Stampa valore Alcool

//Serial.print("Limit: ");
//Serial.print(limit);//Lettura del pin digitale che non ho capito ancora a cosa serva

delay(200); //delay da cambiare a seconda dello "sfarfallio" del display
}
