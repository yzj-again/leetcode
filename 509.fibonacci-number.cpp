/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
/*
1.dp[i]表示第i个Fibonacci Number
2.dp[i]=dp[i-1]+dp[i-2]
3.dp[0]=0;dp[1]=1
4.从前向后
5.遍历数组
*/
// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end
