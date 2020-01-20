/*

In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: [[0,1],[1,0]]
Output: 1
Example 2:

Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Note:

1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1

*/

class Solution {
public:

    void flood_fill(vector<vector<int>>& ar,int x,int y,int m,int n,int colour,set<pair<int,int>> &s,int k)
    {   if(x<0||y<0||x>=n||y>=m||ar[x][y]!=colour)
        {
            return ;
        }
        ar[x][y]=k;
        pair<int,int> p=make_pair(x,y);
        if(s.count(p)==0 &&)
        {  //cout<<" ds";
            s.insert(p);
        }
        flood_fill(ar,x,y+1,m,n,colour,s,k);
        flood_fill(ar,x+1,y,m,n,colour,s,k);
        flood_fill(ar,x-1,y,m,n,colour,s,k);
        flood_fill(ar,x,y-1,m,n,colour,s,k);
    }
    int shortestBridge(vector<vector<int>>& A) 
    {
        int n=A.size();
        int m=A[0].size();
        set<pair<int,int>> s1;
        set<pair<int,int>> s2;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(A[i][j]==1)
                {
                    flood_fill(A,i,j,m,n,1,s1,2);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(A[i][j]==1)
                {
                    flood_fill(A,i,j,m,n,1,s2,2);
                    break;
                    flag=1;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    
     //   cout<<s1.size()<<" "<<s2.size();
        int ans=INT_MAX;
        for(auto a:s1)
        {
            for(auto b:s2)
            {
                //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
                int op=abs(a.first-b.first)+abs(a.second-b.second);
                ans=min(ans,op);
            }
        }
        return ans-1;
    }
};