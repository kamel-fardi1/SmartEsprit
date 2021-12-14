#include <gtk/gtk.h>
typedef struct{
char boisson[100];
char produit_cerealier[100];
char vienoiserie[100];
}pdej;
typedef struct{
char entree[100];
char plat_princ[100];
char dessert[50];
}repas;
typedef struct{
int jour;
int mois;
pdej petit_dej;
repas dejeuner;
repas diner;
}menu;

int decision;

void ajouter(menu x);
void supprimer(menu x);
void modifier(menu x);
void afficher(int numsemaine,GtkWidget *liste);
void chercher(menu x,GtkWidget *liste);
void affichage(GtkWidget *liste);
void affiche_meileur_menu(char ch1[],char ch2[],char ch3[]);
int trouve(menu x);
