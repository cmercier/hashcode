#include <iostream>
#include <vector>
#include <fstream>

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
    ifstream fichier("dc.in", ios::in);  // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        // instructions
            fichier.close();  // on ferme le fichier
    }
    else  // sinon
            cerr << "Impossible d'ouvrir le fichier !" << endl;

    cout << "Hello World!" << endl;
    return 0;
}

