#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    int taille;
    int max_taille;
};


void initialise(Liste* liste)
{
    Noeud* nouveau = new Noeud;
    nouveau=nullptr;
    liste->premier=nouveau;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier==nullptr){
        return true;
    }
    return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* current = liste->premier;
    while(current->suivant!=nullptr){
        current=current->suivant;
    }
    Noeud* nouveau = new Noeud;
    nouveau->donnee=valeur;
    current->suivant=nouveau;
}

void affiche(const Liste* liste)
{
    Noeud* current = liste->premier;
    std::cout<<"{";
    while(current!=nullptr)
    {
        std::cout<<current->donnee<<", ";
    }
    std::cout<<"}"<<std::endl;
}

int recupere(const Liste* liste, int n)
{
    Noeud* current = liste->premier;
    for(int i;i<n;i++)
    {
        current = current->suivant;
    }
    return current->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* current = liste->premier;
    int index = 0;
    while(current->suivant!=nullptr)
    {
        if(current->donnee==valeur)
        {
            return index;
        }
        index++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* current = liste->premier;
    for(int i;i<n;i++)
    {
        current = current->suivant;
    }
    current->donnee=valeur;
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille+1>tableau->max_taille)
    {
        int new_donnees[tableau->max_taille+1];
        for(int index=0;index<tableau->max_taille;index++)
        {
            new_donnees[index]=tableau->donnees[index];
        }
        tableau->donnees = new_donnees;
    }
    
    tableau->donnees[tableau->taille] = valeur;
    tableau->taille ++;

}


void initialise(DynaTableau* tableau, int capacite)
{
    int jeu_2_donnees[capacite];
    int taille = 0;
    tableau->donnees = jeu_2_donnees;
    tableau->max_taille = capacite;
    tableau->taille=taille;
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->taille==0)
    {
        return true;
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    std::cout<<"[";
    for(int index=0; index<tableau->taille;index++)
    {
        std::cout<<tableau->donnees[index]<<", ";
    }
    std::cout<<"]";
}

int recupere(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n];
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int index=0;index<tableau->taille;index++)
    {
        if(tableau->donnees[index]==valeur){
            return index;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n]=valeur;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud* nouveau_noeud = new Noeud;
    nouveau_noeud->donnee = valeur;
    nouveau_noeud->suivant = liste->premier;
    liste->premier = nouveau_noeud;
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    Noeud* current = liste->premier;
    while(current->suivant!=nullptr)
    {
        current = current->suivant;
    }
    return current->donnee;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    return 0;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
