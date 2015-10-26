project : stack.o logic.o main.o out.o screen.o
	cc *.o -o project -lncurses
screen.o: screen.c logic.h
	cc -c screen.c
logic.o: logic.c logic.h
	cc -c logic.c
main.o: main.c logic.h screen.h out.h logic.h
	cc -c main.o
out.o: out.h logic.h stack.h
	cc -c out.c
stack.o: stack.c stack.h
	cc -c stack.o
clean :
	rm *.o project	
