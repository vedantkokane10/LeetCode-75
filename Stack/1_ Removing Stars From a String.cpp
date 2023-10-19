/*
2390. Removing Stars From a String

You are given a string s, which contains stars *.
In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.
Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe"
*/

string removeStars(string s) {
    string ans = "";
    stack<char> s1;
    for(int i=s.size()-1;i>=0;i--){
        char x = s[i];
        if(x == '*'){
            s1.push(x);
        }
        else{
            if(!s1.empty() && s1.top() == '*'){
                s1.pop();
            }
            else{
                ans += s[i];
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
