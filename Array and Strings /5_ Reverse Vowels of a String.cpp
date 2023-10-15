/*
345. Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"
*/

string reverseVowels(string s) {
    string vowel = "aeiouAEIOU";
    int i = 0,j =s.size()-1;
    while(i <= j){
        if((vowel.find(s[i]) != -1) && (vowel.find(s[j]) != -1)){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        if (vowel.find(s[i]) == -1){
            i++;
        }
        else if(vowel.find(s[j]) == -1){
            j--;
        }
    }
    return s;
}
