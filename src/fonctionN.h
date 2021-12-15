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

void nbajouter(menu x);
void nbsupprimer(menu x);
void nbmodifier(menu x);
void nbafficher(int numsemaine,GtkWidget *liste);
void nbchercher(menu x,GtkWidget *liste);
void nbaffichage(GtkWidget *liste);
void nbaffiche_meileur_menu(GtkWidget *liste,int x);
int nbtrouve(menu x);
