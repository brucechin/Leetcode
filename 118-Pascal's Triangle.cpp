/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
/*

没啥好讲的。。

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        for(int i=0;i<numRows;i++){
            vector<int> layer(i+1,1);
            for(int j=1; j<i;j++){
                layer[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(layer);
        }
        return result;
    }
};
