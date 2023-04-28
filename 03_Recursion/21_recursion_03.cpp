#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j)
{
    // Base case
    if (i > j)
    {
        return;
    }

    // Processing part
    swap(str[i], str[j]);
    i++;
    j--;

    // recursive relation
    reverse(str, i, j);
}

int main()
{

    string str1;
    cin >> str1;
    reverse(str1, 0, str1.size() - 1);

    cout << str1 << endl;
}

// -> sachin
// nihcas