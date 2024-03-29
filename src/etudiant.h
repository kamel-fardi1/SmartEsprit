#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <gtk/gtk.h>
typedef struct
{
 int annee;
 int mois;
 int jour;   /* data */
} kfdate;
typedef struct
{
char cin[10];
char nom[20];
char prenom[20];
char adress[20];
char services[100];
char sexe[20];
char aderess_mail[100];
char numero_telephonique[20];
char chambre[20];
char photo[1000];
kfdate date_d_hebergement;
kfdate date_de_naissance;
char classe[20];
}Etudiant;
typedef struct 
{
    char nom_d_utilisateur[50];
    char mot_de_passe[50];
    char role[50];
}user;
user utilisateur;
Etudiant etd,p;
int nbr;
char kftexthint[100];
char kfchaine[300];
char kfbackground[1000];
char kflogo[100];
char kfbuttonlabel[100];



//////////////////////CRUD//////////////////////////////////////////////

void set_text(char size[],char color[],char text[],int ajt_sup);
Etudiant chercher_etudiant(gchar *cin_cher,char file_etudiants[]);
void ajouter_etudiant(Etudiant etd,char file_etudiants[]);
void modifier_etudiant(char esm[],Etudiant etd,char file_etudiants[]);
void modif_admin(char un[],char pswd[],char file[]);
void modif_etud(char un[],char pswd[],char file[]);
int alldigit(char ch[]);
void supprimer_etudiant(char cin[],char file_etudiants[]);
int verif_cin(gchar *c,char file[]);
void afficher_etudiant(GtkWidget *liste,char file_etudinats[]);

///////////////////////admin////////////////////////////////

void supprimer_utilisateur(char un[],char pswrd[],char role[],char file[]);
void afficher_utilisateur(GtkWidget *liste,char file[]);
void afficher_responsables(GtkWidget *liste,char file[]);
void afficher_person(GtkWidget *liste,char nomu[]);
int login(char username[],char pswrd[],char *file);
void ajouter_utilisateur(char nom[],char mot_de_passe[],char role[],char fichier[]);

/////////////////tache2////////////////////////////////

int nombres_des_etudiant(char file_etudiants[],char nv);
#endif // ETUDIANT_H_INCLUDED
