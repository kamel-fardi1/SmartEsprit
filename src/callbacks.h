#include <gtk/gtk.h>


void
on_kamel_fardi_authen_wind_login_auth_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_authen_wind_quitter_auth_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_empl_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_admin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_es_admin_supprimer_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_es_admin_liste_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_es_admin_chercher_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_ajouter_res_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_role_admin_window_combobox_editing_done
                                        (GtkCellEditable *celleditable,
                                        gpointer         user_data);

void
on_kamel_fardi_logout_admin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_Gestion_des_etudiants_hebergee_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_gestion_des_menus_de_la_semaine_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_Gestion_des_capteurs_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_gestion_de_stock_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_Gestion_des_reclamations_hebergee_admin_window_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_window_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_window_modif_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_window_supp_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_ajout_window_ajouter_cin_entry_editing_done
                                        (GtkCellEditable *celleditable,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_gestion_etudiants_ajouter_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_gestion_etudiants_annuler_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_gestion_etudiants_filechooserbutton_file_set
                                        (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_kamel_fardi_ajout_window_ajouter_m_radiob_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_ajout_window_ajouter_f_radiob_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_ajouter_restaurant_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_ajouter_piscine_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_etudiant_gestion_etudiants_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_ajout_window_retour_buttonbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_piscine_checkbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_ajouter_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_annuler_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_filechooserbutton_file_set
                                        (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_female_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_male_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_restaurant_checkbutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_modifier_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_affichage_liste_etudiant_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_kamel_fardi_afficher_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_afficher_ajouter_etd_buttonbutton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_afficher_chercher_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_ajout_hint_fixed_retour_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_rechercher_faild_fixed_ok_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_dash_board_fixed_espaceadmin_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_dash_board_fixed_logout_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

//void
//on_nombreetudiant_clicked              (GtkWidget       *button,
 //                                       gpointer         user_data);

void
on_kamel_fardi_dash_board_fixed_logout_button_nombreetudiant_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_kamel_fardi_bien_ajoutee_ok_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);
/////////////;ohamed khoualdia/////////////////////////////////////////////
void
on_mk_dash_treeview_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_mk_dash_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data);
void
on_Med_kh_checkbutton_e1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_checkbutton_e2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_checkbutton_e3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_button1_Ajouter_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_bouton_modifier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_checkbutton_e6_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_checkbutton_e5_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_checkbutton_e4_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Med_kh_Ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_Supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_button_CF_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Med_kh_Rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Med_kh_treeview3_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Med_kh_button_conf_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_treeview1_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Med_kh_Act_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_modif_conf_button_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Med_kh_supp_confirme_button_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_button_retour2_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_button_retour1_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Med_kh_button_retour0_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);
