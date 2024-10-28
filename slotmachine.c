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
double total_winnings = 10.0;      // Variable to track total winnings


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
            int number_calc = rand() % 1000 +1;
            int rand_symbol = 0;
            if ( number_calc > 460 ) {
                rand_symbol = 0;
                printf("Got a broccoli with: %d\n", number_calc);
            }
            else if ( number_calc > 220 ) {
                rand_symbol = 1;
                printf("Got a lemon with: %d\n", number_calc);
                lemon_score++;
                // printf("Score for lemon: %d\n", lemon_score);
            }
            else if ( number_calc > 100 ) {
                rand_symbol = 2;
                printf("Got a orange with: %d\n", number_calc);
                orange_score++;
                // printf("Score for orange: %d\n", orange_score);
            }
            else if ( number_calc > 50 ) {
                rand_symbol = 3;
                printf("Got a pineapple with: %d\n", number_calc);
                pineapple_score++;
                // printf("Score for pineapple: %d\n", pineapple_score);
            }
            else if ( number_calc > 30 ) {
                rand_symbol = 4;
                printf("Got a melon with: %d\n", number_calc);
                melon_score++;
                // printf("Score for melon: %d\n", melon_score);
            }
            else {
                rand_symbol = 5;
                printf("Got a star with: %d\n", number_calc);
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
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "1.00");
                    total_winnings = (total_winnings + 1.00);
                    printf("Score for lemons: %d\n", lemon_score);
                }
                else {
                    //slot_labels[i][COLS] = "+$.50";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "0.50");
                    total_winnings = (total_winnings + 0.50);
                    printf("Score for lemons: %d\n", lemon_score);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$.25";
                gtk_label_set_text(GTK_LABEL(double_labels[i]), "0.25");
                total_winnings = (total_winnings + 0.25);
                printf("Score for lemons: %d\n", lemon_score);
            }
        }
        else if (orange_score > 2) {
            if (orange_score > 3) {
                if (orange_score > 4){
                    // slot_labels[i][COLS] = "+$1.50";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "4.00");
                    total_winnings = (total_winnings + 4.00);
                    printf("Score for orange: %d\n", orange_score);
                }
                else {
                    // slot_labels[i][COLS] = "+$1.25";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "2.00");
                    total_winnings = (total_winnings + 2.00);
                    printf("Score for orange: %d\n", orange_score);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$1.00";
                gtk_label_set_text(GTK_LABEL(double_labels[i]), "1.00");
                total_winnings = (total_winnings + 1.00);
                printf("Score for orange: %d\n", orange_score);
            }
        }
        else if (pineapple_score > 2) {
            if (pineapple_score > 3) {
                if (pineapple_score > 4){
                    // slot_labels[i][COLS] = "+$2.25";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "8.00");
                    total_winnings = (total_winnings + 8.00);
                    printf("Score for pineapple: %d\n", pineapple_score);
                }
                else {
                    // slot_labels[i][COLS] = "+$2.00";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "4.00");
                    total_winnings = (total_winnings + 4.00);
                    printf("Score for pineapple: %d\n", pineapple_score);
                }
            }
            else {
            // slot_labels[i][COLS] = "+$1.75";
            gtk_label_set_text(GTK_LABEL(double_labels[i]), "2.00");
            total_winnings = (total_winnings + 2.00);
            printf("Score for pineapple: %d\n", pineapple_score);
            }
        }
        else if (melon_score > 2) {
            if (melon_score > 3) {
                if (melon_score > 4){
                    // slot_labels[i][COLS] = "+$3.00";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "16.00");
                    total_winnings = (total_winnings + 16.00);
                    printf("Score for melon: %d\n", melon_score);
                }
                else {
                    // slot_labels[i][COLS] = "+$2.75";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "8.00");
                    total_winnings = (total_winnings + 8.00);
                    printf("Score for melon: %d\n", melon_score);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$2.50";
                gtk_label_set_text(GTK_LABEL(double_labels[i]), "4.00");
                total_winnings = (total_winnings + 4.00);
                printf("Score for melon: %d\n", melon_score);
            }
        }
        else if (star_score > 2) {
            if (star_score > 3) {
                if (star_score > 4){
                    // slot_labels[i][COLS] = "+$3.75";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "32.00");
                    total_winnings = (total_winnings + 32.00);
                    printf("Score for star: %d\n", star_score);
                }
                else {
                    // slot_labels[i][COLS] = "+$3.50";
                    gtk_label_set_text(GTK_LABEL(double_labels[i]), "16.00");
                    total_winnings = (total_winnings + 16.00);
                    printf("Score for star: %d\n", star_score);
                }
            }
            else {
                // slot_labels[i][COLS] = "+$3.25";
                gtk_label_set_text(GTK_LABEL(double_labels[i]), "8.00");
                total_winnings = (total_winnings + 8.00);
                printf("Score for star: %d\n", star_score);
            }
        }
        else {
            // slot_labels[i][COLS] = "$0";
            gtk_label_set_text(GTK_LABEL(double_labels[i]), "0");
            printf("No score for row: %d\n", i);
        }
    }

    printf("Total Money: %.2f\n", total_winnings);

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
