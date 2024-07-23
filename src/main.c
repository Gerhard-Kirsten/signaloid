#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>
#include <uncertain.h>

double empiricalTaylorFactorValues[] = {
						3.2,
						3.9,
						4.1,
						3.2,
						3.8,
						3.8,
						2.1,
						3.0,
						1.9,
						3.9,
						2.3,
						2.2,
						3.2,
						2.2,
						3.9,
						2.2,
						1.9,
						3.2,
						3.9,
						3.1,
					};

	*M		= libUncertainDoubleDistFromSamples(
								empiricalTaylorFactorValues,
								sizeof(empiricalTaylorFactorValues)/sizeof(double)
							);

int
main(int argc, char *  argv[])
{
	double	a, b, c;

	double empiricalTaylorFactorValues[] = {
						3.2,
						3.9,
						4.1,
						3.2,
						3.8,
						3.8,
						2.1,
						3.0,
						1.9,
						3.9,
						2.3,
						2.2,
						3.2,
						2.2,
						3.9,
						2.2,
						1.9,
						3.2,
						3.9,
						3.1,
					};

	a		= libUncertainDoubleDistFromSamples(
								empiricalTaylorFactorValues,
								sizeof(empiricalTaylorFactorValues)/sizeof(double)
							);

	#a = UxHwDoubleUniformDist(0.5, 1.0);
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

