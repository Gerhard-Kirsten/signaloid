#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>
#include <math.h>

// Function prototypes
double calculateAirDensity(double temperatureC, double pressurePa, double humidity);

int main() {
    double temperatureC = UxHwDoubleUniformDist(20,30); // Temperature in Celsius

	printf("Temperature: %lf celcius\n", temperatureC);
	
    double pressurePa = UxHwDoubleUniformDist(101200,101400); // Pressure in Pa

	printf("Pressure: %lf Pa\n", pressurePa);
	
    double humidity = UxHwDoubleUniformDist(70,90); // Humidity in percentage

	printf("Humidity: %lf Precentage\n", humidity);

    double airDensity = calculateAirDensity(temperatureC, pressurePa, humidity);
    printf("Calculated Air Density: %lf kg/m³\n", airDensity);

    return 0;
}

double calculateAirDensity(double temperatureC, double pressurePa, double humidity) {
    double R_d = 287.05; // Specific gas constant for dry air, J/(kg·K)
    double R_v = 461.5; // Specific gas constant for water vapor, J/(kg·K)
    
    // Convert temperature to Kelvin
    double temperatureK = temperatureC + 273.15;
    
    // Calculate saturation vapor pressure (e_s) in hPa
    double e_s = 6.112 * exp((17.67 * temperatureC) / (temperatureC + 243.5));
    
    // Convert e_s to Pa
    e_s *= 100;
    
    // Calculate actual vapor pressure (e) in Pa
    double e = (humidity / 100.0) * e_s;
    
    // Calculate partial pressure of dry air (p_d) in Pa
    double p_d = pressurePa - e;
    
    // Calculate air density (rho) in kg/m³
    double rho = (p_d / (R_d * temperatureK)) + (e / (R_v * temperatureK));
    
    return rho;
}
