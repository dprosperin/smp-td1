//
// Created by David PROSPÉRIN on 09/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    bool partie_finie = false;
    int position_joueur[2] = { 0, 0 };
    int de1 = 0, de2 = 0;
    int deplacement = 0;
    // Joueur 1 joue en premier
    int qui_joue = 0;

    cout << "==== Bienvenue au jeu de l'oie ====" << endl;

    while (!partie_finie) {
        cout << "=== Joueur " << qui_joue + 1 <<  " ===" << endl;
        // On tire les deux dés
        cout << "Quelle est la valeur du dé 1 ? ";
        while (!(cin >> de1) ||
            !(de1 >= 1 && de1 <= 6) ){
            if (cin.fail()) {
                cout << "Entrée invalide. Veuillez réessayer." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                cout << "La valeur du dé doit entre comprise entre 1 et 6 inclue. Veuillez réessayer." << endl;
            }
            cout << "Quelle est la valeur du dé 1 ? ";
            }

        cout << "Quelle est la valeur du dé 2 ? ";
        while (!(cin >> de2) ||
            !(de2 >= 1 && de2 <= 6) ){
            if (cin.fail()) {
                cout << "Entrée invalide. Veuillez réessayer." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                cout << "La valeur du dé doit entre comprise entre 1 et 6 inclue. Veuillez réessayer." << endl;
            }
            cout << "Quelle est la valeur du dé 2 ? ";
            }

        // Nb de place à avancer
        deplacement = de1 + de2;

        cout << "Le joueur " << qui_joue + 1 << " se déplace de " << deplacement  << " cases." << endl;
        position_joueur[qui_joue] += deplacement;

        // Si le joueur tombe sur les cases : 9, 18, 27, 36, 45 et 54, il double son déplacement
        switch (position_joueur[qui_joue]) {
            case 9: case 18: case 27: case 36: case 45: case 54:
                cout << "Le joueur " << qui_joue + 1 << " est tombé sur l'oie. Il avance encore de " << deplacement << " cases." << endl;
                position_joueur[qui_joue] += deplacement;
                break;
        }

        if (position_joueur[qui_joue] > 63) {
            position_joueur[qui_joue] = 63 - (position_joueur[qui_joue] % 63);
        }

        // Afficher la case du joueur courant
        cout << "Le joueur " << qui_joue + 1 << " est sur la case " << position_joueur[qui_joue] << endl;

        if (position_joueur[qui_joue] == 63) {
            // Le joueur gagne
            cout << "=== Joueur " << qui_joue + 1 << " gagne la partie ===" << endl;
            partie_finie = true;
        } else if (position_joueur[qui_joue] == 52) {
            // Le joueur perd
            cout << "=== Joueur " << qui_joue + 1 << " perd la partie ===" << endl;
            partie_finie = true;
        }
        // On passe la main à l'autre joueur
        qui_joue = (qui_joue == 0) ? 1 : 0;
    }

    cout << "==== Fin de la partie ====" << endl;
    return 0;
}