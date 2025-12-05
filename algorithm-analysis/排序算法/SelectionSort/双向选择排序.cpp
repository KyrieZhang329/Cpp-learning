#include <iostream>
using namespace std;

void SelectionSort(int *arr,int n)
{
    int left=0;
    int right=n-1;
    while (left < right) 
    {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (arr[i] < arr[minIndex]) 
                minIndex = i;
            if (arr[i] > arr[maxIndex]) 
                maxIndex = i;
        }
        if (minIndex != left) 
        {
            int temp = arr[left];
            arr[left] = arr[minIndex];
            arr[minIndex] = temp;
            if (maxIndex == left) 
                maxIndex = minIndex;
        }
        if (maxIndex != right) 
        {
            int temp = arr[right];
            arr[right] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
        left++;
        right--;
    }
}

int main() 
{
    int arr[16]={9, 11, 13, 4, 6, 5, 7, 12, 1, 10, 15, 2, 8, 3, 16, 14};
    int size=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,size);
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    return 0;
}