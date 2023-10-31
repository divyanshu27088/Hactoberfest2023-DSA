#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElementII(vector<int> &arr) {
    unordered_map<int, int> mp;
    
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }
    
    int k = arr.size() / 3;
    vector<int> m;
    
    for (auto i : mp) {
        if (i.second > k) {
            m.push_back(i.first);
        }
    }
    
    return m;
}
