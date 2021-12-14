#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include"capteur.h"
#include"reclamation.h"
#include "etudiant.h"
#include <time.h>
int pisc=0;
int restau=0;
int s;
char id[30];
char a[70];char b[70];char c[70];char d[70];char e[70];char f[70];char g[70];
int radio_type;
void
on_kamel_fardi_authen_wind_login_auth_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *authentification;
  GtkWidget *w,*v,*kamel_fardi_authen_wind_username_auth_entry,*kamel_fardi_authen_wind_password_auth_entry,*treeview;
  char *file_users="utilisateurs.txt";
  char *fichier="etudiants.txt";
  kamel_fardi_authen_wind_username_auth_entry = lookup_widget(button, "kamel_fardi_authen_wind_username_auth_entry");
  kamel_fardi_authen_wind_password_auth_entry = lookup_widget(button, "kamel_fardi_authen_wind_password_auth_entry");
  authentification = lookup_widget(button, "authentification");
  switch (login(gtk_entry_get_text(GTK_ENTRY(kamel_fardi_authen_wind_username_auth_entry)),gtk_entry_get_text(GTK_ENTRY(kamel_fardi_authen_wind_password_auth_entry)),file_users))
  {
  case 1:
    gtk_widget_hide (authentification);
    w = create_admin ();
    v=create_kamel_fardi_dash_board_window ();
    //gtk_widget_show (w);
    gtk_widget_show (v);
    treeview = lookup_widget(w, "kamel_fardi_espace_admin_treeview_responsables");
    afficher_utilisateur(treeview,file_users);
    break;
  case 2:
    gtk_widget_hide (authentification);
    w = create_kamel_fardi_afficher_window ();
    gtk_widget_show (w);
    treeview = lookup_widget(w, "kamel_fardi_affichage_liste_etudiant_treeview");
    afficher_etudiant(treeview,fichier);
    break;
    /*case 4:
    gtk_widget_hide (authentification);
    w = create_Med_kh_w_Menu ();
    gtk_widget_show (w);
    break;
    /*case 7:
    gtk_widget_hide (authentification);
    w = create_tesnime_affichage ();
    gtk_widget_show (w);
    break;
  default:
    break;*/
  }
  

}


void
on_kamel_fardi_authen_wind_quitter_auth_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
    gtk_exit(0);
}


void
on_treeview_empl_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkWidget *kamel_fardi_etudiant_window,*ajout_hint,*cinentry;
    GtkWidget *kamel_fardi_afficher_window;
    //GtkWidget *classe,*services,*img, *fixed1, *nom, *prenom, *adress, *cin, *sexe, *ntlfn, *nenfn, *wind,*mail,*dtheberg,*naissance;
    GtkTreeIter iter;
    //char *buf1;
    //char *buf2;
    char *fichier="etudiants.txt";
    //Etudiant p;
    gchar *c1,*c2,*c3;

     //ajout_hint = create_kamel_fardi_ajout_hint_window (); 
    kamel_fardi_etudiant_window = create_kamel_fardi_etudiant_window ();
   

    


   GtkTreeModel *model=gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model,&iter,path))
      {
    
        gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&c1, 1, &c2, 2, &c3, -1);
    p=chercher_etudiant(c1,fichier);*/
}


void
on_kamel_fardi_modifier_admin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *kamel_fardi_es_admin_admin_edit_entry,*kamel_fardi_es_admin_admin_pd_edit_entry;
char un[30],pwd[30];
char *file="utilisateurs.txt";
kamel_fardi_es_admin_admin_edit_entry = lookup_widget(button, "kamel_fardi_es_admin_admin_edit_entry");
kamel_fardi_es_admin_admin_pd_edit_entry = lookup_widget(button, "kamel_fardi_es_admin_admin_pd_edit_entry");

strcpy(un,gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_admin_edit_entry)));
strcpy(pwd,gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_admin_pd_edit_entry)));
modif_admin(un,pwd,file);
}


void
on_kamel_fardi_es_admin_supprimer_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_kamel_fardi_es_admin_liste_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *admin;
  GtkWidget *treeview;
  char *fichier="utilisateurs.txt";  
  admin = lookup_widget(button, "admin");
    treeview = lookup_widget(admin, "kamel_fardi_espace_admin_treeview_responsables");
    afficher_utilisateur(treeview,fichier);
}


void
on_kamel_fardi_es_admin_chercher_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_kamel_fardi_ajouter_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
char username[20];
char pswrd[30];
char role[100];
char *fichier="utilisateurs.txt";  
GtkWidget *kamel_fardi_es_admin_resp_un_entry,*kamel_fardi_es_admin_pswrd_resp_entry,*kamel_fardi_role_admin_window_combobox;

//////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////
//////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
kamel_fardi_es_admin_resp_un_entry = lookup_widget(button, "kamel_fardi_es_admin_resp_un_entry");
kamel_fardi_es_admin_pswrd_resp_entry = lookup_widget(button, "kamel_fardi_es_admin_pswrd_resp_entry");
kamel_fardi_role_admin_window_combobox = lookup_widget(button, "kamel_fardi_role_admin_window_combobox");
//////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////

//////////------enregirstrer les informations dans la structure---------/////////////////////////////////////////////////////////////////////////
if(!strlen(gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_resp_un_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_pswrd_resp_entry)))||(gtk_combo_box_get_active_text(GTK_COMBO_BOX(kamel_fardi_role_admin_window_combobox))==NULL)){

      set_text("50000","red","Remplir tout les champs !!!",0);
    }
    else{

strcpy(username, gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_resp_un_entry)));
strcpy(pswrd, gtk_entry_get_text(GTK_ENTRY(kamel_fardi_es_admin_pswrd_resp_entry)));
strcpy(role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(kamel_fardi_role_admin_window_combobox)));
ajouter_utilisateur(username,pswrd,role,fichier);
    }
//////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////

////////--------------------reinitialisation des entrees--------------//////////////////////////////////////////////////////////////////////////
gtk_entry_set_text(GTK_ENTRY(kamel_fardi_es_admin_resp_un_entry), "");
gtk_entry_set_text(GTK_ENTRY(kamel_fardi_es_admin_pswrd_resp_entry), "");
//////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////


}


void
on_role_admin_window_combobox_editing_done
                                        (GtkCellEditable *celleditable,
                                        gpointer         user_data)
{

}


void
on_kamel_fardi_logout_admin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *authentification;
  GtkWidget *admin;
  
  authentification = create_authentification();
  gtk_widget_show (authentification);
  admin = lookup_widget(button, "admin");
  gtk_widget_hide (admin);
}


void
on_kamel_fardi_Gestion_des_etudiants_hebergee_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *admin;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *treeview;
  char *fichier="etudiants.txt";  
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  gtk_widget_show (kamel_fardi_afficher_window);
  admin = lookup_widget(button, "admin");
    gtk_widget_hide (admin);
    treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");
    afficher_etudiant(treeview,fichier);
}


void
on_kamel_fardi_gestion_des_menus_de_la_semaine_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_kamel_fardi_Gestion_des_capteurs_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{/*
  GtkWidget *admin;
  GtkWidget *w;

    admin = lookup_widget(button, "admin");
    gtk_widget_hide (admin);
    w = create_Med_kh_w_Menu ();
    gtk_widget_show (w);*/

}


void
on_kamel_fardi_gestion_de_stock_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{/*
  GtkWidget *admin;
  GtkWidget *w;

    admin = lookup_widget(button, "admin");
    gtk_widget_hide (admin);
    w =create_tesnime_affichage ();
    gtk_widget_show (w);*/
}


void
on_kamel_fardi_Gestion_des_reclamations_hebergee_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *admin;
GtkWidget *w;

    admin = lookup_widget(button, "admin");
    gtk_widget_hide (admin);
    w =create_houssem_gestion_de_reclamatio();
    gtk_widget_show (w);
}


void
on_kamel_fardi_etudiant_window_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *kamel_fardi_etudiant_window;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *treeview;
  char *fichier="etudiants.txt";  
  kamel_fardi_etudiant_window = lookup_widget(button, "kamel_fardi_etudiant_window");
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");


  afficher_etudiant(treeview,fichier);
  gtk_widget_show (kamel_fardi_afficher_window);
  gtk_widget_hide (kamel_fardi_etudiant_window);
}


void
on_kamel_fardi_etudiant_window_modif_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
    GtkWidget *kamel_fardi_etudiant_window,*kamel_fardi_modifier_window;
    GtkWidget *treeview;
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry, *lieu_de_residence_entry, *date_de_naissance_calendar;
    GtkWidget *numero_telephonique_entry, *cin_entry, *groupe,*mail,*chambre,*classe;
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    //////////----------------obtenir les fenetres graphiques-------------////////////////////////////////////////////////////////////////////////////
    kamel_fardi_etudiant_window = lookup_widget(button, "kamel_fardi_etudiant_window");
    kamel_fardi_modifier_window = create_kamel_fardi_modifier_window ();
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    nom_entry = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_NOM_entry");
    prenom_entry = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_prenom_entry");
    lieu_de_residence_entry = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_adress_entry");
    numero_telephonique_entry = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_telfentry");
    cin_entry = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_cin_entry");
    date_de_naissance_calendar = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_calendar");
    chambre = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_chmbr_entry");
    groupe = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_groupe_spinbutton");
    mail = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_email_entry");
    classe = lookup_widget(kamel_fardi_modifier_window, "kamel_fardi_modifier_classe_combobox");
    ////////--------------------reinitialisation des entrees--------------//////////////////////////////////////////////////////////////////////////
    
    gtk_entry_set_text(GTK_ENTRY(nom_entry), p.nom);
    gtk_entry_set_text(GTK_ENTRY(prenom_entry),p.prenom);
    gtk_entry_set_text(GTK_ENTRY(lieu_de_residence_entry), p.adress);
    gtk_entry_set_text(GTK_ENTRY(numero_telephonique_entry), p.numero_telephonique);
    gtk_entry_set_text(GTK_ENTRY(cin_entry), p.cin);
    gtk_entry_set_text(GTK_ENTRY(mail), p.aderess_mail);
    gtk_entry_set_text(GTK_ENTRY(chambre), p.chambre);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(groupe), atoi(&p.classe[-1]));
    gtk_calendar_select_month(GTK_CALENDAR(date_de_naissance_calendar),
                              p.date_de_naissance.mois,
                              p.date_de_naissance.annee);
    gtk_calendar_select_day(GTK_CALENDAR(date_de_naissance_calendar),
                            p.date_de_naissance.jour);
    ///////-------------------------------------------------------------//////////////////////////////////////////////////////////////////////////
    gtk_widget_hide (kamel_fardi_etudiant_window);
    gtk_widget_show (kamel_fardi_modifier_window);
}


void
on_kamel_fardi_etudiant_window_supp_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *kamel_fardi_etudiant_window;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *treeview;
  char *fichier="etudiants.txt";
  char *file_users="utilisateurs.txt";  
  kamel_fardi_etudiant_window = lookup_widget(button, "kamel_fardi_etudiant_window");
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");
  supprimer_etudiant(p.cin,fichier);

  afficher_etudiant(treeview,fichier);
  gtk_widget_show (kamel_fardi_afficher_window);
  gtk_widget_hide (kamel_fardi_etudiant_window);
}


void
on_kamel_fardi_ajout_window_ajouter_cin_entry_editing_done
                                        (GtkCellEditable *celleditable,
                                        gpointer         user_data)
{
///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
    GtkWidget *wind, *cin_entry,*hint;
    char *fichier="etudiants.txt";
    char grp[20];
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    wind = create_kamel_fardi_ajout_hint_window ();
    cin_entry = lookup_widget(wind, "kamel_fardi_ajout_window_ajouter_cin_entry");
    strcpy(grp, gtk_entry_get_text(GTK_ENTRY(cin_entry)));
  if(verif_cin(grp,fichier)==1){
  gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
  hint = create_kamel_fardi_ajout_hint_window ();
  gtk_widget_show (hint);
  }
}


void
on_kamel_fardi_etudiant_gestion_etudiants_ajouter_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    int g;
    char grp[2];
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry, *lieu_de_residence_entry, *date_de_naissance_calendar;
    GtkWidget *numero_telephonique_entry, *cin_entry, *groupe,*mail,*chambre,*classe,*hintlabel,*fixed1;
    GtkWidget *hint,*kamel_fardi_ajout_etudiant_window1;
    char *fichier="etudiants.txt";
    char *fichier_users="utilisateurs.txt";
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    nom_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_nom_entry");
    
    prenom_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_prenom_entry");
    lieu_de_residence_entry = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_adress_entry");
    numero_telephonique_entry = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_tlf_entry");
    cin_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_cin_entry");
    date_de_naissance_calendar = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_date_naissance_calendar");
    chambre = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_chambre_entry");
    groupe = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_spinbutton");
    mail = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_mail_entry");
    classe = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_combobox");
    g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(groupe));
    sprintf(grp, "%d", g);
    if(!strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(nom_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(prenom_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(lieu_de_residence_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(numero_telephonique_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(chambre)))||!strlen(gtk_entry_get_text(GTK_ENTRY(mail)))||!strlen(gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)))||!strlen(etd.photo)||gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe))==NULL){

      set_text("50000","red","Remplir tout les champs !!!",0);
    }
    else{
      if(strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))>8||strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))<8){
        
        set_text("50000","red","Cin doit avoir 8 digits!!!",0);
        
      }
      else{
    //////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////

    //////////------enregirstrer les informations dans la structure---------///////////////////////////////////////////////////////////////////////////
    //etd.cin=gtk_entry_get_text(GTK_ENTRY(cin_entry));
    strcpy(etd.cin, gtk_entry_get_text(GTK_ENTRY(cin_entry)));
    strcpy(etd.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(etd.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(etd.adress, gtk_entry_get_text(GTK_ENTRY(lieu_de_residence_entry)));
    strcpy(etd.numero_telephonique, gtk_entry_get_text(GTK_ENTRY(numero_telephonique_entry)));
    strcpy(etd.aderess_mail, gtk_entry_get_text(GTK_ENTRY(mail)));
    strcpy(etd.chambre, gtk_entry_get_text(GTK_ENTRY(chambre)));
    strcpy(etd.classe, gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)));
    strcat(etd.classe,grp);
    
    strcpy(etd.services, "hebergement");
    
    gtk_calendar_get_date(GTK_CALENDAR(date_de_naissance_calendar),
                          &etd.date_de_naissance.annee,
                          &etd.date_de_naissance.mois,
                          &etd.date_de_naissance.jour);
    if((timeinfo->tm_year+1900-etd.date_de_naissance.annee)<17){

      set_text("50000","red","Age doit etre supperieur a 18 !!!",0);
    }
    else{
    etd.date_d_hebergement.annee=timeinfo->tm_year+1900;
    etd.date_d_hebergement.mois=timeinfo->tm_mon+1;
    etd.date_d_hebergement.jour=timeinfo->tm_mday;
    if (restau)strcat(etd.services,"+restaurant");
    if (pisc)strcat(etd.services,"+piscine");
  if(verif_cin(etd.cin,fichier)==0){
  gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
  set_text("50000","red","Cin deja utilisee !!!",0);
  }
  else{
    /////////--------------------------------------------------------------/////////////////////////////////////////////////////////////////////////
    ajouter_etudiant (etd,fichier);
    ajouter_utilisateur(etd.nom,etd.cin,"etudiant",fichier_users);
    //1 pour ajouter
    set_text("40000","green","Un nouveau Etudiant ajoutee !!!",1);
    ////////--------------------reinitialisation des entrees--------------//////////////////////////////////////////////////////////////////////////
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(lieu_de_residence_entry), "");
    gtk_entry_set_text(GTK_ENTRY(numero_telephonique_entry), "");
    gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
    gtk_entry_set_text(GTK_ENTRY(mail), "");
    gtk_entry_set_text(GTK_ENTRY(chambre), "");
    ///////-------------------------------------------------------------///////////////////////////////////////////////////////////////////////////
}
}
}
}
}


void
on_kamel_fardi_etudiant_gestion_etudiants_annuler_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
 ///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    
    int g;
    char grp[2];
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry, *lieu_de_residence_entry, *date_de_naissance_calendar;
    GtkWidget *numero_telephonique_entry, *cin_entry, *groupe,*mail,*chambre,*classe;
    GtkWidget *hint,*kamel_fardi_ajout_etudiant_window1;
    char *fichier="etudiants.txt";
    char *fichier_users="utilisateurs.txt";
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    nom_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_nom_entry");
    prenom_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_prenom_entry");
    lieu_de_residence_entry = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_adress_entry");
    numero_telephonique_entry = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_tlf_entry");
    cin_entry = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_cin_entry");
    date_de_naissance_calendar = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_date_naissance_calendar");
    chambre = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_chambre_entry");
    groupe = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_spinbutton");
    mail = lookup_widget(button, "kamel_fardi_etudiant_gestion_etudiants_mail_entry");
    classe = lookup_widget(button, "kamel_fardi_ajout_window_ajouter_combobox");
    
  ////////--------------------reinitialisation des entrees--------------//////////////////////////////////////////////////////////////////////////
    //gtk_label_set_text(GTK_LABEL(lbl),"bien ajouter !!");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry),"");
    gtk_entry_set_text(GTK_ENTRY(lieu_de_residence_entry), "");
    gtk_entry_set_text(GTK_ENTRY(numero_telephonique_entry), "");
    gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
    gtk_entry_set_text(GTK_ENTRY(mail), "");
    gtk_entry_set_text(GTK_ENTRY(chambre), "");
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(groupe), 1);
    gtk_calendar_select_month(GTK_CALENDAR(date_de_naissance_calendar),
                              timeinfo->tm_mon,
                              timeinfo->tm_year+1882);
    gtk_calendar_select_day(GTK_CALENDAR(date_de_naissance_calendar),
                            timeinfo->tm_mday);
}


void
on_kamel_fardi_etudiant_gestion_etudiants_filechooserbutton_file_set
                                        (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
  strcpy(etd.photo, gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton)));
}


void
on_kamel_fardi_ajout_window_ajouter_m_radiob_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  strcpy(etd.sexe,"masculin");

}


void
on_kamel_fardi_ajout_window_ajouter_f_radiob_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  strcpy(etd.sexe,"feminin");
}


void
on_kamel_fardi_ajouter_restaurant_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(restau)restau=0;
else restau=1;
}


void
on_kamel_fardi_ajouter_piscine_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(pisc)pisc=0;
else pisc=1;
}


void
on_kamel_fardi_etudiant_gestion_etudiants_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *authentification;
  GtkWidget *admin;
  GtkWidget *kamel_fardi_ajout_etudiant_window1;
  
  authentification = create_authentification();
  gtk_widget_show (authentification);
  kamel_fardi_ajout_etudiant_window1 = lookup_widget(button, "kamel_fardi_ajout_etudiant_window1");
  gtk_widget_hide (kamel_fardi_ajout_etudiant_window1); 
}


void
on_kamel_fardi_ajout_window_retour_buttonbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *kamel_fardi_ajout_etudiant_window1;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *treeview;
  char *fichier="etudiants.txt";  
  kamel_fardi_ajout_etudiant_window1 = lookup_widget(button, "kamel_fardi_ajout_etudiant_window1");
  gtk_widget_hide (kamel_fardi_ajout_etudiant_window1);
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");
  afficher_etudiant(treeview,fichier);
  gtk_widget_show (kamel_fardi_afficher_window);
}


void
on_kamel_fardi_modifier_piscine_checkbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
if(pisc)pisc=0;
else pisc=1;
}


void
on_kamel_fardi_modifier_ajouter_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  
  ///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
  time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    GtkWidget *kamel_fardi_modifier_window;
    GtkWidget *kamel_fardi_afficher_window;
    GtkWidget *treeview;
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry, *lieu_de_residence_entry, *date_de_naissance_calendar;
    GtkWidget *numero_telephonique_entry, *cin_entry, *groupe,*mail,*chambre,*classe;
    GtkWidget *hint,*kamel_fardi_modif_etudiant_window1,*hintlabel,*fixed1;
    char *fichier="etudiants.txt";
    char *fichier_users="utilisateurs.txt";
    int g;
    char grp[2];
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    nom_entry = lookup_widget(button, "kamel_fardi_modifier_NOM_entry");
    prenom_entry = lookup_widget(button, "kamel_fardi_modifier_prenom_entry");
    lieu_de_residence_entry = lookup_widget(button, "kamel_fardi_modifier_adress_entry");
    numero_telephonique_entry = lookup_widget(button, "kamel_fardi_modifier_telfentry");
    cin_entry = lookup_widget(button, "kamel_fardi_modifier_cin_entry");
    date_de_naissance_calendar = lookup_widget(button, "kamel_fardi_modifier_calendar");
    chambre = lookup_widget(button, "kamel_fardi_modifier_chmbr_entry");
    groupe = lookup_widget(button, "kamel_fardi_modifier_groupe_spinbutton");
    mail = lookup_widget(button, "kamel_fardi_modifier_email_entry");
    classe = lookup_widget(button, "kamel_fardi_modifier_classe_combobox");
    g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(groupe));
    sprintf(grp, "%d", g);
    if(!strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(nom_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(prenom_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(lieu_de_residence_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(numero_telephonique_entry)))||!strlen(gtk_entry_get_text(GTK_ENTRY(chambre)))||!strlen(gtk_entry_get_text(GTK_ENTRY(mail)))||!gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe))||!strlen(etd.photo)||gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe))==NULL){

      hint = create_kamel_fardi_ajout_hint_window ();
      hintlabel=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed_label");
      fixed1=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed");
      strcpy(kftexthint,"<span color=\"red\"><b>Remplir tout les champs !!!</b></span>");
      hintlabel = gtk_label_new (_(kftexthint));
      gtk_widget_show (hintlabel);
      gtk_fixed_put (GTK_FIXED (fixed1), hintlabel, 400, 336);
      gtk_widget_set_size_request (hintlabel, 250, 36);
      gtk_label_set_use_markup (GTK_LABEL (hintlabel), TRUE);
      gtk_widget_show (hint);
    }
    else{
      if(strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))>8||strlen(gtk_entry_get_text(GTK_ENTRY(cin_entry)))<8){
        hint = create_kamel_fardi_ajout_hint_window ();
      hintlabel=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed_label");
      fixed1=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed");
      strcpy(kftexthint,"<span color=\"red\"><b>Cin doit avoir 8 digits!!!</b></span>");
      hintlabel = gtk_label_new (_(kftexthint));
      gtk_widget_show (hintlabel);
      gtk_fixed_put (GTK_FIXED (fixed1), hintlabel, 400, 336);
      gtk_widget_set_size_request (hintlabel, 250, 36);
      gtk_label_set_use_markup (GTK_LABEL (hintlabel), TRUE);
      gtk_widget_show (hint);}
      else{
    //////////------------------------------------------------------------///////////////////////////////////////////////////////////////////////////

    //////////------enregirstrer les informations dans la structure---------///////////////////////////////////////////////////////////////////////////
    strcpy(etd.cin, gtk_entry_get_text(GTK_ENTRY(cin_entry)));
    strcpy(etd.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(etd.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(etd.adress, gtk_entry_get_text(GTK_ENTRY(lieu_de_residence_entry)));
    strcpy(etd.numero_telephonique, gtk_entry_get_text(GTK_ENTRY(numero_telephonique_entry)));
    strcpy(etd.aderess_mail, gtk_entry_get_text(GTK_ENTRY(mail)));
    strcpy(etd.chambre, gtk_entry_get_text(GTK_ENTRY(chambre)));
    strcpy(etd.classe, gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)));
    strcat(etd.classe,grp);
    strcpy(etd.sexe,"masculin");
    //char *esm=gtk_entry_get_text(GTK_ENTRY(cin_entry));
    strcpy(etd.services, "hebergement");
    
    gtk_calendar_get_date(GTK_CALENDAR(date_de_naissance_calendar),
                          &etd.date_de_naissance.annee,
                          &etd.date_de_naissance.mois,
                          &etd.date_de_naissance.jour);
    etd.date_d_hebergement.annee=p.date_d_hebergement.annee;
    etd.date_d_hebergement.mois=p.date_d_hebergement.mois;
    etd.date_d_hebergement.jour=p.date_d_hebergement.jour;
    if((timeinfo->tm_year+1900-etd.date_de_naissance.annee)<17){

      hint = create_kamel_fardi_ajout_hint_window ();
      hintlabel=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed_label");
      fixed1=lookup_widget(hint,"kamel_fardi_ajout_hint_fixed");
      strcpy(kftexthint,"<span color=\"red\"><b>Age doit etre supperieur a 18 !!!</b></span>");
      hintlabel = gtk_label_new (_(kftexthint));
      gtk_widget_show (hintlabel);
      gtk_fixed_put (GTK_FIXED (fixed1), hintlabel, 400, 336);
      gtk_widget_set_size_request (hintlabel, 250, 36);
      gtk_label_set_use_markup (GTK_LABEL (hintlabel), TRUE);
      gtk_widget_show (hint);
    }
    else{
    if (restau)strcat(etd.services,"+restaurant");
    if (pisc)strcat(etd.services,"+piscine");
  if(verif_cin(etd.cin,fichier)==0){
  
    modifier_etudiant(p.cin,etd,fichier);
    modif_etud(etd.nom,etd.cin,fichier_users);

  kamel_fardi_modifier_window = lookup_widget(button, "kamel_fardi_modifier_window");
  gtk_widget_hide (kamel_fardi_modifier_window);
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");
  afficher_etudiant(treeview,fichier);
  gtk_widget_show (kamel_fardi_afficher_window);
  }
  else{
    /////////--------------------------------------------------------------/////////////////////////////////////////////////////////////////////////
    gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
      hintlabel = gtk_label_new (_("<span color=\"red\"><b>Cin deja existe !!!</b></span>"));
      gtk_widget_show (hintlabel);
      gtk_fixed_put (GTK_FIXED (fixed1), hintlabel, 400, 336);
      gtk_widget_set_size_request (hintlabel, 200, 36);
      gtk_label_set_use_markup (GTK_LABEL (hintlabel), TRUE);
      gtk_widget_show (hint);
}
}
}
}
}


void
on_kamel_fardi_modifier_annuler_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
///////////-------------------------declarations---------------------///////////////////////////////////////////////////////////////////////////
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    int g;
    char grp[2];
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry, *lieu_de_residence_entry, *date_de_naissance_calendar;
    GtkWidget *numero_telephonique_entry, *cin_entry, *groupe,*mail,*chambre,*classe;
    GtkWidget *hint,*kamel_fardi_ajout_etudiant_window1;
    char *fichier="etudiants.txt";
    char *fichier_users="utilisateurs.txt";
    //////////-----------------------------------------------------------////////////////////////////////////////////////////////////////////////////
    
    //////////----------------obtenir les objects graphiques-------------////////////////////////////////////////////////////////////////////////////
    nom_entry = lookup_widget(button, "kamel_fardi_modifier_NOM_entry");
    prenom_entry = lookup_widget(button, "kamel_fardi_modifier_prenom_entry");
    lieu_de_residence_entry = lookup_widget(button, "kamel_fardi_modifier_adress_entry");
    numero_telephonique_entry = lookup_widget(button, "kamel_fardi_modifier_telfentry");
    cin_entry = lookup_widget(button, "kamel_fardi_modifier_cin_entry");
    date_de_naissance_calendar = lookup_widget(button, "kamel_fardi_modifier_calendar");
    chambre = lookup_widget(button, "kamel_fardi_modifier_chmbr_entry");
    groupe = lookup_widget(button, "kamel_fardi_modifier_groupe_spinbutton");
    mail = lookup_widget(button, "kamel_fardi_modifier_email_entry");
    classe = lookup_widget(button, "kamel_fardi_modifier_classe_combobox");
    
  ////////--------------------reinitialisation des entrees--------------//////////////////////////////////////////////////////////////////////////
    gtk_entry_set_text(GTK_ENTRY(nom_entry), p.nom);
    gtk_entry_set_text(GTK_ENTRY(prenom_entry),p.prenom);
    gtk_entry_set_text(GTK_ENTRY(lieu_de_residence_entry), p.adress);
    gtk_entry_set_text(GTK_ENTRY(numero_telephonique_entry), p.numero_telephonique);
    gtk_entry_set_text(GTK_ENTRY(cin_entry), p.cin);
    gtk_entry_set_text(GTK_ENTRY(mail), p.aderess_mail);
    gtk_entry_set_text(GTK_ENTRY(chambre), p.chambre);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(groupe), atoi(&p.classe[-1]));
    gtk_calendar_select_month(GTK_CALENDAR(date_de_naissance_calendar),
                              p.date_de_naissance.mois,
                              p.date_de_naissance.annee);
    gtk_calendar_select_day(GTK_CALENDAR(date_de_naissance_calendar),
                            p.date_de_naissance.jour);
}


void
on_kamel_fardi_modifier_filechooserbutton_file_set
                                        (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
  strcpy(etd.photo, gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton)));

}


void
on_kamel_fardi_modifier_female_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  strcpy(etd.sexe,"femini");
}


void
on_kamel_fardi_modifier_male_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  strcpy(etd.sexe,"masculin");
}


void
on_kamel_fardi_modifier_restaurant_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(restau)restau=0;
else restau=1;
}


void
on_kamel_fardi_modifier_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *authentification;
  GtkWidget *kamel_fardi_modifier_window;
  authentification = create_authentification ();
  gtk_widget_show (authentification);
  kamel_fardi_modifier_window = lookup_widget(button, "kamel_fardi_modifier_window");
  gtk_widget_hide (kamel_fardi_modifier_window);
}


void
on_kamel_fardi_modifier_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *kamel_fardi_modifier_window;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *treeview;
  char *fichier="etudiants.txt";  
  kamel_fardi_modifier_window = lookup_widget(button, "kamel_fardi_modifier_window");
  gtk_widget_hide (kamel_fardi_modifier_window);
  kamel_fardi_afficher_window = create_kamel_fardi_afficher_window ();
  treeview = lookup_widget(kamel_fardi_afficher_window, "kamel_fardi_affichage_liste_etudiant_treeview");
  afficher_etudiant(treeview,fichier);
  gtk_widget_show (kamel_fardi_afficher_window);
}


void
on_kamel_fardi_affichage_liste_etudiant_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkWidget *kamel_fardi_etudiant_window,*ajout_hint,*cinentry;
    GtkWidget *kamel_fardi_afficher_window;
    GtkWidget *classe,*services,*img, *fixed1, *nom, *prenom, *adress, *cin, *sexe, *ntlfn, *nenfn, *wind,*mail,*dtheberg,*naissance;
    GtkTreeIter iter;
    char *buf1;
    char *buf2;
    char *fichier="etudiants.txt";
    //Etudiant p;
    gchar *c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8,*c9,*c10,*c11,*c12,*c13;

     //ajout_hint = create_kamel_fardi_ajout_hint_window (); 
    kamel_fardi_etudiant_window = create_kamel_fardi_etudiant_window ();
   

    nom = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_nom");
    prenom = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_prenom");
    adress = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_adresse");
    cin = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_cin");
    ntlfn = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_num_tlf");
    mail=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_mail_label");
    sexe = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_sexe");
    naissance=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_date_de_naissace_label");
    classe=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_classe_lable");
    services=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_service_entrylabel");
    dtheberg=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_dt_heberg_en_label");
    fixed1 = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_fiche_etudiant_fixed");
    img = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_photo");


   GtkTreeModel *model=gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model,&iter,path))
      {
    
        gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&c1, 1, &c2, 2, &c3, 3, &c4, 4, &c5,5, &c6, 6, &c7, 7, &c8, 8, &c9, 9,&c10, 10, &c11, 11,&c12,12,&c13, -1);
    p=chercher_etudiant(c1,fichier);
    
    buf1=g_strdup_printf("%d-%d-%d", p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);
    buf2=g_strdup_printf("%d-%d-%d",p.date_d_hebergement.jour,p.date_d_hebergement.mois,p.date_d_hebergement.annee);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.nom,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (nom), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.prenom,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (prenom), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.adress,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (adress), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.aderess_mail,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (mail), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.classe,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (classe), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.services,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (services), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.cin,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (cin), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.sexe,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (sexe), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",p.numero_telephonique,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (ntlfn), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",buf2,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (dtheberg), kfchaine);
    sprintf(kfchaine, "%s%s%s","<span font_desc=\"arial\" color=\"black\"><b>",buf1,"</b></span>");
    gtk_label_set_markup (GTK_LABEL (naissance), kfchaine);
    g_free(buf2);
    g_free(buf1);
    
    img = gtk_image_new_from_file(p.photo);
    gtk_container_add(GTK_CONTAINER(fixed1), img);
    gtk_widget_show(img);
    gtk_fixed_move(GTK_FIXED(fixed1), img, 500, 100);
    gtk_widget_set_size_request(img, 400, 400);
    gtk_widget_show (kamel_fardi_etudiant_window);
      }
}


void
on_kamel_fardi_afficher_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *authentification;
  GtkWidget *kamel_fardi_afficher_window;
  authentification = create_authentification ();
  gtk_widget_show (authentification);
  kamel_fardi_afficher_window = lookup_widget(button, "kamel_fardi_afficher_window");
  gtk_widget_hide (kamel_fardi_afficher_window);
}


void
on_kamel_fardi_afficher_ajouter_etd_buttonbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
   
  GtkWidget *kamel_fardi_ajout_etudiant_window1;
  GtkWidget *kamel_fardi_afficher_window,*date_de_naissance_calendar;
  strcpy(etd.sexe,"masculin");
  
  kamel_fardi_ajout_etudiant_window1 = create_kamel_fardi_ajout_etudiant_window1 ();
  date_de_naissance_calendar = lookup_widget(kamel_fardi_ajout_etudiant_window1, "kamel_fardi_etudiant_gestion_etudiants_date_naissance_calendar");
 
    gtk_calendar_select_month(GTK_CALENDAR(date_de_naissance_calendar),
                              timeinfo->tm_mon,
                              timeinfo->tm_year+1882);
    gtk_calendar_select_day(GTK_CALENDAR(date_de_naissance_calendar),
                            timeinfo->tm_mday);
  gtk_widget_show (kamel_fardi_ajout_etudiant_window1);
  kamel_fardi_afficher_window = lookup_widget(button, "kamel_fardi_afficher_window");
  gtk_widget_hide (kamel_fardi_afficher_window);
}


void
on_kamel_fardi_afficher_chercher_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *kamel_fardi_etudiant_window,*ajout_hint,*cinentry;
  GtkWidget *kamel_fardi_afficher_window;
  GtkWidget *classe,*services,*img, *fixed1, *nom, *prenom, *adress, *cin, *sexe, *ntlfn, *nenfn, *wind,*mail,*dtheberg,*lbl;
  char *buf1;
  char *buf2;
  char *fichier="etudiants.txt";
  
  kamel_fardi_etudiant_window = create_kamel_fardi_etudiant_window ();
  ajout_hint = create_kamel_fardi_ajout_hint_window ();  
  kamel_fardi_afficher_window = lookup_widget(button,"kamel_fardi_afficher_window");
  cinentry=lookup_widget(button, "kamel_fardi_afficher_chercher_entry");
  if(verif_cin(gtk_entry_get_text(GTK_ENTRY(cinentry)),fichier)==0){
    //setters
    
    p=chercher_etudiant(gtk_entry_get_text(GTK_ENTRY(cinentry)),fichier);
    
    nom = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_nom");
    prenom = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_prenom");
    adress = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_adresse");
    cin = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_cin");
    ntlfn = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_num_tlf");
    mail=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_mail_label");
    sexe = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_sexe");
    lbl=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_date_de_naissace_label");
    classe=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_classe_lable");
    services=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_service_entrylabel");
    dtheberg=lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_dt_heberg_en_label");



    buf1=g_strdup_printf("%d %d %d", p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);
    buf2=g_strdup_printf("%d %d %d",p.date_d_hebergement.jour,p.date_d_hebergement.mois,p.date_d_hebergement.annee);
    gtk_label_set_text(GTK_LABEL(nom), p.nom);
    gtk_label_set_text(GTK_LABEL(prenom), p.prenom);
    gtk_label_set_text(GTK_LABEL(adress), p.adress);
    gtk_label_set_text(GTK_LABEL(mail), p.aderess_mail);
    gtk_label_set_text(GTK_LABEL(classe), p.classe);
    gtk_label_set_text(GTK_LABEL(services), p.services);
    gtk_label_set_text(GTK_LABEL(cin), p.cin);
    gtk_label_set_text(GTK_LABEL(sexe), p.sexe);
    gtk_label_set_text(GTK_LABEL(ntlfn), p.numero_telephonique);
    gtk_label_set_text(GTK_LABEL(dtheberg), buf2);
    gtk_label_set_text(GTK_LABEL(lbl), buf1);
    g_free(buf2);
    g_free(buf1);
    fixed1 = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_fiche_etudiant_fixed");
    img = lookup_widget(kamel_fardi_etudiant_window, "kamel_fardi_etudiant_window_etd_photo");
    img = gtk_image_new_from_file(p.photo);
    gtk_container_add(GTK_CONTAINER(fixed1), img);
    gtk_widget_show(img);
    gtk_fixed_move(GTK_FIXED(fixed1), img, 500, 100);
    gtk_widget_set_size_request(img, 400, 400);
    gtk_widget_hide (kamel_fardi_afficher_window);
    gtk_widget_show (kamel_fardi_etudiant_window);
 
  }
  else{
  gtk_entry_set_text(GTK_ENTRY(cinentry), "");
  ajout_hint = create_kamel_fardi_rechercher_faild_window ();
  gtk_widget_show (ajout_hint);
}
}


void
on_kamel_fardi_ajout_hint_fixed_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *hint;
    GtkWidget *cin_entry;
  hint = lookup_widget(button, "kamel_fardi_ajout_hint_window");
  gtk_widget_hide (hint);
}


void
on_kamel_fardi_rechercher_faild_fixed_ok_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *hint;
  hint = lookup_widget(button, "kamel_fardi_rechercher_faild_window");
  gtk_widget_hide (hint);
}


void
on_kamel_fardi_dash_board_fixed_espaceadmin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *w,*treeview,*authentification;
    char *file_users="utilisateurs.txt";
    authentification=create_authentification();
    gtk_widget_hide (authentification);
    w = create_admin ();
    gtk_widget_show (w);
    treeview = lookup_widget(w, "kamel_fardi_espace_admin_treeview_responsables");
    afficher_utilisateur(treeview,file_users);
}


void
on_kamel_fardi_dash_board_fixed_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *authentification;
  GtkWidget *kamel_fardi_afficher_window;
  authentification = create_authentification ();
  gtk_widget_show (authentification);
  kamel_fardi_afficher_window = lookup_widget(button, "kamel_fardi_dash_board_window");
  gtk_widget_hide (kamel_fardi_afficher_window);
}
void
on_kamel_fardi_dash_board_fixed_logout_button_nombreetudiant_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *v,*lbl,*kamel_fardi_dash_board_fixed_espaceadmin_nombrelabel;
int s=1;
char *file="etudiants.txt";
char t[100];
char grp[300];
v = lookup_widget(button, "kamel_fardi_dash_board_fixed_logout_button_combobox");
strcpy(t, gtk_combo_box_get_active_text(GTK_COMBO_BOX(v)));
s=nombres_des_etudiant(file,t[0]);
sprintf(grp, "%s%d%s","<span font-size=\"13000\"color=\"black\"><b>",s,"</b></span>");
kamel_fardi_dash_board_fixed_espaceadmin_nombrelabel = lookup_widget(button, "kamel_fardi_dash_board_fixed_espaceadmin_nombrelabel");
gtk_label_set_markup (GTK_LABEL (kamel_fardi_dash_board_fixed_espaceadmin_nombrelabel), grp);
}


void
on_kamel_fardi_bien_ajoutee_ok_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////  M O H A M E D--------K H O U A L D I A /////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_mk_dash_treeview_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkWidget *w_Ajouter,*confirme;
	GtkTreeIter iter;
	char *fich="capteurs.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	confirme=create_Med_kh_confirme();
	gtk_widget_show (confirme);*/
}


void
on_mk_dash_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *kamel_fardi_dash_board_window,*mk_dash_combobox;
   GtkWidget *mk_dash_treeview;
   char *file="temperature.txt";
   char chaine[100];
   char E;
mk_dash_treeview=lookup_widget(button,"mk_dash_treeview");
mk_dash_combobox=lookup_widget(button,"mk_dash_combobox");
strcpy(chaine,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mk_dash_combobox)));
E=chaine[0];
cap_defecteux(mk_dash_treeview,E,file);*/
}
void
on_Med_kh_button1_Ajouter_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
   capteur c;
   

   GtkWidget *ref,*ajout;
   GtkWidget *type;
   GtkWidget *V_Max;
   GtkWidget *V_Min;
   GtkWidget *jour;
   GtkWidget *mois;
   GtkWidget *annee;
   GtkWidget *entry_e1;
   GtkWidget *entry_e2;
   GtkWidget *entry_e3;
   
  
   
   ajout=lookup_widget(objet,"Med_kh_w_Ajouter");
   
   ref=lookup_widget(objet,"Med_kh_ref_1");

   type=lookup_widget(objet,"Med_kh_comboboxentry1");

   V_Max=lookup_widget(objet,"Med_kh_V_Max_1");
   V_Min=lookup_widget(objet,"Med_kh_V_Min_1");

   jour=lookup_widget(objet,"Med_kh_jour_1");
   mois=lookup_widget(objet,"Med_kh_mois_1");
   annee=lookup_widget(objet,"Med_kh_annee_1");

   entry_e1=lookup_widget(objet,"Med_kh_checkbutton_e1");
   entry_e2=lookup_widget(objet,"Med_kh_checkbutton_e2");
   entry_e3=lookup_widget(objet,"Med_kh_checkbutton_e3");

   
   

  c.ref=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ref));

  strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

   c.V_Max=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(V_Max));
   c.V_Min=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(V_Min));


   c.dt.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
   c.dt.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
   c.dt.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

   if(s==1)
	strcpy(c.Emplacement,"E1");
	else if (s==2)
	strcpy(c.Emplacement,"E2");
	else
	strcpy(c.Emplacement,"E3");

  
						  
    Ajouter_capt(c);
    gtk_widget_hide (ajout);*/

}


void
on_Med_kh_checkbutton_e1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=1;*/
}


void
on_Med_kh_checkbutton_e2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=2;*/
}


void
on_Med_kh_checkbutton_e3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=3;*/
}


void
on_Med_kh_bouton_modifier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
capteur c;
GtkWidget *modif;
   GtkWidget *ref;
   GtkWidget *type;
   GtkWidget *V_Max;
   GtkWidget *V_Min;
   GtkWidget *jour;
   GtkWidget *mois;
   GtkWidget *annee;
   GtkWidget *entry_e4;
   GtkWidget *entry_e5;
   GtkWidget *entry_e6;
  
   
   
//modif=create_w_Modifier();
   modif=lookup_widget(objet,"Med_kh_w_Modifier");
   ref=lookup_widget(objet,"Med_kh_ref_2");

   type=lookup_widget(objet,"Med_kh_comboboxentry2");

   V_Max=lookup_widget(objet,"Med_kh_V_Max_2");
   V_Min=lookup_widget(objet,"Med_kh_V_Min_2");

   jour=lookup_widget(objet,"Med_kh_jour_2");
   mois=lookup_widget(objet,"Med_kh_mois_2");
   annee=lookup_widget(objet,"Med_kh_annee_2");

   entry_e4=lookup_widget(objet,"Med_kh_checkbutton_e4");
   entry_e5=lookup_widget(objet,"Med_kh_checkbutton_e5");
   entry_e6=lookup_widget(objet,"Med_kh_checkbutton_e6");


   

  c.ref=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ref));

  strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

   c.V_Max=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(V_Max));
   c.V_Min=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(V_Min));


   c.dt.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
   c.dt.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
   c.dt.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

   if(s==1)
	strcpy(c.Emplacement,"E1");
	else if (s==2)
	strcpy(c.Emplacement,"E2");
	else
	strcpy(c.Emplacement,"E3");






	modifier(c,cap.ref);
	gtk_widget_hide (modif);*/

}


void
on_Med_kh_checkbutton_e6_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=3;*/
}


void
on_Med_kh_checkbutton_e5_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=2;*/
}


void
on_Med_kh_checkbutton_e4_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
 if (gtk_toggle_button_get_active(togglebutton));
	s=1;*/
}


void
on_Med_kh_Ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
GtkWidget *Menu;
GtkWidget *Ajouter;

Ajouter=lookup_widget(objet,"Med_kh_w_Ajouter");
Ajouter=create_Med_kh_w_Ajouter();

gtk_widget_show(Ajouter);*/

}

void
on_Med_kh_Supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
GtkWidget *Menu;
GtkWidget *aff;
GtkWidget *tree;
//aff=lookup_widget(objet,"w_aff_supp");


//Menu=lookup_widget(objet,"Med_kh_w_Menu");
aff = create_Med_kh_w_aff_supp ();


//tree=lookup_widget(aff,"Med_kh_treeview1");
//afficher_capteur(tree);
gtk_widget_show (aff);
//gtk_widget_hide(Menu);*/
}


void
on_Med_kh_button_CF_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{/*
  GtkWidget *Menu;
  GtkWidget *def;
  GtkWidget *treeview3;
  capteur c;
          FILE *F, *f3;
    F=fopen("capteurs.txt","r");
    f3=fopen("temperature.txt","a+");
    if(F!=NULL)
   {
	while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)
         {
	   if(f3!=NULL)
            {
              if ((strcmp(c.type,"capteur_de_temperature")==0) && (c.dt.mois==11) && (((c.V_Max>30)||(c.V_Max<10)) || ((c.V_Min>30)||(c.V_Min<10))))
               {
		    fprintf(f3,"%d %s %f %f %d %d %d %s\n",c.ref,c.type,c.V_Max,c.V_Min,c.dt.jour,c.dt.mois,c.dt.annee,c.Emplacement);
                  
               }	
             }
	  }
    }fclose(F);
     fclose(f3);
    
  def = create_Med_kh_windowC_f();


  treeview3=lookup_widget(def,"Med_kh_treeview3");
  Aff_captdef(treeview3);
  gtk_widget_show (def);
 */
   
}


void
on_Med_kh_Rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{/*
  GtkWidget *Menu;
  GtkWidget *rechercher;
  GtkWidget *treeview2;
  GtkWidget *REFE;
  
  int NUM;
  int b=0;
  capteur c;
          FILE *F, *f2;

   REFE=lookup_widget(objet,"Med_kh_ref_rech");

   NUM= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(REFE));
   
    F=fopen("capteurs.txt","r");
    f2=fopen("recherche.txt","a+");
    if(F!=NULL)
   {
	while(fscanf(F,"%d %s %f %f %d %d %d %s\n",&c.ref,c.type,&c.V_Max,&c.V_Min,&c.dt.jour,&c.dt.mois,&c.dt.annee,c.Emplacement)!=EOF)
         {
	   if(f2!=NULL)
            {
              if (NUM==c.ref)
               {   
                    b=1;
		    fprintf(f2,"%d %s %f %f %d %d %d %s\n",c.ref,c.type,c.V_Max,c.V_Min,c.dt.jour,c.dt.mois,c.dt.annee,c.Emplacement);
                  
               }
               
             }
	  }
    }fclose(F);
     fclose(f2);
  rechercher = create_Med_kh_w_Rechercher();


  treeview2=lookup_widget(rechercher,"Med_kh_treeview2");
  Rech_affich(treeview2);
  gtk_widget_show (rechercher);*/
  
}


void
on_Med_kh_treeview3_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
        GtkWidget *def;
	GtkTreeIter iter;
	char *fich="temperature.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	def=create_Med_kh_windowC_f();
	gtk_widget_show (def);*/
}



void
on_Med_kh_treeview1_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*
	GtkWidget *w_Ajouter,*confirme;
	GtkTreeIter iter;
	char *fich="capteurs.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	confirme=create_Med_kh_confirme();
	gtk_widget_show (confirme);*/
}


void
on_Med_kh_Act_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
GtkWidget *act;
GtkWidget *aff;
GtkWidget *tree;
//aff=lookup_widget(objet,"w_aff_supp");


act=lookup_widget(objet,"Med_kh_Act");
tree=lookup_widget(objet,"Med_kh_treeview1");
afficher_capteur(tree);*/
}


void
on_Med_kh_modif_conf_button_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{/*
   GtkWidget *confirme;
   GtkWidget *aff,*modif;
   GtkWidget *ref;
   GtkWidget *type;
   GtkWidget *V_Max;
   GtkWidget *V_Min;
   GtkWidget *jour;
   GtkWidget *mois;
   GtkWidget *annee;
   GtkWidget *entry_e1;
   GtkWidget *entry_e2;
   GtkWidget *entry_e3;
  
   
   confirme=lookup_widget(button,"Med_kh_confirme");
   modif=create_Med_kh_w_Modifier();
   aff=create_Med_kh_w_aff_supp();
   
   ref=lookup_widget(modif,"Med_kh_ref_2");

   type=lookup_widget(modif,"Med_kh_comboboxentry2");

   V_Max=lookup_widget(modif,"Med_kh_V_Max_2");
   V_Min=lookup_widget(modif,"Med_kh_V_Min_2");

   jour=lookup_widget(modif,"Med_kh_jour_2");
   mois=lookup_widget(modif,"Med_kh_mois_2");
   annee=lookup_widget(modif,"Med_kh_annee_2");

   /*entry_e1=lookup_widget(objet,"checkbutton_e1");
   entry_e2=lookup_widget(objet,"checkbutton_e2");
   entry_e3=lookup_widget(objet,"checkbutton_e3");*/


   
/*
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(ref),cap.ref);

  //strcpy(cap.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

   gtk_spin_button_set_value(GTK_SPIN_BUTTON(V_Max),cap.V_Max);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(V_Min),cap.V_Min);


   gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),cap.dt.jour);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),cap.dt.mois);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),cap.dt.annee);
	gtk_widget_hide (confirme);
	//gtk_widget_hide (aff);
	gtk_widget_show (modif);*/
}


void
on_Med_kh_supp_confirme_button_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
GtkWidget *confirme;
GtkWidget *aff;
GtkWidget *tree;

confirme=lookup_widget(objet,"Med_kh_confirme");
supprimer(cap.ref);
gtk_widget_hide (confirme);*/
}


void
on_Med_kh_button_retour2_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
 GtkWidget *windowC_f;
 windowC_f=lookup_widget(objet,"Med_kh_windowC_f");
 gtk_widget_destroy(windowC_f);*/
}


void
on_Med_kh_button_retour1_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
 GtkWidget *w_Rechercher;
 w_Rechercher=lookup_widget(objet,"Med_kh_w_Rechercher");
 gtk_widget_destroy(w_Rechercher);*/
}


void
on_Med_kh_button_retour0_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{/*
 GtkWidget *w_aff_supp;
 w_aff_supp=lookup_widget(objet,"Med_kh_w_aff_supp");
 gtk_widget_destroy(w_aff_supp);*/
}

//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////tesnim/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void
on_button3_tessnime_affichage_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *code;
char *file="produits.txt";

code=lookup_widget(button,"entry9_recherche_tesnime");
//strcpy(f.code,gtk_entry_get_text(GTK_ENTRY(code)));
tes_supprimer(file,gtk_entry_get_text(GTK_ENTRY(code)));*/
}


 void 
on_button1_tesnim_affichage_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *fenetre_ajout;
  GtkWidget *fenetre_afficher;
  fenetre_afficher = lookup_widget(button, "tesnime_affichage");
  gtk_widget_destroy(fenetre_afficher);
  //fenetre_ajout = lookup_widget(button, "tesnime_ajouter");
  fenetre_ajout = create_tesnime_ajouter();
  gtk_window_set_position(GTK_WINDOW(fenetre_ajout),GTK_WIN_POS_CENTER_ALWAYS);
  gtk_widget_show(fenetre_ajout);*/
}


void
on_button2_tesnime_affichage_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{/*
produit p;
  

  gchar *nom;
  gchar *code;
  gchar *quantite;  
  gchar *prix;
  gchar *type;
  gchar *date;
	//char *d;
  GtkWidget *affichage;
  GtkWidget *modifier;
  GtkWidget *nomproduit;
  GtkWidget *codeproduit;
  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;
  GtkWidget *depot;
  GtkWidget *retrait;
  


    modifier=create_tesnime_modifier();
	affichage= lookup_widget(button,"tesnime_affichage");
    gtk_widget_hide(affichage);
    //gtk_window_set_position(GTK_WINDOW(modifier),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_show(modifier);
     
    sscanf(d, "%d/%d/%d", &p.d.jour, &p.d.mois, &p.d.annee);
   
     nomproduit= lookup_widget(modifier, "entry5_tesnim_modif_nom");
     codeproduit = lookup_widget(modifier, "entry6_tesnim_modif_code");
     quantite = lookup_widget(modifier, "entry8_tes_modif_quantite");
     prix= lookup_widget(modifier, "entry7_tes_modif_prix");
   
   
   
    jour = lookup_widget(modifier, "spinbutton4_tes_modif_jour");
    mois = lookup_widget(modifier, "spinbutton5_tes_modif_mois");
    annee = lookup_widget(modifier, "spinbutton6_tes_modifannee");
    depot = lookup_widget(modifier, "radiobutton3_tes_modif_depot");
    retrait = lookup_widget(modifier, "radiobutton4_tes_modif_retrait");
   
    gtk_entry_set_text(GTK_ENTRY(nomproduit), b);
    gtk_entry_set_text(GTK_ENTRY(codeproduit), c);
    gtk_entry_set_text(GTK_ENTRY(quantite), e);
    gtk_entry_set_text(GTK_ENTRY(prix), f);
   
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), p.d.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois), p.d.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), p.d.annee);
 
       
    if ((strcmp(p.type, "depot") == 0))
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(depot), 1);
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(retrait), 0);
    }
    else if ((strcmp(p.type, "retrait") == 0))
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(depot), 0);
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(retrait), 1);
}*/
}


void
on_button4_tesnime_affichage_rechercher_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{/*
produit p;
  GtkWidget *affichage;
  GtkWidget *entry9_recherche;
  GtkWidget *treeview;
  FILE *f;
  FILE *f2;
  char code[30];

  affichage = lookup_widget(button, "tesnime_affichage");
  entry9_recherche = lookup_widget(button, "entry9_recherche_tesnime");
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(entry9_recherche)));
  f = fopen("produits.txt", "r");

  if (f != NULL)
  {
    while (fscanf(f, "%s %s %s %s %s %s %s\n", p.categorie,p.nom, p.code, p.quantite, p.prix, p.date, p.type) != EOF)
    {
      f2 = fopen("recherche.txt", "a+");
      if (f2 != NULL)
      {
        if ((strcmp(p.code,id ) == 0))
        {
          fprintf(f2, "%s %s %s %s %s %s %s\n", p.categorie, p.nom, p.code, p.quantite,p.prix,p.date, p.type);
        }
        treeview = lookup_widget(affichage, "tesnime_treeview");
        fclose(f2);
        recherche(treeview);
        
      }
    }

    fclose(f);
  }
  //remove("recherche.txt");*/
}




void
on_button5_tesnime_afficher__clicked   (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *fenetre_afficher;
  GtkWidget *treeview;

  //fenetre_afficher = lookup_widget(button, "tesnime_affichage");
  treeview = lookup_widget(button, "tesnime_treeview");
  afficher(treeview);*/
}


void
on_radiobutton2_tes_ajouter_retrait_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_tes_ajout_depot_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}







void
on_button7_tesnim_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{/*
  GtkWidget *fenetre_afficher;
  fenetre_ajout = lookup_widget(button, "tesnime_ajouter");
  gtk_widget_destroy(fenetre_ajout);
  //fenetre_afficher = lookup_widget(button, "tesnime_ajouter");
  fenetre_afficher = create_tesnime_affichage();
  //gtk_window_set_position(GTK_WINDOW(fenetre_afficher),GTK_WIN_POS_CENTER_ALWAYS);
  gtk_widget_show(fenetre_afficher);*/
}






void
on_radiobutton3_tes_modif_depot_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton4_tes_modif_retrait_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_valider_tes_modiffier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
/*
produit p;
 
 
  GtkWidget *nom;
  GtkWidget *code;
  GtkWidget *prix;
  GtkWidget *quantite;
  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;
  GtkWidget *categorie;
  char *file="produits.txt";
 
   
  jour = lookup_widget(button, "spinbutton4_tes_modif_jour");
  mois = lookup_widget(button, "spinbutton5_tes_modif_mois");
  annee = lookup_widget(button, "spinbutton6_tes_modifannee");
  nom = lookup_widget(button, "entry5_tesnim_modif_nom");
  code = lookup_widget(button, "entry6_tesnim_modif_code");
  prix = lookup_widget(button, "entry7_tes_modif_prix");
  quantite = lookup_widget(button, "entry8_tes_modif_quantite");
  categorie=lookup_widget(button,"combobox2_tesnim_cate_modif");
  
 
  strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(p.quantite, gtk_entry_get_text(GTK_ENTRY(quantite)));
  strcpy(p.prix, gtk_entry_get_text(GTK_ENTRY(prix)));
  strcpy(p.code, gtk_entry_get_text(GTK_ENTRY(code)));
  strcpy(p.categorie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
  p.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  p.d.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  p.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
  sprintf(p.date, "%d/%d/%d", p.d.jour, p.d.mois, p.d.annee);
  strcpy(p.type,"depot");
	switch(radio_type)
	{
		case 1 : strcpy(p.type,"depot");
		break;
		case 0 : strcpy(p.type,"retrait");
		break;
		default : strcpy(p.type,"depot");
		break;
	}
  modification(file,p);*/
}



void
on_button9_retour_tes_modifier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *fenetre_ajout;
  GtkWidget *fenetre_afficher;
  fenetre_ajout = lookup_widget(button, "tesnime_modifier");
  gtk_widget_destroy(fenetre_ajout);
  //fenetre_afficher = lookup_widget(button, "tesnime_modifier");
  fenetre_afficher = create_tesnime_affichage();
  gtk_window_set_position(GTK_WINDOW(fenetre_afficher),GTK_WIN_POS_CENTER_ALWAYS);
  gtk_widget_show(fenetre_afficher);*/
}



void
on_radiobutton1_tes_ajout_depot_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
radio_type=1;*/
}


void
on_radiobutton2_tes_ajouter_retrait_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
radio_type=0;*/
}


void
on_button6_tesnim_ajouter_valider_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{/*
produit p;
 
 
  GtkWidget *nom;
  GtkWidget *code;
  GtkWidget *prix;
  GtkWidget *quantite;
  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;
  GtkWidget *categorie;

 
   
  jour = lookup_widget(button, "spinbutton1_jour_ajouter");
  mois = lookup_widget(button, "spinbutton2_tes_mois_ajouter");
  annee = lookup_widget(button, "spinbutton3_annee");
  nom = lookup_widget(button, "entry1_tesnim_ajouter_nom");
  code = lookup_widget(button, "entry2_tesnime_ajouter_code");
  prix = lookup_widget(button, "entry3_tesnime_ajouter_prix");
  quantite = lookup_widget(button, "entry4_tesnim_ajouter_quantite");
  categorie=lookup_widget(button,"combobox1_tesnim_ajouter");
  
 
  strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(p.quantite, gtk_entry_get_text(GTK_ENTRY(quantite)));
  strcpy(p.prix, gtk_entry_get_text(GTK_ENTRY(prix)));
  strcpy(p.code, gtk_entry_get_text(GTK_ENTRY(code)));
  strcpy(p.categorie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
  p.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  p.d.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  p.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
  sprintf(p.date, "%d/%d/%d", p.d.jour, p.d.mois, p.d.annee);

	switch(radio_type)
	{
		case 1 : strcpy(p.type,"depot");
		break;
		case 0 : strcpy(p.type,"retrait");
		break;
		default : strcpy(p.type,"depot");
		break;
	}
  ajout(p);*/
}


void
on_tesnime_treeview_row1_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
produit p ;
  GtkTreeIter iter;
  gchar *categorie;
  gchar *nom ;
  gchar *code ;
  gchar *type;
  gchar *quantite ;
  gchar *date;
  gchar *prix;

  
 
 
//affichage = lookup_widget(treeview, "tesnime_affichage");
  GtkTreeModel *model = gtk_tree_view_get_model(treeview);
  if (gtk_tree_model_get_iter(model, &iter, path))
  {
    gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &categorie, 1, &nom, 2, &code, 3, &type, 4, &quantite, 5, &prix, 6,&date, -1);
   
    strcpy(a, categorie);
    strcpy(b, nom);
    strcpy(c, code);
    strcpy(d, type);
    strcpy(e, quantite);
    strcpy(f, prix);
    strcpy(g, date);
}*/
}
void
on_ts_deconnect_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data){/*
  
  GtkWidget *authentification;
  GtkWidget *admin;
  
  authentification = create_authentification();
  gtk_widget_show (authentification);
  admin = lookup_widget(button, "tesnime_affichage");
  gtk_widget_hide (admin);
                                 */     }





reclamation roe;
int x;
int ge[2]={0,0};
char he[20]="hebergement";
char de[20]="restauration";
soulofthedead poe;

void
on_houssemkh_treeview1_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
int a;
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* ID;
gchar* type;
gchar* numero;
gchar* text;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&mois,2,&annee,3,&nom,4,&prenom,5,&ID,6,&type,7,&numero,8,&text,-1);
strcpy(poe.jour1,jour);
strcpy(poe.mois1,mois);
strcpy(poe.annee1,annee);
strcpy(poe.nom,nom);
strcpy(poe.prenom,prenom);
strcpy(poe.ID,ID);
strcpy(poe.type_reclamation,type);
strcpy(poe.numero_reclamation,numero);
strcpy(poe.text_reclamation,text);

}

}


void
on_houssemkh_button6_aficher_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(button,"houssemkh_treeview1");
affich(treeview);
}


void
on_houssem_buttonbaby44_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windore;
windore=create_houssem_CONFIRMATION();
gtk_widget_show (windore);

}


void
on_houssem_button2_ajout_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowre;
windowre=create_houssem_ajoutdereclamation();
gtk_widget_show (windowre);

}


void
on_houssem_leplusreclamer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windore;
windore=create_houssemkh_dache_bord();
gtk_widget_show (windore);

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_houssem_button4_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowre;
windowre=create_houssem_modification();
gtk_widget_show (windowre);

}


void
on_houssem_button5_rech_clicked         (GtkWidget       *objet_graphique,gpointer  user_data)
{
GtkWidget *treevieww;

treevieww=lookup_widget(objet_graphique,"houssemkh_treeview1");
char nq[20];
char pq[20];

GtkWidget *jouro;
GtkWidget *rto;

jouro=lookup_widget(objet_graphique,"houssem_enterderecherche");
rto=lookup_widget(objet_graphique,"houssemkhentryderecherche2");
strcpy(nq,gtk_entry_get_text(GTK_ENTRY(jouro)));
strcpy(pq,gtk_entry_get_text(GTK_ENTRY(rto)));
chercher(nq,pq,treevieww);

}


void
on_alignment4_check_resize             (GtkContainer    *container,
                                        gpointer         user_data)
{
  




}


void
on_houssemkh_button_ajout_rasmi_clicked
                                       (GtkWidget       *objet_graphique,gpointer  user_data)
{

newreclam  z;
int e;
char s;
int tr;


GtkWidget *nom, *prenom, *id, *type, *text, *numr;
GtkWidget *jouro;
GtkWidget *moiso;
GtkWidget *annneo;
nom=lookup_widget(objet_graphique,"houssemkh_entry_nom");
prenom=lookup_widget(objet_graphique,"houssemkh_entryss_prenom");
id=lookup_widget(objet_graphique,"houssemkh_entryrr_id");
text=lookup_widget(objet_graphique,"houssemkh_entry_textq");
numr=lookup_widget(objet_graphique,"houssemkh_entreyomyheart");
jouro=lookup_widget(objet_graphique,"houssemkh_spinbutton101");
moiso=lookup_widget(objet_graphique,"houssem_spinbutton233");
annneo=lookup_widget(objet_graphique,"houssemkh_comboboxentry101");




z.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jouro));
z.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiso));
if(strcmp("2021",gtk_combo_box_get_active_text(GTK_COMBO_BOX(annneo)))==0)
z.annee1=2021;
else
z.annee1=2022;






strcpy(z.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(z.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(z.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(z.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text)));
strcpy(z.numero_reclamation,gtk_entry_get_text(GTK_ENTRY(numr)));
if(x==1)

{
strcpy(z.type_reclamation,he);
}
else if(x==2)
{
strcpy(z.type_reclamation,de);
}
tr=verification(z);
if(tr==0)
ajouter_reclam(z);
else if (tr==1)
{
GtkWidget *windowre;
windowre=create_houssem_kharroubi_eroor();
gtk_widget_show (windowre);

}



}

void
on_houssemkh_button7_confirmer_desuprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
if(ge[1]==2)

supprimer_reclam(poe);
else 
ge[0]=1;
}


void
on_checkbutton2_ssa_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
ge[0]=1;
}


void
on_checkbutton1_yess_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
ge[1]=2;

}


void
on_houssemkh_modification23_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{


newreclam o;
int t;
int x=1 ;
char z[20] ;



GtkWidget *jour,*mois,*annee,*nom, *prenom, *id, *type, *text,*numc,*calanderofthisar;

nom=lookup_widget(objet,"entry1nomholy");
prenom=lookup_widget(objet,"entry2holy");
id=lookup_widget(objet,"entrydeid2");
text=lookup_widget(objet,"entrykiko");
numc=lookup_widget(objet,"entrydenumdereclam");

calanderofthisar=lookup_widget(objet,"houssem_calendar1");
o.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
gtk_calendar_get_date(GTK_CALENDAR(calanderofthisar),
                          &o.annee1,
                          &o.mois1,
                          &o.jour1);

       
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(o.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(o.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text)));
strcpy(o.numero_reclamation,gtk_entry_get_text(GTK_ENTRY(numc)));
if(x==1)
{
strcpy(roe.type_reclamation,he);
}
else if(x==2)
{
strcpy(roe.type_reclamation,de);
}

modifier_reclam(poe,o);
}


void
on_boutonderecuperationhoussem_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *jour,*mois,*annee,*nom, *prenom, *id, *type, *text,*numc,*calanderofthisar;

nom=lookup_widget(button,"entry1nomholy");
prenom=lookup_widget(button,"entry2holy");
id=lookup_widget(button,"entrydeid2");
text=lookup_widget(button,"entrykiko");
numc=lookup_widget(button,"entrydenumdereclam");
gtk_entry_set_text(GTK_ENTRY(nom),poe.nom);
gtk_entry_set_text(GTK_ENTRY(prenom),poe.prenom);
gtk_entry_set_text(GTK_ENTRY(id),poe.ID);
gtk_entry_set_text(GTK_ENTRY(text),poe.text_reclamation);
gtk_entry_set_text(GTK_ENTRY(numc),poe.numero_reclamation);
}


void
on_houssemkh_bouton_de_tache2_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(button,"houssemkh_treeview2");
 leplusreclamer(treeview);
}

void
on_houssemkh_bouton_fermer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *confez;
confez = lookup_widget(button,"houssemkh_bouton_fermer");
gtk_widget_destroy(confez);

}

                                        

void
on_houssem_radiobutton1_restauration_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=2;
}


void
on_houssemkh_radiobutton3_hebergement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;

}


int decision;


void
on_naim_bouraoui_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget* windowOK;
FILE *d=NULL;
d=fopen("suppression.txt","w");
GtkTreeIter iter;
	gint mois;
	gint jour;
	gchar* boisson;
	gchar* produit;
	gchar* vienoiserie;
	gchar* entreedej;
	gchar* platdej;
	gchar* dessertdej;
	gchar* entreedin;
	gchar* platdin;
	gchar* dessertdin;
	menu menu;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter ,0,&mois,1,&jour,2,&boisson,3,&produit,     4,&vienoiserie,5,&entreedej,6,&platdej,7,&dessertdej,8,&entreedin,9,&platdin,10,&dessertdin,-1);
	menu.mois=mois;
	menu.jour=jour;
	if(d!=NULL)
	{
	fprintf(d,"%d %d",menu.mois,menu.jour);
	fclose(d);
	}
	windowOK=create_naim_bouraoui_confirmation();
	gtk_widget_show(windowOK);	
}
}

void
on_button_ajouter_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowMenu,*fenetre_gestion;
windowMenu=create_naim_bouraoui_ajout_menu();
fenetre_gestion=lookup_widget(objet_graphique,"naim_bouraoui_gestion_des_menus");
gtk_widget_show (windowMenu);
gtk_widget_hide(fenetre_gestion);
}


void
on_button_modif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget * windowModif,*fenetre_gestion;
GtkWidget * windowMenu,* window_afficher,* treeview,* mois1,* jour1,* boiss,* fenetre_afficher,
* produits,* vien,* entreepd,* platpd,* desspd,* entreed,* platd
,* dessd;
fenetre_afficher=lookup_widget(objet_graphique,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");
GtkTreeSelection *selection;
GtkTreeIter iter;
	gint mois;
	gint jour;
	gchar* boisson;
	gchar* produit;
	gchar* vienoiserie;
	gchar* entreedej;
	gchar* platdej;
	gchar* dessertdej;
	gchar* entreedin;
	gchar* platdin;
	gchar* dessertdin;
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	GtkTreeModel* model;
	if (gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	gtk_tree_model_get(model,&iter,0,&mois,1,&jour,2,&boisson,3,&produit,4,&vienoiserie,	5,&entreedej,6,&platdej,7,&dessertdej,8,&entreedin,9,&platdin,10,&dessertdin,-1);
	windowModif=create_naim_bouraoui_modif_menu();
	gtk_widget_show (windowModif);

	mois1=lookup_widget(windowModif,"naim_bouraoui_spin");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois1),mois);

	jour1=lookup_widget(windowModif,"naim_bouraoui_spin1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour1),jour);

	boiss=lookup_widget(windowModif,"naim_bouraoui_boisson1");
	gtk_entry_set_text(GTK_ENTRY(boiss),boisson);

	produits=lookup_widget(windowModif,"naim_bouraoui_produit1");
	gtk_entry_set_text(GTK_ENTRY(produits),produit);

	vien=lookup_widget(windowModif,"naim_bouraoui_vienoi1");
	gtk_entry_set_text(GTK_ENTRY(vien),vienoiserie);

	entreepd=lookup_widget(windowModif,"naim_bouraoui_entreedej1");
	gtk_entry_set_text(GTK_ENTRY(entreepd),entreedej);

	platpd=lookup_widget(windowModif,"naim_bouraoui_platdej1");
	gtk_entry_set_text(GTK_ENTRY(platpd),platdej);

	desspd=lookup_widget(windowModif,"naim_bouraoui_dessdej1");
	gtk_entry_set_text(GTK_ENTRY(desspd),dessertdej);
	
	entreed=lookup_widget(windowModif,"naim_bouraoui_entreedin1");
	gtk_entry_set_text(GTK_ENTRY(entreed),entreedin);
	
	platd=lookup_widget(windowModif,"naim_bouraoui_platdin1");
	gtk_entry_set_text(GTK_ENTRY(platd),platdin);

	dessd=lookup_widget(windowModif,"naim_bouraoui_dessdin1");
	gtk_entry_set_text(GTK_ENTRY(dessd),dessertdin);
	}
gtk_widget_hide(fenetre_afficher);
}


void
on_button_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mois1 ,*jour1, *windowOK;
menu menu;
FILE *d=NULL;
d=fopen("suppression.txt","w");
mois1=lookup_widget(button,"naim_bouraoui_spinbuttonM1");
jour1=lookup_widget(button,"naim_bouraoui_spinbuttonM2");
menu.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
menu.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
if(d!=NULL)
{
fprintf(d,"%d %d",menu.mois,menu.jour);
fclose(d);
}
windowOK=create_naim_bouraoui_confirmation();
gtk_widget_show(windowOK);
}


void
on_button_rechercher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
menu menu;
int trouvee;
GtkWidget *fenetre_afficher, *treeview, *mois2, *jour2,*fenetre_erreur;
fenetre_erreur=create_naim_bouraoui_erreur_recherche();
mois2=lookup_widget(button,"naim_bouraoui_spinbuttonM1");
jour2=lookup_widget(button,"naim_bouraoui_spinbuttonM2");
menu.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
menu.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
fenetre_afficher=lookup_widget(button,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");
trouvee=trouve(menu);
if(trouvee==1){
chercher(menu,treeview);}
else{
gtk_widget_show(fenetre_erreur);}
}


void
on_naim_bouraoui_checkbuttons_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
decision=3;
}


void
on_naim_bouraoui_checkbuttonT_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
decision=2;
}


void
on_naim_bouraoui_Afficher_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *fenetre_mode, *fenetre_afficher, *combobox;
int numsemaine;
fenetre_afficher=lookup_widget(objet,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");

combobox=lookup_widget(objet,"naim_bouraoui_combobox");
if(decision==3)
{
if(strcmp("",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=10;
if(strcmp("Semaine 1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=1;
else if (strcmp("Semaine 2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=2;
else if (strcmp("Semaine 3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=3;
else 
  numsemaine=4;
afficher(numsemaine,treeview);
}
if (decision==2)
{
affichage(treeview);
}
}


void
on_button_valider_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int trouvee;
menu semaine1;
GtkWidget *fenetre_erreur,*mois1, *jour1, *boiss, *produits, *vien, *entreepd, *platpd, *desspd, *entreed, *platd, *dessd;
fenetre_erreur=create_naim_bouraoui_erreur();
mois1=lookup_widget(objet_graphique,"naim_bouraoui_mois");
jour1=lookup_widget(objet_graphique,"naim_bouraoui_jour");
boiss=lookup_widget(objet_graphique,"naim_bouraoui_boisson");
produits=lookup_widget(objet_graphique,"naim_bouraoui_cerealier");
vien=lookup_widget(objet_graphique,"naim_bouraoui_vienoiserie");
entreepd=lookup_widget(objet_graphique,"naim_bouraoui_entreedej");
platpd=lookup_widget(objet_graphique,"naim_bouraoui_platdej");
desspd=lookup_widget(objet_graphique,"naim_bouraoui_dessertdej");
entreed=lookup_widget(objet_graphique,"naim_bouraoui_entreedin");
platd=lookup_widget(objet_graphique,"naim_bouraoui_platdin");
dessd=lookup_widget(objet_graphique,"naim_bouraoui_dessertdin");
semaine1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
semaine1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
strcpy(semaine1.petit_dej.boisson,gtk_entry_get_text(GTK_ENTRY(boiss)));
strcpy(semaine1.petit_dej.produit_cerealier,gtk_entry_get_text(GTK_ENTRY(produits)));
strcpy(semaine1.petit_dej.vienoiserie,gtk_entry_get_text(GTK_ENTRY(vien)));
strcpy(semaine1.dejeuner.entree,gtk_entry_get_text(GTK_ENTRY(entreepd)));
strcpy(semaine1.dejeuner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platpd)));
strcpy(semaine1.dejeuner.dessert,gtk_entry_get_text(GTK_ENTRY(desspd)));
strcpy(semaine1.diner.entree,gtk_entry_get_text(GTK_ENTRY(entreed)));
strcpy(semaine1.diner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platd)));
strcpy(semaine1.diner.dessert,gtk_entry_get_text(GTK_ENTRY(dessd)));
trouvee=trouve(semaine1);
if(trouvee==0){
ajouter(semaine1);
}
else{
gtk_widget_show(fenetre_erreur);
}
}

void
on_naim_bouraoui_radiobutton_supprimer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
decision=1;
}


void
on_naim_bouraoui_radiobutton_annuler_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
decision=0;
}


void
on_naim_bouraoui_ok_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_confirmation;
menu menu;
FILE *f=NULL;
f=fopen("suppression.txt","r");
if(f!=NULL)
{
fscanf(f,"%d %d",&menu.mois,&menu.jour);
fclose(f);
}
else 
printf("file not found");
fenetre_confirmation=lookup_widget(objet_graphique,"naim_bouraoui_confirmation");
if(decision==1)
{
supprimer(menu);
gtk_widget_destroy(fenetre_confirmation);
}
else if(decision==0)
gtk_widget_destroy(fenetre_confirmation);
}


void
on_naim_bouraoui_modifier2_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
menu semaine1;
GtkWidget *mois1, *jour1, *boiss, *produits, *vien, *entreepd, *platpd, *desspd, *entreed, *platd, *dessd;
mois1=lookup_widget(objet_graphique,"naim_bouraoui_spin");
jour1=lookup_widget(objet_graphique,"naim_bouraoui_spin1");
boiss=lookup_widget(objet_graphique,"naim_bouraoui_boisson1");
produits=lookup_widget(objet_graphique,"naim_bouraoui_produit1");
vien=lookup_widget(objet_graphique,"naim_bouraoui_vienoi1");
entreepd=lookup_widget(objet_graphique,"naim_bouraoui_entreedej1");
platpd=lookup_widget(objet_graphique,"naim_bouraoui_platdej1");
desspd=lookup_widget(objet_graphique,"naim_bouraoui_dessdej1");
entreed=lookup_widget(objet_graphique,"naim_bouraoui_entreedin1");
platd=lookup_widget(objet_graphique,"naim_bouraoui_platdin1");
dessd=lookup_widget(objet_graphique,"naim_bouraoui_dessdin1");

semaine1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
semaine1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
strcpy(semaine1.petit_dej.boisson,gtk_entry_get_text(GTK_ENTRY(boiss)));
strcpy(semaine1.petit_dej.produit_cerealier,gtk_entry_get_text(GTK_ENTRY(produits)));
strcpy(semaine1.petit_dej.vienoiserie,gtk_entry_get_text(GTK_ENTRY(vien)));
strcpy(semaine1.dejeuner.entree,gtk_entry_get_text(GTK_ENTRY(entreepd)));
strcpy(semaine1.dejeuner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platpd)));
strcpy(semaine1.dejeuner.dessert,gtk_entry_get_text(GTK_ENTRY(desspd)));
strcpy(semaine1.diner.entree,gtk_entry_get_text(GTK_ENTRY(entreed)));
strcpy(semaine1.diner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platd)));
strcpy(semaine1.diner.dessert,gtk_entry_get_text(GTK_ENTRY(dessd)));
modifier(semaine1);
}



void
on_naim_bouraoui_erreur1_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_erreur;
fenetre_erreur=lookup_widget(objet_graphique,"naim_bouraoui_erreur");
gtk_widget_destroy(fenetre_erreur);
}





void
on_naim_bouraoui_actualiser_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1,*treeview;
w1=lookup_widget(button,"naim_bouraoui_gestion_des_menus");
fenetre_afficher=create_naim_bouraoui_gestion_des_menus();

gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");
//vider(treeview);
affichage(treeview);
}


void
on_naim_bouraoui_retour_modif_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif,* fenetre_gestion;
fenetre_gestion=create_naim_bouraoui_gestion_des_menus();
fenetre_modif=lookup_widget(button,"naim_bouraoui_modif_menu");
gtk_widget_show(fenetre_gestion);
gtk_widget_hide(fenetre_modif);
}


void
on_naim_bouraoui_erreur_rech_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_erreur;
fenetre_erreur=lookup_widget(button,"naim_bouraoui_erreur_recherche");
gtk_widget_destroy(fenetre_erreur);
}


void
on_naim_bouraoui_retou_ajout_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout,* fenetre_gestion;
fenetre_gestion=create_naim_bouraoui_gestion_des_menus();
fenetre_ajout=lookup_widget(button,"naim_bouraoui_ajout_menu");
gtk_widget_show(fenetre_gestion);
gtk_widget_hide(fenetre_ajout);
}




void
on_naim_bouraoui_boutton_ret_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}

