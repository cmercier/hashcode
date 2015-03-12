#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define MAX_INT 1000

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
    bool used;
} Serveur;

vector<Emplacement*> emplIndisponibles;
vector<Serveur*> serveurTrie;
vector<Serveur*> serveurAAllouer;

bool grille[MAX_INT][MAX_INT];

bool read_input_file (string filename) {
    FILE *f = NULL;
    f = fopen(filename, "r+");
    bool success = false;
    if (f) {
        success = true;
        fscanf(f, "%d %d %d %d %d\n", &R, &S, &U, &P, &M);
        for (int i = 0; i < U; i++) {
            Emplacement *e = new Emplacement();
            fscanf(f, "%d %d\n", &(e->r), &(e->c));
            emplIndisponibles.push_back(e);

            grille[e->r][e->c] = true;

            //cout << e->r << "-" << e->c << endl;
        }
        for (int i = 0; i < U; i++) {
            Serveur *s = new Serveur();
            fscanf(f, "%d %d\n", &(s->t), &(s->c));
            serveurAAllouer.push_back(s);

            //cout << s->t << "-" << s->c << endl;
        }
        fclose(f);
    }
    return success;
}

bool print_output_file (string filename) {
    FILE *f = NULL;
    f = fopen(filename, "w+");
    bool success = false;
    if (f) {
        success = true;
        for (int i = 0; i < serveurAAllouer.size(); i++) {
            Serveur *s = serveurAAllouer[i];
            if (1) {
                fprintf(outputFile, "%d %d %d\n", 0, 0, 0);
            } else {
                fprintf(outputFile, "x\n");
            }
        }
        fclose(f);
    }
    return success;
}

void init_vars () {
    read_input_file("dc.in");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            grille[i][j] = false;
        }
    }
}

bool triPerformance(Serveur* i, Serveur* j)
{
    return (i->c/i->t) > (j->c/j->t);
}

int main()
{
    init_vars();
    print_output_file("dc.txt");

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

            //cout << e->r << "-" << e->c << endl;
            grille[e->r][e->c] = true;
            count++;
        }

        count = 0;
        while (count < M)
        {
            Serveur *s = new Serveur();
            fscanf(f, "%d %d\n", &(s->t), &(s->c));
            serveurAAllouer.push_back(s);

            //cout << s->t << "-" << s->c << endl;
            count++;
        }
        fclose(f);  // on ferme le fichier

        for(int i = 0; i < serveurAAllouer.size(); i++)
        {
            serveurTrie.push_back(serveurAAllouer[i]);
        }

        sort(serveurTrie.begin(), serveurTrie.end(), triPerformance);

        for(int i = 0; i < serveurTrie.size(); i++)
        {
            cout << serveurTrie[i]->t << "-" << serveurTrie[i]->c << endl;
        }


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
            cerr << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}
