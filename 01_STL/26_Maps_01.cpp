// Here instead of hashing we can also use Maps for calculating frequency , if range is greater than 10e5 or 10e7 ,
// where hashing cannot be used if elements size is greater than 10e5 (in local ) and 10e7 in (in global )

// Generally use unordered_map for hashing purpose because it not take much time complexity like odered map
// O(log n) - This time complexity is taken by odered map or map for access or insertion of each element
// O(1)     -  This time complexity is taken by unordered_map for access or insertion of each element
// To save time complexity use unordered_map

#include <bits/stdc++.h>
using namespace std;
// Map stored the elements in key-value pair
// pairs stored in map is not in random form in memory
// Every 'key' is unique in map , there is no duplicate keys in map
// While printing map , it will print according to sorting order of 'key' value , either key is string , int or float , it will get printed in sorted order .

void print_map (map<int,int> pd)
{
    cout<<"Printed using function "<<endl;
    cout<<pd.size()<<endl;
    for(auto kr: pd)
    {
        cout<<kr.first<<" "<<kr.second<<endl;
    }
}

int main()
{
    map<int, string> vect; // Here any complex datatype can be used inside map
    vect[1] = "str"; // here O(log n) time complexity is taken by compiler for accessing and insertion values in map
    vect[9] = "btr";
    vect[7] = "ltr";
    vect[3] = "ztr";
    vect[11]; // here by default empty string will be taken by compiler, If 'value' is 'int' here then zero will be taken by compiler
    vect.insert({5, "ptr"});

    map<int, string>::iterator it;

    cout << "First method to print the map" << endl;
    // here for accessing each value take O(log n) time complexity
    for (it = vect.begin(); it != vect.end(); it++) // here the map will get printed in sorted order according to key values , whatever the input pattern is there
    {
        cout << (*it).first << " " << (*it).second << endl;
        // cout << it->first << " " << it->second << endl;
    }

    cout << "Second method to print the map" << endl;
    for (auto pr : vect)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Here we are calculating string frequency and storing the string and frequency in map
    map<string, int> vect3;
    cout << "Enter the Input for total strings -";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) // Here Obersve the loop carefully
    {
        string str;
        cin >> str;
        vect3[str] = vect3[str] + 1; // Here using vect3[str] automatically str string is taken in map and its 'value' is taken as 'zero',
        // vect[str]++
    }

    for (auto pt : vect3) // Here strings will printed in lexiographical order with its frequency
    {
        cout << pt.first << " " << pt.second << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    map<int, int> vect2;
    vect2[2]; // here compiler take zero value by default for this key
    vect2[7] = 23;
    vect2[7] = 67; // here key should be unique, so vect2[7] will take last input value which is 67;
    vect2[8] = 90;
    vect2[3] = 78;
    vect2[5] = 45;

    cout<<"One method of printing "<<endl;
    for (auto ty : vect2)
    {
        cout << ty.first << " " << ty.second << endl;
    }

    print_map(vect2);
    /////////////////////////////////////////////////////////////////////////////////
    // here below mp is iterator
    // find() operation takes O(log n) time complexity
    auto mp = vect2.find(3); // Here find() will return iterator , pointing to entered key pair
    if (mp == vect2.end())
    {
        cout << "No value";
    }
    else
    {
        cout << "key-value pair" << endl;
        cout << (*mp).first << " " << (*mp).second << endl;
        // cout<<mp->first<<" "<<mp->second<<endl;
    }
    //////////////////////////////////////////////////////////////////////////////////

    vect2.erase(8); // here 'key-value' pair will be get deleted where 8 is its 'value'
    // vect2.erase(key/value/iterator) // here anything can be given to erase() function

    //////////////////////////////////////////////////////////////////////////////////

    vect2.clear();        // It will clear all map 'key-value' pair
    cout << vect2.size(); // Now it will return zero value due to clear function
}

// 1 str
// 3 ztr
// 5 ptr
// 7 ltr
// 9 btr
// 11 
// Second method to print the map
// 1 str
// 3 ztr
// 5 ptr
// 7 ltr
// 9 btr
// 11
// Enter the Input for total strings -8
// -> sachin
// -> rohan
// -> mohan
// -> soham
// -> sachin
// -> sachin
// -> soham
// -> sachin
// mohan 1
// rohan 1
// sachin 4
// soham 2
// One method of printing
// 2 0
// 3 78
// 5 45
// 7 67
// 8 90
// Printed using function
// 5
// 2 0
// 3 78
// 5 45
// 7 67
// 8 90
// key-value pair
// 3 78
// 0