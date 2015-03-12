#include <iostream>
#include <vector>

using namespace std;

int R, // Nb de rangees du centre
    S, // Nb emplacements de chaque rangee
    U, // Nb emplacements indisponibles
    P, // Nb de groupes a creer
    M; // Nb de serveurs a allouer

typedef struct emplacement {
    int r, c; // rangee & colonne
} Emplacement;

typedef struct serveur {
    int t, c; // taille & capacite
} Serveur;

vector<Emplacement> emplIndisponibles;
vector<Serveur> serveurAAllouer;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

