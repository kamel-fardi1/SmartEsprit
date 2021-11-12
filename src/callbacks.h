#include <gtk/gtk.h>


void
on_login_auth_button_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_empl_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimer_empl_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_empl_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_empl_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_logout_admin_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_admin_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_liste_empl_button_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_win_refresh_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_filechooser_file_set        (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_annuler_ajouter_ouvrier_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_ouvrier_button_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_mariee_ouvrier_ajouter_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_celibataire_ouvrier_ajouter_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifier_ouvrier_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_modifier_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_nom_ouvrier_button_entry_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_filechooser_file_set       (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_ouvrier_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_ouvrier_afficher_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficger_ovr_tv_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_suprimer_ouvrier_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);
