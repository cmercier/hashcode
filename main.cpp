#include <iostream>
#include <fstream>

using namespace std;

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

