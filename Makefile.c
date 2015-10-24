screen.c :
	cc -c screen.c
	
screen.o : screen.c
	cc -c screen.c
	
logic.c : logic.h
	cc -c logic.c
	
logic.o : logic.c logic.h
	cc -c logic.c
	
main.c : logic.h screen.h out.h
	cc -c main.c
	
main.o : main.c logic.h screen.h out.h
	cc -c main.o

out.c : 
	cc -c basic.c 

out.o : basic.c
	cc -c basic.c

project :
	cc *.o -o project

clean :
	rm *.o project	
