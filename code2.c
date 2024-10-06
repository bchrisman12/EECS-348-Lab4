#include <stdio.h>

float celsius_to_fahrenheit(float celsius) { //Converts from celsius to fahrenheit
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit){  //converts from fahrenheit to celsius
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius){ //converts from celsuis to kelvin
    return (celsius + 273.15);
}

float kelvin_to_celsius(float kelvin){//converts from kelvin to celcius
    return (kelvin - 273.15);
}

void temp_category(float celsius){ //determines category based on the celcius temperature
    if (celsius < 0.0){ //limit for freezing
        printf("Weather Category: Freezing\n");
        printf("Weather Advisory: Stay inside\n");
    }
    else if (celsius < 10.0){//limit for cold weather
        printf("Weather Category: Cold\n");
        printf("Weather Advisory: Bundle up\n");
    }
    else if (celsius < 25.0){//limit for nice weather
        printf("Weather Category: Comfortable\n");
        printf("Weather Advisory: Perfect day to enjoy the outdoors\n");
    }
    else if (celsius < 35.0){//limit for hot weather
        printf("Weather Category: Hot\n");
        printf("Weather Advisory: Stay hydrated\n");
    }
    else{//limit for extreme heat
        printf("Weather Category: Extreme Heat\n");
        printf("Weather Advisory: Find some place cool\n");
    }
}

int main() {
    float temp; //initialize temp
    int scaleChoice, conversionChoice; //initialize our choice variables
    float convertedTemp; //variable for our converted temp to be outputted

    while (1) {//while loop so the program keeps running
        printf("Enter a Temperature: ");
        if (scanf("%f", &temp) != 1) { //checks to see whether or not we are recieving a vailid input
            printf("Invalid input. Please enter a valid temperature.\n");
            while (getchar() != '\n'); //clears the buffer so that we do not enter an infinite loop
            continue;
        }

        printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &scaleChoice) != 1 || scaleChoice != 2 || scaleChoice != 3) { //looks to see if we get a valid choice for the scale
            printf("Invalid input. Please choose 1, 2, or 3.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
//checks to see if we are have a temp above absolute 0
        if ((scaleChoice == 1 && temp < -273.15) || //celcius
            (scaleChoice == 2 && temp < -460) || //fahrenheit
            (scaleChoice == 3 && temp < 0)) { //kelvin
            printf("Invalid input. Temperature cannot be below absolute zero.\n");
            continue;
        }

        printf("Choose scale to convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //looks to see if we get a valid choice for our conversion
        if (scanf("%d", &conversionChoice) != 1 || conversionChoice != 2 || conversionChoice != 3) {
            printf("Invalid input. Please choose 1, 2, or 3.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Conversion logic
        if (scaleChoice == 1) { // Celsius
            float celsius = temp;
            if (conversionChoice == 1) {
                printf("Scales are the same. No conversion needed.\n");
            } else if (conversionChoice == 2) {
                convertedTemp = celsius_to_fahrenheit(temp);
                printf("Converted Temperature: %.2f Fahrenheit\n", convertedTemp);
                temp_category(celsius);
            } else if (conversionChoice == 3) {
                convertedTemp = celsius_to_kelvin(temp);
                printf("Converted Temperature: %.2f Kelvin\n", convertedTemp);
                temp_category(celsius);
            }

        } else if (scaleChoice == 2) { // Fahrenheit
            float celsius = fahrenheit_to_celsius(temp);
            if (conversionChoice == 1) {
                printf("Converted Temperature: %.2f Celsius\n", celsius);
                temp_category(celsius);
            } else if (conversionChoice == 2) {
                printf("Scales are the same. No conversion needed.\n");
            } else if (conversionChoice == 3) {
                convertedTemp = celsius_to_kelvin(celsius);
                printf("Converted Temperature: %.2f Kelvin\n", convertedTemp);
                temp_category(celsius);
            }
            

        } else if (scaleChoice == 3) { // Kelvin
            float celsius = kelvin_to_celsius(temp);
            if (conversionChoice == 1) {
                printf("Converted Temperature: %.2f Celsius\n", celsius);
                temp_category(celsius);
            } else if (conversionChoice == 2) {
                convertedTemp = celsius_to_fahrenheit(celsius);
                printf("Converted Temperature: %.2f Fahrenheit\n", convertedTemp);
                temp_category(celsius);
            } else if (conversionChoice == 3) {
                printf("Scales are the same. No conversion needed.\n");
            }
        }
    }

    return 0;
}




