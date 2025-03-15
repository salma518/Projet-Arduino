#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// Déclaration des constantes pour le clavier
const byte ROWS = 4; // Nombre de lignes du clavier
const byte COLS = 4; // Nombre de colonnes du clavier

// Définition des broches du clavier
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinRows[ROWS] = {0,1 , 2, 3};    // Broches de ligne connectées à Arduino
byte pinCols[COLS] = {4, 5, 6,7};    // Broches de colonne connectées à Arduino



// Définition des broches pour le servomoteur
const int SERVO_PIN = 9;

// Création des objets
Servo servo;
Keypad keypad = Keypad(makeKeymap(keys), pinRows, pinCols, ROWS, COLS);
LiquidCrystal_I2C lcd(32,16,2);

// Code du mot de passe
char password[] = "1234"; // Mot de passe à quatre chiffres

// Variables
char enteredPassword[5];  // Mot de passe entré par l'utilisateur
int passwordIndex = 0;    // Index du caractère du mot de passe entré

void setup() {
  // Initialisation de l'écran LCD
  lcd.init();
  lcd.setCursor(0,0);
   lcd.backlight();
   lcd.display();
   lcd.setCursor(0,0);
  lcd.print("Entrez le code:");
   delay(2000);
  lcd.clear();
   delay(2000);


  // Attachement du servomoteur à la broche
  servo.attach(SERVO_PIN);
}

void loop() {
  // Lecture de la touche du clavier
  servo.write(0);
  char key = keypad.getKey();
  
  // Vérification si une touche a été appuyée
  if (key) {
    if (key == '#') {
      // Vérification du mot de passe
       
      if (strcmp(enteredPassword, password) == 0) {
        lcd.clear();
        lcd.print("Code correct!");
        delay(2000);

        // Ouvrir la porte
        servo.write(90);  // Angle d'ouverture de la porte
        delay(2000);
        servo.write(0);   // Retour à la position initiale

        // Réinitialisation du mot de passe entré
        memset(enteredPassword, 0, sizeof(enteredPassword));
        passwordIndex = 0;

        lcd.clear();
        lcd.print("Entrez le code:");
        lcd.setCursor(0,0);
      } else {
        // Code incorrect
        lcd.clear();
        lcd.print("Code incorrect!");
        delay(2000);

        // Réinitialisation du mot de passe entré
        memset(enteredPassword, 0, sizeof(enteredPassword));
        passwordIndex = 0;

        lcd.clear();
        lcd.print("Entrez le code:");
        lcd.setCursor(0,0);
      }
      delay(3000);
      lcd.clear();
    } 
    else {
      // Ajouter le caractère au mot de passe entré
      enteredPassword[passwordIndex] = key;
      lcd.print('*');  // Afficher un astérisque pour chaque caractère entré
      passwordIndex++;
    }
  }
}