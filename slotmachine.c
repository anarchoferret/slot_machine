#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

const char *symbols[] = {"🥦", "🍋", "🍊", "🍍", "🍈", "⭐"};
#define SYMBOL_COUNT (sizeof(symbols) / sizeof(symbols[0]))

GtkWidget *slot_labels[ROWS][COLS];

// Function to update the slots with random symbols
void spin_slots() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int number_calc = rand() % 100;
            int rand_symbol = 0;
            if ( number_calc > 50 ) {
                rand_symbol = 0;
                printf("Random symbol index: %d\n", number_calc);
            }
            else if ( number_calc > 25 ) {
                rand_symbol = 1;
                printf("Random symbol index: %d\n", number_calc);
            }
            else if ( number_calc > 13 ) {
                rand_symbol = 2;
                printf("Random symbol index: %d\n", number_calc);
            }
            else if ( number_calc > 6 ) {
                rand_symbol = 3;
                printf("Random symbol index: %d\n", number_calc);
            }
            else if ( number_calc > 3 ) {
                rand_symbol = 4;
                printf("Random symbol index: %d\n", number_calc);
            }
            else if ( number_calc >= 0 ) {
                rand_symbol = 5;
                printf("Random symbol index: %d\n", number_calc);
            }
            gtk_label_set_text(GTK_LABEL(slot_labels[i][j]), symbols[rand_symbol]);
        }
    }
}

// Function to adjust font size based on window dimensions
void adjust_font_size(GtkWidget *widget, GtkAllocation *allocation, gpointer data) {
    int width = allocation->width;
    int height = allocation->height;

    // Calculate font size relative to window size
    int font_size = (width / COLS + height / ROWS) / 4;

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

    // Connect size-allocate signal to dynamically adjust font size
    g_signal_connect(window, "size-allocate", G_CALLBACK(adjust_font_size), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            GtkWidget *label = gtk_label_new("?");
            gtk_widget_set_hexpand(label, TRUE);
            gtk_widget_set_vexpand(label, TRUE);
            gtk_label_set_xalign(GTK_LABEL(label), 0.5);
            gtk_label_set_yalign(GTK_LABEL(label), 0.5);
            gtk_grid_attach(GTK_GRID(grid), label, j, i, 1, 1);
            slot_labels[i][j] = label;
        }
    }

    GtkWidget *spin_button = gtk_button_new_with_label("Spin");
    gtk_widget_set_size_request(spin_button, 80, 40);
    gtk_box_pack_start(GTK_BOX(vbox), spin_button, FALSE, FALSE, 0);
    g_signal_connect(spin_button, "clicked", G_CALLBACK(on_spin_button_clicked), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}