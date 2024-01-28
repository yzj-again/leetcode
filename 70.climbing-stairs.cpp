/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
/*
1.dp[i]:爬到第i层，有dp[i]种方法
2.dp[i]=dp[i-1]+dp[i-2]
3.dp[1]=1;dp[2]=2;
4.从前向后
5.遍历数组
*/
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end
