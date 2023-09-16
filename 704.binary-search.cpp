/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size();
        int middle=0;
        while(left<right){
            middle= left + ((right-left)>>1);
            if(nums[middle]>target){
                right=middle;
            }
            else if(nums[middle]<target){
                left=middle+1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end

