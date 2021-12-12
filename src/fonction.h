#include <gtk/gtk.h>
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{

   
    char categorie[100];
    char nom[100];
    char code[100];
    char quantite[1000];
    char prix[100];
    char type[100];
    char date[100];
    Date d;

} produit ;

void ajout(produit p);
void modification(char fichier[], produit p);
void tes_supprimer(char fichier[],char prod_code[]);
void recherche(GtkWidget *treeview);
void afficher(GtkWidget *treeview);


