// Unordered_Sets have unique values, there is no duplication/repitation for values in sets
// Unordered_Sets not follow ordered/sorted behavoir while accessing/printing the values of sets
// Unordered_sets have O(log 1)-> Time complexity for accessing and inserting elements in unordered_set
// Sets have O(log n)-> Time Complexity for accessing and inserting elements in sets

// To find the element present in set or not , there unordered sets are used.

#include <bits/stdc++.h>
using namespace std;

void print_me(unordered_set<int> tre)
{
    cout << tre.size() << endl;
    for (auto ty : tre)
    {
        cout << ty << endl;
    }
}
int main()
{
    // Here elements are not in sorted/ordered manner , but each element is unique and there is no duplication/repitation of elements exists here
    unordered_set<int> vect; // Here complex datatypes can not be used like pair,vector,complex datatypes or containers inside the unordered_set
    vect.insert(56);         // Here time complexity of insertion and access is O(log 1)
    vect.insert(78);
    vect.insert(90);
    vect.insert(45);
    vect.insert(11);
    vect.insert(56);

    for (auto lp : vect) // elements are not printed in sorted manner
    {
        cout << lp << endl; // here each access is O(log 1) time complexity
    }
    cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        cout << (*it) << endl;
    }
    cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////
    print_me(vect); // Accessing elements using function
    cout << endl;
    ///////////////////////////////////////////////////////////////////////////////////////
    unordered_set<string> vect2;
    cout << "Enter the no. of strings to be insert - ";
    int h;
    cin >> h;
    for (int i = 0; i < h; i++) // Here strings input into unordered_set are shown
    {
        string str;
        cin >> str;
        vect2.insert(str);
    }

    for (auto yu : vect2) // Here strings are not printed in lexiographical order
    {
        cout << yu << endl;
    }
    cout << endl;

    for (auto it = vect2.begin(); it != vect2.end(); it++)
    {
        cout << (*it) << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    auto pt = vect2.find("sachin");
    if (pt == vect2.end())
    {
        cout << "Not there";
    }
    else
    {
        cout << "Present" << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
}
// 11
// 45
// 90
// 78
// 56

// 11
// 45
// 90
// 78
// 56

// 5
// 11
// 45
// 90
// 78
// 56

// Enter the no. of strings to be insert - 8
// -> sachin
// -> sachin
// -> krishna
// -> rohan
// -> soham
// -> rohan
// -> sham
// -> sachin
// -> sham
// -> soham
// -> rohan
// -> krishna
// -> sachin

// sham
// soham
// rohan
// krishna
// sachin

// Present