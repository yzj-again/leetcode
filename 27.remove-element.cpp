/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        int fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end

