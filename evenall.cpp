#include <stdio.h>

// Define a struct to hold the count of total and even digits
typedef struct {
    int totalDigits;
    int evenDigits;
} DigitCount;

// Recursive function to count total and even digits
void countDigitsRecursive(int num, DigitCount *counts) {
    if (num == 0)
        return; // Base case: stop when the number becomes 0

    int digit = num % 10; // Extract the last digit

    counts->totalDigits++; // Increment total digit count
    if (digit % 2 == 0)    // Check if the digit is even
        counts->evenDigits++;

    countDigitsRecursive(num / 10, counts); // Recursive call with the remaining digits
}

int main() {
    int num;
    DigitCount counts = {0, 0}; // Initialize the struct with zero counts

    printf("Enter a number: ");
    scanf("%d", &num);

    // If the number is negative, make it positive
    if (num < 0)
        num = -num;

    // Handle the special case for 0
    if (num == 0) {
        counts.totalDigits = 1;
        counts.evenDigits = 1;
    } else {
        countDigitsRecursive(num, &counts);
    }

    printf("Total digits: %d\n", counts.totalDigits);
    printf("Even digits: %d\n", counts.evenDigits);

    return 0;
}

