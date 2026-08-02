// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int getSum(int numbers[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return sum;
}

double getAverage(int numbers[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return static_cast<double>(sum) / n;
}

int getMaximum(int numbers[], int n) {
    int max = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int getMinimum(int numbers[], int n) {
    int min = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    int numbers[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = getSum(numbers, n);
    double average = getAverage(numbers, n);
    int maximum = getMaximum(numbers, n);
    int minimum = getMinimum(numbers, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}

