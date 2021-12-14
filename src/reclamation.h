#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "reclamation.h"
typedef struct
{
    int jour;
    int mois;
    int annee;
}Datee;
typedef struct
{
    Datee date;
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    int numero_reclamation;
    char text_reclamation[1000];
}reclamation;
typedef struct
{
    int jour1;
    int mois1;
    int annee1;
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
}newreclam;
typedef struct
{
    char jour1[20];
    char mois1[20];
    char annee1[20];
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
}soulofthedead;

void ajouter_reclam(newreclam r);
void modifier_reclam(soulofthedead p ,newreclam r);
void afficher_reclam(void);
void supprimer_reclam(soulofthedead p);
void chercher(char n[20],char p[20],GtkWidget *liste);
void test(soulofthedead r);
void affich(GtkWidget *liste);
void leplusreclamer(GtkWidget *liste);
int verification(newreclam r);


#endif // FONCTION_H_INCLUDED

