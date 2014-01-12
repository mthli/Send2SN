#include "send2sn.h"

/* 回调函数 */
void help_about(GtkWidget *widget, gpointer parents);

int main(int argc, char **argv)
{
    GtkWidget *main_window;

    GtkWidget *vbox;
    GtkWidget *hbox;

    GtkWidget *menubar, *menubar_item, *menu, *menu_item;

    GtkWidget *scrolled_window;

    struct Item *item;
    item = (struct Item *)malloc(sizeof(struct Item));

    gtk_init(&argc, &argv);

    /* 创建主窗口 */
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), " Send2SN");
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(main_window), 400, 240);
    /* 连接信号 */
    g_signal_connect(G_OBJECT(main_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建菜单栏 */
    menubar = gtk_menu_bar_new();
    /* 创建“选项”菜单 */
    menubar_item = gtk_menu_item_new_with_label("选项");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("设置");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    menu_item = gtk_menu_item_new_with_label("退出");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);
    /* 创建“帮助”菜单 */
    menubar_item = gtk_menu_item_new_with_label("帮助");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("指南");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    menu_item = gtk_menu_item_new_with_label("关于");
    g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(help_about), main_window);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);

    /* 创建主窗口框架 */
    vbox = gtk_vbox_new(FALSE, 0);
    hbox = gtk_hbox_new(FALSE, 0);
    /* 将菜单栏和主体控件组装进vbox */
    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(menubar),
                       FALSE, FALSE, 0);
    /* 创建text_view */
    (*item).text_view = gtk_text_view_new();
    /* 创建文本框部分 */
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC,
                                   GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window),
                                          (*item).text_view);
    /* 将scrolled_window放置于vbox之中 */
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window,
                                        TRUE, TRUE, 0);
    /* 创建选项按钮 */
    (*item).renren_button = gtk_check_button_new_with_label("人人网");
    gtk_widget_set_size_request(GTK_WIDGET((*item).renren_button), 100, 25);
    gtk_box_pack_start(GTK_BOX(hbox), (*item).renren_button,
                                       TRUE, TRUE, 0);
    (*item).qzone_button = gtk_check_button_new_with_label("QQ空间");
    gtk_widget_set_size_request(GTK_WIDGET((*item).qzone_button), 100, 25);
    gtk_box_pack_start(GTK_BOX(hbox), (*item).qzone_button,
                                       TRUE, TRUE, 0);
    (*item).weibo_button = gtk_check_button_new_with_label("新浪微博");
    gtk_widget_set_size_request(GTK_WIDGET((*item).weibo_button), 100, 25);
    gtk_box_pack_start(GTK_BOX(hbox), (*item).weibo_button,
                                       TRUE, TRUE, 0);
    (*item).ok_button = gtk_button_new_with_label("发送"); /* 注意添加相应回调函数 */
    gtk_widget_set_size_request(GTK_WIDGET((*item).ok_button), 100, 25);
    gtk_box_pack_start(GTK_BOX(hbox), (*item).ok_button,
                                       TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox,
                                       FALSE, FALSE, 0);

    /* 将vbox组装进main_window中 */
    gtk_container_add(GTK_CONTAINER(main_window), vbox);

    gtk_widget_show_all(main_window);
    gtk_main();

    return 0;
}


