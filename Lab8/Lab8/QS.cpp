//
//  QS.cpp
//  Lab8
//
//  Created by Austin Tebbs on 11/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "QS.h"
#include <sstream>

QS::~QS()
{
    clear();
}

/*
 * sortAll()
 *
 * Sorts elements of the array.  After this function is called, every
 * element in the array is less than or equal its successor.
 *
 * Does nothing if the array is empty.
 */

void QS::sortAll()
{
    sort(0, (size-1));
}

void QS::sort(int left, int right)
{
    if (left < right)
    {
        int pivot = medianOfThree(left, right);
        pivot = partition(left,right,pivot);
        sort(left, (pivot-1));
        sort((pivot+1), right);
    }
}

/*
 * medianOfThree()
 *
 * The median of three pivot selection has two parts:
 *
 * 1) Calculates the middle index by averaging the given left and right indices:
 *
 * middle = (left + right)/2
 *
 * 2) Then bubble-sorts the values at the left, middle, and right indices.
 *
 * After this method is called, data[left] <= data[middle] <= data[right].
 * The middle index will be returned.
 *
 * Returns -1 if the array is empty, if either of the given integers
 * is out of bounds, or if the left index is not less than the right
 * index.
 *
 * @param left
 * 		the left boundary for the subarray from which to find a pivot
 * @param right
 * 		the right boundary for the subarray from which to find a pivot
 * @return
 *		the index of the pivot (middle index); -1 if provided with invalid input
 */
int QS::medianOfThree(int left, int right)
{
    if ( size == 0 )
    {
        return -1;
    }
    if (left >= right || right > size-1 || left < 0)
    {
        return -1;
    }
    int middle_index = (left + right) / 2;
    
    if (array[left] > array[middle_index])
    {
        int temp = array[left];
        array[left] = array[middle_index];
        array[middle_index] = temp;
    }
    if(array[left] > array[right])
    {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
    if(array[middle_index] > array[right])
    {
        int temp = array[middle_index];
        array[middle_index] = array[right];
        array[right] = temp;
    }
    
    return middle_index;
}

/*
 * Partitions a subarray around a pivot value selected according to
 * median-of-three pivot selection.
 *
 * The values which are smaller than the pivot should be placed to the left
 * of the pivot; the values which are larger than the pivot should be placed
 * to the right of the pivot.
 *
 * Returns -1 if the array is null, if either of the given integers is out of
 * bounds, or if the first integer is not less than the second integer, or if the
 * pivot is not between the two boundaries.
 *
 * @param left
 * 		the left boundary for the subarray to partition
 * @param right
 * 		the right boundary for the subarray to partition
 * @param pivotIndex
 * 		the index of the pivot in the subarray
 * @return
 *		the pivot's ending index after the partition completes; -1 if
 * 		provided with bad input
 */
int QS::partition(int left, int right, int pivotIndex)
{
    if(array==NULL)
        return -1;
    if(pivotIndex>right||pivotIndex<left)
        return -1;
    if(left<0 || right>size-1 || left>right)
        return -1;
    pivotIndex=medianOfThree(left,right);
    //cout<<"PIVOT VALUE: "<<array[pivotIndex]<<endl;
    int small[size];
    int large[size];
    int equal[size];
    int largecount=0;
    int smallcount=0;
    int equalcount=0;
    for(int i=left;i<=right;i++)
    {
        if(array[i]<array[pivotIndex])
        {
            //cout<<array[i]<<"<"<<array[pivotIndex]<<endl;
            small[smallcount]=array[i];
            //cout<<"SMALL: "<<small[smallcount]<<endl;
            smallcount++;
        }
        else if(array[i]>array[pivotIndex])
        {
            //cout<<array[i]<<">"<<array[pivotIndex]<<endl;
            large[largecount]=array[i];
            //cout<<"LARGE: "<<large[largecount]<<endl;
            largecount++;
        }
        else if(array[i]==array[pivotIndex])
        {
            //cout<<array[i]<<"="<<array[pivotIndex]<<endl;
            equal[equalcount]=array[i];
            //cout<<"EQUAL: "<<equal[equalcount]<<endl;
            equalcount++;
        }
    }
    // cout<<"LARGE AT 0: "<<large[0]<<endl;
    // cout<<"SMALL AT 0: "<<small[0]<<endl;
    // cout<<"EQUAL AT 0: "<<equal[0]<<endl;
    // cout<<"Small: [";
    // for(int i=0;i<smallcount;i++)
    // {
    // 	cout<<small[i];
    // 	if(i<smallcount-1) cout<<", ";
    // }
    // cout<<"]"<<endl;
    // cout<<"Equal: [";
    // for(int i=0;i<equalcount;i++)
    // {
    // 	cout<<equal[i];
    // 	if(i<equalcount-1) cout<<", ";
    // }
    // cout<<"]"<<endl;
    // cout<<"Large: [";
    // for(int i=0;i<largecount;i++)
    // {
    // 	cout<<large[i];
    // 	if(i<largecount-1) cout<<", ";
    // }
    // cout<<"]"<<endl;
    
    for(int i=0;i<smallcount;i++)
    {
        array[left+i]=small[i];
    }
    for(int i=0;i<equalcount;i++)
    {
        array[left+smallcount+i]=equal[i];
    }
    for(int i=0;i<largecount;i++)
    {
        array[left+smallcount+equalcount+i]=large[i];
    }
    return left+smallcount;

}

/*
 * Produces a comma delimited string representation of the array. For example: if my array
 * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
 * with no trailing comma.  The number of cells included equals the number of values added.
 * Do not include the entire array if the array has yet to be filled.
 *
 * Returns an empty string, if the array is NULL or empty.
 *
 * @return
 *		the string representation of the current array
 */
string QS::getArray()
{
    if(size==0)
        return "";
    stringstream arraystream;
    //arraystream<<"{";
    for(int i=0;i<size;i++)
    {
        arraystream<<array[i];
        if(i!=size-1)
        {
            arraystream<<",";
        }
    }
    
    //arraystream<<"}"<<endl;
    return arraystream.str();
}

/*
 * Returns the number of elements which have been added to the array.
 */
int QS::getSize()
{
    return size;
}

/*
 * Adds the given value to the end of the array starting at index 0.
 * For example, the first time addToArray is called,
 * the give value should be found at index 0.
 * 2nd time, value should be found at index 1.
 * 3rd, index 2, etc up to its max capacity.
 *
 * If the array is filled, do nothing.
 */
void QS::addToArray(int value)
{
   	if(size < capacity)
    {
        array[size]=value;
        size++;
    }
}

/*
 * Dynamically allocates an array with the given capacity.
 * If a previous array had been allocated, delete the previous array.
 * Returns false if the given capacity is non-positive, true otherwise.
 *
 * @param
 *		size of array
 * @return
 *		true if the array was created, false otherwise
 */
bool QS::createArray(int Capacity)
{
    if(!arrayAvailable)
    {
        array = new int[Capacity];
        arrayAvailable=true;
        capacity = Capacity;
        return true;
    }
    else
    {
        clear();
        createArray(Capacity);
    }
    return false;
}

/*
 * Resets the array to an empty or NULL state.
 */
void QS::clear()
{
   	int* temp=array;
    delete[] temp;
    array=NULL;
    capacity=0;
    arrayAvailable=false;
    size=0;
}