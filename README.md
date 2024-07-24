[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/Gerhard-Kirsten/signaloid#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/Gerhard-Kirsten/signaloid#gh-light-mode-only)

# Airfoil Lift Generation Model

This repository contains a C program that models the lift generation of an airfoil using the Bernoulli equation and other relevant physical principles. 
In this specific version we consider uncertainties in the ambient temperature, humidity and static air pressure to compute the air density as a probability distribution on the Signaloid Cloud Developer Platform. This probability distribution is then, in turn used to compute the velocity as a probability distribution using the Pitot Tube formula. Both these probability distributions are then used as inputs to finally compute the lift force as a probability distribution.

## Model Description

The lift force $L$ generated by an airfoil is computed using:

$$
L = 0.5 \times \rho \times V^2 \times C_L \times A
$$

where:
- $\rho$ is the air density (kg/m³)
- $V$ is the air velocity (m/s)
- $C_L$ is the coefficient of lift (dimensionless)
- $A$ is the wing area (m²)

### Air Density Calculation

Air density $\rho$ is calculated using:

$$
\rho = \frac{p_d}{R_d \times T} + \frac{e}{R_v \times T}
$$

where:
- $T$ is the temperature in Kelvin (Coming from a data set)
- $p_d$ is the partial pressure of dry air (Pa) (Coming from a data set)
- $e$ is the actual vapor pressure (Pa) - This is a function of the humidity (Coming from a data set)
- $R_d$ is the specific gas constant for dry air $287.05$ $\frac{J}{kg·K}$
- $R_v$ is the specific gas constant for water vapor $461.5$ $\frac{J}{kg·K}$)

### Wind Speed Calculation

Wind speed $V$ is determined using:

$$
V = \sqrt{\frac{2 \times (\text{total pressure} - \text{static pressure})}{\rho}}
$$

### Assumptions and Data Sources

- **Data Source:** Distributions are formed based on the empirical data for Temperature, pressure, and humidity from the Cape Town weather service (hourly data for July).
- **Wing Area ($A$):** Fixed at $10.0$ m².
- **Coefficient of Lift ($C_L$):** Uniform distribution between $1.1$ and $1.3$.
- **Static Pressure:** Taken to be the same distribution as $p_d$ above coming from the empirical data.
- **Total Pressure:** Uniform distribution between $104200$ and $104400$.
- **Elevation Effects:** Not considered.
- **Airfoil Geometry:** Implicitly accounted for in $C_L$.

## Running the Program

1. **Set Up the Environment:** Ensure access to the Signaloid Cloud Developer Platform.
2. **Compile and Run:** Follow the platform's instructions to compile and run the C program.

## References

- [Signaloid GitHub Page](https://github.com/signaloid)
- [Bernoulli's Principle](https://en.wikipedia.org/wiki/Bernoulli%27s_principle)
- [Air Density Calculation](https://en.wikipedia.org/wiki/Density_of_air)

