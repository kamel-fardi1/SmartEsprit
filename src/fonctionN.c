#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctionN.h"
#include <gtk/gtk.h>

void ajouter(menu x)
{
FILE *f=NULL;
f=fopen("menu.txt","a");
if(f!=NULL)
{
fprintf(f,"%d %d %s %s %s %s %s %s %s %s %s \n",x.mois,x.jour,x.petit_dej.boisson,x.petit_dej.produit_cerealier,
x.petit_dej.vienoiserie,x.dejeuner.entree,x.dejeuner.plat_princ,x.dejeuner.dessert,
x.diner.entree,x.diner.plat_princ,x.diner.dessert);
fclose(f);
}
else
printf("\n not found");
}



void supprimer(menu x)
{
menu menutmp;
FILE *f=NULL;
FILE *fich=NULL;
f=fopen("menu.txt","r");
fich=fopen("tmpmenu.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %d %s %s %s %s %s %s %s %s %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)
{
if((x.mois!=menutmp.mois)||(x.jour!=menutmp.jour))
{
fprintf(fich,"%d %d %s %s %s %s %s %s %s %s %s \n",menutmp.mois,menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert);
}
}
fclose(fich);
fclose(f);
remove("menu.txt");
rename("tmpmenu.txt","menu.txt");
}
}

void modifier(menu x)
{
menu menutmp;
FILE *f=NULL;
FILE *fich=NULL;
f=fopen("menu.txt","r");
fich=fopen("menutmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %d %s %s %s %s %s %s %s %s  %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)
{
if((x.mois!=menutmp.mois)||(x.jour!=menutmp.jour))
{
fprintf(fich,"%d %d %s %s %s %s %s %s %s %s %s \n",menutmp.mois,menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert);
}
else
fprintf(fich,"%d %d %s %s %s %s %s %s %s %s %s \n",x.mois,x.jour,x.petit_dej.boisson,x.petit_dej.produit_cerealier,
x.petit_dej.vienoiserie,x.dejeuner.entree,x.dejeuner.plat_princ,x.dejeuner.dessert,
x.diner.entree,x.diner.plat_princ,x.diner.dessert);
}
}
fclose(fich);
fclose(f);
remove("menu.txt");
rename("menutmp.txt","menu.txt");
}
enum
{
	Emois,
	Ejour,
	Eboissons,
	Eproduit_cerealier,
	Evienoiserie,
	Eentree_dej,
	Eplat_dej,
	Edessert_dej,
	Eentree_diner,
	Eplat_diner,
	Edessert_diner,
	COLUMNS
};
void afficher(int numsemaine,GtkWidget *liste)
{
menu menutmp[32];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
int i=1;
FILE *f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Emois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Ejour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("boisson",renderer,"text",Eboissons,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("produit cerealier",renderer,"text",Eproduit_cerealier,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("vienoiserie",renderer,"text",Evienoiserie,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée dejeuner",renderer,"text",Eentree_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("plat principale",renderer,"text",Eplat_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",Edessert_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée",renderer,"text",Eentree_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Plat principale",renderer,"text",Eplat_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",Edessert_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("menu.txt","r");
if(f==NULL)
{
	return;
}
else
{
while(fscanf(f,"%d %d %s %s %s %s %s %s %s %s  %s",&menutmp[i].mois,&menutmp[i].jour,menutmp[i].petit_dej.boisson,menutmp[i].petit_dej.produit_cerealier,
menutmp[i].petit_dej.vienoiserie, menutmp[i].dejeuner.entree, menutmp[i].dejeuner.plat_princ, menutmp[i].dejeuner.dessert, menutmp[i].diner.entree,
menutmp[i].diner.plat_princ, menutmp[i].diner.dessert)!=EOF)
{
i++;
}
}
if(numsemaine==1)
{
for(i=1;i<=7;i++)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,Emois,menutmp[i].mois,Ejour,menutmp[i].jour,Eboissons,menutmp[i].petit_dej.boisson,Eproduit_cerealier,menutmp[i].petit_dej.produit_cerealier,Evienoiserie,
menutmp[i].petit_dej.vienoiserie,Eentree_dej,menutmp[i].dejeuner.entree,Eplat_dej,menutmp[i].dejeuner.plat_princ,
Edessert_dej,menutmp[i].dejeuner. dessert,Eentree_diner,menutmp[i].diner.entree,Eplat_diner,menutmp[i].diner.plat_princ,Edessert_diner,
menutmp[i].diner.dessert, -1);
}
}
else if(numsemaine==2)
{
for(i=8;i<=14;i++)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter,Emois,menutmp[i].mois,Ejour,menutmp[i].jour,Eboissons,menutmp[i].petit_dej.boisson,Eproduit_cerealier,menutmp[i].petit_dej.produit_cerealier,Evienoiserie,
menutmp[i].petit_dej.vienoiserie,Eentree_dej,menutmp[i].dejeuner.entree,Eplat_dej,menutmp[i].dejeuner.plat_princ,
Edessert_dej,menutmp[i]. dejeuner.dessert,Eentree_diner,menutmp[i].diner.entree,Eplat_diner,menutmp[i].diner.plat_princ,Edessert_diner,
menutmp[i].diner.dessert, -1);
}
}
else if(numsemaine==3)
{
for(i=15;i<=21;i++)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter,Emois,menutmp[i].mois,Ejour,menutmp[i].jour,Eboissons,menutmp[i].petit_dej.boisson,Eproduit_cerealier,menutmp[i].petit_dej.produit_cerealier,Evienoiserie,
menutmp[i].petit_dej.vienoiserie,Eentree_dej,menutmp[i].dejeuner.entree,Eplat_dej,menutmp[i].dejeuner.plat_princ,
Edessert_dej,menutmp[i].dejeuner.dessert,Eentree_diner,menutmp[i].diner.entree,Eplat_diner,menutmp[i].diner.plat_princ,Edessert_diner,
menutmp[i].diner.dessert, -1);
}
}
else{
for(i=22;i<29;i++)
{

gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter,Emois,menutmp[i].mois,Ejour,menutmp[i].jour,Eboissons,menutmp[i].petit_dej.boisson,Eproduit_cerealier,menutmp[i].petit_dej.produit_cerealier,Evienoiserie,
menutmp[i].petit_dej.vienoiserie,Eentree_dej,menutmp[i].dejeuner.entree,Eplat_dej,menutmp[i].dejeuner.plat_princ,
Edessert_dej,menutmp[i].dejeuner.dessert,Eentree_diner,menutmp[i].diner.entree,Eplat_diner,menutmp[i].diner.plat_princ,Edessert_diner,
menutmp[i].diner.dessert, -1);
}
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);

}


void chercher(menu x,GtkWidget *liste)
{
menu menutmp;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
int trouve=0;
FILE *f=NULL;
f=fopen("menu.txt","r");
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Emois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Ejour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("boisson",renderer,"text",Eboissons,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("produit cerealier",renderer,"text",Eproduit_cerealier,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("vienoiserie",renderer,"text",Evienoiserie,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée dejeuner",renderer,"text",Eentree_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("plat principale",renderer,"text",Eplat_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",Edessert_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée",renderer,"text",Eentree_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Plat principale",renderer,"text",Eplat_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",Edessert_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
if(f==NULL)
{
return;
}																					
else
{
while((fscanf(f,"%d %d %s %s %s %s %s %s %s %s  %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)&&(trouve==0))
{
if((x.mois==menutmp.mois)&&(x.jour==menutmp.jour))
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,Emois,menutmp.mois,Ejour,menutmp.jour,Eboissons,menutmp.petit_dej.boisson,Eproduit_cerealier,menutmp.petit_dej.produit_cerealier,Evienoiserie,
menutmp.petit_dej.vienoiserie,Eentree_dej,menutmp.dejeuner.entree,Eplat_dej,menutmp.dejeuner.plat_princ,
Edessert_dej,menutmp. dejeuner.dessert,Eentree_diner,menutmp.diner.entree,Eplat_diner,menutmp.diner.plat_princ,Edessert_diner,
menutmp.diner.dessert, -1);
trouve=1;
}
}
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}

void affiche_meileur_menu(char ch1[],char ch2[],char ch3[])
{
menu menutmp;
int i,min1,min2,min3;
int j,k,a;
int type;
float pourcentage;
typedef struct
{
int j;
int type;
float pourcentage;
}prc;
prc T1[31],T2[31],T3[31];
FILE *d=NULL;
FILE *f=NULL;
d=fopen("dechets.txt","r");
f=fopen("menu.txt","r");
i=-1;
k=-1;
a=-1;
					
if(d!=NULL)
{
while(fscanf(d,"%d %d %f",&j,&type,&pourcentage)!=EOF)
{
if(type==1)
{
i++;
T1[i].j=j;
T1[i].type=type;
T1[i].pourcentage=pourcentage;
}
else if(type==2)
{
a++;
T2[a].j=j;
T2[a].type=type;
T2[a].pourcentage=pourcentage;
}
else if(type==3)
{
k++;
T3[k].j=j;
T3[k].type=type;
T3[k].pourcentage=pourcentage;
}
}
}
fclose(d);
min1=0;
for(k=1;k<29;k++)
{
if(T1[k].pourcentage<T1[min1].pourcentage)
min1=k;
}
min2=0;
for(k=1;k<29;k++)
{
if(T2[k].pourcentage<T2[min2].pourcentage)
min2=k;
}
min3=0;
for(k=1;k<29;k++)
{
if(T3[k].pourcentage<T3[min3].pourcentage)
min3=k;
}
if(f!=NULL)
{
while(fscanf(f,"%d %d %s %s %s %s %s %s %s %s %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree,menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)
{
if(menutmp.jour==T1[min1].j)
{
strcpy(ch1,menutmp.petit_dej.boisson);
strcat(ch1,"+");
strcat(ch1, menutmp.petit_dej.produit_cerealier);
strcat(ch1,"+");
strcat(ch1, menutmp.petit_dej.vienoiserie);
}
else if(menutmp.jour==T2[min2].j)
{
strcpy(ch2,menutmp.dejeuner.entree);
strcat(ch2,"+");
strcat(ch2, menutmp.dejeuner.plat_princ);
strcat(ch2,"+");
strcat(ch2, menutmp.dejeuner.dessert);
}
else if (menutmp.jour==T3[min3].j)
{
strcpy(ch3,menutmp.diner.entree);
strcat(ch3,"+");
strcat(ch3, menutmp.diner.plat_princ);
strcat(ch3,"+");
strcat(ch3, menutmp.diner.dessert);
}
}
fclose(f);
}
}


enum
{
	Smois,
	Sjour,
	Sboissons,
	Sproduit_cerealier,
	Svienoiserie,
	Sentree_dej,
	Splat_dej,
	Sdessert_dej,
	Sentree_diner,
	Splat_diner,
	Sdessert_diner,
	COLUMNs
};


void affichage(GtkWidget *liste)
{
menu menutmp;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
FILE *f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Smois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Sjour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("boisson",renderer,"text",Sboissons,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("produitcerealier",renderer,"text",Sproduit_cerealier,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("vienoiserie",renderer,"text",Svienoiserie,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée dejeuner",renderer,"text",Sentree_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("plat principale",renderer,"text",Splat_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",Sdessert_dej,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrée",renderer,"text",Sentree_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Plat principale",renderer,"text",Splat_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",Sdessert_diner,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNs,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("menu.txt","r");
if(f==NULL)
{
return;
}
else
{
while(fscanf(f,"%d %d %s %s %s %s %s %s %s %s  %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,Smois,menutmp.mois,Sjour,menutmp.jour,Sboissons,menutmp.petit_dej.boisson,Sproduit_cerealier,menutmp.petit_dej.produit_cerealier,Svienoiserie,
menutmp.petit_dej.vienoiserie,Sentree_dej,menutmp.dejeuner.entree,Splat_dej,menutmp.dejeuner.plat_princ,
Sdessert_dej,menutmp.dejeuner. dessert,Sentree_diner,menutmp.diner.entree,Splat_diner,menutmp.diner.plat_princ,Sdessert_diner,
menutmp.diner.dessert, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}


int trouve(menu x)
{
menu menutmp;
FILE *f=NULL;
f=fopen("menu.txt","r");
int trouve=0;
if(f!=NULL)
{
while((fscanf(f,"%d %d %s %s %s %s %s %s %s %s  %s",&menutmp.mois,&menutmp.jour,menutmp.petit_dej.boisson,menutmp.petit_dej.produit_cerealier,
menutmp.petit_dej.vienoiserie, menutmp.dejeuner.entree, menutmp.dejeuner.plat_princ, menutmp.dejeuner.dessert, menutmp.diner.entree,
menutmp.diner.plat_princ, menutmp.diner.dessert)!=EOF)&&(trouve==0))
{
if((x.mois==menutmp.mois)&&(x.jour==menutmp.jour))
{
trouve=1;
}
}
}
fclose(f);
return trouve;
}
