#include "send2sn.h"

void send2sn(GtkWidget *widget, Item *parents)
{
    GtkWidget *dialog;

    GtkTextIter start, end;
    gchar *text;

    gboolean tof_mail = FALSE, tof_renren = FALSE;

    FILE *fp;

    int mail_return = 0, renren_return = 0;

    /* 获取当前文本区域的起始位置和终止位置 */
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER((*parents).buffer), &start);
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER((*parents).buffer), &end);
    /* 从文本缓冲区中获取文本, 设置为TRUE则不返回不可见的字符，比如制表符等等 */
    text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER((*parents).buffer), &start, &end, TRUE);
    tof_mail = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON((*parents).mail_button));
    tof_renren = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON((*parents).renren_button));

    if (strlen(text) == 0) {
        g_free(text);
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "没有输入任何信息");
        gtk_window_set_title(GTK_WINDOW(dialog), "信息");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(GTK_WIDGET(dialog));
    } else {
        /* 首先把text写入message.txt */
        fp = fopen("message.txt", "w");
        fputs(text, fp);
        fclose(fp);
        g_free(text);
        /* 接着开始发送操作 */
        if (tof_mail == TRUE && tof_renren == FALSE) {
            mail_return = system("python2 mail.py");
            if (mail_return < 0) {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_ERROR,
                                                GTK_BUTTONS_OK,
                                                "群发邮件失败 :(");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            } else {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "群发邮件成功 :)");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            }
        } else if (tof_mail == FALSE && tof_renren == TRUE) {
            renren_return = system("python2 renren.py");
            if (renren_return < 0) {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_ERROR,
                                                GTK_BUTTONS_OK,
                                                "发送到人人网失败 :(");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            } else {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "成功发送到人人网 :)");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            }
        } else if (tof_mail == TRUE && tof_renren == TRUE) {
            mail_return = system("python2 mail.py");
            renren_return = system("python2 renren.py");
            if (mail_return < 0 || renren_return < 0) {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_ERROR,
                                                GTK_BUTTONS_OK,
                                                "发送到失败 :(");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            } else {
                dialog = gtk_message_dialog_new(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                " 发送成功 :)");
                gtk_window_set_title(GTK_WINDOW(dialog), "信息");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(GTK_WIDGET(dialog));
            }
        } else {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "未选择发送目标");
            gtk_window_set_title(GTK_WINDOW(dialog), "信息");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(GTK_WIDGET(dialog));
        }
    }
}
