#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RIGHT    0x00
#define LEFT     0x01
#define friction 0.5

struct VARS {
	double x;
	double v_plus;
	double v;
	unsigned int dir;
	double a;
};

struct VARS step(struct VARS vars, double dt)
{
	double f;
	if(vars.dir & (1 << 0))
	{	
		f = friction; 
	}
	else
	{
		f = - friction;
	}
 
	vars.a = -vars.x + f;
	vars.v_plus = vars.v + vars.a*dt;
	vars.x = vars.x + vars.v*dt;
	vars.v = vars.v_plus;
	
	return vars;
}

// argv -> [starting position] [time step] [total simulation steps]

int main(int argc, char **argv)
{
	if(strcmp(argv[1],"-h")==0)
	{
		printf("\n>> SPRING SIMULATION\n\n\
>> PARAMETERS:\n\
     [X_0] - initial starting position\n\
      [dt] - size of time step for euler step\n\
   [STEPS] - how many steps in the simulation\n\n\
>> RUN AS:\n\
   ./spring_sim [X_0] [dt] [STEPS]\n\n");
		exit(1);
	}
	
	struct VARS vars;
	
	// Grab input from CLI arguments //
	double dt = atof(argv[2]);
	int total_steps = atoi(argv[3]);
	vars.x = atof(argv[1]);

	// Additional variables and filenaming //
	int steps = 0;
	char fn[80];
	strcpy(fn,"output_x0_");
	strcat(fn,argv[1]);
	strcat(fn,".txt");
	FILE* xout;
	xout = fopen(fn,"w");
	
	// Main Loop //

	while(steps < total_steps )	
	{
		// check sign of velocity //
		if(vars.v < 0)
		{
			vars.dir = LEFT;	
		}
		else if(vars.v > 0)
		{
			vars.dir = RIGHT;
		}
		
		// Run step function //
		vars = step(vars,dt); 

		// Write coordinates to file //
		fprintf(xout,"\n%lf\t%lf",steps*dt,vars.x);
		steps++;
	}
	fclose(xout);
}		
