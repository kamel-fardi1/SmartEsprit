
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include<config.h>
#include"capteur.h"
#include"support.h"

enum
{
	EREF,
	ETYPE,
	EV_MAX,
	EV_MIN,
	EJOUR,
	EMOIS,
	EANNEE,
	EEMPLACEMENT,
	COLUMNS
};

enum
{	
	cp,
	etg,
	vl,
	COLUMNS1
};

int rech(int refrech)
{
    FILE *F=NULL;
    capteur c;
    F=fopen("capteurs.txt","r");
        while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)
        {
            if (c.ref==refrech)
            {
                
                return 1;
            }
        }
    fclose(F);
    return 0;
}

//////fonction ajouter
void Ajouter_capt(capteur c)
{
    FILE *F=NULL;

    F=fopen("capteurs.txt","a+");
  if (F!=NULL)
     {
      fprintf(F,"%d %s %f %f %d %d %d %s\n",c.ref,c.type,c.V_Max,c.V_Min,c.dt.jour,c.dt.mois,c.dt.annee,c.Emplacement);
      fclose(F);
      }
}
///fonction rechercher
void Rech_affich(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	capteur c;
	FILE *f2;
	
	store=NULL;
	
     if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ref",renderer, "text",EREF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_max",renderer, "text",EV_MAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_min",renderer, "text",EV_MIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMPLACEMENT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}

	store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_FLOAT,G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
   f2 = fopen("recherche.txt", "r");
   if (f2 != NULL)
     {
	 while (fscanf(f2,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement) != EOF)
		{
		gtk_list_store_append(store,&iter);
						       gtk_list_store_set(store,&iter,EREF,c.ref,ETYPE,c.type,EV_MAX,c.V_Max,EV_MIN,c.V_Min,EJOUR,c.dt.jour,EMOIS,c.dt.mois,EANNEE,c.dt.annee,EEMPLACEMENT,c.Emplacement,-1);
		}
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	fclose(f2);
        remove("recherche.txt");
     }
}
///////fonction supprimer
void supprimer(int REF)
{

    FILE *Fich,*F;
    capteur c;
    F=fopen("capteurs.txt","r");
    Fich=fopen("temp_capteur.txt","w+");
        while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)
		{
        if (REF!=c.ref)
            {
                fprintf(Fich,"%d %s %f %f %d %d %d %s\n",c.ref,c.type,c.V_Max,c.V_Min,c.dt.jour,c.dt.mois,c.dt.annee,c.Emplacement);
            }
    }
    fclose(Fich);
    fclose(F);
    remove("capteurs.txt");
    rename("temp_capteur.txt","capteurs.txt");
        }
/////////fonction modifier
void modifier(capteur c,int REF)
{
            FILE *F,*Fich;
            capteur cn;
            F=fopen("capteurs.txt","r");
            Fich=fopen("temp_capteur.txt","a");
              while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&cn.ref,cn.type,&cn.V_Max,&cn.V_Min,&cn.dt.jour,&cn.dt.mois,&cn.dt.annee,cn.Emplacement)!=EOF){
              if (REF==cn.ref)
              {
                fprintf(Fich,"%d %s %f %f %d %d %d %s\n",c.ref,c.type,c.V_Max,c.V_Min,c.dt.jour,c.dt.mois,c.dt.annee,c.Emplacement);
              }
              else
              fprintf(Fich,"%d %s %f %f %d %d %d %s\n",cn.ref,cn.type,cn.V_Max,cn.V_Min,cn.dt.jour,cn.dt.mois,cn.dt.annee,cn.Emplacement);
            }
            fclose(F);
            fclose(Fich);
            remove("capteurs.txt");
            rename("temp_capteur.txt","capteurs.txt");
 }
////////fonction afficher 
void  afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	capteur c;
	
	store=NULL;
	FILE *F;
	F = fopen("capteurs.txt","r+");

     store=gtk_tree_view_get_model(liste);
     if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ref",renderer, "text",EREF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_max",renderer, "text",EV_MAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_min",renderer, "text",EV_MIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMPLACEMENT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}

	store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_FLOAT,G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
	if(F!=NULL){

	while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)

		{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,EREF,c.ref,ETYPE,c.type,EV_MAX,c.V_Max,EV_MIN,c.V_Min,EJOUR,c.dt.jour,EMOIS,c.dt.mois,EANNEE,c.dt.annee,EEMPLACEMENT,c.Emplacement,-1);
			}
			}

	
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
		fclose(F);
}
        


////////fonction aff capteurs defectueux
void Aff_captdef(GtkWidget *liste)
 {
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	capteur c;
	 FILE *f3;
	
	store=NULL;

       if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ref",renderer, "text",EREF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_max",renderer, "text",EV_MAX,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("v_min",renderer, "text",EV_MIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EEMPLACEMENT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}

	store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_FLOAT,G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);

  f3=fopen("temperature.txt","r");      
  if(f3!=NULL)	
     {     while(fscanf(f3,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)
		{
		gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EREF,c.ref,ETYPE,c.type,EV_MAX,c.V_Max,EV_MIN,c.V_Min,EJOUR,c.dt.jour,EMOIS,c.dt.mois,EANNEE,c.dt.annee,EEMPLACEMENT,c.Emplacement,-1);
		}
	
   	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);       
        fclose(f3); 
	//remove("temperature.txt");
     }
 }
void cap_defecteux(GtkWidget *liste,char E,char *file)
 {
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	FILE *f3;
	int id,etage,j,h;
	float val;
	f3=fopen(file,"r");
	store=NULL;
	store = gtk_tree_view_get_model(liste);
       if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap id",renderer, "text",cp,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",etg,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Valeur",renderer, "text",vl,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}
	store=gtk_list_store_new(COLUMNS1, G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);
    if(f3==NULL){
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,cp,0,etg,0,vl,0,-1);

	}
	else{
	while(fscanf(f3,"%d %d %d %f",&j,&h,&etage,&val)!=EOF)
		{
			if((etage+48)==((int)E))
				{
				if(val>30||val<10){
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,cp,etage,etg,etage,vl,val,-1);
				}
				}
		}
	}
   	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);       
    fclose(f3);      
 }