/*
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/


vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s1;
    // only same sign elements will be there in the answer 
    // as opposite sign elements will collide and the one with max value stays
    for(int i=0;i<asteroids.size();i++){
        int x = asteroids[i];
        if(s1.empty() || x > 0){
            s1.push(x);
        }
        else{
            while(!s1.empty() && (s1.top() > 0 && abs(x) > s1.top())){
                s1.pop();
            }
            if(!s1.empty() && s1.top() == abs(x)){
                s1.pop();
            }
            else{
                if(s1.empty() || s1.top() < 0){
                    s1.push(x);
                }
            }
        }
    }
    vector<int>ans;
    while(!s1.empty()){
        int x = s1.top();
        ans.push_back(x);
        s1.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
