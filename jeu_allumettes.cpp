//
// Created by David PROSPÉRIN on 09/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    int nb_allumettes = 10;
    int qui_joue = 1;
    int entree_joueur = 0;

    while (nb_allumettes > 0) {

        cout << "==== Tour joueur " << qui_joue << " ====" << endl;
        cout << "Il reste " << nb_allumettes << " allumettes" << endl;
        cout << "Combien de allumettes voulez-vous retirer ? ";
        while (!(cin >> entree_joueur) ||
            !(entree_joueur >= 1 && entree_joueur <= 3) ||
            !(entree_joueur <= nb_allumettes)) {
            if (cin.fail()) {
                cout << "Entrée invalide. Veuillez réessayer." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                cout << "Retirer " << entree_joueur << " allumette(s) n'est pas possible. Veuillez réessayer." << endl;
            }
            cout << "Combien de allumettes voulez-vous retirer ? ";
        }

        nb_allumettes  -= entree_joueur;
        entree_joueur = 0;

        // On change le prochain joueur qui va jouer au prochain tour
        qui_joue = (qui_joue == 1) ? 2 : 1;
    }
    /*
     * On annonce le gagnant
     */
    cout << "==== Fin de la partie ====" << endl;
    cout << "Le joueur " << qui_joue << " a gagné la partie." << endl;
    return 0;
}