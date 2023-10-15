/*
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    // vector<int> pre(n);
    // vector<int> pos(n);
    // vector<int> ans(n);
    // pre[0] = nums[0];
    // pos[nums.size()-1] = nums[nums.size()-1];
    // for(int i=1;i<nums.size();i++){
    //     pre[i] = pre[i-1] * nums[i]; 
    // }
    // for(int i=nums.size()-2;i>=0;i--){
    //     pos[i] = pos[i+1] * nums[i];
    // }
    // ans[0] =  pos[1];
    // for(int i=1;i<nums.size()-1;i++){
    //     ans[i] = pre[i-1] * pos[i+1];
    // }
    // ans[nums.size()-1] = pre[n-2];
    // return ans;

    vector<int> ans(n,1);
    int pre = 1;
    for(int i=0;i<n;i++){
        ans[i] = pre;
        pre *= nums[i];
    }
    int post = 1;
    for(int i=n-1;i>=0;i--){
        ans[i] *= post;
        post *= nums[i];
    }
    return ans;
}
