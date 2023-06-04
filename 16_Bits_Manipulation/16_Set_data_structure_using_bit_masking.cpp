// Set data structure using bit masking

// Bit_masking only be used if array or vector have size less than or equal to 64
// Bit_masking is used in range of(0,63) for long long
// Bit_masking is used in range of(0,31) for int

#include <bits/stdc++.h>
using namespace std;

class set_bit
{
private:
    // 64 bits are there in X variable
    long long x; // so we can store the values from range (0,63) only.

public:
    set_bit()
    {
        x = 0;
    }
    void add(int k)
    {
        long long temp = 1;
        long long mask = (temp << k);
        x = (x | mask);
    }
    void remove(int k)
    {
        if (((x >> k) & 1) == 1)
        {
            long long temp = 1;
            long long mask = (temp << k);
            x = (x ^ mask);
        }
    }
    void print()
    {
        int cnt = 0;
        long long temp = x;
        while (temp != 0)
        {
            if ((temp & 1) == 1)
                cout << cnt << " ";
            temp = temp >> 1;
            cnt++;
        }
        cout << endl;
    }
};

int main()
{
    set_bit st;
    st.add(56);
    st.add(7);
    st.add(11);
    st.add(13);
    st.add(50);
    st.add(7);
    st.print(); // printing the elements

    st.remove(7);
    st.remove(50);
    st.remove(48); // removing not present element.
    st.add(32);
    st.add(53);
    st.print(); // printing the elements
}

// 7 11 13 50 56
// 11 13 32 53 56