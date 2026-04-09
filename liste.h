#ifndef LISTE_H
#define LISTE_H

typedef struct Etudiant {
    int matricule;
    char nom[50];
    float moyenne;
} Etudiant;

typedef struct Node {
    Etudiant data;
    struct Node* next;
} Node;

// Fonctions
Node* initialiserListe();
Node* creerNoeud(Etudiant e);
Node* ajouterFin(Node* head, Etudiant e);
void afficherListe(Node* head);
Node* rechercher(Node* head, int matricule);
Node* supprimer(Node* head, int matricule);
Node* modifier(Node* head, int matricule);
int compter(Node* head);
void libererListe(Node* head);

#endif
