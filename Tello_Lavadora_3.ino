#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

int InRojo = 2;         int OutRojo = 5;
int InAmarillo = 3;     int OutAmarillo = 12;
int InAzul = 4;         int OutAzul = 7;
int Salida = 8;         int Motor = 9;
int A = 10;             int B = 11;
void setup() 
{
  Wire.begin(); lcd.begin(); lcd.clear(); lcd.backlight(); lcd.clear();
  pinMode(InRojo, INPUT);         pinMode(OutRojo, OUTPUT);
  pinMode(InAmarillo, INPUT);     pinMode(OutAmarillo, OUTPUT);
  pinMode(InAzul, INPUT);         pinMode(OutAzul, OUTPUT);
  pinMode(Salida, OUTPUT);        pinMode(Motor, OUTPUT);
  pinMode(A, OUTPUT);             pinMode(B, OUTPUT);
  Serial.begin(9600);
  digitalWrite(OutRojo, HIGH);
  digitalWrite(OutAmarillo, HIGH);
  digitalWrite(OutAzul, HIGH);
  digitalWrite(Salida, HIGH);     // rele
  digitalWrite(Motor, LOW);

  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");delay(2000); 
  //lcd.setCursor(0,0); lcd.print(" Una produccion "); lcd.setCursor(0,1); lcd.print(" De AlvaritoTec ");delay(2000); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Proyecto de:   "); lcd.setCursor(0,1); lcd.print(" T E X T I L   !");delay(3500); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Integrantes :  "); lcd.setCursor(0,1); lcd.print("----------------");delay(3500); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Marlyn         "); lcd.setCursor(0,1); lcd.print(" Martinez       ");delay(3000); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Carlos         "); lcd.setCursor(0,1); lcd.print(" Tello          ");delay(3000); lcd.clear();
  lcd.setCursor(0,0); lcd.print("       &        "); lcd.setCursor(0,1); lcd.print("                ");delay(1000); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Roger          "); lcd.setCursor(0,1); lcd.print(" Del Aguila     ");delay(3000); lcd.clear();
  lcd.setCursor(0,0); lcd.print(" Profesor:      "); lcd.setCursor(0,1); lcd.print(" Mario Chauca   ");delay(3000); lcd.clear();
  }

void loop() 
{
  digitalWrite(Salida, HIGH);      //
  lcd.setCursor(0,0); lcd.print("   Textil  !!!  ");
  lcd.setCursor(0,1); lcd.print("................");
  delay(2000);
  Inicio:
  Serial.println("Inicio");
  Serial.println("Que Color es?");
  
  if (digitalRead(InRojo) == LOW) 
  { lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
    lcd.setCursor(0,0); lcd.print("  Color Rojo    "); lcd.setCursor(0,1); lcd.print("................");
    digitalWrite(OutRojo, LOW); digitalWrite(OutAmarillo, HIGH); digitalWrite(OutAzul, HIGH); Serial.println("Rojo"); delay(20000); goto Secuencia;}
  
  if (digitalRead(InAmarillo) == LOW) 
  { lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
    lcd.setCursor(0,0); lcd.print(" Color Amarillo "); lcd.setCursor(0,1); lcd.print("................");
    digitalWrite(OutAmarillo, LOW); digitalWrite(OutRojo, HIGH); digitalWrite(OutAzul, HIGH); Serial.println("Amarillo"); delay(20000); goto Secuencia;}
   
  if (digitalRead(InAzul) == LOW) 
  { lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
    lcd.setCursor(0,0); lcd.print("   Color Azul   "); lcd.setCursor(0,1); lcd.print("................");
    digitalWrite(OutAzul, LOW); digitalWrite(OutAmarillo, HIGH); digitalWrite(OutRojo, HIGH); Serial.println("Azul"); delay(20000); goto Secuencia;}
  
  goto Inicio;
  Secuencia:
  digitalWrite(OutRojo, HIGH); digitalWrite(OutAmarillo, HIGH); digitalWrite(OutAzul, HIGH); Serial.println("Take it Easy"); delay(1500); 
  digitalWrite(A, HIGH); digitalWrite(B, LOW); analogWrite(Motor, 150); Serial.println("Suave, suavecito"); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  Suave, Suave  "); lcd.setCursor(0,1); lcd.print("  Suavecito...  ");delay(6000);
  
  digitalWrite(A, LOW); digitalWrite(B, LOW); analogWrite(Motor, 0); Serial.println("Stop"); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  S T O P  !!!  "); lcd.setCursor(0,1); lcd.print("________________");delay(6000);

  digitalWrite(A, HIGH); digitalWrite(B, LOW); analogWrite(Motor, 150); Serial.println("De nuevo, Suave suavecito"); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  De Nuevo...   "); lcd.setCursor(0,1); lcd.print("  Suavecito...  ");delay(20000);

  digitalWrite(Salida, HIGH);
  digitalWrite(A, HIGH); digitalWrite(B, LOW); digitalWrite(Motor, HIGH); Serial.println("Shaky Shaky Shaky, TERREMOTO !!! "); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  Shaky Shaky   "); lcd.setCursor(0,1); lcd.print("  TERREMOTO !!! ");delay(1000);
  
  digitalWrite(Salida, LOW); Serial.println("Salimos !!! "); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  Salimos !!!   "); lcd.setCursor(0,1); lcd.print("________________");delay(16000);
  
  digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(Motor, LOW); Serial.println("ACABO !!!"); 
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("  Termino !!!   "); lcd.setCursor(0,1); lcd.print("________________");delay(1000);
  
  digitalWrite(Salida, HIGH); Serial.println("............................"); delay(2000);
  Serial.println("Gracias Totales !!!"); delay(1000);
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print("    Gracias     "); lcd.setCursor(0,1); lcd.print("  Totales !!!   ");delay(3000);

  Serial.println("Todo esta en el Paper..."); delay(1000);
  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  lcd.setCursor(0,0); lcd.print(" Todo esta en el"); lcd.setCursor(0,1); lcd.print(" P A P E R   !! ");delay(4000);

  lcd.setCursor(0,0); lcd.print("                "); lcd.setCursor(0,1); lcd.print("                ");
  //lcd.setCursor(0,0); lcd.print(" Gracias a :    "); lcd.setCursor(0,1); lcd.print(" alvaro marshall");delay(2000);
  
}
