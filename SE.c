#include <stdio.h>

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 == 0) {
        printf("Error: division by zero\n");
        return 0;
    } else {
        return num1 / num2;
    }
}

int main() {
    float num1, num2, result;
    int choice;

    do {
        printf("MENU:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = add(num1, num2);
                printf("The sum of %f and %f is %f\n", num1, num2, result);
                break;
            case 2:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = subtract(num1, num2);
                printf("The difference between %f and %f is %f\n", num1, num2, result);
                break;
            case 3:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = multiply(num1, num2);
                printf("The product of %f and %f is %f\n", num1, num2, result);
                break;
            case 4:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = divide(num1, num2);
                if (result != 0) {
                    printf("The quotient of %f and %f is %f\n", num1, num2, result);
                }
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
