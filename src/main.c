#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int
main(int argc, char *  argv[])
{
	double	a, b, c;


	samples[] = {90, 120, 96, 20, 99, 102, 112, 68, 90, 109};
    
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

