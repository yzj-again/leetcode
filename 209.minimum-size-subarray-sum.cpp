/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum =0;
        int slowIndex=0;
        int subLength =0;
        // f指针先往前走，知道某个区间的值的和大于target
        // 直到大于，然后算出subLength(待定)=>得到result
        // 开始缩小区间，然后f++再次判断区间值是否大于target
        // 大于动s,缩小区间;小于动f,扩大区间
        for(int fastIndex = 0;fastIndex<nums.size();fastIndex++){
            sum+=nums[fastIndex];
            while(sum>=target){
                subLength=fastIndex-slowIndex+1;
                result=result<subLength?result:subLength;
                sum-=nums[slowIndex++];
            }
        }
        return result==INT32_MAX?0:result;
    }
};
// @lc code=end

