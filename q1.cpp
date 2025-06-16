#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int key, int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, key, low, mid - 1);
    else
        return binarySearch(arr, key, mid + 1, high);
}

int main() {
    int arr[10], key;

    cout << "Enter 10 unique student IDs:\n";
    for (int i = 0; i < 10;) {
        int temp, duplicate = 0;
        cin >> temp;
        for (int j = 0; j < i; j++) {
            if (arr[j] == temp) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            arr[i] = temp;
            i++;
        } else {
            cout << "Duplicate. Enter again:\n";
        }
    }

    cout << "Enter student ID to search: ";
    cin >> key;

    if (isSorted(arr, 10)) {
        cout << "Using Binary Search...\n";
        int index = binarySearch(arr, key, 0, 9);
        if (index != -1)
            cout << "ID found at index " << index << ".\n";
        else
            cout << "ID not found.\n";
    } else {
        cout << "Using Sequential Search...\n";
        int index = sequentialSearch(arr, 10, key);
        if (index != -1)
            cout << "ID found at index " << index << ".\n";
        else
            cout << "ID not found.\n";
    }

    return 0;
}
