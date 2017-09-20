CC = gcc

all:
	${CC} -o spring_sim spring_sim.c

clean:
	rm *.o  
