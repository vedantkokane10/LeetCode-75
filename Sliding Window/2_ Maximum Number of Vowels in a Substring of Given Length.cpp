/*
1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
*/

int maxVowels(string s, int k) {
    int i = 0 , j = 0, ans = 0, cnt = 0;
    while(j < s.size()){
        if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'i' || s[j] == 'u'){
            cnt++;
        }
        if(j-i+1 == k){
            ans = max(ans,cnt);
            if(s[i] == 'a' || s[i]  == 'e' || s[i]  == 'o' || s[i] == 'i' || s[i] == 'u'){
                cnt--;
            }
            i++;
        }
        j++;
    }
    return ans;
}
