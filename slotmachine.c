#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

const char *symbols[] = {"🥦", "🍋", "🍊", "🍍", "🍈", "⭐"};
#define SYMBOL_COUNT (sizeof(symbols) / sizeof(symbols[0]))

GtkWidget *slot_labels[ROWS][COLS];
GtkWidget *double_labels[ROWS];  // Array for double display labels
GtkWidget *info_label;            // Label to display total winnings
double total_winnings = 100.00;      // Variable to track total winnings

// Rigging the Game with a Bonus Score
double bonus_score = 0;
double broccoli_win_rig = 0.50;
double lemon_bonus = 1;
double orange_bonus = 2;
double pineapple_bonus = 4;
double melon_bonus = 8;
double star_bonus = 16;


// Adjust the Winnings
double lemon_base = 0.25;
double orange_base = 0.50;
double pineapple_base = 1.00;
double melon_base = 2.00;
double star_base = 4.00;

// Function to update the slots with random symbols
void spin_slots() {
    if (total_winnings < 0.25) {
        // Display total winnings in the info label
        char info_text[50];
        snprintf(info_text, sizeof(info_text), "ERROR BALANCE: %.2f", total_winnings);
        gtk_label_set_text(GTK_LABEL(info_label), info_text);
        return;
    }
    else {
        total_winnings = (total_winnings - 0.25);
        // Display total winnings in the info label
        char info_text[50];
        snprintf(info_text, sizeof(info_text), "Total winnings: %.2f", total_winnings);
        gtk_label_set_text(GTK_LABEL(info_label), info_text);
    }

    for (int i = 0; i < ROWS; i++) {
        // Resets the score tally when going to a new row
        int lemon_score = 0;
        int orange_score = 0;
        int pineapple_score = 0;
        int melon_score = 0;
        int star_score = 0;

        for (int j = 0; j < COLS; j++) {
            if (bonus_score > 100) {
                bonus_score = 100;
            }
            if (bonus_score < 0) {
                bonus_score = 0;
            }
            double number_calc = rand() % 1000000 +1;
            number_calc = number_calc - (bonus_score * 10000); // Adds a bit of rigging when losing/winning too muchooooooooooooo
            int rand_symbol = 0;
            if ( number_calc > 500000 ) {
                rand_symbol = 0;
                printf("Got a broccoli with: %.2f", number_calc);
            }
            else if ( number_calc > 250000 ) {
                rand_symbol = 1;
                printf("Got a lemon with: %.2f", number_calc);
                lemon_score++;
                // printf("Score for lemon: %d\n", lemon_score);
            }
            else if ( number_calc > 125000 ) {
                rand_symbol = 2;
                printf("Got a orange with: %.2f", number_calc);
                orange_score++;
                // printf("Score for orange: %d\n", orange_score);
            }
            else if ( number_calc > 62500 ) {
                rand_symbol = 3;
                printf("Got a pineapple with: %.2f", number_calc);
                pineapple_score++;
                // printf("Score for pineapple: %d\n", pineapple_score);
            }
            else if ( number_calc >  18800) {
                rand_symbol = 4;
                printf("Got a melon with: %.2f", number_calc);
                melon_score++;
                // printf("Score for melon: %d\n", melon_score);
            }
            else {
                rand_symbol = 5;
                printf("Got a star with: %.2f", number_calc);
                star_score++;
                // printf("Score for star: %d\n", star_score);
            }
            gtk_label_set_text(GTK_LABEL(slot_labels[i][j]), symbols[rand_symbol]);
        }

        // Displays the score.
        if (lemon_score > 2) {
            if (lemon_score > 3) {
                if (lemon_score > 4){
                    // slot_labels[i][COLS] = "+$.75"; // Didn't work
                    gchar *text = g_strdup_printf("%.2f", 4.00 * lemon_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (4.00 * lemon_base));
                    bonus_score = bonus_score - (4 * lemon_bonus);
                    printf("Score for lemons: %d\n", lemon_score);
                    g_free(text); 
                }
                else {
                    //slot_labels[i][COLS] = "+$.50";
                    gchar *text = g_strdup_printf("%.2f", 2.00 * lemon_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (2.00 * lemon_base));
                    bonus_score = bonus_score - (2 * lemon_bonus);
                    printf("Score for lemons: %d\n", lemon_score);
                    g_free(text); 
                }
            }
            else {
                // slot_labels[i][COLS] = "+$.25";
                gchar *text = g_strdup_printf("%.2f", lemon_base);
                gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                total_winnings = (total_winnings + lemon_base);
                bonus_score = bonus_score - lemon_bonus;
                printf("Score for lemons: %d\n", lemon_score);
                g_free(text);
            }
        }
        else if (orange_score > 2) {
            if (orange_score > 3) {
                if (orange_score > 4){
                    // slot_labels[i][COLS] = "+$1.50";
                    gchar *text = g_strdup_printf("%.2f", 4.00 * orange_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (4.00 * orange_base));
                    bonus_score = bonus_score - (4 * orange_bonus);
                    printf("Score for orange: %d\n", orange_score);
                    g_free(text);
                }
                else {
                    // slot_labels[i][COLS] = "+$1.25";
                    gchar *text = g_strdup_printf("%.2f", 2.00 * orange_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (2.00 * orange_base));
                    bonus_score = bonus_score - (2 * orange_bonus);
                    printf("Score for orange: %d\n", orange_score);
                    g_free(text);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$1.00";
                gchar *text = g_strdup_printf("%.2f", orange_base);
                gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                total_winnings = (total_winnings + orange_base);
                bonus_score = bonus_score - orange_bonus;
                printf("Score for orange: %d\n", orange_score);
                g_free(text);
            }
        }
        else if (pineapple_score > 2) {
            if (pineapple_score > 3) {
                if (pineapple_score > 4){
                    // slot_labels[i][COLS] = "+$2.25";
                    gchar *text = g_strdup_printf("%.2f", 4.00 * pineapple_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (4 * pineapple_base));
                    bonus_score = bonus_score - (4 * pineapple_bonus);
                    printf("Score for pineapple: %d\n", pineapple_score);
                    g_free(text);
                }
                else {
                    // slot_labels[i][COLS] = "+$2.00";
                    gchar *text = g_strdup_printf("%.2f", 2.00 * pineapple_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (2 * pineapple_base));
                    bonus_score = bonus_score - (2 * pineapple_bonus);
                    printf("Score for pineapple: %d\n", pineapple_score);
                    g_free(text);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$1.75";
                gchar *text = g_strdup_printf("%.2f", pineapple_base);
                gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                total_winnings = (total_winnings + pineapple_bonus);
                bonus_score = bonus_score - pineapple_base;
                printf("Score for pineapple: %d\n", pineapple_score);
                g_free(text);
            }
        }
        else if (melon_score > 2) {
            if (melon_score > 3) {
                if (melon_score > 4){
                    // slot_labels[i][COLS] = "+$3.00";
                    gchar *text = g_strdup_printf("%.2f", 4.00 * melon_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (4.00 * melon_base));
                    bonus_score = bonus_score - (4 * melon_bonus);
                    printf("Score for melon: %d\n", melon_score);
                    g_free(text);
                }
                else {
                    // slot_labels[i][COLS] = "+$2.75";
                    gchar *text = g_strdup_printf("%.2f", 2.00 * melon_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (2.00 * melon_base));
                    bonus_score = bonus_score - (2 * melon_bonus);
                    printf("Score for melon: %d\n", melon_score);
                    g_free(text);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$2.50";
                gchar *text = g_strdup_printf("%.2f", melon_base);
                gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                total_winnings = (total_winnings + melon_base);
                bonus_score = bonus_score - melon_bonus;
                printf("Score for melon: %d\n", melon_score);
                g_free(text);
            }
        }
        else if (star_score > 2) {
            if (star_score > 3) {
                if (star_score > 4){
                    // slot_labels[i][COLS] = "+$3.75";
                    gchar *text = g_strdup_printf("%.2f", 4.00 * star_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (4.00 * star_base));
                    bonus_score = bonus_score - (4 * star_bonus);
                    printf("Score for star: %d\n", star_score);
                    g_free(text);
                }
                else {
                    // slot_labels[i][COLS] = "+$3.50";
                    gchar *text = g_strdup_printf("%.2f", 2.00 * star_base);
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                    total_winnings = (total_winnings + (2.00 * star_base));
                    bonus_score = bonus_score - (2 * star_bonus);
                    printf("Score for star: %d\n", star_score);
                    g_free(text);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$3.25";
                gchar *text = g_strdup_printf("%.2f", star_base);
                gtk_label_set_text(GTK_LABEL(double_labels[i]), text);
                total_winnings = (total_winnings + star_base);
                bonus_score = bonus_score - star_bonus;
                printf("Score for star: %d\n", star_score);
                g_free(text);
            }
        }
        else {
            // slot_labels[i][COLS] = "$0";
            gtk_label_set_text(GTK_LABEL(double_labels[i]), "0");
            bonus_score = bonus_score + broccoli_win_rig;
            printf("No score for row: %d\n", i);
        }
    }

    printf("Total Money note: %.2f\n", total_winnings);
    printf("Rigged Score: %.2f\n", bonus_score);

    // Display total winnings in the info label
    char info_text[50];
    snprintf(info_text, sizeof(info_text), "Total winnings: %.2f", total_winnings);
    gtk_label_set_text(GTK_LABEL(info_label), info_text);
}

// Function to adjust font size based on window dimensions and DPI
void adjust_font_size(GtkWidget *widget, GtkAllocation *allocation, gpointer data) {
    int width = allocation->width;
    int height = allocation->height;

    // Get the screen's DPI
    GdkScreen *screen = gtk_widget_get_screen(widget);
    double dpi = gdk_screen_get_resolution(screen);

    // Set a scaling factor for high-DPI screens
    double scale_factor = dpi > 96 ? dpi / 96.0 : 1.0;

    // Base font size calculation (scaled by DPI factor for higher resolution screens)
    int font_size = ((width / COLS + height / ROWS) / 4) * scale_factor;

    // Create a PangoAttributeList and add a size attribute
    PangoAttrList *attr_list = pango_attr_list_new();
    PangoAttribute *attr_size = pango_attr_size_new(font_size * PANGO_SCALE);
    pango_attr_list_insert(attr_list, attr_size);

    // Update each label's font attributes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gtk_label_set_attributes(GTK_LABEL(slot_labels[i][j]), attr_list);
        }
    }

    // Unreference the attribute list to avoid memory leaks
    pango_attr_list_unref(attr_list);
}

// Callback for the "Spin" button click
void on_spin_button_clicked(GtkWidget *widget, gpointer data) {
    spin_slots();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    srand(time(NULL));

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Slot Machine");
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Set window to fullscreen
    gtk_window_fullscreen(GTK_WINDOW(window));

    // Connect size-allocate signal to dynamically adjust font size
    g_signal_connect(window, "size-allocate", G_CALLBACK(adjust_font_size), NULL);

    // Create a vertical box layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            GtkWidget *label = gtk_label_new("❓");
            gtk_widget_set_hexpand(label, TRUE);
            gtk_widget_set_vexpand(label, TRUE);
            gtk_label_set_xalign(GTK_LABEL(label), 0.5);
            gtk_label_set_yalign(GTK_LABEL(label), 0.5);
            gtk_grid_attach(GTK_GRID(grid), label, j, i, 1, 1);
            slot_labels[i][j] = label;
        }

        // Add double label in the sixth column
        GtkWidget *double_label = gtk_label_new("0.00");
        gtk_widget_set_hexpand(double_label, TRUE);
        gtk_widget_set_vexpand(double_label, TRUE);
        gtk_label_set_xalign(GTK_LABEL(double_label), 0.5);
        gtk_label_set_yalign(GTK_LABEL(double_label), 0.5);
        gtk_grid_attach(GTK_GRID(grid), double_label, COLS, i, 1, 1);
        double_labels[i] = double_label;
    }

    // Create a horizontal box for the split "Spin" button and info display
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    // Left side: Spin button
    GtkWidget *spin_button = gtk_button_new_with_label("Spin");
    gtk_widget_set_size_request(spin_button, 80, 40);
    g_signal_connect(spin_button, "clicked", G_CALLBACK(on_spin_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), spin_button, TRUE, TRUE, 0);

    // Right side: Label to display spin count
    info_label = gtk_label_new("Credit: 10.00");
    gtk_widget_set_size_request(info_label, 80, 40);
    gtk_box_pack_start(GTK_BOX(hbox), info_label, TRUE, TRUE, 0);

    // Initialize the total winnings label with the current value
    char info_text[50];
    snprintf(info_text, sizeof(info_text), "Credit: %.2f", total_winnings);
    gtk_label_set_text(GTK_LABEL(info_label), info_text);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
