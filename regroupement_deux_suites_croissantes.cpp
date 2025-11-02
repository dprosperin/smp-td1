//
// Created by david on 11/10/2025.
//

#include <fstream>
#include <vector>
#include <iostream>
#include <cstddef>
using namespace std;

void triSelection(std::vector<int> &tab)
{
    // Remarque : size_t est un entier non sign´e (toujours positif)
    // utilis´e par la biblioth`eque standard C++ pour repr´esenter
    // les indices et tailles des conteneurs (comme tab.size()).
    // On parcourt tout le tableau, sauf le dernier ´el´ement
    // (qui sera forc´ement le plus grand `a la fin).
    for (std::size_t i = 0; i < tab.size(); ++i)
    {
        // pmin garde l'indice du plus petit ´el´ement trouv´e dans la partie non tri´ee
        std::size_t pmin = i;
        // Parcourt la sous-partie [i+1, fin) pour trouver le plus petit ´el´ement
        for (std::size_t j = i + 1; j < tab.size(); ++j)
        {
            if (tab[j] < tab[pmin])
                pmin = j; // on m´emorise la position du nouveau minimum
        }
        // Si on a trouv´e un plus petit ´el´ement, on l'´echange avec tab[i]
        if (pmin != i)
            std::swap(tab[i], tab[pmin]);
    }
}

int main()
{
    ifstream s1_file, s2_file;
    ofstream fusion_file;
    s1_file.open("s1.dat");
    s2_file.open("s2.dat");
    fusion_file.open("fusion.dat", ios::out);
    vector<int> s1_nombres, s2_nombres;

    int nombre = 0;

    if (!(s1_file.is_open() && s2_file.is_open() && fusion_file.is_open()))
        return -1;

    while (!s1_file.eof())
    {
        s1_file >> nombre;

        if (nombre == -1)
        {
            break;
        }
        s1_nombres.push_back(nombre);
    }

    s1_file.close();

    while (!s2_file.eof())
    {
        s2_file >> nombre;

        if (nombre == -1)
        {
            break;
        }
        s2_nombres.push_back(nombre);
    }

    s2_file.close();

    // On ajout s2_nombres à s1_nombres
    s1_nombres.insert(s1_nombres.end(), s2_nombres.begin(), s2_nombres.end());
    // On trie par ordre croissant
    triSelection(s1_nombres);

    for (const auto &s1_nombre : s1_nombres)
    {
        fusion_file << s1_nombre << endl;
    }
    fusion_file << "-1" << endl;

    fusion_file.close();

    return 0;
}
