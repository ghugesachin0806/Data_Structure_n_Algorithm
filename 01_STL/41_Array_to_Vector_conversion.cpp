#include <bits/stdc++.h>
using namespace std;

// vector<int> vect(array_name , (array_name + size_of_array))

int main()
{
    int gfg[] = {5, 6, 7, 7, 6, 5, 5, 6};

    vector<int> vect(gfg, gfg + 8);

    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
}
// 5 6 7 7 6 5 5 6