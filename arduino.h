#ifndef PAGE_H
#define PAGE_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Définition de la structure Client
struct Client {
    const char* id;
    const char* nom;
};

// Déclarations
extern LiquidCrystal_I2C lcd;
extern Keypad keypad;
extern Client clients[];
extern const int nbClients;

// Fonctions
void initialiserLCD();
void afficherDemandeID();
void afficherClient(const char* idSaisi);
const char* rechercherClient(const char* id);

#endif // PAGE_H
