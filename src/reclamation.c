#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "reclamation.h"

void ajouter_reclam(newreclam r)
{

    
    FILE *f=NULL;

    
f=fopen("reclamation.txt","a");
if(f!=NULL)
{
    
    printf("your safe now be happy");

fprintf(f,"%d %d %d %s %s %s %s %s %s \n",r.jour1,r.mois1,r.annee1,r.nom,r.prenom,r.ID,r.type_reclamation,r.numero_reclamation,r.text_reclamation);
fclose(f);
}
else
printf("\n not found baby ");



}


void modifier_reclam( soulofthedead p ,newreclam r)
{
newreclam tmp;
strcpy(r.type_reclamation,p.type_reclamation);

FILE *f=NULL;
FILE *fich=NULL;
f=fopen("reclamation.txt","r");
fich=fopen("tmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %s %s",&tmp.jour1,&tmp.mois1,&tmp.annee1,tmp.nom,tmp.prenom,
             tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation)!=EOF)
{
 if (strcmp(p.numero_reclamation,tmp.numero_reclamation)!=0)
{
fprintf(fich,"%d %d %d %s %s %s %s %s %s \n",tmp.jour1,tmp.mois1,tmp.annee1,tmp.nom,
        tmp.prenom,tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation);
}
else
fprintf(fich,"%d %d %d %s %s %s %s %s %s \n",r.jour1,r.mois1,r.annee1,r.nom,r.prenom,
        r.ID,r.type_reclamation,r.numero_reclamation,r.text_reclamation);
}
}
fclose(fich);
fclose(f);
remove("reclamation.txt");
rename("tmp.txt","reclamation.txt");
}
void supprimer_reclam(soulofthedead  p)
{
soulofthedead tmp;
FILE *f=NULL;
FILE *fich=NULL;
f=fopen("reclamation.txt","r");
fich=fopen("tmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s",tmp.jour1,tmp.mois1,tmp.annee1,tmp.nom,tmp.prenom,
             tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation)!=EOF)
{
if(strcmp(p.numero_reclamation,tmp.numero_reclamation)!=0)
{
fprintf(fich,"%s %s %s %s %s %s %s %s %s \n",tmp.jour1,tmp.mois1,tmp.annee1,tmp.nom,
        tmp.prenom,tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation);

}

}
}
fclose(fich);
fclose(f);
remove("reclamation.txt");
rename("tmp.txt","reclamation.txt");
}
void afficher_reclam(void)
{

reclamation tmp;
FILE *f=NULL;
f=fopen("reclamation.txt","r");

if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %d %s",&tmp.date.jour,&tmp.date.mois,&tmp.date.annee,tmp.nom,tmp.prenom,
             tmp.ID,tmp.type_reclamation,&tmp.numero_reclamation,tmp.text_reclamation)!=EOF)
{
    printf("%d %d %d %s %s %s %s %d %s \n",tmp.date.jour,tmp.date.mois,tmp.date.annee,tmp.nom,
        tmp.prenom,tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation);
}
fclose(f);
}
}
enum
{
Ejou,
Emoi,
Eyea,
Eno,
Epreno,
EI,
Etyperecla,
Enumrecla,
Etextrecla,
COLUMN
};
void hkchercher(char n[20] ,char p[20],GtkWidget *liste)
{
     GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
    char jour1[20];
    char mois1[20];
    char annee1[20];
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour1",renderer,"text",Ejou,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois1",renderer,"text",Emoi,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee1",renderer,"text",Eyea,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Eno,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",Epreno,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EI,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type_reclamation",renderer,"text",Etyperecla,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero_reclamation",renderer,"text",Enumrecla,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("text_reclamation",renderer,"text",Etextrecla,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMN,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",jour1,mois1,annee1,nom,prenom,ID,type_reclamation,numero_reclamation,text_reclamation)!=EOF)
		{



   if ((strcmp(n,numero_reclamation)==0)&(strcmp(p,ID)==0))
           {
			gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Ejou,jour1,Emoi,mois1,Eyea,annee1,Eno,nom,Epreno,prenom,EI,ID,Etyperecla,type_reclamation,Enumrecla,numero_reclamation,Etextrecla,text_reclamation,-1);
          }
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}

}
enum
{
Ejour,
Emois,
Eyear,
Enom,
Eprenom,
EID,
Etypereclam,
Enumreclam,
Etextreclam,
COLUMNS
};

void hkaffich(GtkWidget *liste)
{




    GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
    char jour1[20];
    char mois1[20];
    char annee1[20];
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour1",renderer,"text",Ejour,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois1",renderer,"text",Emois,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee1",renderer,"text",Eyear,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",Enom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",prenom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type_reclamation",renderer,"text",Etypereclam,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero_reclamation",renderer,"text",Enumreclam,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("text_reclamation",renderer,"text",Etextreclam,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",jour1,mois1,annee1,nom,prenom,ID,type_reclamation,numero_reclamation,text_reclamation)!=EOF)
		{
			gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Ejour,jour1,Emois,mois1,Eyear,annee1,Enom,nom,Eprenom,prenom,EID,ID,Etypereclam,type_reclamation,Enumreclam,numero_reclamation,Etextreclam,text_reclamation,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}

}
enum
{
Ejo,
COLUM
};
void hkleplusreclamer(GtkWidget *liste)
{
FILE *f;
int g,d,a;
char r[44];
d=0;
g=0;
soulofthedead tmp;
f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s",tmp.jour1,tmp.mois1,tmp.annee1,tmp.nom,tmp.prenom,tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation)!=EOF)
		{
            if(strcmp("restauration",tmp.type_reclamation)==0)
                d++;
              else
                 g++;


	       }
		}
		fclose(f);


if (g>d)
strcpy(r,"hebergement");
else
strcpy(r,"restauration");
    char leplusreclamer[20];
   strcpy(leplusreclamer,r);
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
      store=NULL;
if(store==NULL)
	{
    renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Service le Plus Reclamé",renderer,"text",Ejo,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
}
store=gtk_list_store_new(COLUM,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Ejo,leplusreclamer,-1);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
int hkverification(newreclam r)
{
int xr;

newreclam tmp;
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %s %s %s %s %s %s",&tmp.jour1,&tmp.mois1,&tmp.annee1,tmp.nom,tmp.prenom,
             tmp.ID,tmp.type_reclamation,tmp.numero_reclamation,tmp.text_reclamation)!=EOF)
{
 if (strcmp(r.numero_reclamation,tmp.numero_reclamation)==0)
{
xr=1;
}
else
xr=0;
}
}
fclose(f);
return(xr);
}
