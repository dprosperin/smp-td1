//
// Created by david on 11/10/2025.
//

#include <fstream>
#include <vector>
using namespace std;

int main () {
    ifstream s1_file, s2_file;
    ofstream fusion_file;
    s1_file.open("s1.dat");
    s2_file.open("s2.dat");
    fusion_file.open("fusion.dat");
    vector<int> s1_nombres, s2_nombres;

    int nombre = 0;

    if (!(s1_file.is_open() && s2_file.is_open() && fusion_file.is_open()))
        return -1;

    while (!s1_file.eof()) {
        s1_file >> nombre;

        if (nombre == -1) {
            break;
        }
        s1_nombres.push_back(nombre);
    }

    while (!s2_file.eof()) {
        s2_file >> nombre;

        if (nombre == -1) {
            break;
        }
        s2_nombres.push_back(nombre);
    }
    return 0;
}
