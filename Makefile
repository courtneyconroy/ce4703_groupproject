exec := llist
llist: 01-llist.c 01-llist.h 01-llistMain.c
	gcc -Wall -ggdb -o llist 01-llist.c 01-llistMain.c

clean:
	rm $(exec) *.o *~ *#
