/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int leftIndex=0;
        int rightIndex=nums.size()-1;
        int k=nums.size()-1;
        vector<int> out(nums.size(),0);
        while (k>=0)
        {
            if((nums[leftIndex]*nums[leftIndex])<(nums[rightIndex]*nums[rightIndex])){
                out[k--]=nums[rightIndex]*nums[rightIndex];
                rightIndex--;
            }else{
                out[k--]=nums[leftIndex]*nums[leftIndex];
                leftIndex++;
            }
        }
        return out;
    }
};
// @lc code=end

