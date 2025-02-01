#include <iostream>
using namespace std;

void findMaxSumSubarray(int arr[], int n) {
    int maxSum = INT_MIN;
    int start = 0, end = 0;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = i;
                end = j;
            }
        }
    }

    // Output the result
    cout << "Maximum Sum: " << maxSum << endl;
    cout << "Subarray: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i]<<endl;
        //if (i < end) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {1, -3, 2, 1, -1, 3, -2, 3, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxSumSubarray(arr, n);

    return 0;
}

