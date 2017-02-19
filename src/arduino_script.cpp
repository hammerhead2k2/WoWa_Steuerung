//WohWa Steuerung

#include <Bounce2.h> // Library für das Entprellen der Taster
#include <Servo.h> // Library für die Ansteuerung von Servomotoren

// Ein & Ausgänge sowie Objekte deklarieren
Servo meinServomotor;  // erstellt das Objekt "meinServomotor"
int temp = 21; //Setzt die Variable für die Temperatur auf 21

#define button_rauf 2 // Taster "Temperatur rauf" auf Pin2
#define button_runter 3 // Taster "Temperatur runter" auf Pin2
Bounce debouncerA = Bounce(); // Taster entprellen "debouncerA"
Bounce debouncerB = Bounce(); // Taster entprellen "debouncerB"

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.

  pinMode(button_rauf, INPUT_PULLUP); // Digital Pin2 (Modus) wird auf Eingabe gesetzt
  pinMode(button_runter, INPUT_PULLUP); // Digital Pin3 (Modus) wird auf Eingabe gesetzt
  meinServomotor.attach(4);  // verknüpft das Objekt "meinServomotor" mit Pin 4

  debouncerA.attach(button_rauf); //"debouncerA" wird mit "button_rauf" verknüpft
  debouncerA.interval(5); // "debouncerA" Entprellen auf 5 ms einstellen
  debouncerB.attach(button_runter); // "debouncerB" wird mit "button_runter" verknüpft
  debouncerB.interval(5); // "debouncerB" Entprellen auf 5ms einstellen
  Serial.begin(9600); // Ausgabe auf Serieller Schnittstelle starten

}

// the loop routine runs over and over again forever:
void loop() {


// Den Status der debouncer aktualisieren
  debouncerA.update();
  debouncerB.update();

 // die debouncer nach dem Loslassen der Taste einlesen und in die Variablen "valueA, valueB" schreiben
 int valueA = debouncerA.fell();
 int valueB = debouncerB.fell();

// Wenn valueA "taster_rauf" betätigt wurde dann:
// Und wenn die Temperatur kleiner 24
// Dann wird die Temperatur um 1°C erhöht
// Serial Print gibt den Wert auf dem Seriellen Monitor aus

   if ( valueA == HIGH) {
    if (temp < 24) {
    temp ++;
    }
    Serial.print(temp);
   }

   // Wenn valueB "taster_runter" betätigt wurde dann:
   // Und wenn die Temperatur größer 15
   // Dann wird die Temperatur um 1°C verringert
   // Serial Print gibt den Wert auf dem Seriellen Monitor aus

   if ( valueB == HIGH) {
    if (temp > 15){
      temp --;
    }
    Serial.print(temp);
   }
//

  //Ab hier wird der Servomotor in Abhängigkeit von der Temperatur angesteuert.
  //Für jede Temperatur kann ein eigener case angelegt werden
switch (temp) {
  case 24:
      meinServomotor.write(0);//Servomotor wird in die definierte Position bewegt
      break;
  case 23:
      meinServomotor.write(5);//Servomotor wird in die definierte Position bewegt
      break;
  case 22:
      meinServomotor.write(10);//Servomotor wird in die definierte Position bewegt
      break;
  case 21:
      meinServomotor.write(15);//Servomotor wird in die definierte Position bewegt
      break;
   case 20:
      meinServomotor.write(20);//Servomotor wird in die definierte Position bewegt
      break;
   case 19:
      meinServomotor.write(25);//Servomotor wird in die definierte Position bewegt
      break;
   case 18:
      meinServomotor.write(30);//Servomotor wird in die definierte Position bewegt
      break;
   case 17:
      meinServomotor.write(35);//Servomotor wird in die definierte Position bewegt
      break;
   case 16:
      meinServomotor.write(40);//Servomotor wird in die definierte Position bewegt
      break;
   case 15:
      meinServomotor.write(45);//Servomotor wird in die definierte Position bewegt
      break;


    default:
      // wenn nichts anderes passt, kann ein default Wert vorgegeben werden
      // der default Wert ist optional
    break;
  }


}
