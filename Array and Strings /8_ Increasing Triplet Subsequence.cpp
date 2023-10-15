/*
334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
*/

bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX,second = INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(first >= nums[i]){
            first = nums[i];
        }
        else if(second >= nums[i]){
            second = nums[i];
        }
        else{
            return true;
        }
    }
    return false;
}
