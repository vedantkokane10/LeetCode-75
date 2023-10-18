/*
1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:
Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

*/

bool closeStrings(string word1, string word2) {
    unordered_map<char,int> mp1,mp2;
    if(word1.size() != word2.size()){
        return 0;
    }
    for(int i=0;i<word1.size();i++){
        mp1[word1[i]]++;
        mp2[word2[i]]++;
    }
    vector<int> v1,v2;
    for(auto x : mp1){
        v1.push_back(x.second);
        if(mp2.find(x.first) == mp2.end()){
            return 0;
        }
    }
    for(auto x : mp2){
        v2.push_back(x.second);
        if(mp1.find(x.first) == mp1.end()){
            return 0;
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<v1.size();i++){
        if(v1[i] != v2[i]){
            return 0;
        }
    }
    return 1;
}
