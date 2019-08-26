/* 

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> v;
        vector<int>a(n,0);
        for(int i=0;i<n;i++)
        {
            v.push_back(a);
        }       
        
        int count=1;
        int row1=0;
        int row2=n-1;
        int col1=0;
        int col2=n-1;
        while(count!=n*n+1)
        {
            for(int i=col1;i<=col2;i++)
            {
                v[row1][i]=count;
                count++;
            }
            row1++;
            
            for(int i=row1;i<=row2;i++)
            {
                v[i][col2]=count;
                count++;
            }
            col2--;
            
            for(int i=col2;i>=col1;i--)
            {
                v[row2][i]=count;
                count++;
            }
            row2--;
            
            for(int i=row2;i>=row1;i--)
            {
                v[i][col1]=count;
                count++;
            }
            col1++;
        }
        return v;
    }
};