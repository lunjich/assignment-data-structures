#include <iostream>
using namespace std;

void mergeTwoArrays(int a[], int n1, int b[], int n2, int result[], int& size) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    while (i < n1) result[k++] = a[i++];
    while (j < n2) result[k++] = b[j++];
    size = k;
}

int main() {
    int arr1[5], arr2[5], arr3[5];
    int temp[10], arrayMerg[15];
    int size1 = 5, size2 = 5, size3 = 5, tempSize, finalSize;

    cout << "Enter 5 elements for arr1 in ascending order:\n";
    for (int i = 0; i < size1; i++) cin >> arr1[i];

    cout << "Enter 5 elements for arr2 in ascending order:\n";
    for (int i = 0; i < size2; i++) cin >> arr2[i];

    cout << "Enter 5 elements for arr3 in ascending order:\n";
    for (int i = 0; i < size3; i++) cin >> arr3[i];

    mergeTwoArrays(arr1, size1, arr2, size2, temp, tempSize);
    mergeTwoArrays(temp, tempSize, arr3, size3, arrayMerg, finalSize);

    cout << "Merged array in ascending order:\n";
    for (int i = 0; i < finalSize; i++)
        cout << arrayMerg[i] << " ";

    return 0;
}
