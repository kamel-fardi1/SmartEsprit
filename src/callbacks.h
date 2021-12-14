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
////////////////////////////tesnime////////////////////////////////////////////
void
on_button3_tessnime_affichage_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_tesnim_affichage_ajouter_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_tesnime_affichage_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_tesnime_affichage_rechercher_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_tesnime_afficher__clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_tes_ajouter_retrait_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_tes_ajout_depot_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);



void
on_button7_tesnim_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data);

/*void
on_button6_tesnim_ajouter_valider_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_radiobutton3_tes_modif_depot_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton4_tes_modif_retrait_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_valider_tes_modiffier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_retour_tes_modifier_clicked (GtkButton       *button,
                                        gpointer         user_data);



void
on_radiobutton1_tes_ajout_depot_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_tes_ajouter_retrait_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button6_tesnim_ajouter_valider_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_tesnime_treeview_row1_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_button6_tesnim_ajouter_valider_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
void
on_ts_deconnect_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssemkh_treeview1_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_houssemkh_button6_aficher_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_buttonbaby44_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_button2_ajout_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_leplusreclamer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_houssem_button4_mod_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_button5_rech_clicked        (GtkWidget       *objet_graphique,gpointer  user_data);

void
on_alignment4_check_resize             (GtkContainer    *container,
                                        gpointer         user_data);

void
on_houssemkh_button_ajout_rasmi_clicked
                                        (GtkWidget       *objet_graphique,gpointer  user_data);

void
on_houssemkh_radiobutton3_hebergement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_houssem_radiobutton1_restauration_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_houssemkh_button7_confirmer_desuprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_ssa_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_yess_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_houssemkh_modification23_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_boutonderecuperationhoussem_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssemkh_bouton_de_tache2_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_kharroubi_bouton_error_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssemkh_bouton_fermer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_houssem_radiobutton1_restauration_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_houssemkh_radiobutton3_hebergement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
