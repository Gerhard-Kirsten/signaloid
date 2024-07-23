#include <stdio.h>
#include <uxhw.h>
#include <stdint.h>
#include <math.h>

// Function prototypes
double calculateAirDensity(double temperatureC, double pressurePa, double humidity);

int main() {




	double  temperatureC, samplesTemp[] = {10, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 12, 12, 12, 13, 13, 14, 14, 14, 14, 14, 13, 14, 13, 13, 13, 12.9, 13, 13, 13, 13, 13, 13, 13, 14, 15, 17, 17, 16, 16, 16, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 15, 15, 13, 15, 15, 15, 15, 15, 17, 17, 17, 14, 13, 14, 13, 13, 14, 13, 13.3, 13, 13, 13, 13, 13, 12, 13, 12, 13, 13, 13, 13, 14, 15, 15, 15, 15, 14, 14, 13, 13, 13, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 14, 11, 10, 10, 12, 12, 10, 11, 11, 11, 11, 11, 11, 10, 9, 9, 9, 8, 9, 9, 8, 11, 11, 12, 11, 14, 15, 15, 15, 15, 14, 14, 13, 13, 12, 12, 12, 11, 10, 10, 11, 10, 10, 10, 10, 10, 11, 13, 14, 16, 17, 16, 15, 15, 15, 14, 14, 12, 12, 12, 12, 13, 12, 12, 12, 11, 10, 9, 11, 11, 11, 12, 13, 15, 16, 16, 14, 15, 14, 14, 13, 12, 12, 13, 12};
    
  temperatureC = UxHwDoubleDistFromSamples(samplesTemp, sizeof(samplesTemp)/sizeof(double)); // // Temperature in Celsius

	printf("Temperature: %lf celcius\n", temperatureC);

	 double  pressurePa, samples[] = {101700, 101700, 101600, 101500, 101400, 101200, 101100, 101000, 101000, 100900, 100900, 100800, 100900, 100800, 100800, 100800, 100800, 100800, 100900, 101000, 101000, 101100, 101100, 101200, 101200, 101200, 101280, 101300, 101200, 101300, 101200, 101300, 101300, 101300, 101300, 101200, 101100, 101100, 100900, 100900, 100900, 100800, 100700, 100700, 100700, 100700, 100600, 100670, 100500, 100500, 100500, 100400, 100400, 100400, 100500, 100500, 100600, 100600, 100600, 100700, 100500, 100500, 100400, 100600, 100600, 100600, 100800, 100900, 100900, 100900, 100950, 100900, 101000, 100900, 100900, 100900, 100900, 101000, 100900, 101000, 101100, 101100, 101200, 101200, 101200, 101200, 101200, 101200, 101200, 101300, 101400, 101500, 101600, 101600, 101600, 101700, 101700, 101600, 101600, 101600, 101600, 101500, 101600, 101600, 101600, 101600, 101600, 101600, 101700, 101600, 101500, 101600, 101600, 101600, 101700, 101800, 101700, 101800, 101800, 101800, 101800, 101900, 101900, 101900, 101900, 101900, 101900, 101900, 102000, 102100, 102200, 102200, 102100, 102200, 102200, 102300, 102300, 102400, 102400, 102500, 102500, 102600, 102500, 102600, 102600, 102600, 102600, 102600, 102600, 102500, 102500, 102500, 102500, 102500, 102500, 102500, 102400, 102300, 102200, 102200, 102200, 102100, 102100, 102100, 102000, 102000, 102000, 102000, 101900, 101900, 101900, 101900, 101900, 101800, 101800, 101900, 101900, 101900, 102000, 101900, 101900, 101800, 101700, 101800, 101800, 101800, 101800, 101800, 101800, 101800, 101900, 101900};
    
    pressurePa = UxHwDoubleDistFromSamples(samples, sizeof(samples)/sizeof(double)); // Pressure in Pa

	printf("Pressure: %lf Pa\n", pressurePa);

	 double  humidity, samplesHum[] = {87, 94, 82, 82, 88, 88, 94, 88, 94, 94, 94, 94, 100, 94, 88, 88, 88, 88, 94, 88, 88, 88, 77, 82, 88, 82, 81, 88, 88, 88, 82, 94, 94, 94, 88, 88, 72, 72, 77, 72, 72, 82, 82, 82, 88, 88, 94, 85, 88, 88, 82, 88, 94, 94, 100, 94, 88, 88, 88, 88, 83, 77, 77, 88, 88, 88, 88, 88, 72, 82, 83, 82, 82, 82, 82, 82, 94, 88, 94, 88, 88, 88, 88, 88, 77, 77, 77, 72, 72, 72, 82, 82, 82, 82, 94, 94, 94, 88, 94, 88, 88, 88, 88, 82, 94, 94, 88, 77, 76, 87, 94, 82, 82, 82, 88, 82, 88, 82, 88, 76, 76, 94, 94, 94, 93, 87, 87, 93, 76, 82, 82, 88, 88, 77, 77, 77, 77, 82, 82, 88, 88, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 87, 82, 77, 72, 59, 55, 68, 63, 63, 67, 72, 72, 77, 82, 82, 88, 67, 77, 88, 88, 88, 87, 100, 88, 94, 94, 88, 88, 82, 77, 82, 88, 82, 88, 88, 88, 94, 94, 88, 94};
	
       humidity = UxHwDoubleDistFromSamples(samplesHum, sizeof(samplesHum)/sizeof(double)); // Humidity in percentage

	printf("Humidity: %lf Precentage\n", humidity);


    double airDensity = calculateAirDensity(temperatureC, pressurePa, humidity);
    printf("Calculated Air Density: %lf kg/m³\n", airDensity);

    // Total Pressure (totalPressure)
   double totalPressure = UxHwDoubleUniformDist(1018,1022);
	printf("Total Pressure = %lf\n", totalPressure);

	
	// Air velocity (V) in m/s
   double V = calculateWindSpeed(totalPressure, pressurePa, airDensity);
	printf("V = %lf\n", V);
    
    // Coefficient of lift (CL)
   double CL = UxHwDoubleUniformDist(1.1,1.3);
	printf("CL = %lf\n", CL);
    
    // Wing area (A) in m^2 (assumed to be known precisely)
    double A = 10.0;

    // Compute the lift force
   double lift =  0.5 * airDensity * V * V * CL * A;
	printf("lift = %lf\n", lift);

    return 0;
}


// Wind Speed as measure by a Pitot tube

double calculateWindSpeed(double totalPressure, double staticPressure, double density) {
    // Convert pressures from hPa to Pa
    double totalPressurePa = totalPressure * 100;
    double staticPressurePa = staticPressure * 100;
    
    // Calculate dynamic pressure
    double dynamicPressure = totalPressurePa - staticPressurePa;
    
    // Calculate wind speed
    double windSpeed = sqrt((2 * dynamicPressure) / density);
    return windSpeed;
}

// Formula for air density

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
