#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};




void initialise_l(Liste* liste)
{
    Noeud* init = new Noeud;
    init = nullptr;
    liste->premier = init;
}

bool est_vide_l(const Liste* liste)
{
    if(liste->premier==nullptr){
        return true;
    }
    return false;
}

void ajoute_l(Liste* liste, int valeur)
{
    Noeud* new_noeud = new Noeud;
    new_noeud->donnee = valeur;
    new_noeud->suivant = nullptr;
    if(est_vide_l(liste)){
        liste->premier = new_noeud;
    }
    else{
        Noeud* current = liste->premier;
        while(current->suivant != nullptr){
            current = current->suivant;
        }
        current->suivant = new_noeud;
    }
}

void affiche_l(const Liste* liste)
{
    Noeud* current = liste->premier;
    std::cout<<"{ ";
    while(current!=nullptr){
        std::cout<<", "<<current->donnee;
        current = current->suivant;
    }
    std::cout<<" }"<<std::endl;
}

int recupere_l(const Liste* liste, int n)
{
    Noeud* current = liste->premier;
    for(int i=0;i<n;i++){
        current = current->suivant;
    }
    return current->donnee;
}

int cherche_l(const Liste* liste, int valeur)
{
    Noeud* current = liste->premier;
    int cmp = 1;
    while(current!=nullptr){
        if(current->donnee == valeur){
            return cmp;
        }
        cmp++;
        current = current->suivant;
    }
    return -1;
}

void stocke_l(Liste* liste, int n, int valeur)
{
    Noeud* current = liste->premier;
    for(int i = 0; i<n-1;i++){
        current = current->suivant;
    }
    current->donnee = valeur;
}

struct DynaTableau{
    int* donnees;
    int max_taille;
};

void initialise_t(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int[capacite];
    tableau->max_taille = capacite;
}

void ajoute_t(DynaTableau* tableau, int valeur)
{
    if(tableau->donnees == nullptr)
    {
        tableau->donnees = new int[1];
        tableau->donnees[0] = valeur;
        tableau->max_taille = 1;
    }else
    {
        int* newTab = new int[tableau->max_taille+1];
        for(int i = 0 ; i<tableau->max_taille+1;i++)
        {
            newTab[i] = tableau->donnees[i];
        }
        newTab[tableau->max_taille] = valeur;
        tableau->max_taille++;
        tableau->donnees = newTab;
    }
}

bool est_vide_t(DynaTableau* tableau)
{
   return tableau->donnees == nullptr;
}

void affiche_t(DynaTableau* tableau)
{
    std::cout<<"[ ";
    for(int i = 0; i <tableau->max_taille;i++){
    std::cout<<", "<<tableau->donnees[i];
    }
    std::cout<<" ]";
}

int recupere_t(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n-1];
}

int cherche_t(const DynaTableau* tableau, int valeur)
{
    for(int i = 0 ; i< tableau->max_taille;i++)
    {
        if(tableau->donnees[i]==valeur)
        {
            return i+1;
        };
    };
    return -1;
}

void stocke_t(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n-1] = valeur;
    return;
}

/*PILE ET FILE*/

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file_l(Liste* liste, int valeur)
{
    Noeud* nouveau_noeud = new Noeud;
    nouveau_noeud->donnee = valeur;
    nouveau_noeud->suivant = liste->premier;
    liste->premier = nouveau_noeud;
}

//int retire_file(Liste* liste)
int retire_file_l(Liste* liste)
{
    Noeud* current = liste->premier;
    if(liste->premier->suivant == nullptr){
        int valeur = liste->premier->donnee;
        liste->premier = nullptr;
        return valeur;
    }
    while(current->suivant->suivant!=nullptr)
    {
    
        current = current->suivant;
    }
    int valeur = current->suivant->donnee;
    current->suivant  = nullptr;
    return valeur;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile_l(Liste* liste, int valeur)
{
    Noeud* current = liste->premier;
    Noeud* new_noeud = new Noeud;
    new_noeud->donnee = valeur;
    new_noeud->suivant = nullptr;
    if(est_vide_l(liste)){
        liste->premier = new_noeud;
    }
    else{
        while(current->suivant != nullptr){
            current = current->suivant;
        }
    
    current->suivant = new_noeud;
    }
}

//int retire_pile(DynaTableau* liste)
int retire_pile_l(Liste* liste)
{   
    Noeud* current = liste->premier;
    if(liste->premier->suivant == nullptr){
        int valeur = liste->premier->donnee;
        liste->premier = nullptr;
        return valeur;
    }
    while(current->suivant->suivant!=nullptr)
    {
        current = current->suivant;
    }
    int valeur = current->suivant->donnee;
    current->suivant = nullptr;
    return valeur;
}


int main()
{
    Liste liste;
    initialise_l(&liste);
    DynaTableau tableau;
    initialise_t(&tableau, 0);
    std::cout<<"Valeurs par défauts :"<<std::endl;
    affiche_l(&liste);
    affiche_t(&tableau);
    std::cout<<std::endl;

    if (!est_vide_l(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide_t(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }
    
    for (int i=1; i<=7; i++) {
        ajoute_l(&liste, i*7);
        ajoute_t(&tableau, i*5);
    }

    if (est_vide_l(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide_t(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche_l(&liste);
    affiche_t(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere_l(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere_t(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche_l(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans le tableau à " << cherche_t(&tableau, 15) << std::endl;

    stocke_l(&liste, 4, 7);
    stocke_t(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    
    affiche_l(&liste);
    affiche_t(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise_l(&pile);
    initialise_l(&file);

    for (int i=1; i<=7; i++) {
        pousse_file_l(&file, i);
        pousse_pile_l(&pile, i);
    }

    std::cout<<"La file "<<std::endl;
    affiche_l(&file);
    std::cout<<"La pile "<<std::endl;
    affiche_l(&pile);

    std::cout<<"Vidons la file : "<<std::endl;
    int compteur = 10;
    while(!est_vide_l(&file) && compteur > 0)
    {
        std::cout << retire_file_l(&file) << std::endl;
        affiche_l(&file);
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    std::cout<<"Vidons la pile : "<<std::endl;
    compteur = 10;
    while(!est_vide_l(&pile) && compteur > 0)
    {
        std::cout << retire_pile_l(&pile) << std::endl;
        affiche_l(&pile);
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
