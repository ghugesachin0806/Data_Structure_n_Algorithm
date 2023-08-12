#include <bits/stdc++.h>
using namespace std;

// it will points to nums[index] > target_element , from left to right , whichever comes first.


int main()
{
    vector<int> vect = {4, 11, 11, 17, 22, 27, 33, 44, 55, 66, 77, 88};

    /////////////////////////// one way ////////////////////////////////////

    // element present int the vector
    auto it1 = upper_bound(vect.begin(), vect.end(), 17);
    // vector<int>::iterator it1 = upper_bound(vect.begin(), vect.end(), 17);
    cout << it1 - vect.begin() << endl;

    // element not present in the vector
    auto it2 = upper_bound(vect.begin(), vect.end(), 37);
    // vector<int>::iterator it2 = upper_bound(vect.begin(), vect.end(), 37);
    cout << it2 - vect.begin() << endl;

    // element greater than the any element present in the vector
    auto it3 = upper_bound(vect.begin(), vect.end(), 99);
    // vector<int>::iterator it2 = upper_bound(vect.begin(), vect.end(), 99);
    cout << it3 - vect.begin() << endl;

    // element smaller than the any element present in the vector
    auto it4 = upper_bound(vect.begin(), vect.end(), 2);
    // vector<int>::iterator it2 = upper_bound(vect.begin(), vect.end(), 2);
    cout << it4 - vect.begin() << endl;

    // duplicate element present int the vector
    auto it5 = upper_bound(vect.begin(), vect.end(), 11);
    // vector<int>::iterator it1 = upper_bound(vect.begin(), vect.end(), 11);
    cout << it5 - vect.begin() << endl;

    /////////////////////////// second way ////////////////////////////////////

    int temp = upper_bound(vect.begin(), vect.end(), 27) - vect.begin();
    cout << temp << endl;
}

// 4
// 7
// 12
// 0
// 3
// 6