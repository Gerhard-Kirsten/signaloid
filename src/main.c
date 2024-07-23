#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int
main(int argc, char *  argv[])
{
	double	a, b, c;


	    double  value, samples[] = {90, 120, 96, 20, 99, 102, 112, 68, 90, 109};
    
    value = UxHwDoubleDistFromSamples(samples, sizeof(samples)/sizeof(double));

    a = fopen("sd0/uxString.txt", "w+");
    fprintf(a, "value = %lf\n", value);
    printf("value = %lf\n", value);

	#a = UxHwDoubleUniformDist(0.5, 1.0);
	#printf("a = %lf\n", a);

	b = UxHwDoubleUniformDist(10.0, 20.0);
	printf("b = %lf\n", b);

	c = (a+b)/(a-b);
	printf("c = %lf\n", c);

#ifdef DEBUG
	printf("debug message\n");
#endif

	return 0;
}

