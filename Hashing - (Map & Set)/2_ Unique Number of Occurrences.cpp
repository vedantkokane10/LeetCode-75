/*
1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false
*/

bool uniqueOccurrences(vector<int>& arr) {
    // we have to return if frequency of any elements is same
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    set<int> s1;
    for(auto x:mp){
        if(s1.find(x.second) != s1.end()){
            return 0;
        }
        else{
            s1.insert(x.second);
        }
    }
    return 1;
}
