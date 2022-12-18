#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v; // vectors can be made of any datatype
    int n = 5;
    cout << "// INPUT //" << endl;
    for (int i = 0; i < n; i++)  // Here strings are input and stored in vector
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cout << "// Output //" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
// // INPUT //
// csdbc
// cndscn
// csdmlcsdk
// dcwdkkl
// mkd
// // Output //
// csdbc
// cndscn
// csdmlcsdk
// dcwdkkl
// mkd