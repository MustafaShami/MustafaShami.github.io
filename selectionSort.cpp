//
// Created by Mustafa on 7/2/2021.
//

/** Finds the largest item in an array.
 * @pre  The size of the array is >= 1.
 * @post  The arguments are unchanged
 * @param theArray  The given array
 * @param size  The number of elements in theArray
 * @return  The index of the largest entry in the array
 */
template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
    int indexSoFar = 0;  // Index of the largest entry found so far
    for(int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        //  At this point, theArray[indexSoFar] >= all entries in theArray[0...currentIndex - 1]
        if(theArray[currentIndex] > theArray[indexSoFar])
        {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar; //Index of largest entry returned
}

/**
 * @pre  None.
 * @post  The array is sorted into ascending order; the size of the array is unchanged
 * @param theArray  The array to sort.
 * @param n  The size of theArray.
 */
template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
    // last = index of the last item in the subarray of items yet to be sorted
    // largest = index of the largest item found
    for(int last = n-1; last >= 1; last--)
    {
        // At this point, theArray[last+1...n-i] is sorted, and its entries are greater that those in theArray[0...last]
        // Select the largest entry in theArray[0...last]
        int largest = findIndexOfLargest(theArray, last+1);

        // Swap the largest entry, theArray[largest], with theArray[last]
        std::swap(theArray[largest], theArray[last]);
    }
}
