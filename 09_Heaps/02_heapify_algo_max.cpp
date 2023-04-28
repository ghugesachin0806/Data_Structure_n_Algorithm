#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    vector<int> vect;

    heap()
    {
        vect.push_back(-1);
    }

    // heapify algo
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left < vect.size() && vect[left] > vect[largest])
            largest = left;
        if (right < vect.size() && vect[right] > vect[largest])
            largest = right;

        if (largest != index)
        {
            swap(vect[largest], vect[index]);
            heapify(largest);
        }
    }

    // printing heap
    void print()
    {
        cout << "vector of heap : ";
        for (int i = 0; i < vect.size(); i++)
            cout << vect[i] << " ";

        cout << endl;
    }
};

int main()
{
    heap h;
    h.vect.push_back(21);
    h.vect.push_back(18);
    h.vect.push_back(15);
    h.vect.push_back(75);
    h.vect.push_back(36);
    h.vect.push_back(85);
    h.vect.push_back(63);
    h.vect.push_back(65);
    h.vect.push_back(89);
    h.vect.push_back(70);
    h.vect.push_back(90);
    h.vect.push_back(20);
    h.vect.push_back(100);
    h.vect.push_back(95);
    h.vect.push_back(101);
    h.print();

    // Callin g heapify function
    int size = h.vect.size() - 2;
    for (int i = (size / 2); i > 0; i--)
    {
        h.heapify(i);
    }

    h.print();
    return 0;
}

// vector of heap : -1 21 18 15 75 36 85 63 65 89 70 90 20 100 95 101
// vector of heap : -1 101 90 100 89 70 85 95 65 75 18 36 20 21 15 63