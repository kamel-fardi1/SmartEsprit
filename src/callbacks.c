#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"capteur.h"
#include "etudiant.h"
#include <time.h>
int pisc=0;
int restau=0;
int s;
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
    case 4:
    gtk_widget_hide (authentification);
    w = create_Med_kh_w_Menu ();
    gtk_widget_show (w);
    break;
  default:
    break;
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
{
  GtkWidget *admin;
  GtkWidget *w;

    admin = lookup_widget(button, "admin");
    gtk_widget_hide (admin);
    w = create_Med_kh_w_Menu ();
    gtk_widget_show (w);

}


void
on_kamel_fardi_gestion_de_stock_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_kamel_fardi_Gestion_des_reclamations_hebergee_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

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
{
GtkWidget *w_Ajouter,*confirme;
	GtkTreeIter iter;
	char *fich="capteurs.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	confirme=create_Med_kh_confirme();
	gtk_widget_show (confirme);
}


void
on_mk_dash_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *kamel_fardi_dash_board_window,*mk_dash_combobox;
   GtkWidget *mk_dash_treeview;
   char *file="temperature.txt";
   char chaine[100];
   char E;
mk_dash_treeview=lookup_widget(button,"mk_dash_treeview");
mk_dash_combobox=lookup_widget(button,"mk_dash_combobox");
strcpy(chaine,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mk_dash_combobox)));
E=chaine[0];
cap_defecteux(mk_dash_treeview,E,file);
}
void
on_Med_kh_button1_Ajouter_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
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
    gtk_widget_hide (ajout);

}


void
on_Med_kh_checkbutton_e1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=1;
}


void
on_Med_kh_checkbutton_e2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=2;
}


void
on_Med_kh_checkbutton_e3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=3;
}


void
on_Med_kh_bouton_modifier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
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
	gtk_widget_hide (modif);

}


void
on_Med_kh_checkbutton_e6_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=3;
}


void
on_Med_kh_checkbutton_e5_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=2;
}


void
on_Med_kh_checkbutton_e4_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton));
	s=1;
}


void
on_Med_kh_Ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *Ajouter;

Ajouter=lookup_widget(objet,"Med_kh_w_Ajouter");
Ajouter=create_Med_kh_w_Ajouter();

gtk_widget_show(Ajouter);

}

void
on_Med_kh_Supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *aff;
GtkWidget *tree;
//aff=lookup_widget(objet,"w_aff_supp");


//Menu=lookup_widget(objet,"Med_kh_w_Menu");
aff = create_Med_kh_w_aff_supp ();


//tree=lookup_widget(aff,"Med_kh_treeview1");
//afficher_capteur(tree);
gtk_widget_show (aff);
//gtk_widget_hide(Menu);
}


void
on_Med_kh_button_CF_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
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
 
   
}


void
on_Med_kh_Rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
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
  gtk_widget_show (rechercher);
  
}


void
on_Med_kh_treeview3_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkWidget *def;
	GtkTreeIter iter;
	char *fich="temperature.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	def=create_Med_kh_windowC_f();
	gtk_widget_show (def);
}



void
on_Med_kh_treeview1_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkWidget *w_Ajouter,*confirme;
	GtkTreeIter iter;
	char *fich="capteurs.txt";
		

	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cap.ref,1,&cap.type,2,&cap.V_Max,3,&cap.V_Min,4,&cap.dt.jour,5,&cap.dt.mois,6,&cap.dt.annee,7,&cap.Emplacement,-1);
	}
	confirme=create_Med_kh_confirme();
	gtk_widget_show (confirme);
}


void
on_Med_kh_Act_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *act;
GtkWidget *aff;
GtkWidget *tree;
//aff=lookup_widget(objet,"w_aff_supp");


act=lookup_widget(objet,"Med_kh_Act");
tree=lookup_widget(objet,"Med_kh_treeview1");
afficher_capteur(tree);
}


void
on_Med_kh_modif_conf_button_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
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


   

  gtk_spin_button_set_value(GTK_SPIN_BUTTON(ref),cap.ref);

  //strcpy(cap.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

   gtk_spin_button_set_value(GTK_SPIN_BUTTON(V_Max),cap.V_Max);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(V_Min),cap.V_Min);


   gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),cap.dt.jour);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),cap.dt.mois);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),cap.dt.annee);
	gtk_widget_hide (confirme);
	//gtk_widget_hide (aff);
	gtk_widget_show (modif);
}


void
on_Med_kh_supp_confirme_button_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *confirme;
GtkWidget *aff;
GtkWidget *tree;

confirme=lookup_widget(objet,"Med_kh_confirme");
supprimer(cap.ref);
gtk_widget_hide (confirme);
}


void
on_Med_kh_button_retour2_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *windowC_f;
 windowC_f=lookup_widget(objet,"Med_kh_windowC_f");
 gtk_widget_destroy(windowC_f);
}


void
on_Med_kh_button_retour1_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *w_Rechercher;
 w_Rechercher=lookup_widget(objet,"Med_kh_w_Rechercher");
 gtk_widget_destroy(w_Rechercher);
}


void
on_Med_kh_button_retour0_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *w_aff_supp;
 w_aff_supp=lookup_widget(objet,"Med_kh_w_aff_supp");
 gtk_widget_destroy(w_aff_supp);
}

