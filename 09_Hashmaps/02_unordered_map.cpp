#include <bits/stdc++.h>
using namespace std;

int main()
{
    // It is implemented using hashing.
    // It is formed by combination of  Key-value pair and hashed/mapped value.
    // In unordered map, order of key is not preserved ,it is stored by combination of  Key-value pair and hashed/mapped value.

    ///////////////////////////////// Time complexity of map //////////////////////////////////////////////////////
    // 1. Insert() --> O(1), O(N) worst case
    // 2. find/search/update --> O(1), O(N) worst case
    // 3. erase() --> O(1) , O(N) worst case
    // 4. count() --> O(1)
    // 5. size()/empty() --> O(1)
    ///////////////////////////////// creation /////////////////////////////////////////////////////////////
    unordered_map<string, int> mt;

    // Insertion

    // Type-1
    pair<string, int> pt = make_pair("soham", 3);
    mt.insert(pt);

    // Type-2
    pair<string, int> pt1("sachin", 4);
    mt.insert(pt1);

    // Type-3
    mt["abc"] = 9;
    mt["raghu"] = 78;
    mt["ghuge"] = 45;

    ///////////////////////////////// traversing //////////////////////////////////////////////////////
    cout << "Traversing through map" << endl;

    // Type-1
    unordered_map<string, int>::iterator it = mt.begin();
    // auto it = mt.begin();

    while (it != mt.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout << endl;

    // Type-2
    for (auto temp : mt)
    {
        cout << temp.first << " " << temp.second << endl;
    }
    cout << endl;

    ///////////////////////////////////////// Updation of map ////////////////////////////////////////////////////////
    cout << "Updation of map" << endl;
    // if key_pair present it will update ,if not it will create that key_value pair

    cout << mt.size() << endl;
    mt["ghuge"] = 56; // This is already present, so it will update the value
    cout << mt.size() << endl;
    mt["aniket"] = 23; // This is not present , so it will create this key_value pair in map
    cout << mt.size() << endl;

    /////////////////////////////////////////// searching map //////////////////////////////////////////////////////
    cout << "searching through map " << endl;
    // It will return frequency of key ,if it is present
    // If key is not present , then it will insert that key_value pair and value=0 and return 0;

    cout << mt.size() << endl;
    cout << mt["sachin"] << endl;
    cout << mt["mouse"] << endl;
    cout << mt.size() << endl;

    ///////////////////////////////////////// count function to check presence ////////////////////////////////////////
    cout << "cout function of map" << endl;
    // If key is present, then it will return 1 , if not then 0

    cout << mt.size() << endl;
    cout << mt.count("sachin") << endl;
    cout << mt.count("computer") << endl;
    cout << mt.size() << endl;

    //////////////////////////////////////// erase function of map ///////////////////////////////////////////////
    cout << "erase function of map" << endl;
    // It will erase the key_value pair if that key present , if not it will not erase anything.

    cout << mt.size() << endl;
    mt.erase("abc");
    cout << mt.size() << endl;
    mt.erase("pc");
    cout << mt.size() << endl;

    return 0;
}