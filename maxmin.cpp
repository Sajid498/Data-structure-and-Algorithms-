#include <iostream>
#include <climits>
using namespace std;

// Structure to hold the min and max values
struct MinMax {
    int min;
    int max;
};

// Function to find the minimum and maximum using Divide and Conquer
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, leftResult, rightResult;

    // Base case: If there is only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // Base case: If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide the array into two parts
    int mid = (low + high) / 2;

    // Recursively find the min and max in the left and right halves
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    // Combine results
    result.min = min(leftResult.min, rightResult.min);
    result.max = max(leftResult.max, rightResult.max);

    return result;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 0, -4, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum: " << result.min << endl;
    cout << "Maximum: " << result.max << endl;

    return 0;
}

