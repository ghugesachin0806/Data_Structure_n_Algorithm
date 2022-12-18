// Generally use unordered_map for hashing purpose because it not take much time complexity like odered map
// O(log n) - This time complexity is taken by odered map or map for access or insertion of each element
// O(1)     -  This time complexity is taken by unordered_map for access or insertion of each element
// To save time complexity use unordered_map
#include <bits/stdc++.h>
using namespace std;

// The difference between maps and unordered_maps are mentioned below
// 1. Timecomplexity
// 2. Datatype
// 3. Inbuild Implementation
// 4. unable to access in sorted order for key values

void print_me(unordered_map<int, string> tr)
{
    cout << tr.size() << endl;
    for (auto lop : tr)
    {
        cout << lop.first << " " << lop.second << endl;
    }
}

int main()
{
    // In unordered_map , every key is unique , no duplication / repeatation is not allowed for 'keys' in unordered_map
    unordered_map<int, string> mt; // Here complex datatypes can not be used
    mt[2] = "Rohan";               // Here elemnt access or insertion take O(1) time complexity
    mt[7] = "Mohan";
    mt[5] = "Sachin";
    mt[1] = "Rakesh";
    mt[8] = "Dinesh";
    mt[11] = "daniya";
    mt[2] = "Danger";            // Here in unordered_map also unique values is taken for 'keys'

    for (auto pt : mt) // Here unoredered_map printed unsorted and unordered way
    {
        cout << pt.first << " " << pt.second << endl; // Each access command for element take O(1) time complexity
    }
    cout << endl;

    // Accessing elements by function

    print_me(mt);
}
// 11 daniya
// 8 Dinesh
// 1 Rakesh
// 5 Sachin
// 7 Mohan
// 2 Rohan

// 6
// 11 daniya
// 8 Dinesh
// 1 Rakesh
// 5 Sachin
// 7 Mohan
// 2 Rohan
