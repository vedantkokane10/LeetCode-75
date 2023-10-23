/*
394. Decode String

Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/

string decodeString(string s) {
    stack<int> count;
    stack<string> str;
    int num = 0;
    string ans = "";
    for(int i=0;i<s.size();i++){
        char x = s[i];
        if(x >= '0' && x <= '9'){
            num = num * 10 + (x-'0');
        }
        else if(x == '['){
            count.push(num);
            str.push(ans);
            ans = "";
            num = 0;
        }
        else if(x == ']'){
            string temp = ans;
            ans = str.top();
            str.pop();
            int n = count.top();
            count.pop();
            while(n--){
                ans += temp;
            }
        }
        else if(isalpha(x)){
            ans += x;
        }
    }
    return ans;
}
