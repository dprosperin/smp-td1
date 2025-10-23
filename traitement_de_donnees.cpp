//
// Created by david on 11/10/2025.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int entree = 0;
    int nb_valeurs = 0;
    int somme_valeurs = 0;
    int min_valeur = INT_MAX;
    int max_valeur = INT_MIN;
    float moyenne = 0.0;
    float dxu = 0;
    float somme_dxu_carre = 0;
    float ecart_type = 0.0;
    vector<int> valeurs;

    do {
        cin >> entree;
        if (entree != -1) {
            valeurs.push_back(entree);
            somme_valeurs += entree;
            nb_valeurs++;

            min_valeur = min(min_valeur, entree);
            max_valeur = max(max_valeur, entree);
        }
    } while (entree != -1);

    moyenne = static_cast<float>(somme_valeurs) / static_cast<float>(nb_valeurs);

    for (const int & valeur: valeurs) {
        dxu = static_cast<float>(valeur) - moyenne;
        somme_dxu_carre += dxu * dxu;
    }

    ecart_type = sqrt(somme_dxu_carre / static_cast<float>(nb_valeurs));

    cout << "Ecart type: " << ecart_type << endl;
    cout << "Moyenne: " << moyenne << endl;
    cout << "Min: " << min_valeur << endl;
    cout << "Max: " << max_valeur << endl;
    return 0;
}
