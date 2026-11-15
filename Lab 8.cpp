#include <iostream>
using namespace std;
const int SIZE = 10;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    int arr[SIZE];
    int choice, target, result;
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];
    do
    {
        cout << "MENU";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            selectionSort(arr, SIZE);
            cout << "Array after Selection Sort:\n";
            displayArray(arr, SIZE);
        }
        else if (choice == 2)
        {
            bubbleSort(arr, SIZE);
            cout << "Array after Bubble Sort:\n";
            displayArray(arr, SIZE);
        }
        else if (choice == 3)
        {
            insertionSort(arr, SIZE);
            cout << "Array after Insertion Sort:\n";
            displayArray(arr, SIZE);
        }
        else if (choice == 4)
        {
            insertionSort(arr, SIZE);

            cout << "Enter number to search: ";
            cin >> target;

            result = binarySearch(arr, SIZE, target);

            if (result != -1)
                cout << "Number found at index " << result << endl;
            else
                cout << "Number not found.\n";
        }
        else if (choice == 5)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
