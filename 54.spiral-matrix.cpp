/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startX=0,startY=0;
        int m = matrix.length;
        int n= matrix[0].length;
        int loop=max(m,n)/2;
        int offset = 1;
        int i,j;
        while (loop--)
        {
            i=startX;
            j=startY;
            for(j=startY;j<n-offset;j++){
                cout<<matrix[startX][j];
            }
            for(i=startX;i<m-offset;i++){
                cout<<matrix[i][j];
            }
            for(;j>startY;j--){
                cout<<matrix[i][j];
            }
            for(;i>startX;i--){
                cout<<matrix[i][j];
            }
            startX++;
            startY++;
            offset++;
        }
    
        
    }
};
// @lc code=end

