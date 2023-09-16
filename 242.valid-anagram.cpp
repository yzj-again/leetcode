/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int ms = s.length();
        int mt = t.length();
        if(ms!=mt){
            return false;
        }
        int ans[26]={0};
        // 可以用unordered set实现
        for(int i=0;i<ms;i++){
            ans[s[i]-'a']++;
            ans[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(ans[i]!=0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

