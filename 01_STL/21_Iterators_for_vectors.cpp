// In map and sets , we don't have indexing to access the element like vectors where we access the elements
// using indexing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect;
    for (int i = 0; i < 7; i++)
    {
        vect.push_back(i);
    }

    vector<int>::iterator it = vect.begin(); // iteraor declared here

    cout << *it << endl;       // First element of vector printed using iterator
    cout << *(it + 1) << endl; // Second element of vector printed using iterator
    cout << *(it + 2) << endl; // Third element of vector printed using iterator

    cout << "///////////////////////////////////////////" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Generally, use this method to print the elements
    vector<int> vect2;
    for (int i = 0; i < 7; i++)
    {
        vect2.push_back(i);
    }

    vector<int>::iterator pt;

    for (pt = vect2.begin(); pt != vect2.end(); pt++) // here vector can be printed like this using iterator, here we use (pt++) in 'for loop'.
    {
        cout << *(pt) << " ";
    }
    cout << endl;
    cout << "/////////////////////////////////////////////////////" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<int> vect3;
    for (int i = 0; i < 8; i++)
    {
        vect3.push_back(i);
    }

    vector<int>::iterator ptu;

    for (ptu = vect3.begin(); ptu != vect3.end(); ptu = ptu + 1) // here vector can be printed like this using iterator, here we use (pt+1) in 'for loop'.
    {                                                            // here we can use (ptu+1) for vector only due to its contigous stored nature in memory,
        cout << *(ptu) << " ";                                   // we can't use (ptu+1) for map or set where all elements randomly stored and
    }                                                            // where (ptu+1) point to next location not next element,(ptu++ or ++ptu) points to next element
    cout << endl;                                                // so we use (++ptu or ptu++) for map and set , where elements are randomly stored
    cout << "/////////////////////////////////////////////////////" << endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // vectors -> (pt+1) or (pt++) or (++pt) , to point next element
    // map and set -> (++pt) or (pt++) , to point next element
}

// 0
// 1
// 2
// ///////////////////////////////////////////
// 0 1 2 3 4 5 6
// /////////////////////////////////////////////////////
// 0 1 2 3 4 5 6 7
// /////////////////////////////////////////////////////