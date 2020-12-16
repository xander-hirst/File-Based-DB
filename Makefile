db.o: db.c db.h db_ops.c db_ops.h
	gcc -c -Wall --pedantic db.c
db_ops.o: db_ops.c db_ops.h
	gcc -c -Wall --pedantic db_ops.c
db: db.o db_ops.o
	gcc -o db db.o db_ops.o
all: db

clean:
	rm -f db.o db_ops.o db
tarball: db.c db.h db_ops.c db_ops.h  Makefile
	tar -c -f db.tar -v db.c db.h db_ops.c db_ops.h Makefile
