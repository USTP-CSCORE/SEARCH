#include <iostream>
using namespace std;

int interpolSearch(int numbers[], int left, int right, int key, int count) 
{
    while (left<=right && key >= numbers[left] && key <= numbers[right]) // check if the key is in the array
    {  
        // the process is same as binary search
        cout << "Number of try: "<< count << endl;
        int pos = left + (((double)(right - left)/ (numbers[right]- numbers[left]))*(key - numbers[left])); // this formula is used instead of the mid = (left + right) / 2
        if (numbers[pos] == key)
        {
            return pos;
        }
        if (numbers[pos] < key)
        {
            return interpolSearch(numbers, pos + 1, right, key, count +1) ; // left index is adjusted higher than the position index, since the position index is already searched in line 11
        }
        if (numbers[pos] > key)
        {
            return interpolSearch(numbers, left, pos - 1, key, count +1) ; // right index is adjusted higher than the position index, since the position index is already searched in line 11
        }
    }
    return -1;
}

int main()
{
        int count = 1; // counter for calculation reference
        int numbers[10]; // you can change num of array and try some set of num
        cout << "Enter numbers for array: " << endl;
        for (int i = 0; i < (sizeof(numbers)/sizeof(numbers[0])); i++ )
        {
            cout << i << ": "; cin >> numbers[i];
        }
        int right = sizeof(numbers)/sizeof(numbers[0]) - 1;
        int key;
        cout << "Enter value to be found: ";cin >> key;
        int index = interpolSearch(numbers, 0, right, key, count);
        if (index >= 0 )
        {
            cout << "Results found in index: " << index << endl;
        }
        else
        {
            cout << "Result not found" << endl;
        }
    
    return 0;
}
