/*

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/
//压缩空间复杂度，判断第j个时，只需要上一轮j+1的记录，再往前的轮次数据可以被覆盖
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> result(B.size()+1,0);
        int Max = 0;
        for(int i=A.size()-1;i>=0;i--){
            for(int j=0;j<B.size();j++){
                    Max = max(Max,result[j] = A[i]==B[j] ? result[j+1]+1:0);
            }
        }
        return Max;
    }
};