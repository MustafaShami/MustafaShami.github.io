//
// Created by Mustafa on 7/2/2021.
//

/** Sorts the items in an array into ascending order/
 * @pre None.
 * @post theArray in sorted into ascending order; n in unchanged.
 * @param theArray  The given array
 * @param n  The size of the array
 */
template<class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
    bool sorted = false;
    int pass = 1;
    while(!sorted && (pass < n))
    {
        //  At this point, theArray[n+1-pass...n-1] is sorted and all of its entries are > the entries in theArray[0...n-pass]
        sorted = true; // Assume sorted
        for(int index = 0; index < n - pass; index++)
        {
            // At this point, all entries in theArray[0...index-1] are <= theArray[index]
            int nextIndex = index + 1;
            if(theArray[index] > theArray[nextIndex])
            {
                std::swap(theArray[index], theArray[nextIndex]); // Exchange entries
                sorted = false;       // Signal exchange
            }
        }
        pass++;
    }
}

