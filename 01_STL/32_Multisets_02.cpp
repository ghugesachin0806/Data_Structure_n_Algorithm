// Question of Multiset
// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
// Monk and the Magical Candy Bags
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        multiset<long long> bags;
        for(int i=0;i<n;i++)
        {
            long long x;
            cin>>x;
            bags.insert(x);
        }
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            auto it=bags.end();
            --it;
            long long temp=(*it);
            sum=sum+temp;
            bags.erase(*it);
            temp=temp/2;
            bags.insert(temp);
        }
        cout<<sum<<endl;
    } 

}
// -> 1
// -> 5 3
// -> 2 1 7 4 2

// 14