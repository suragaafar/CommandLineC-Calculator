// Sura Gaafar
// Command-Line Calculator

#include <stdio.h>

//Functions used to display the list of options available and to implement certain options in the code (particularly repeated ones)
char list_of_available_options(char just_started);
int optionE(char option);
float optionB(float first_number, char operation, float second_number);
float optionU(float num, char operation);

int main() {
    // Start
    char option, operation, variable; // Stores the option the user selects; stores the operation and variable inputted by the user
    float first_number, second_number, result, num; // Stores the numbers inputted by the user, and result ouputted by the program
    char just_started = 'y'; // Flag used to check whether a prompt or a quick option message should be shown
    float variables[5] = {0}; // Array to store values for variables a-e (0-4)

    // Show a Welcome message to the user
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Sura Gaafar\n");
    printf("Version: 1\n");
    printf("Date: Friday, October 18th, 2024\n");
    printf("------------------------------------------------------------\n");


    // Loop {for asking the user to input their option}
    while (1) {
        
        option = list_of_available_options(just_started); // Assigning the option variable with a value from the showing the list function

        // if (option == 'E') then
        if (option == 'E') {
            if(optionE('E')) {
                break;
            }
        } 
        // Else if (option == 'B') then
        else if (option == 'B') {
            // Ask the user to enter their first number
            printf("Please enter the first number:\n");
            // Validating their first number
            while (scanf("%f", &first_number) != 1) { 
                printf("Invalid input. Please enter a valid first number:\n");
                while (getchar() != '\n');  // Clear the invalid input from the buffer
            }
            
            while(1) {
                // Ask the user to enter the operation
                printf("Please enter the operation ( + , - , * , / , %% , P , X , I ):\n");
                // Read(operation)
                scanf(" %c", &operation); // Add space before %c to skip newline in buffer
                
                // Check if the entered operator is valid
                if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'P' || operation == 'X' || operation == 'I') {
                    break;  // Exit loop if valid operator is entered
                } 
                else {
                    printf("Invalid operator. Please try again.\n");
                }
            }

            // Ask the user to enter their second number
            printf("Please enter the second number:\n");
            // Validating their second number
            while (scanf("%f", &second_number) != 1) { 
                printf("Invalid input. Please enter a valid first number:\n");
                while (getchar() != '\n');  // Clear the invalid input from the buffer
            }
            
            result = optionB(first_number, operation, second_number);
            printf("The result is %.2f\n", result);
        }
        else if (option == 'U') {
            // Prompt user for the number and validate input
            printf("Please enter the number:\n");
            while (scanf("%f", &num) != 1) { 
                printf("Invalid input. Please enter a valid number:\n");
                while (getchar() != '\n');  // Clear the invalid input from the buffer
            }
            
            // Prompt user for the unary operator and validate input
            while (1) {
                printf("Please enter the operator ( S , L , E , C , F ):\n");
                scanf(" %c", &operation);  // Add space before %c to skip newline in buffer
                
                // Check if the entered operator is valid
                if (operation == 'S' || operation == 'L' || operation == 'E' || operation == 'C' || operation == 'F') {
                    break;  // Exit loop if valid operator is entered
                } 
                else {
                    printf("Invalid operator. Please try again.\n");
                }
            }
            
            result = optionU(num, operation);
            printf("The result is %.4f\n", result);
        }
        
        else if (option == 'V') {
            while(1) {
                printf("Please enter a single alphabetic character for the name of a variable (a - e): \n");
                scanf(" %c", &variable);
                
                if (variable == 'a' || variable == 'b' || variable == 'c' || variable == 'd' || variable == 'e') {
                    break;
                }
                else {
                    printf("Invalid variable name.");
                }
            }
            printf("Please enter the initial value:\n");
            while (scanf("%f", &num) != 1) { 
                printf("Invalid input. Please enter a valid initial number:\n");
                while (getchar() != '\n');  // Clear the invalid input from the buffer
            }
            // Store the value for the selected variable
            int index = variable - 'a';  // Map variable 'a' to index 0, 'b' to index 1, etc.
            variables[index] = num;  // Store the value in the corresponding array index

            // Print the result
            printf("%c = %.2f\n", variable, num);
        }
        else if (option == 'A') {
            while(1) {
                printf("Select one of the following items ( B , U , E ):\n");
                scanf(" %c", &option);
                if (option == 'B') {
                    // Prompt the user for the first number or variable
                    printf("Please enter the first number or variable (a to e):\n");
                    // Check if the input is a valid number
                    if (scanf("%f", &first_number) == 1) {
                        // If it's a valid number, do nothing (no print)
                    }
                    // If it's not a valid number, check if it's a valid variable (a to e)
                    else if (scanf(" %c", &variable) == 1) {
                        // If the input is a letter between 'a' and 'e'
                        if (variable >= 'a' && variable <= 'e') {
                            first_number = variables[variable - 'a'];  // Get value from variables array
                        } else {
                            // If the variable is not valid (greater than 'e')
                            first_number = 0;
                            printf("Invalid variable. Assuming value 0.\n");
                            
                        }
                        
                    } else {
                        // If neither a valid number nor valid variable is entered, prompt again
                        printf("Invalid input. Please enter a valid first number or variable.\n");
                        while (getchar() != '\n');  // Clear the invalid input from the buffer
                        
                    }
                    while(1) {
                        // Ask the user to enter the operation
                        printf("Please enter the operation ( + , - , * , / , %% , P , X , I ):\n");
                        // Read(operation)
                        scanf(" %c", &operation); // Add space before %c to skip newline in buffer
                
                        // Check if the entered operator is valid
                        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'P' || operation == 'X' || operation == 'I') {
                            break;  // Exit loop if valid operator is entered
                        } 
                        else {
                            printf("Invalid operator. Please try again.\n");
                        }
                    }
                    // Prompt the user for the second number or variable
                    printf("Please enter the second number or variable (a to e):\n");
                    // Check if the input is a valid number
                    if (scanf("%f", &second_number) == 1) {
                        // If it's a valid number, do nothing (no print)
                    }
                    // If it's not a valid number, check if it's a valid variable (a to e)
                    else if (scanf(" %c", &variable) == 1) {
                        // If the input is a letter between 'a' and 'e'
                        if (variable >= 'a' && variable <= 'e') {
                            second_number = variables[variable - 'a'];  // Get value from variables array
                        } else {
                            // If the variable is not valid (greater than 'e')
                            second_number = 0;
                            printf("Invalid variable. Assuming value 0.\n");
                            
                        }
                        
                    } else {
                        // If neither a valid number nor valid variable is entered, prompt again
                        printf("Invalid input. Please enter a valid second number or variable.\n");
                        while (getchar() != '\n');  // Clear the invalid input from the buffer
                        
                    }
                    
                    result = optionB(first_number, operation, second_number);
                    printf("The result is %.2f\n", result);
                    
                }
                else if (option == 'U') {
                    // Prompt the user for the first number or variable
                    printf("Please enter the number or variable (a to e):\n");
                    // Check if the input is a valid number
                    if (scanf("%f", &num) == 1) {
                        // If it's a valid number, do nothing (no print)
                    }
                    // If it's not a valid number, check if it's a valid variable (a to e)
                    else if (scanf(" %c", &variable) == 1) {
                        // If the input is a letter between 'a' and 'e'
                        if (variable >= 'a' && variable <= 'e') {
                            num = variables[variable - 'a'];  // Get value from variables array
                        } else {
                            // If the variable is not valid (greater than 'e')
                            num = 0;
                            printf("Invalid variable. Assuming value 0.\n");
                            
                        }
                        
                    } else {
                        // If neither a valid number nor valid variable is entered, prompt again
                        printf("Invalid input. Please enter a valid first number or variable.\n");
                        while (getchar() != '\n');  // Clear the invalid input from the buffer
                        
                    }
                    // Prompt user for the unary operator and validate input
                    while (1) {
                        printf("Please enter the operator ( S , L , E , C , F ):\n");
                        scanf(" %c", &operation);  // Add space before %c to skip newline in buffer
                        // Check if the entered operator is valid
                        if (operation == 'S' || operation == 'L' || operation == 'E' || operation == 'C' || operation == 'F') {
                            break;  // Exit loop if valid operator is entered
                        }else {
                            printf("Invalid operator. Please try again.\n");
                            
                        }
                        
                    }
                    
                    result = optionU(num, operation);
                    printf("The result is %.4f\n", result);
                    
                }
                else if (option == 'E') {
                    if(optionE('E')) {
                        break;
                    }
                }
                else {
                    printf("Sorry, at this time I don't have enough knowledge to serve you in this category.\n");
                    
                }
            
            }
        }
        // If (option != 'B' && option != 'E') then
        else{
            // Show an apology message for not having enough information
            printf("Sorry, at this time I don't have enough knowledge to serve you in this category.\n");
        } 
        // Set that the loop didn't just start, therefore the prompt shouldn't be displayed again
        just_started = 'n';
    }
    // Show a Goodbye message
    printf("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!\n");
    // End
    return 0;
}

char list_of_available_options(char just_started) {
    char option;
    // If the loop just started, show a prompt for user selection
    if(just_started == 'y') {
        printf("\nSelect one of the following items:\n");
        printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
        printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
        printf("A) - Advanced Mathematical Operations, using variables, arrays.\n");
        printf("V) - Define variables and assign them values.\n");
        printf("E) - Exit\n");
    }
    // If not, ask the user the select their option
    else{
        printf("Please select your option ( B , U , A , V , E )\n");
    }
    // Read(option)
    scanf(" %c", &option); // Add space before %c to skip newline in buffer
    
    while(option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E') {
        printf("Invalid option. Please select a valid option ( B , U , A , V , E )\n");
        scanf(" %c", &option);
    }
    return option;
}
int optionE (char option) {
    int flag = 0;
    
    if(option == 'E') {
        flag = 1;
    }
    
    return flag;
}
float optionB(float first_number, char operation, float second_number) {
    // Initialize result = 0
    float result = 0;
    
    // If (operation == '+') then
    if (operation == '+') {
        result = first_number + second_number;
    } 
    // Else if (operation == '-') then
    else if (operation == '-') {
        result = first_number - second_number;
    } 
    // Else if (operation == '*') then
    else if (operation == '*') {
        result = first_number * second_number;
        
    } 
    // Else if (operation == '/') then
    else if (operation == '/') {
        while(second_number == 0) {
            // Ask the user to enter their second number
            printf("Division by zero is invalid. Please enter a valid second number:\n");
            // Validating their second number
            while (scanf("%f", &second_number) != 1) { 
                printf("Invalid input. Please enter a valid first number:\n");
                while (getchar() != '\n');  // Clear the invalid input from the buffer
            }
        }
        result = first_number / second_number;
        
    }
    // Gets the remainder of two numbers
    else if (operation == '%') { 
        result = (int)first_number % (int)second_number;
        
    }
    // Gets the result of a number to the power of another
    else if (operation == 'P') { 
        result = 1;
        if (first_number != 0) {
            if(second_number > 0) {
                while(second_number > 0) {
                    result *= first_number;
                    second_number--;
                }
            }  
            else {
                while(second_number < 0) {
                    result /= first_number;
                    second_number++;
                }
            }
        }
        else {
            result = 0;
            
        }
        
    }
    // Gets the maximum value of two numbers
    else if (operation == 'X') { 
        if (first_number>second_number) {
            result = first_number;
        } else {
            result = second_number;
        }
    }
    // Gets the minimum value of two numbers
    else if (operation == 'I') { 
        if (first_number<second_number) {
            result = first_number;
        } else {
            result = second_number;
        }
    }
    
    return result;
}

float optionU(float num, char operation) {
    // Initialize result = 0
    float result = 0;
    
    int intOfNum;
    
    if (operation == 'S') { // Gets the square root of a number
        while(num<0) {
            printf("Invalid input. Please enter a non negative number:\n");
            scanf(" %f", &num);
            while (getchar() != '\n');  // Clear the invalid input from the buffer
        }
        result = 1; // Initial guess for the square root
        int iterations = 10; // Number of iterations for approximation
        while (iterations > 0) {
            result = 0.5 * (result + num / result);
            iterations--;
        }
        if(num==0) {
            result = 0;
        }
    }
    else if (operation == 'L') { // Gets the logarithm of a number
        while(num<=0) {
            printf("Invalid input. Please enter a positive number:\n");
            scanf(" %f", &num);
            while (getchar() != '\n');  // Clear the invalid input from the buffer
        }
        result = 0; // Initialize the result
        double ln_10 = 2.302585092994045684; // Initialize ln 10 so that we can get log to base 10
        float x = (num - 1) / (num + 1); // Transformation for better convergence
        float term = x; // First term of the series
        int iterations = 10; // Number of terms for approximation
        int n = 1; // Counter for series terms
        
        while (iterations > 0) {
            result += (term / n); // Add the current term to the result
            term *= x * x; // Update term (x^3, x^5, x^7...)
            n += 2; // Increment to next odd number (1, 3, 5, ...)
            iterations--; // Decrement iterations
        }
        result *= 2; // Multiply by 2 to complete the logarithm formula
        result /= ln_10;
    }
    else if (operation == 'E') { // Gets the exponential of a number
        result = 1;
        if(num!=0) {
            double e = 2.71828182846; // Approximation of e that is the base of the natural logarithms
            while(num > 0) {
                result *= e;
                num--;
            }
            while(num < 0) {
                result /= e;
                num++;
            }
        }
    }
    else if (operation == 'C') { // Gets the ceiling value of a number
        intOfNum = (int)num;
        if (num>intOfNum) {
            intOfNum++;
        }
        result = intOfNum;
    }
    else if (operation == 'F') { // Gets the floor value of a number
        intOfNum = (int)num;
        if (num<0 && num!=intOfNum) {
            intOfNum--;
        }
        result = intOfNum;
    }
    return result;
}