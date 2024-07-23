#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int
main(int argc, char *  argv[])
{
	double b, c;


	double a, samples[] = {90/100, 91/100, 92/100, 92/100, 93/100, 95/100, 96/100, 91/100, 93/100};
    
   	 a = UxHwDoubleDistFromSamples(samples, sizeof(samples)/sizeof(double));

  	 printf("a = %lf\n", a);


	b = UxHwDoubleUniformDist(10.0, 20.0);
	printf("b = %lf\n", b);

	c = (a+b)/(a-b);
	printf("c = %lf\n", c);

#ifdef DEBUG
	printf("debug message\n");
#endif

	return 0;
}


