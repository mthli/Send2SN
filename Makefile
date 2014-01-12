Send2SN: main_window.o \
	     help_about.o
	gcc -o Send2SN \
		   main_window.o \
		   help_about.o \
		   `pkg-config --cflags --libs gtk+-2.0`
main_window.o: main_window.c send2sn.h
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
help_about.o: help_about.c send2sn.h
	gcc -c help_about.c `pkg-config --cflags --libs gtk+-2.0`

clean: 
	rm Send2SN \
	   main_window.o \
	   help_about.o

