/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int ans = 0;
       unordered_map<int, int> cnt;
       for(int i = 0, j = 0, s = 0;i<fruits.size();i++){
        if(++cnt[fruits[i]]==1){
            s++;
        }
        while(s>2){
            if(--cnt[fruits[j]]==0) {
                s--;
                cnt.erase(fruits[j]);
            }
            j++;
        }
        ans = max(ans,i-j+1);
       }
       return ans;
    }
};
// @lc code=end
/*
给定一个数组,
*/

