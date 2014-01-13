#ifndef __SEND2SN__
#define __SEND2SN__

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Item {
    GtkWidget *mail_button;
    GtkWidget *weixin_button;
    GtkWidget *renren_button;
    GtkTextBuffer *buffer;
}
Item;

#endif
