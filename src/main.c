#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int
main(int argc, char *  argv[])
{
	double c;

	double a, samples[] = {0.91, 0.91, 0.92, 0.92, 0.99, 1.2, 1.3, 1.4, 1.5, 1.5};
    
   	 a = UxHwDoubleDistFromSamples(samples, sizeof(samples)/sizeof(double));

  	 printf("a = %lf\n", a);

	double b, samples2[] = {11,12,11,13,15,13,17,17,17,19,12,12,12,12,12};
    
   	 b = UxHwDoubleDistFromSamples(samples2, sizeof(samples2)/sizeof(double));

  	 printf("b = %lf\n", b);

	c = (a+b)/(a-b);
	printf("c = %lf\n", c);

#ifdef DEBUG
	printf("debug message\n");
#endif

	return 0;
}

