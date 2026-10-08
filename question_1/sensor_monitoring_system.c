#include <stdio.h>
#include <math.h>

// Function to calculate the Water-Quality Index
// Index = 100 - (|Temperature - 25| + Turbidity / 2)
double calculate_index(double temperature, double turbidity) {
    double temp_deviation = fabs(temperature - 25.0);
    double turbidity_penalty = turbidity / 2.0;
    return 100.0 - (temp_deviation + turbidity_penalty);
}

// Function to classify water quality based on index value
const char* classify_water(double index) {
    if (index >= 80.0) {
        return "Good";
    } else if (index >= 60.0) {
        return "Warning";
    } else {
        return "Critical";
    }
}

int main(void) {
    // 1. Declare sensor reading variables
    double temperature = 10.4;  // Degrees Celsius (°C)
    double turbidity = 25.0;    // Nephelometric Turbidity Units (NTU)

    // 2 & 3. Compute index and classification using functions
    double index = calculate_index(temperature, turbidity);
    const char* status = classify_water(index);

    // 4. Formatted monitoring report
    printf("=========================================\n");
    printf("     WATER-QUALITY MONITORING REPORT     \n");
    printf("=========================================\n");
    printf(" Temperature Reading : %.2f °C\n", temperature);
    printf(" Turbidity Reading   : %.2f NTU\n", turbidity);
    printf("-----------------------------------------\n");
    printf(" Water-Quality Index : %.2f\n", index);
    printf(" Water Status        : %s\n", status);
    printf("=========================================\n");

    return 0;
}