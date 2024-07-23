#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>

int main() {
    // Define the mean and uncertainties for each parameter
    // Air density (rho) in kg/m^3
    double rho = UxHwDoubleUniformDist(1.2, 1.3);

	printf("rho = %lf\n", rho);
	
    // Air velocity (V) in m/s
   double V = UxHwDoubleUniformDist(45, 55);
	printf("V = %lf\n", V);
    
    // Coefficient of lift (CL)
   double CL = UxHwDoubleUniformDist(1.1,1.3);
	printf("CL = %lf\n", CL);
    
    // Wing area (A) in m^2 (assumed to be known precisely)
    double A = 10.0;

    // Compute the lift force
   double lift =  0.5 * rho * V * V * CL * A;
	printf("lift = %lf\n", lift);
    

    return 0;
}
