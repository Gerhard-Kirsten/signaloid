/*
 *	Copyright (c) 2020--2022, Signaloid.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <uxhw.h>

/*
 * Airfoil Lift Generation Model
 *
 * This program models the lift generation of an airfoil using the Bernoulli equation and other physical principles.
 * It considers uncertainties in ambient temperature, humidity, and static air pressure to compute air density as a probability distribution.
 * The air density distribution is then used to compute the wind speed as a probability distribution using the Pitot Tube formula.
 * These distributions are used to compute the lift force as a probability distribution.
 *
 * Lift Force Equation:
 * L = 0.5 * ρ * V^2 * C_L * A
 * where:
 * - ρ: Air density (kg/m³)
 * - V: Air velocity (m/s)
 * - C_L: Coefficient of lift (dimensionless)
 * - A: Wing area (m²)
 *
 * Air Density Calculation:
 * ρ = (p_d / (R_d * T)) + (e / (R_v * T))
 * where:
 * - T: Temperature in Kelvin
 * - p_d: Partial pressure of dry air (Pa)
 * - e: Actual vapor pressure (Pa)
 * - R_d: Specific gas constant for dry air (287.05 J/(kg·K))
 * - R_v: Specific gas constant for water vapor (461.5 J/(kg·K))
 *
 * Wind Speed Calculation:
 * V = sqrt((2 * (total pressure - static pressure)) / ρ)
 */

// Function prototypes
double calculateAirDensity(double temperatureC, double pressurePa, double humidity);
double calculateWindSpeed(double totalPressure, double staticPressure, double density);

int main() {
     // Sample data for temperature in Celsius
     double temperatureSamples[] = {10, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 12, 12, 12, 13,   13, 14, 14, 14, 14, 14, 13, 14, 13, 13, 13, 12.9, 13,
                                    13, 13, 13, 13, 13, 13, 14, 15, 17, 17, 16, 16, 16, 15, 15,   15, 15, 15, 15, 16, 16, 16, 16, 16, 15, 15, 13,   15,
                                    15, 15, 15, 15, 17, 17, 17, 14, 13, 14, 13, 13, 14, 13, 13.3, 13, 13, 13, 13, 13, 12, 13, 12, 13, 13, 13, 13,   14,
                                    15, 15, 15, 15, 14, 14, 13, 13, 13, 12, 11, 11, 11, 11, 11,   11, 11, 11, 11, 12, 11, 11, 12, 14, 11, 10, 10,   12,
                                    12, 10, 11, 11, 11, 11, 11, 11, 10, 9,  9,  9,  8,  9,  9,    8,  11, 11, 12, 11, 14, 15, 15, 15, 15, 14, 14,   13,
                                    13, 12, 12, 12, 11, 10, 10, 11, 10, 10, 10, 10, 10, 11, 13,   14, 16, 17, 16, 15, 15, 15, 14, 14, 12, 12, 12,   12,
                                    13, 12, 12, 12, 11, 10, 9,  11, 11, 11, 12, 13, 15, 16, 16,   14, 15, 14, 14, 13, 12, 12, 13, 12};

     // Sample data for pressure in Pascals
     double pressureSamples[] = {101700, 101700, 101600, 101500, 101400, 101200, 101100, 101000, 101000, 100900, 100900, 100800, 100900, 100800, 100800, 100800,
                                 100800, 100800, 100900, 101000, 101000, 101100, 101100, 101200, 101200, 101200, 101280, 101300, 101200, 101300, 101200, 101300,
                                 101300, 101300, 101300, 101200, 101100, 101100, 100900, 100900, 100900, 100800, 100700, 100700, 100700, 100700, 100600, 100670,
                                 100500, 100500, 100500, 100400, 100400, 100400, 100500, 100500, 100600, 100600, 100600, 100700, 100500, 100500, 100400, 100600,
                                 100600, 100600, 100800, 100900, 100900, 100900, 100950, 100900, 101000, 100900, 100900, 100900, 100900, 101000, 100900, 101000,
                                 101100, 101100, 101200, 101200, 101200, 101200, 101200, 101200, 101300, 101400, 101500, 101600, 101600, 101600, 101700, 101700,
                                 101600, 101600, 101600, 101600, 101500, 101600, 101600, 101600, 101600, 101600, 101600, 101700, 101600, 101500, 101600, 101600,
                                 101600, 101700, 101800, 101700, 101800, 101800, 101800, 101800, 101900, 101900, 101900, 101900, 101900, 101900, 101900, 102000,
                                 102100, 102200, 102200, 102100, 102200, 102200, 102300, 102300, 102400, 102400, 102500, 102500, 102600, 102500, 102600, 102600,
                                 102600, 102600, 102600, 102600, 102500, 102500, 102500, 102500, 102500, 102500, 102500, 102400, 102300, 102200, 102200, 102200,
                                 102100, 102100, 102100, 102000, 102000, 102000, 102000, 101900, 101900, 101900, 101900, 101900, 101800, 101800, 101900, 101900,
                                 101900, 102000, 101900, 101900, 101800, 101700, 101800, 101800, 101800, 101800, 101800, 101800, 101800, 101900, 101900};

     // Sample data for humidity in percentage
     double humiditySamples[] = {87, 94, 82, 82, 88, 88, 94,  88, 94, 94, 94, 94, 100, 94, 88, 88, 88, 88, 94, 88, 88, 88, 77, 82, 88, 82, 81,  88,
                                 88, 88, 82, 94, 94, 94, 88,  88, 72, 72, 77, 72, 72,  82, 82, 82, 88, 88, 94, 85, 88, 88, 82, 88, 94, 94, 100, 94,
                                 88, 88, 88, 88, 83, 77, 77,  88, 88, 88, 88, 88, 72,  82, 83, 82, 82, 82, 82, 82, 94, 88, 94, 88, 88, 88, 88,  88,
                                 77, 77, 77, 72, 72, 72, 82,  82, 82, 82, 94, 94, 94,  88, 94, 88, 88, 88, 88, 82, 94, 94, 88, 77, 76, 87, 94,  82,
                                 82, 82, 88, 82, 88, 82, 88,  76, 76, 94, 94, 94, 93,  87, 87, 93, 76, 82, 82, 88, 88, 77, 77, 77, 77, 82, 82,  88,
                                 88, 94, 94, 94, 94, 94, 94,  94, 94, 94, 94, 94, 87,  82, 77, 72, 59, 55, 68, 63, 63, 67, 72, 72, 77, 82, 82,  88,
                                 67, 77, 88, 88, 88, 87, 100, 88, 94, 94, 88, 88, 82,  77, 82, 88, 82, 88, 88, 88, 94, 94, 88, 94};

     // Generate distributions from the empirical data for temperature, pressure, and humidity
     double temperatureC = UxHwDoubleDistFromSamples(temperatureSamples, sizeof(temperatureSamples) / sizeof(double));
     double pressurePa = UxHwDoubleDistFromSamples(pressureSamples, sizeof(pressureSamples) / sizeof(double));
     double humidity = UxHwDoubleDistFromSamples(humiditySamples, sizeof(humiditySamples) / sizeof(double));

     // Compute the air density as a distribution using the distributions defined above
     double airDensity = calculateAirDensity(temperatureC, pressurePa, humidity);
     printf("Air Density (Computed from Temp, Hum & Press): %lf kg/m³\n", airDensity);

     // Total Pressure (totalPressure)
     double totalPressure = UxHwDoubleUniformDist(104200, 104400);

     // Calculate wind speed using a Pitot tube. All 3 variables are distributions defined and computed above
     double windSpeed = calculateWindSpeed(totalPressure, pressurePa, airDensity);
     printf("Wind Speed (Computed via Pitot Tube) = %lf m/s\n", windSpeed);

     // Coefficient of lift (CL)
     double coefficientLift = UxHwDoubleUniformDist(1.1, 1.3);

     // Wing area (A) in m^2 (assumed to be known precisely)
     double wingArea = 10.0;

     // Compute the lift force
     double liftForce = 0.5 * airDensity * windSpeed * windSpeed * coefficientLift * wingArea;
     printf("Lift Force = %lf N\n", liftForce);

     return 0;
}

// Function to calculate wind speed using the Pitot Tube formula
double calculateWindSpeed(double totalPressure, double staticPressure, double density) {
     // Pitot tube formula: V = sqrt(2 * (totalPressure - staticPressure) / density)
     double windSpeed = sqrt(2 * (totalPressure - staticPressure) / density);
     return windSpeed;
}

// Function to calculate air density
double calculateAirDensity(double temperatureC, double pressurePa, double humidity) {
     // Convert temperature to Kelvin
     double temperatureK = temperatureC + 273.15;

     // Calculate partial pressure of water vapor (approximation using Tetens formula)
     double saturationVaporPressure = 6.1078 * pow(10, (7.5 * temperatureC) / (temperatureC + 237.3)) * 100;
     double actualVaporPressure = (humidity / 100.0) * saturationVaporPressure;

     // Calculate air density
     double Rd = 287.05;  // Specific gas constant for dry air in J/(kg·K)
     double Rv = 461.5;   // Specific gas constant for water vapor in J/(kg·K)

     // Air density formula: ρ = (pd / (Rd * T)) + (e / (Rv * T))
     double airDensity = (pressurePa - actualVaporPressure) / (Rd * temperatureK) + actualVaporPressure / (Rv * temperatureK);

     return airDensity;
}
