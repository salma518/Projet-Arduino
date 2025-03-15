# Projet-Arduino
Ce code implémente un système de verrouillage de porte simple utilisant un clavier matriciel 4x4, un servomoteur, et un écran LCD I2C.  Voici un `README` plus complet pour ce projet :

# Système de Verrouillage de Porte avec Clavier Matriciel

Ce projet décrit un système de verrouillage de porte contrôlé par un mot de passe entré sur un clavier matriciel 4x4. Le système utilise un écran LCD I2C pour l'interaction utilisateur et un servomoteur pour actionner le mécanisme de verrouillage.

## Fonctionnalités

* **Authentification par mot de passe :** L'utilisateur doit entrer un mot de passe correct pour déverrouiller la porte.
* **Clavier matriciel :** Un clavier matriciel 4x4 permet à l'utilisateur d'entrer le mot de passe.
* **Affichage LCD :** Un écran LCD I2C affiche des messages de confirmation ou d'erreur.
* **Contrôle du servomoteur :** Un servomoteur actionne le mécanisme de verrouillage/déverrouillage de la porte.
* **Sécurité basique :** Le mot de passe est codé en dur dans le code.  (**Important :**  Pour une application réelle, il faudrait implémenter une méthode de stockage de mot de passe plus sécurisée.)

## Matériel Nécessaire

* Carte Arduino (Uno, Nano, etc.)
* Clavier matriciel 4x4
* Servomoteur
* Écran LCD I2C 16x2
* Fils de connexion
* Alimentation 5V

## Schéma de câblage

(Un schéma de câblage est recommandé ici.  Il devrait montrer la connexion entre l'Arduino, le clavier, le servomoteur, et l'écran LCD.  Indiquer les numéros de broches Arduino utilisés.)

**Exemple (à adapter à votre câblage):**

* **Clavier 4x4 :**
    * Lignes (ROWS) :  Broches Arduino 0 à 3
    * Colonnes (COLS) : Broches Arduino 4 à 7
* **Servomoteur :**  Broche Arduino 9
* **LCD I2C :**  SDA et SCL (consultez la documentation de votre écran LCD pour les broches I2C)


## Installation du code

1. **Installer les librairies :** Installez les librairies `LiquidCrystal_I2C` et `Keypad` dans l'IDE Arduino.
2. **Copier le code :** Copiez le code fourni dans l'IDE Arduino.
3. **Modifier le mot de passe :** Modifiez la variable `password` dans le code avec votre mot de passe souhaité.
4. **Téléverser le code :** Téléversez le code sur votre carte Arduino.

## Contact

Pour toute question, contactez-nous par email à salma.fathi16000@gmail.com


