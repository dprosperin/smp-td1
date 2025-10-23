//
// Created by david on 11/10/2025.
//

#include <iostream>
using namespace std;

int main() {
    int entree = 0;
    int nb_changements_de_signe = 0;
    int ancienne_entree = -1;

    do {
        cin >> entree;

        if (((entree >= 0 && ancienne_entree < 0) || (entree < 0 && ancienne_entree >= 0)) && (
                ancienne_entree != -1) && (entree != -1))
            nb_changements_de_signe++;

        ancienne_entree = entree;
    } while (entree != -1);


    cout << "Nb changements de signe: " << nb_changements_de_signe << endl;
    return 0;
}