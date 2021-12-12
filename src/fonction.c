#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>
#include "fonction.h"

enum
{
categorie,
nomproduit,
codeproduit,
quantite,
prix,
DATE,
typequantite,
COLUMNS,
};

void ajout(produit p)

{

FILE *f;
f =fopen("produits.txt","a+");

if (f !=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s\n", p.categorie, p.nom, p.code, p.quantite, p.prix, p.type, p.date); 
}
fclose(f);
}

void afficher(GtkWidget *treeview)
{
produit p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;

GtkTreeIter iter;
GtkListStore *store=NULL;
//gtk_list_store_clear(treeview);
FILE *f = NULL;
store = gtk_tree_view_get_model(treeview);
if (store == NULL)

{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("categorie", renderer, "text",categorie , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", nomproduit, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("code", renderer, "text", codeproduit, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

                renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", quantite, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",prix, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",typequantite, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);



}

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("produits.txt", "r");
if (f == NULL)
{
return;
}
else
{

while (fscanf(f,"%s %s %s %s %s %s %s", p.categorie, p.nom,p.code, p.quantite, p.prix, p.type, p.date) != EOF)
{

gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,categorie,p.categorie,nomproduit,p.nom, codeproduit , p.code,quantite, p.quantite,prix, p.prix,typequantite, p.type, DATE, p.date, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void tes_supprimer(char fichier[],char prod_code[])
{

produit p;
FILE *f, *tmp;

f = fopen(fichier, "r");
tmp = fopen("tmp.txt", "w+");

if ((f == NULL) || (tmp == NULL))
{
return;
}
else
{
while (fscanf(f, "%s %s %s %s %s %s %s", p.categorie,p.nom, p.code, p.quantite, p.prix, p.type, p.date) != EOF)
{
if (strcmp(p.code,prod_code))

fprintf(tmp, "%s %s %s %s %s %s %s\n",p.categorie,p.nom, p.code, p.quantite, p.prix, p.type, p.date); 
}
}
fclose(f);
fclose(tmp);
remove(fichier);
rename("tmp.txt", fichier);
}



void recherche(GtkWidget *treeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
FILE *f2;
produit p;
store = NULL;
store =gtk_tree_view_get_model(treeview);

//f2 = fopen("produits.txt", "r");

if (store == NULL)

{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("categorie", renderer, "text", categorie, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", nomproduit, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

 renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("code", renderer, "text", codeproduit, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", quantite, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

               
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text", prix, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", typequantite, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f2 = fopen("recherche.txt", "r+");
while (fscanf(f2, "%s %s %s %s %s %s %s\n", p.categorie, p.nom,p.code, p.quantite, p.prix, p.date, p.type) != EOF) 
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,categorie, p.categorie ,nomproduit,p.nom, codeproduit , p.code,quantite, p.quantite,prix, p.prix, DATE, p.date, typequantite, p.type,  -1);
}
fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
g_object_unref(store);
remove("recherche.txt");
}


void modification(char fichier[30] , produit p)
{

produit k;
FILE *f1 = NULL, *f = NULL;
//sprintf(p.date, "%d/%d/%d", p.d.jour, p.d.mois, p.d.annee);
//sprintf(k.date, "%d/%d/%d", k.d.jour, k.d.mois, k.d.annee);
f = fopen(fichier, "r");
f1 = fopen("tmp.txt", "w+");
if ((f != NULL) && (f1 != NULL))
{
while (fscanf(f, "%s %s %s %s %s %s %s", k.categorie, k.nom,k.code, k.quantite, k.prix, k.date, k.type) != EOF)
{
if (!strcmp(p.code,k.code))
{
fprintf(f1, "%s %s %s %s %s %s %s\n", p.categorie, p.nom,p.code, p.quantite, p.prix, p.date, p.type);
       }    
else
{
fprintf(f1, "%s %s %s %s %s %s %s\n",k.categorie, k.nom,k.code, k.quantite, k.prix, k.date, k.type) ;
       }
       }

}
fclose(f);
fclose(f1);
remove(fichier);
rename("tmp.txt", fichier);
}





