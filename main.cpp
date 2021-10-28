#include <iostream>
using namespace std;
#include <ctime>

#include "selectionSort.cpp"
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"

const int ARRAY_SIZE = 10;
const int LARGE_SIZE = 10000;

void printArray(string a[])
{
    cout << "The array content is: ";
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sortedPrint(string a[])
{
    cout << "The array, now sorted, is: ";
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void testAll()
{
    clock_t clockStart, clockEnd;
    cout.precision(8);
    cout << fixed;
    int largeArray[LARGE_SIZE];

    cout << "Sorting an array of " << LARGE_SIZE << " integers in reversed order (9999, 9998, ... , 1, 0)." << endl;

    for(int i=0; i<LARGE_SIZE; i++)
    { largeArray[i] = LARGE_SIZE - i; }
        cout << "Sorting using Bubble Sort:    ";
        clockStart = clock();
        bubbleSort(largeArray, 300);
        clockEnd = clock();
        cout << "runtime was " << static_cast<double>(clockEnd-clockStart) / CLOCKS_PER_SEC << " seconds." << endl;


    for(int i=0; i<LARGE_SIZE; i++)
    { largeArray[i] = LARGE_SIZE - i; }
        cout << "Sorting using Selection Sort:    ";
        clockStart = clock();
        selectionSort(largeArray, LARGE_SIZE);
        clockEnd = clock();
        cout << "runtime was " << static_cast<double>(clockEnd-clockStart) / CLOCKS_PER_SEC << " seconds." << endl;


    for(int i=0; i<LARGE_SIZE; i++)
    { largeArray[i] = LARGE_SIZE - i; }
        cout << "Sorting using Insertion Sort:    ";
        clockStart = clock();
        insertionSort(largeArray, LARGE_SIZE);
        clockEnd = clock();
        cout << "runtime was " << static_cast<double>(clockEnd-clockStart) / CLOCKS_PER_SEC << " seconds." << endl;


    for(int i=0; i<LARGE_SIZE; i++)
    { largeArray[i] = LARGE_SIZE - i; }
        cout << "Sorting using Merge Sort:    ";
        clockStart = clock();
        mergeSort(largeArray, 0, LARGE_SIZE-1);
        clockEnd = clock();
        cout << "runtime was " << static_cast<double>(clockEnd-clockStart) / CLOCKS_PER_SEC << " seconds." << endl;

}

int main() {

    string a[ARRAY_SIZE] = {"H","E","L","L","O","W","O","R","L","D"};
    char option;

    cout << "------------------------------------------"<<endl;
    cout << "       Testing Sorting Algorithms:"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "       S -> Selection Sort" << endl;
    cout << "       I -> Insertion Sort" << endl;
    cout << "       B -> Bubble Sort" << endl;
    cout << "       M -> Merge Sort" << endl;
    cout << "       A -> All and Compare" << endl;
    cout << "------------------------------------------"<<endl;
    cout << " Select Option [S, I, B, M, A]:";
    cin >> option;

    switch (toupper(option)) {
        case 'S':
            printArray(a);
            cout << "Sorting using Selection Sort"<<endl;
            selectionSort(a, ARRAY_SIZE);
            cout << "DONE!" << endl;
            break;

        case 'B':
            printArray(a);
            cout << "Sorting using Bubble Sort"<<endl;
            bubbleSort(a,ARRAY_SIZE);
            cout << "DONE!" << endl;
            break;

        case 'I':
            printArray(a);
            cout << "Sorting using Insertion Sort"<<endl;
            insertionSort(a,ARRAY_SIZE);
            cout << "DONE!" << endl;
            break;

        case 'M':
            printArray(a);
            cout << "Sorting using Merge Sort" << endl;
            mergeSort(a,0,ARRAY_SIZE-1);
            cout << "DONE!" << endl;
            break;

        case 'A':
            testAll();
            exit(0);

        default:
            cout << "INVALID OPTION" << endl;
    }

    if(toupper(option) == 'S' || toupper(option) == 'I' || toupper(option) == 'B'|| toupper(option) == 'M')
    { sortedPrint(a); }

    return 0;
}
