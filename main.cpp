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
int parcoursGroup = 0;

bool grille[MAX_INT][MAX_INT];

int getGroup()
{
    if (parcoursGroup >= P)
        parcoursGroup = 0;
    return parcoursGroup++;
}

bool read_input_file (string filename) {
    FILE *f = NULL;
    f = fopen(filename.c_str(), "r+");
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
        for (int i = 0; i < M; i++) {
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
    f = fopen(filename.c_str(), "w+");
    bool success = false;
    if (f) {
        success = true;
        for (int i = 0; i < serveurAAllouer.size(); i++) {
            Serveur *s = serveurAAllouer[i];
            if (1) {
                fprintf(f, "%d %d %d\n", s->row, s->column, s->group);
            } else {
                fprintf(f, "x\n");
            }
        }
        fclose(f);
    }
    return success;
}

bool init_vars () {
    if (read_input_file("dc.in")) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < S; j++) {
                grille[i][j] = false;
            }
        }
        return true;
    }
    return false;
}

bool triPerformance(Serveur* i, Serveur* j)
{
    return (i->c/i->t) > (j->c/j->t);
}

bool testTaille(int row, int column, int taille)
{
    for(int i = column; i + taille < S && i < column + taille; i++)
    {
        if (grille[row][i] == true)
           return false;
    }
    return true;
}

bool addToRangee(int rangee,int index)
{
    Serveur* serveur = serveurTrie[index];
    int taille = serveur->t;
    for(int i = 0; i < S; i++)
    {
        if (grille[rangee][i] == false){
            if(testTaille(rangee, i, taille))
            {
                serveur->row = rangee;
                serveur->column = i;
                serveur->group = getGroup();
                serveurTrie.erase(serveurTrie.begin() + index);
                for(int j = 0; j < taille; j++)
                {
                    grille[rangee][i + j] = true;
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{
    if (init_vars()) {
        for(int i = 0; i < serveurAAllouer.size(); i++)
        {
            serveurTrie.push_back(serveurAAllouer[i]);
        }

        sort(serveurTrie.begin(), serveurTrie.end(), triPerformance);

        for(int i = 0; i < serveurTrie.size(); i++)
        {
            cout << serveurTrie[i]->t << "-" << serveurTrie[i]->c << endl;
        }

        for (int k = 0; k < R; k++) {
            for(int i = 0; i < R; i++)
            {
                int indexServeur = 0;
                while (addToRangee(i, indexServeur) == false && indexServeur < serveurTrie.size())
                {
                    indexServeur++;
                }
                cout << serveurTrie.size()<< endl;
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < S; j++) {
                if (grille[i][j] == true) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }

        print_output_file("dc.txt");
    }
    return 0;
}
