CC = gcc
CC_FLAGS =  -g -ansi -pedantic -Wall -w
FILES = main.c student.c course.c enrollment.c
OUT = Assignment1

.PHONY: clean

$(OUT): $(FILES:.c=.o)
	$(CC) $(CC_FLAGS) -o $(OUT) $(FILES:.c=.o)

main.o student.o enrollment.o: student.h
main.o course.o enrollment.o: course.h
main.o enrollment.o: enrollment.h
main.o: defs.h

clean:
	rm -f $(OUT) $(FILES:.c=.o)