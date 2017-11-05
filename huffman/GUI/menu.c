#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>


GtkWidget *popup;

G_MODULE_EXPORT void
cb_show_prop( GtkButton *button, GtkWidget *popup ) {
    gtk_window_present( GTK_WINDOW( popup ) );
}

static void menu_response(GtkWidget* menu_item, gpointer data) {
    if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "New") == 0) {
        g_print("You pressed New\n");
    }
    else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Exit") == 0) {
        gtk_main_quit();
    }
    else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "About") == 0) {
        g_print("You pressed About\n");
    }
}

static void Decompress(GtkWidget *widget, gpointer data) {
    size_t length = strlen(gtk_entry_get_text(GTK_ENTRY(data)));
    char extension[] = ".huff";
    char *file = malloc(sizeof(char) * length + 2);
    strcpy(file, gtk_entry_get_text(GTK_ENTRY(data)));
    int isValid = 1;
    if(length < 5)
        gtk_window_present(GTK_WINDOW(popup));
        //g_print("This is not a valid .huff file !\n");
    else {
        int i, j;
        for(i = length - 1, j = 4;i > length - 5;i--, j--) {
            if(extension[j] != file[i]) isValid = 0;
        }
        if(isValid) g_print("This is a valid file, Decompressing...\n");
        else gtk_window_present(GTK_WINDOW(popup)); 
            //g_print("This is not a valid .huff file!\n");
    }   
}

static void Compress(GtkWidget *widget, gpointer data) {
    FILE* inputFile = fopen(gtk_entry_get_text(GTK_ENTRY(data)), "rb");
    if(!inputFile) {
        gtk_window_present(GTK_WINDOW(popup));
        g_print("File not found or corrupted!");
    }
    else 
        g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
}

int main(int argc, char* argv[]) {
    gtk_init(&argc,&argv);  // open brackets of gtk
    GtkBuilder *builder;
    GtkWidget *window, *menu_bar, *menu_item, *file_menu, *help_menu, *vbox, *button, *image, *table, *entry;
    builder = gtk_builder_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_add_from_file( builder, "popup.builder", NULL );

    //window = GTK_WIDGET( gtk_builder_get_object( builder, "main_w" ) );
    popup  = GTK_WIDGET( gtk_builder_get_object( builder, "popup_w" ) );

    gtk_builder_connect_signals( builder, popup );
    g_object_unref( G_OBJECT( builder ) );

    

    //// MENU///////////////////////////////////////////////////////////////////
    menu_bar  = gtk_menu_bar_new();

    file_menu = gtk_menu_new();
    help_menu = gtk_menu_new();

    menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    menu_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
    ////////////////////////////////////////////////////////////////////////////
    /// sub-items of File menu /////////////////////////////////////////////////

    menu_item = gtk_menu_item_new_with_label("New");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);

    menu_item = gtk_menu_item_new_with_label("Exit");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
    ////////////////////////////////////////////////////////////////////////////
    /// sub-items of Help menu /////////////////////////////////////////////////

    menu_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
    ////////////////////////////////////////////////////////////////////////////

    table  = gtk_table_new(2, 2, 2);
    

    vbox   = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), table, 0, 0, 0);

    entry  = gtk_entry_new();
    button = gtk_button_new_with_label("Compactar um arquivo");
    g_signal_connect(button ,"clicked", G_CALLBACK(Compress), entry);
    //g_signal_connect(button ,"clicked", G_CALLBACK(cb_show_prop), popup);
    g_signal_connect(entry, "activate", G_CALLBACK(Compress), entry);
    gtk_table_attach(GTK_TABLE(table), button, 0, 1, 0 ,1, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(table), entry, 1, 2, 0 ,1, GTK_FILL, GTK_FILL, 0, 0);

    entry  = gtk_entry_new();
    button = gtk_button_new_with_label("Descompactar um arquivo");
    g_signal_connect(button ,"clicked", G_CALLBACK(Decompress), entry);
    g_signal_connect(entry, "activate", G_CALLBACK(Decompress), entry);
    gtk_table_attach(GTK_TABLE(table), button, 0, 1, 1 ,2, GTK_FILL, GTK_FILL, 0, 0); // (start horizontal, end horizontal, start vertical, end vertical)
    gtk_table_attach(GTK_TABLE(table), entry, 1, 2, 1 ,2, GTK_FILL, GTK_FILL, 0, 0);        
    image = gtk_image_new_from_file("pp.jpg");
    gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);  

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_set_size_request(window, 300, 300);
    gtk_window_set_title(GTK_WINDOW(window), "HUFFMAN");
    gtk_widget_show_all(window);

    gtk_main();             // close brackets of gkt

    return 0;
}