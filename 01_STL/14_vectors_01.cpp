#include <bits/stdc++.h>
using namespace std;

// vectors can be globally defined upto 10^7 and locally upto 10^5
void print_vector(vector<int> m) // here datatype given in vector '<>' brackets for vectors
{
    cout << "size of vector - " << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vect1={12,2,3,4,5,6,7};  // Inputs give - 1st way
    print_vector(vect1);

    ////////////////////////////////////////////////////////////////////////////////////////

    vector<int> vect2{12,23,33,45,56,78,89};  // Inputs given - 2nd way
    print_vector(vect2);

    ///////////////////////////////////////////////////////////////////////////////////

    vector<int> v; // size of vector not needed because of its dynamic nature
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i); // taking elements in vector one by one
    }
    print_vector(v);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<int> pro(7); // here we can also assign size for vector, Initially all the elements in the given size vector are zero.

    cout << "size of vector pro " << pro.size() << endl;

    print_vector(pro);

    pro.push_back(11); // Here this '11' element adds after the all the elements given in sized array , due to added element its size also increases
    print_vector(pro);

    vector<int> nop(10, 3); // Here all the 10 elements in nop vector have value equal to 3.
    print_vector(nop);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    v.pop_back(); // here pop_back removes last element from the vector
    print_vector(v);

    vector<int> v2 = v; // we can also copy one vector into other easily
                        // This is not possible in arrays

    print_vector(v2);

    vector<int> &v3 = v; // Here v3 and v are same vector with different name are generated

    v3.pop_back(); // here due to this v3 operation v vector also get affected

    print_vector(v);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> mr;
    cout << "Enter seven element" << endl;
    for (int i = 0; i < n; i++)
    {
        int inp; // Inputs taken from user , this process is used
        cin >> inp;
        mr.push_back(inp);
    }

    print_vector(mr);
    return 0;
}

// size of vector - 7
// 0 1 2 3 4 5 6
// size of vector pro 7
// size of vector - 7
// 0 0 0 0 0 0 0  <------ all the elements are zero for given size vector
// size of vector - 8
// 0 0 0 0 0 0 0 11 <----------- Here 11 added at last
// size of vector - 10
// 3 3 3 3 3 3 3 3 3 3
// size of vector - 6
// 0 1 2 3 4 5  <----- here last element of v vector get removed due to pop_back function
// size of vector - 6
// 0 1 2 3 4 5   <----- Here v gets copied into v2 vector
// size of vector - 5
// 0 1 2 3 4
// Enter seven element
// 15 12 23 69 78 78 52
// size of vector - 7
// 15 12 23 69 78 78 52