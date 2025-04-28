#include <Wire.h>
#include <arduino.h>

// Configuration du clavier
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    // Broches des lignes
byte colPins[COLS] = {5, 4, 3, 2};    // Broches des colonnes

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Configuration de l'écran LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);   // Adresse I2C 0x27, 16 colonnes, 2 lignes

// Base de données des clients
struct Client {
  const char* id;
  const char* nom;
};

Client clients[] = {
  {"1234", "Alice"},
  {"5678", "Bob"},
  {"0000", "Invité"}
};

const int nbClients = sizeof(clients) / sizeof(clients[0]);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Entrez ID client:");
  lcd.setCursor(0, 1);
}

void loop() {
  static String idSaisi = "";
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // Touche "Entrée"
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ID: " + idSaisi);
      lcd.setCursor(0, 1);
      const char* nomClient = rechercherClient(idSaisi.c_str());
      lcd.print(nomClient);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Entrez ID client:");
      lcd.setCursor(0, 1);
      idSaisi = "";
    } else if (key == '*') { // Touche "Effacer"
      idSaisi = "";
      lcd.setCursor(0, 1);
      lcd.print("                "); // Efface la ligne
      lcd.setCursor(0, 1);
    } else if (idSaisi.length() < 8) { // Limite à 8 caractères
      idSaisi += key;
      lcd.print(key);
    }
  }
}

// Fonction pour rechercher le nom du client
const char* rechercherClient(const char* id) {
  for (int i = 0; i < nbClients; i++) {
    if (strcmp(clients[i].id, id) == 0) {
      return clients[i].nom;
    }
  }
  return "Inconnu";
}
port serial
import cx_Oracle

# Connexion au port série
ser = serial.Serial('COM3', 9600, timeout=1)

# Connexion Oracle
dsn = cx_Oracle.makedsn('localhost', 1521, service_name='XE')
conn = cx_Oracle.connect(user='amensa', password='admin', dsn=dsn)
cursor = conn.cursor()

while True:
    ligne = ser.readline().decode().strip()
    if ligne.startswith("ID:"):
        id_client = ligne.split(":")[1]
        cursor.execute("SELECT nom FROM clients WHERE id = :id", id=id_client)
        result = cursor.fetchone()
        if result:
            print(f"Nom du client : {result[0]}")
        else:
            print("Client inconn")
}




