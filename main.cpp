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
        string contenu;
        fichier >> R >> S >> U >> P >> M;
        getline(fichier, contenu);  // on avance

        int count = 0;
        while (count < U)
        {
            string substring;
            istringstream* streamLine = new istringstream(contenu);
            getline(*streamLine, substring, ' ');
            Emplacement* emp = new Emplacement();
            emp->r = substring;
            getline(*streamLine, substring, ' ');
            emp->c = substring;
            emplIndisponibles.push_back(*emp);

            getline(fichier, contenu);  // on met dans "contenu" la ligne
            count++;
        }

        count = 0;
        while (count < M)
        {
            string substring;
            istringstream* streamLine = new istringstream(contenu);
            getline(*streamLine, substring, ' ');
            Serveur* emp = new Serveur();
            emp->t = substring;
            getline(*streamLine, substring, ' ');
            emp->c = substring;
            emplIndisponibles.push_back(*emp);

            getline(fichier, contenu);  // on met dans "contenu" la ligne
            count++;
        }

        fichier.close();  // on ferme le fichier
    }
    else  // sinon
            cerr << "Impossible d'ouvrir le fichier !" << endl;

    cout << M << endl;
    return 0;
}

