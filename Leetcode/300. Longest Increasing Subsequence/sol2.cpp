/*

https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Approch :

In this question we are need to find the largest increasing subsequesnce.

So in this approch We will try to optimise the prev solution in which we used the dp array to store the largest increasing 
subsequence until index i.

So the problem with previous solution was we were reruning the loop from 0 to index. So we can futher optimise this by 
introducing binary search.
breakdown :
We will construct an array in which will be a basically a set of all can contribute to largest increasing sub sebsequence.

for each new element we will check if the element is can be included in the set or not. 
if the element is greater then all the current element in set then oviously its going to contribute.
else if it is smaller then we will try ot include current element in the set by relacing the first element greater 
then the current element.

Notes:
This set doesnot gives the array of the Numbers in the largest increasing subsequence. it Only denotes the size of the largest 
increasing subsequence that can be formed.

eg: [5, 6 , 7 ,1]
output set will be 
=> [5]
=> [5,6]
=> [5, 6, 7]
=> [1, 6 ,7] size will the ans.
but the LIs will be [5, 6, 7] for this.



Time Complexity : O(n*lon(n))
Space Complexity : O(n) 

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
            }else{
                int it = lower_bound(v.begin(),v.end(),nums[i])- v.begin();
                v[it] = nums[i];
            }
        }
        return v.size();
    }
};