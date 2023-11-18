q5 : q5.o
	gcc q5.o -o q5 -lm

q5.o :

.PHONY : clean

clean : 
	-rm q5.o q5