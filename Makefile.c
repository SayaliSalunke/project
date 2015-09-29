basic.c : 
	cc -c basic.c 

basic.o : basic.c
	cc -c basic.c

project :
	cc basic.o -o project

clean :
	rm basic.o project	
