#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

Node* initialiserListe() {
    return NULL;
}

Node* creerNoeud(Etudiant e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation\n");
        exit(1);
    }
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

Node* ajouterFin(Node* head, Etudiant e) {
    Node* newNode = creerNoeud(e);

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void afficherListe(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("Matricule: %d | Nom: %s | Moyenne: %.2f\n",
               temp->data.matricule,
               temp->data.nom,
               temp->data.moyenne);
        temp = temp->next;
    }
}

Node* rechercher(Node* head, int matricule) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.matricule == matricule)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Node* supprimer(Node* head, int matricule) {
    if (head == NULL) return NULL;

    if (head->data.matricule == matricule) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Etudiant supprime\n");
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data.matricule != matricule)
        current = current->next;

    if (current->next == NULL) {
        printf("Etudiant non trouve\n");
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    printf("Etudiant supprime\n");
    return head;
}

Node* modifier(Node* head, int matricule) {
    Node* etu = rechercher(head, matricule);

    if (etu == NULL) {
        printf("Etudiant non trouve\n");
        return head;
    }

    printf("Nouveau nom : ");
    scanf("%49s", etu->data.nom);

    printf("Nouvelle moyenne : ");
    scanf("%f", &etu->data.moyenne);

    printf("Modification reussie\n");
    return head;
}

int compter(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void libererListe(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
