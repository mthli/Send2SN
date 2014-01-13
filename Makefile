Send2SN: main_window.o \
		 mail_setting.o \
		 renren_setting.o \
	     about.o \
		 send2sn.o
	gcc -o Send2SN \
		   main_window.o \
		   mail_setting.o \
		   renren_setting.o \
		   about.o \
		   send2sn.o \
		   `pkg-config --cflags --libs gtk+-2.0`
main_window.o: main_window.c send2sn.h
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
mail_setting.o: mail_setting.c send2sn.h
	gcc -c mail_setting.c `pkg-config --cflags --libs gtk+-2.0`
renren_setting.o: renren_setting.c send2sn.h
	gcc -c renren_setting.c `pkg-config --cflags --libs gtk+-2.0`
about.o: about.c send2sn.h
	gcc -c about.c `pkg-config --cflags --libs gtk+-2.0`
send2sn.o: send2sn.c send2sn.h
	gcc -c send2sn.c `pkg-config --cflags --libs gtk+-2.0`

clean: 
	rm  main_window.o \
	   mail_setting.o \
	   renren_setting.o \
	   about.o \
	   send2sn.o

