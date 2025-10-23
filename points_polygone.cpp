//
// Created by david on 08/10/2025.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <cfloat>
using namespace std;

struct point_s {
    float x;
    float y;
    char nom;
};

struct polygone_s {
    vector<point_s> points;
};

float distance(const point_s & p1, const point_s & p2) {
    const float dy = p1.y - p2.y;
    const float dx = p1.x - p2.x;
    return sqrt(dy * dy + dx * dx);
}

vector<point_s> boiteEnglobante(const vector<point_s>& mes_points) {
    vector<point_s> boite{4};
    float xmin= FLT_MAX;
    float ymin= FLT_MAX;
    float xmax= FLT_MIN;
    float ymax= FLT_MIN;

    for (auto p : mes_points) {
        xmin = min(xmin, p.x);
        ymin = min(ymin, p.y);
        xmax = max(xmax, p.x);
        ymax = max(ymax, p.y);
    }

    boite[0].x = xmin;
    boite[0].y = ymin;
    boite[0].nom = 'A';

    boite[1].x = xmax;
    boite[1].y = ymin;
    boite[1].nom = 'B';

    boite[2].x = xmax;
    boite[2].y = ymax;
    boite[2].nom = 'C';

    boite[3].x = xmin;
    boite[3].y = ymax;
    boite[3].nom = 'D';

    return boite;
}

int main()
{
    ifstream fichier_coordonnes;
    fichier_coordonnes.open("coordonnees_triangle.txt");

    fichier_coordonnes.is_open();
    polygone_s polygone;

    float perimetre = 0;
    float moyenne_perimetre = 0;

    point_s mon_point{};

    fichier_coordonnes >> mon_point.x >> mon_point.y >> mon_point.nom;

    polygone.points.push_back(mon_point);

    do {
        fichier_coordonnes >> mon_point.x >> mon_point.y >> mon_point.nom;

        polygone.points.push_back(mon_point);

    } while (polygone.points[0].nom != mon_point.nom);

    fichier_coordonnes.close();

    const vector<point_s> boite = boiteEnglobante(polygone.points);

    for (size_t i = 0; i < (polygone.points.size() - 1); i++) {
        perimetre += distance(polygone.points[i], polygone.points[i + 1]);
    }

    moyenne_perimetre = perimetre / (polygone.points.size() - 1);

    for (const auto &p : polygone.points) {
        cout << p.x << ' ' << p.y << ' ' << p.nom << endl;
    }

    cout << "Perimetre: " << perimetre << endl;
    cout << "Moyenne perimetre: " << moyenne_perimetre << endl;

    for (const auto &p : boite) {
        cout << p.x << ' ' << p.y << ' ' << p.nom << endl;
    }
    return 0;
}