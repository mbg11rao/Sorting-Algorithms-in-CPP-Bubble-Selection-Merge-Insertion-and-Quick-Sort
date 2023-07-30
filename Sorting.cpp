#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
template <typename T>
void bubbleSort(vector<T>& arr);
template <typename T>
void selectionSort(vector<T>& arr);
template <typename T>
void insertionSort(vector<T>& arr);
template <typename T>
void mergeSort(vector<T>& arr);
template <typename T>
void quickSort(vector<T>& arr);
template <typename T>
void printArray(const vector<T>& arr) {
    for (T num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
template <typename T>
int countInversions(const vector<T>& arr) {
    int n = arr.size();
    int num_inversions = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                num_inversions++;
            }
        }
    }
    return num_inversions;
}
template <typename T>
bool isLargeRange(const vector<T>& arr) {
    T max_val = *max_element(arr.begin(), arr.end());
    T min_val = *min_element(arr.begin(), arr.end());
    return (max_val - min_val > arr.size());
}
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <>
void bubbleSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
template <>
void selectionSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
template <>
void insertionSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
template <typename T>
void mergeSortHelper(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
template <typename T>
void mergeSort(vector<T>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}
template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
template <typename T>
void quickSortHelper(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}
template <typename T>
void quickSort(vector<T>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}
template <typename T>
bool isSorted(const vector<T>& arr) {
    vector<T> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    return arr == sortedArr;
}
template <typename T>
void sortUsingTechnique(vector<T>& arr, string technique) {
    if (technique == "Bubble Sort") {
        bubbleSort(arr);
    }
    else if (technique == "Selection Sort") {
        selectionSort(arr);
    }
    else if (technique == "Insertion Sort") {
        insertionSort(arr);
    }
    else if (technique == "Merge Sort") {
        mergeSort(arr);
    }
    else if (technique == "Quick Sort") {
        quickSort(arr);
    }
}
template <typename T>
string chooseSortingTechnique(const vector<T>& arr) {
    int n = arr.size();
    if (n < 10) {
        int num_inversions = countInversions(arr);
        if (num_inversions < n / 4) {
            return "Bubble Sort";
        }
        else if (num_inversions < n / 2) {
            return "Insertion Sort";
        }
        else {
            return "Selection Sort";
        }
    }
    else {
        if (isLargeRange(arr)) {
            return "Quick Sort";
        }
        else {
            return "Merge Sort";
        }
    }
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    char choice;
    cout << "Enter 'c' for character array or 'n' for integer array: ";
    cin >> choice;
    if (choice == 'c') {
        vector<char> arr(size);
        cout << "Enter " << size << " character array values:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
        string bestTechnique = chooseSortingTechnique(arr);
        if (!isSorted(arr)) {
            sortUsingTechnique(arr, bestTechnique);
            cout << "Array is sorted using " << bestTechnique << " technique." << endl;
        }
        else {
            cout << "Array is already sorted. No sorting is required." << endl;
        }
        cout << "Sorted array using " << bestTechnique << ": ";
        printArray(arr);
    }
    else if (choice == 'n') {
        vector<int> arr(size);
        cout << "Enter " << size << " integer array values:" << endl;
        for (int i = 0; i < size; ++i) 
        {
            cin >> arr[i];
        }
        string bestTechnique = chooseSortingTechnique(arr);
        if (!isSorted(arr)) {
            sortUsingTechnique(arr, bestTechnique);
            cout << " Array is sorted using " << bestTechnique << " technique." << endl;
        }
        else {
            cout << " Array is already sorted. No sorting is required." << endl;
        }
        cout << " Sorted array using " << bestTechnique << ": ";
        printArray(arr);
    }
    else {
        cout << " Invalid choice. Please enter 'c' or 'n'." << endl;
    }
    return 0;
}
