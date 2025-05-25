#include <iostream>
#include <algorithm>
using namespace std;

int comparison = 0;

// Sequential Search
int Sequential(int x[], int n, int key) {
    for (int i = 0; i < n; i++) {
        comparison++;
        if (x[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (requires sorted array)
int Binary(int x[], int n, int key) {
    int low = 0, hi = n - 1;
    while (low <= hi) {
        int mid = (low + hi) / 2;
        comparison++;
        if (x[mid] == key)
            return mid;
        else if (key < x[mid])
            hi = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the key to search: ";
    cin >> key;

    // Sequential Search
    comparison = 0;
    int seqIndex = Sequential(arr, n, key);
    cout << "\nSequential Search:\n";
    if (seqIndex != -1)
        cout << "Key found at index " << seqIndex << endl;
    else
        cout << "Key not found.\n";
    cout << "Comparisons made: " << comparison << endl;

    // Sort the array for binary search
    sort(arr, arr + n);

    // Binary Search
    comparison = 0;
    int binIndex = Binary(arr, n, key);
    cout << "\nBinary Search (after sorting):\n";
    if (binIndex != -1)
        cout << "Key found at index " << binIndex << " (in sorted array)\n";
    else
        cout << "Key not found.\n";
    cout << "Comparisons made: " << comparison << endl;

    delete[] arr;
    return 0;
}
