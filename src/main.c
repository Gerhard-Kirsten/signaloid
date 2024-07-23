#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int
main(int argc, char *  argv[])
{
	double b, c;

	double a, samples[] = {0.91, 0.91, 0.92, 0.92, 0.99, 1.2, 1.3, 1.4, 1.5, 1.5};
    
   	 a = UxHwDoubleDistFromSamples(samples, sizeof(samples)/sizeof(double));

  	 printf("a = %lf\n", a);

	b = UxHwDoubleWeibullDist(1.0, 1.5);
   	 printf("b = %lf\n", value);
    
	c = (a+b)/(a-b);
	printf("c = %lf\n", c);

#ifdef DEBUG
	printf("debug message\n");
#endif

	return 0;
}

