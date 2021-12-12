#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
typedef struct
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct {
int ref;
char type [100];
float V_Max;
float V_Min;
date dt;
char Emplacement [100];
}capteur;


capteur cap;


int REF;
int rech (int refrech);
void Ajouter_capt(capteur c);
void Rech_affich(GtkWidget *liste);
void supprimer(int REF);
void modifier(capteur c,int REF);
void afficher_capteur(GtkWidget *liste);
void Aff_captdef();
void cap_defecteux(GtkWidget *liste,char E ,char *file);
#endif // CAPTEUR_H_INCLUDED

