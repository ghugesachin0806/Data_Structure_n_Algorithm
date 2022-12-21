// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool redundant(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')')
            {
                bool cnt = true;
                while (st.top() != '(')
                {
                    st.pop();
                    cnt = false;
                }

                if (cnt == true)
                    return true;

                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string str;
    cin >> str;

    if (redundant(str))
        cout << "there is redudancy !" << endl;

    else
        cout << "there is no redudancy !" << endl;

    return 0;
}

// (a(a+b))
// there is redudancy !

// (a+(a+b))
// there is no redudancy !

// ((a+b)a)
// there is redudancy !

// ((a+b))
// there is redudancy !
