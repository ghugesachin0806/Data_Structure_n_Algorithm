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

    // heap insertion
    void insert(int data)
    {
        int size = vect.size();
        int index = size;
        vect.push_back(data);

        int parent = index / 2;

        while (index > 1)
        {

            if (vect[parent] < vect[index])
            {
                swap(vect[parent], vect[index]);
                index = parent;
            }
            else
                return;

            parent = index / 2;
        }
    }

    // heap head deletion
    void delete_head()
    {
        if (vect.size() == 1)
            return;

        swap(vect[1], vect[vect.size() - 1]);

        auto it = vect.end();
        it--;
        vect.erase(it);

        if (vect.size() == 1)
            return;
        else
        {
            int index = 1;
            while (1)
            {
                int largest = index;
                int left = 2 * index;
                int right = 2 * index + 1;

                if (left < vect.size() && vect[left] > vect[largest])
                    largest = left;
                if (right < vect.size() && vect[right] > vect[largest])
                    largest = right;

                if (largest == index)
                    break;
                else
                {
                    swap(vect[largest], vect[index]);
                    index = largest;
                }
            }
        }
    }

    // element deletion
    void delete_element(int data)
    {
        int index = -1;

        for (int i = 1; i < vect.size(); i++)
        {
            if (data == vect[i])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Element not present : " << endl;
            return;
        }

        swap(vect[index], vect[vect.size() - 1]);

        auto it = vect.end();
        it--;
        vect.erase(it);

        while (1)
        {
            int largest = index;
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left < vect.size() && vect[left] > vect[largest])
                largest = left;
            if (right < vect.size() && vect[right] > vect[largest])
                largest = right;

            if (largest == index)
                break;
            else
            {
                swap(vect[largest], vect[index]);
                index = largest;
            }
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
    h.insert(21);
    h.insert(18);
    h.insert(15);
    h.insert(75);
    h.insert(36);
    h.insert(85);
    h.insert(63);
    h.insert(65);
    h.insert(89);
    h.insert(70);
    h.insert(90);
    h.insert(20);
    h.insert(100);
    h.insert(95);
    h.insert(101);
    h.print();

    h.delete_head();
    h.print();

    h.delete_element(75);
    h.print();

    return 0;
}

// vector of heap : -1 101 89 100 65 85 75 95 18 36 21 70 15 20 63 90
// vector of heap : -1 100 89 95 65 85 75 90 18 36 21 70 15 20 63
// vector of heap : -1 100 89 95 65 85 63 90 18 36 21 70 15 20