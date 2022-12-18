// Sets have unique values, there is no duplication/repitation for values in sets
// Sets follow ordered/sorted behavoir while accessing/printing the values of sets

#include <bits/stdc++.h>
using namespace std;

void print_me(set<int> str)
{
    cout << "set size -" << str.size() << endl;
    cout << "Printed using function - " << endl;
    for (auto mp : str) // Elements are printed in sorted ordered with unique values
    // Ranged based loops and auto keyword is used to print elements in sets
    {
        cout << mp << endl;
    }
}

int main()
{

    // In sets indexing can not be used
    set<int> st;   // sets can be of any datatype like string, float or any datatype , like container or complex datatype
    st.insert(56); // Insertion elements in sets
    st.insert(90); // Time complexity of insertion and access is O(log n)
    st.insert(34);
    st.insert(55);
    st.insert(23);
    st.insert(90); // Duplicate value not get included into sets , only unique are in sets
    cout << "Printed using for loop -" << endl;

    for (auto it = st.begin(); it != st.end(); it++) // Elements are printed in sorted ordered with unique values
    // Printing elements in sets using iterator
    {
        cout << (*it) << endl;
    }
    print_me(st);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    set<string> vect;
    vect.insert("sachin");
    vect.insert("rohan");
    vect.insert("mohan");
    vect.insert("rahul");
    vect.insert("abcd");
    vect.insert("sachin"); // Duplicate value will not be included here

    for (auto ptr : vect) // Here all strings are printed uniquely in lexiographical order
    {
        cout << ptr << endl;
    }

    auto it = vect.find("sachin");
    if (it != vect.end())
    {
        cout << "using find() function - " << (*it) << endl;
    }

    vect.erase("sachin"); // It will erase sachin value from set
    // vect.erase(iterator/value); // here iterator pointing to that element which we have to erase
    cout << "Elements after erase operation" << endl;
    for (auto kp : vect)
    {
        cout << kp << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    set<string> vect2;
    cout << "Enter the no. of strings to be insert - " << endl;
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        string me; // Another way of taking input from user
        cin >> me;
        vect2.insert(me);
    }
    cout << endl;
    cout << "All the entered strings are get printed in lexiographical ordered" << endl;
    for (auto gt : vect2) // All the strings get printed in sorted lexiographical order uniquely
    {
        cout << gt << endl;
    }
}
// Printed using for loop -
// 23
// 34
// 55
// 56
// 90
// set size -5
// Printed using function -
// 23
// 34
// 55
// 56
// 90
// abcd
// mohan
// rahul
// rohan
// sachin
// using find() function - sachin

// Elements after erase operation
// abcd
// mohan
// rahul
// rohan
// Enter the no. of strings to be insert -
// -> 8
// -> sachin
// -> sachin
// -> rohan
// -> monesh
// -> sachin
// -> monesh
// -> soham
// -> rohan

// All the entered strings are get printed in lexiographical ordered
// monesh
// rohan
// sachin
// soham