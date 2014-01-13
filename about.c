#include "send2sn.h"

void about(GtkWidget *widget, gpointer parents)
{
    GtkWidget *dialog;

    dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "Send2SN");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "0.9");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Matthew Lee");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
                                  "Send2SN是一款简易的班级信息推送应用，可以将班级信息发送至班级成员邮箱、微信公众平台和人人网。\n采用GTK+2.24、C语言以及Python2开发。\n请参考以下网址配置程序。");
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),
                                 "https://github.com/newmlee/Send2SN");

     gtk_dialog_run(GTK_DIALOG(dialog));
     gtk_widget_destroy(dialog);
}
