//
// Created by david on 08/10/2025.
// Pour aller plus loin avec un motif quelconque
//

#include <iostream>
using namespace std;

int main()
{
    int nb_le_dans_phrase = 0;
    char c = '0', c_prev = '0';

    cin >> c;
    while (c != '.')
    {
        if (c_prev == 'L' && c == 'E')
        {
            nb_le_dans_phrase++;
        }

        c_prev = c;
        cin >> c;
    }

    std::cout << nb_le_dans_phrase << endl;

    return 0;
}