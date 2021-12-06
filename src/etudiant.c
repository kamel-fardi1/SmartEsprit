#include "etudiant.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "support.h"
#include "interface.h"
#include <gtk/gtk.h>
enum
{
    Cin,
    Nom,
    Prenom,
    Classe,
    Adress,
    Services,
    Sexe,
    Aderess_mail,
    Numero_telephonique,
    Chambre,
    Date_d_hebergement,
    Date_de_naissance,
    Photo,
    COLUMNS
};

enum
{
    Username,
    password,
    job,
    COLUMNS5
};
enum
{
    Username1,
    password1,
    job1,
    COLUMNS6
};
////////////////////////////ajouter/////////////////////////////////////////////////////////////
void ajouter_etudiant (Etudiant etd,char file_etudiants[]){
    FILE *f;
    f=fopen(file_etudiants,"a+");
    fprintf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd.cin,etd.nom,etd.prenom,etd.classe,etd.sexe,etd.adress,etd.aderess_mail,etd.date_de_naissance.jour,etd.date_de_naissance.mois,etd.date_de_naissance.annee,etd.numero_telephonique,etd.date_d_hebergement.jour,etd.date_d_hebergement.mois,etd.date_d_hebergement.annee,etd.chambre,etd.services,etd.photo);
    nbr++;
    fclose(f);
    }
//////////////////////////////////modifier///////////////////////////////////////////////////////
void modifier_etudiant(char esm[],Etudiant etd,char file_etudiants[]){
    FILE *f,*f1;
    Etudiant etd_test;
    f=fopen(file_etudiants,"r+");
    f1=fopen("temp.txt","w+");
    while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.adress,etd_test.aderess_mail,&etd_test.date_de_naissance.jour,&etd_test.date_de_naissance.mois,&etd_test.date_de_naissance.annee,etd_test.numero_telephonique,&etd_test.date_d_hebergement.jour,&etd_test.date_d_hebergement.mois,&etd_test.date_d_hebergement.annee,etd_test.chambre,etd_test.services,etd_test.photo))!=EOF)
            {

                if(!strcmp(etd_test.cin,esm)){

                        fprintf(f1,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd.cin,etd.nom,etd.prenom,etd.classe,etd.sexe,etd.adress,etd.aderess_mail,etd.date_de_naissance.jour,etd.date_de_naissance.mois,etd.date_de_naissance.annee,etd.numero_telephonique,etd.date_d_hebergement.jour,etd.date_d_hebergement.mois,etd.date_d_hebergement.annee,etd.chambre,etd.services,etd.photo);
                }
                if(strcmp(etd_test.cin,esm)!=0)
                {
                        fprintf(f1,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.adress,etd_test.aderess_mail,etd_test.date_de_naissance.jour,etd_test.date_de_naissance.mois,etd_test.date_de_naissance.annee,etd_test.numero_telephonique,etd_test.date_d_hebergement.jour,etd_test.date_d_hebergement.mois,etd_test.date_d_hebergement.annee,etd_test.chambre,etd_test.services,etd_test.photo);

                }

            }
        fclose(f);
        fclose(f1);
        remove(file_etudiants);
        rename("temp.txt",file_etudiants);
    }
/////////////////////////////////////////supprimer//////////////////////////////////////////////
void supprimer_etudiant(char cin[],char file_etudiants[]){
    FILE *f,*f1;
    Etudiant etd_test;
    f=fopen(file_etudiants,"r");
    f1=fopen("temp.txt","w+");
    if(f==NULL){
            printf("fichier n'existe pas");}
    else
        {
    while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.adress,etd_test.aderess_mail,&etd_test.date_de_naissance.jour,&etd_test.date_de_naissance.mois,&etd_test.date_de_naissance.annee,etd_test.numero_telephonique,&etd_test.date_d_hebergement.jour,&etd_test.date_d_hebergement.mois,&etd_test.date_d_hebergement.annee,etd_test.chambre,etd_test.services,etd_test.photo))!=EOF)
            {
                if(strcmp(etd_test.cin,cin)==0){
                        
                }
                else
                fprintf(f1,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.adress,etd_test.aderess_mail,etd_test.date_de_naissance.jour,etd_test.date_de_naissance.mois,etd_test.date_de_naissance.annee,etd_test.numero_telephonique,etd_test.date_d_hebergement.jour,etd_test.date_d_hebergement.mois,etd_test.date_d_hebergement.annee,etd_test.chambre,etd_test.services,etd_test.photo);
                
            }
        fclose(f);
        fclose(f1);
        }
        remove(file_etudiants);
        rename("temp.txt",file_etudiants);
        }
void supprimer_utilisateur(char un[],char pswrd[],char role[],char file_etudiants[]){
    FILE *f,*f1;
    char *u1,*p1,*r1;
    f=fopen(file_etudiants,"r");
    f1=fopen("temp.txt","w+");
    if(f==NULL){
            printf("fichier n'existe pas");}
    else
        {
    while((fscanf(f,"%s %s %s",u1,p1,r1))!=EOF)
            {
                if((strcmp(un,u1)==0)&&(strcmp(pswrd,p1)==0)&&(strcmp(role,r1)==0)){
                        
                }
                else fprintf(f1,"%s %s %s",u1,p1,r1);
            }
        fclose(f);
        fclose(f1);
        }
        remove(file_etudiants);
        rename("temp.txt",file_etudiants);
        }
///////////////affichage///////////////////////////
/*void afficher_etudiant(char file_etudiants[]){
    FILE *f,*f1;
    Etudiant etd_test;
    f=fopen(file_etudiants,"r");
    if(f==NULL){
            printf("fichier n'existe pas");}
    else
        {

    while((fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %s %s %d %d %d %s",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.nationalite,etd_test.adress,etd_test.aderess_mail,&etd_test.date_de_naissance.jour,&etd_test.date_de_naissance.mois,&etd_test.date_de_naissance.annee,etd_test.lieu_de_naissance,etd_test.numero_telephonique,&etd_test.date_d_hebergement.jour,&etd_test.date_d_hebergement.mois,&etd_test.date_d_hebergement.annee,etd_test.chambre))!=EOF)
            {
                    printf("%s %s %s %s %s %s %s %s %d %d %d %s %s %d %d %d %s\n",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.nationalite,etd_test.adress,etd_test.aderess_mail,etd_test.date_de_naissance.jour,etd_test.date_de_naissance.mois,etd_test.date_de_naissance.annee,etd_test.lieu_de_naissance,etd_test.numero_telephonique,etd_test.date_d_hebergement.jour,etd_test.date_d_hebergement.mois,etd_test.date_d_hebergement.annee,etd_test.chambre);
            }
        fclose(f);
        }
    }*/
///////////tache2/////////////////////
int nombres_des_etudiant(char file_etudiants[],char nv){
    FILE *f;
    Etudiant etd;
    int a,nb_etd=0;
    f=fopen(file_etudiants,"r+");
    if(f!=NULL){
    if(nv=='0'){
        while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd.cin,etd.nom,etd.prenom,etd.classe,etd.sexe,etd.adress,etd.aderess_mail,&etd.date_de_naissance.jour,&etd.date_de_naissance.mois,&etd.date_de_naissance.annee,etd.numero_telephonique,&etd.date_d_hebergement.jour,&etd.date_d_hebergement.mois,&etd.date_d_hebergement.annee,etd.chambre,etd.services,etd.photo))!=EOF)
            {
                nb_etd++;
            }
            }
    else{
    while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd.cin,etd.nom,etd.prenom,etd.classe,etd.sexe,etd.adress,etd.aderess_mail,&etd.date_de_naissance.jour,&etd.date_de_naissance.mois,&etd.date_de_naissance.annee,etd.numero_telephonique,&etd.date_d_hebergement.jour,&etd.date_d_hebergement.mois,&etd.date_d_hebergement.annee,etd.chambre,etd.services,etd.photo))!=EOF)
            {
                //a=atoi(etd.classe[0]);
                if(etd.classe[0]==nv) nb_etd++;
            }

        }
        }
        fclose(f);
    return nb_etd;
    }
int verif_cin(gchar *c,char file[]){
    FILE *f;
    Etudiant etd;
    f=fopen(file,"r");
    if(f==NULL){
            printf("fichier n'existe pas");
            }
    else
        {
            while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s\n",etd.cin,etd.nom,etd.prenom,
            etd.classe,etd.sexe,etd.adress,etd.aderess_mail,&etd.date_de_naissance.jour,&etd.date_de_naissance.mois,&etd.date_de_naissance.annee,etd.numero_telephonique,&etd.date_d_hebergement.jour,&etd.date_d_hebergement.mois,&etd.date_d_hebergement.annee,etd.chambre,etd.services,etd.photo))!=EOF)
            {
                if(strcmp(etd.cin,c)==0)
                
                return 0;
            }
            return 1;
        }
        
        fclose(f);
}
void afficher_etudiant(GtkWidget *liste,char file_etudinats[])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;
    Etudiant etd_test;
    f=fopen(file_etudinats,"r");
    char *buf1;
    char *buf2;
    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", Cin, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              nom          ", renderer, "text", Nom, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              prenom        ", renderer, "text", Prenom, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Classe", renderer, "text", Classe, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("   Adress ", renderer, "text", Adress, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("        Services          ", renderer, "text", Services, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", Sexe, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("             Aderess_mail             ", renderer, "text", Aderess_mail, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Numero_telephonique", renderer, "text", Numero_telephonique, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text", Chambre, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date_d_hebergement", renderer, "text", Date_d_hebergement, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date_de_naissance", renderer, "text", Date_de_naissance, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Photo", renderer, "text", Photo, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s",etd_test.cin,etd_test.nom,etd_test.prenom,etd_test.classe,etd_test.sexe,etd_test.adress,etd_test.aderess_mail,&etd_test.date_de_naissance.jour,&etd_test.date_de_naissance.mois,&etd_test.date_de_naissance.annee,etd_test.numero_telephonique,&etd_test.date_d_hebergement.jour,&etd_test.date_d_hebergement.mois,&etd_test.date_d_hebergement.annee,etd_test.chambre,etd_test.services,etd_test.photo))!=EOF)
            {
            buf1=g_strdup_printf("%d %d %d",etd_test.date_de_naissance.jour,etd_test.date_de_naissance.mois,etd_test.date_de_naissance.annee);
            buf2=g_strdup_printf("%d %d %d",etd_test.date_d_hebergement.jour,etd_test.date_d_hebergement.mois,etd_test.date_d_hebergement.annee);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, Cin,etd_test.cin, Nom, etd_test.nom, Prenom, etd_test.prenom, Classe, etd_test.classe, Adress, etd_test.adress,Services, etd_test.services, Sexe, etd_test.sexe, Aderess_mail, etd_test.aderess_mail, Numero_telephonique, etd_test.numero_telephonique, Chambre,etd_test.chambre, Date_d_hebergement, buf2, Date_de_naissance,buf1,Photo,etd_test.photo, -1);
            g_free(buf2);
            g_free(buf1);
            }
        
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}
void afficher_utilisateur(GtkWidget *liste,char file[])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;
    char u[20],p[30],r[100];
    f=fopen(file,"r");

    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom d'utilisateur", renderer, "text", Username, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              mot de passe          ", renderer, "text", password, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              Role        ", renderer, "text", job, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    while((fscanf(f,"%s %s %s\n",u,p,r))!=EOF)
            {
                
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, Username, u, password, p, job, r, -1);
            }
        
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}
void afficher_responsables(GtkWidget *liste,char file[])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;
    char u1[20],p1[30],r1[100];
    f=fopen(file,"r");

    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom d'utilisateur", renderer, "text", Username1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              mot de passe          ", renderer, "text", password1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              Role        ", renderer, "text", job1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    while((fscanf(f,"%s %s %s\n",u1,p1,r1))!=EOF)
            {
                    
            if(strcmp(r1,"etudiant")){
            
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, Username1, u1, password1, p1, job1, r1, -1);
            }
            
            }
        
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}
int login(char username[],char pswrd[],char *file){
    FILE *f;
    char user[20],pwd[20],role[20];
    f=fopen(file,"r");
    while((fscanf(f,"%s %s %s",user,pwd,role))!=EOF)
            {
                if((strcmp(username,user)==0)&&(strcmp(pswrd,pwd)==0)){
                    if (strcmp(role,"admin")==0)//admin
                    {
                     return 1;
                    }
                    else if (strcmp(role,"Responsable_Hebergement")==0)//hebergement
                    {
                      return 2;
                    }
                    else if (strcmp(role,"Responsable_nutritions")==0)//restau
                    {
                       return 3;
                    }
                    else if (strcmp(role,"Responsable_de_capteurs")==0)//capteurs
                    {
                        return 4;
                    }
                    else if (strcmp(role,"Responsable_de_reclamations")==0)//reclamation
                    {
                       return 5;
                    }
                    else if (strcmp(role,"Responsable_de_stock")==0)//stock
                    {
                        return 6;
                    }
                    else//etudiant
                    {
                        return 7;
                    }
                    
                }
                
            }
            fclose(f);
            return 0;

}
void ajouter_utilisateur(char nom[],char mot_de_passe[],char role[],char fichier[]){
    FILE *f;
    f=fopen(fichier,"a+");
    fprintf(f,"%s %s %s\n",nom,mot_de_passe,role);
    fclose(f);

}
Etudiant chercher_etudiant(gchar *cin_cher,char file[])
{
    FILE *f;
    Etudiant find;
    f=fopen(file,"r");
        while((fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s %d %d %d %s %s %s",find.cin,find.nom,find.prenom,find.classe,find.sexe,find.adress,find.aderess_mail,&find.date_de_naissance.jour,&find.date_de_naissance.mois,&find.date_de_naissance.annee,find.numero_telephonique,&find.date_d_hebergement.jour,&find.date_d_hebergement.mois,&find.date_d_hebergement.annee,find.chambre,find.services,find.photo))!=EOF)
        {
            if(strcmp(find.cin,cin_cher)==0)
            {
            fclose(f);
            return find;}
        }
        fclose(f);
}
/*void afficher_person(GtkWidget *liste,Etudiant E)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;
    char u1[20],p1[30],r1[100];
    f=fopen(file,"r");

    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom d'utilisateur", renderer, "text", Username1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              mot de passe          ", renderer, "text", password1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("              Role        ", renderer, "text", job1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);            
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, Username1, E.cin, password1, E., job1, r1, -1);
            }
            
            
        
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}  */      
void modif_admin(char un[],char pswd[],char file[]){
    FILE *f,*f1;
    char u[20],p[30],r[100];
    char *role="admin";
    f=fopen(file,"r");
    f1=fopen("temp.txt","w+");
    if(f==NULL){
            printf("fichier n'existe pas");}
    else
        {
    while((fscanf(f,"%s %s %s\n",u,p,r))!=EOF)
        {
            if(strcmp(r,"admin")==0)
            fprintf(f1,"%s %s %s\n",un,pswd,role);
            else
            fprintf(f1,"%s %s %s\n",u,p,r);
        }}
    fclose(f);
    fclose(f1);
    remove(file);
    rename("temp.txt",file);   
}
void modif_etud(char un[],char pswd[],char file[]){
    FILE *f,*f1;
    char u[20],p[30],r[100];
    char *role="etudiant";
    f=fopen(file,"r");
    f1=fopen("temp.txt","w+");
    if(f==NULL){
            printf("fichier n'existe pas");}
    else
        {
    while((fscanf(f,"%s %s %s\n",u,p,r))!=EOF)
        {
            if(strcmp(u,un)==0)
            fprintf(f1,"%s %s %s\n",un,pswd,role);
            else
            fprintf(f1,"%s %s %s\n",u,p,r);
        }}
    fclose(f);
    fclose(f1);
    remove(file);
    rename("temp.txt",file);   
}   
void set_text(char size[],char color[],char text[],int ajt_sup){
          GtkWidget *hint,*hintlabel,*fixed1,*kamel_fardi_ajout_hint_fixed,*kamel_fardi_ajout_hint_fixedimage;


          
        
      if(ajt_sup==1){
          strcpy(kfbackground,"bienajouter.png");
          strcpy(kflogo,"gtk-apply");
          strcpy(kfbuttonlabel,"<span font-size=\"30000\"color=\"green\"><b>OK</b></span>");
      }
      else{
          strcpy(kfbackground,"red_back.png");
          strcpy(kflogo,"gtk-stop");
          strcpy(kfbuttonlabel,"<span font-size=\"30000\"color=\"red\"><b>Retour</b></span>");
      }

      hint = create_kamel_fardi_ajout_hint_window ();
      hintlabel=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed_label");
      fixed1=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed");
      kamel_fardi_ajout_hint_fixed=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed");
      sprintf(kfchaine, "%s%s%s%s%s%s%s","<span font-size=\"",size,"\" color=\"",color,"\"><b>",text,"</b></span>" );
      hintlabel = gtk_label_new (_(kfchaine));
      gtk_widget_show (hintlabel);
      gtk_fixed_put (GTK_FIXED (fixed1), hintlabel, 100, 300);
      gtk_widget_set_size_request (hintlabel, 800, 100);
      gtk_label_set_use_markup (GTK_LABEL (hintlabel), TRUE);
      gtk_widget_show (hint);
        }
/*void set_text(char span[],char text[]){
strcpy(chaine,span);
strcat(chaine,text);
strcat(chaine,"</span>");
}*/