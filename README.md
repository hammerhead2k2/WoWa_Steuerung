# Arduino Projekt "WoWa_Steuerung" Version 0.1

##Temperatursteuerung der Heizung in einem Wohnwagen
- Die Temperatur kann mittels zweier Taster erhöht bzw. gesenkt werden.
- Ein Servomoter stellt die Position eines Reglers in Abhängigkeit von der gewählten
  Temperatur auf eine vorgegebene Position.

## Die bisherige Schaltung der Version 0.1
![Schaltplan](http://i.imgur.com/31JvNqd.png)

##ToDo:
Einbindung eines Temperaturfühlers, der den Istwert der Umgebung erfasst.
Die Heizungsregelung soll dann in Abhängigkeit der voreingestellten Soll Temperatur
den Servomotor positionieren.
- Bei größerer Differenz zwischen Ist und Sollwert, soll die Regelung mit einer
größeren Differenz arbeiten, um so ein schnelleres Heizen zu ermöglichen.

##Weitere Ideen:
- Bei der Verwendung eines Temperaturfühlers mit Raumluftfeuchte, kann die Luftfeuchtigkeit
  ebenfalls für die Regelung der Heizung einbezogen werden. Stichwort "Schimmelwarnung"
- Einbindung eines zusätzlichen Lüfters, der in Abhängigkeit der Temperatur und Luftfeuchtigkeit
  automatisch geschalten werden kann.
- Einbindung eines LCD Displays zur Anzeige der Ist / Sollwerte und zum Status des Lüfters.
- Nutzung des Displays um die Sollwerte mittels Tasten zu verändern.
- Einbindung eines Bewegungsmelders um die Vorzeltleuchte zu zu steuern.
- Nutzung eines 633MHz Funkempfängers um die Sollwerte und Vorgaben für den Lüfter zu schalten.

## Stand 19.02.2017
