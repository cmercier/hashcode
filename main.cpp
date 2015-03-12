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
    int t, c, row, column, group;// taille & capacite
    // rangee 1000 equivaut à x
} Serveur;

vector<Emplacement*> emplIndisponibles;
vector<Serveur*> serveurAAllouer;

int main()
{
    FILE *f = NULL;
    f = fopen("dc.in", "r+");

    if(f)  // si l'ouverture a réussi
    {
        fscanf(f, "%d %d %d %d %d\n", &R, &S, &U, &P, &M);

        int count = 0;
        while (count < U)
        {
            Emplacement *e = new Emplacement();
            fscanf(f, "%d %d\n", &(e->r), &(e->c));
            emplIndisponibles.push_back(e);

            cout << e->r << "-" << e->c << endl;
            count++;
        }

        count = 0;
        while (count < M)
        {
            Serveur *s = new Serveur();
            fscanf(f, "%d %d\n", &(s->t), &(s->c));
            serveurAAllouer.push_back(s);

            cout << s->t << "-" << s->c << endl;
            count++;
        }
        fclose(f);  // on ferme le fichier

        FILE *outputFile = NULL;
        outputFile = fopen("dc.txt", "w+");

        if (outputFile) {
            for (int i = 0; i < serveurAAllouer.size(); i++) {
                Serveur *s = serveurAAllouer[i];
                if (1) {
                    fprintf(outputFile, "%d %d %d\n", 0, 0, 0);
                } else {
                    fprintf(outputFile, "x\n");
                }
            }
            fclose(outputFile);  // on ferme le fichier
        }
        else
            cerr << "Impossible d'ouvrir le fichier d'output' !" << endl;




    }
    else  // sinon
            cerr << "Impossible d'ouvrir le fichier d'input' !" << endl;
    return 0;
}

