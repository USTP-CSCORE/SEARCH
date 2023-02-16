#include <iostream>
using namespace std;

int interpolSearch(int numbers[], int lo, int high, int key, int cnt)
{
    while (lo<=high && key >= numbers[lo] && key <= numbers[high])
    {  
        
        cout << "Number of try: "<< cnt << endl;
        int pos = lo + (((double)(high - lo)/ (numbers[high]- numbers[lo]))*(key - numbers[lo]));
        cout << "Position: " << pos << endl;
        if (numbers[pos] == key)
        {
            return pos;
        }
        if (numbers[pos] < key)
        {
            return interpolSearch(numbers, pos + 1, high, key, cnt +1) ;
        }
        if (numbers[pos] > key)
        {
            return interpolSearch(numbers, lo, pos - 1, key, cnt +1) ;
        }
    }
    return -1;
}

int main()
{
        int count = 1; 
        int numbers[10];
        cout << "Enter numbers for array: " << endl;
        for (int i = 0; i < (sizeof(numbers)/sizeof(numbers[0])); i++ )
        {
            cout << i << ": ";
            cin >> numbers[i];
        }
        int high = sizeof(numbers)/sizeof(numbers[0]) - 1;
        int key;
        cout << "Enter value to be found: ";
        cin >> key;
        int index = interpolSearch(numbers, 0, high, key, count);
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
