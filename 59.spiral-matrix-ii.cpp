/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int X=0,Y=0;// 循环的坐标
        int loop = n/2;// 循环的圈数
        int mid = n/2;// 考虑n为奇数的情况
        int count = 1;// 给每圈赋值
        int offset = 1;// 控制每次边循环的长度
        int i,j;// 每次用来循环的坐标
        while (loop--)
        {
            i=X;
            j=Y;
            for(j=Y;j<n-offset;j++){
                res[X][j]=count++;
            }
            for(i=X;i<n-offset;i++){
                res[i][j]=count++;
            }
            for(;j>Y;j--){
                res[i][j]=count++;
            }
            for(;i>X;i--){
                res[i][j]=count++;
            }
            offset+=1;
            X+=1;
            Y+=1;
        }
        if(n%2){
            res[mid][mid]=count;
        }
        return res;
    }
};
// @lc code=end

