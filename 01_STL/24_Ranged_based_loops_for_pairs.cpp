#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> vect={{11,2},{12,3},{13,4},{14,5}};

    for(pair<int,int> val : vect)        // this shorten range based loop is used to print vector of pairs
    {
        cout<<val.first<<" "<<val.second<<endl;
    }

}

// 11 2
// 12 3
// 13 4
// 14 5