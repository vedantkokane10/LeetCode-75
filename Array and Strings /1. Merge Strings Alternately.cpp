/*
1768. Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
*/

string mergeAlternately(string word1, string word2) {
    int n = word1.size(),m=word2.size();
    string ans = "";
    int k = 0,i=0,j=0;
    while(i <n && j < m){
        if(k % 2 == 0){
            ans += word1[i];
            i++;
        }
        else{
            ans += word2[j];
            j++;
        }
        k++;
    }
    while(i<n){
        ans += word1[i];
        i++;
        k++;
    }
    while(j<m){
        ans += word2[j];
        j++;
        k++;
    }
    return ans;
}
