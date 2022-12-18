#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect = {1, 2, 3, 4, 5, 6, 7};

    /////////////////////////////////////////////////////////////////////////
    // this method is used to shorten the for loop

    for (int pt : vect) // here all the values of vect are getting copied into 'pt' variable one by one
    {
        cout << pt << " ";
    }
    cout << endl;
    ////////////////////////////////////////////////////////////////////////
    for (int &pt : vect) // here all the values of vect are get into pt by reference one by one to print
    {
        cout << pt << " ";
    }
    cout << endl;
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    for (int pt : vect)
    {
        pt++; // here this will not affect actual values of vect vector, because pt is copy of vect element variable
    }

    for (int pt : vect)
    {
        cout << pt << " ";
    }
    cout << endl;
    /////////////////////////////////////////////////////////////////////////////////////
    for (int &pt : vect)
    {
        pt++; // here this will affect vect vector , because pt is referrance of that vector
    }
    for (int pt : vect)
    {
        cout << pt << " ";
    }
    cout << endl;
    /////////////////////////////////////////////////////////////////////////////////////
}

// 1 2 3 4 5 6 7
// 1 2 3 4 5 6 7
// 1 2 3 4 5 6 7
// 2 3 4 5 6 7 8