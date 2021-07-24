// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int n, int row,int col,vector<string> &ans,vector<vector<int>> &m,vector<vector<int>> &visited,int drow[],int dcol[],string moves)
    {
        if(row==n-1 and col==n-1)
        {
            ans.push_back(moves);
            return;
        }
        string dir="DLRU";
        
        for(int i=0;i<4;i++)
        {
            int nextRow= row + drow[i];
            int nextCol=col + dcol[i];
            
            if(nextRow>=0 and nextCol>=0 and nextRow< n and nextCol<n and !visited[nextRow][nextCol] and m[nextRow][nextCol]==1)
            {
                visited[row][col]=1;
                solve(n,nextRow,nextCol,ans,m,visited,drow,dcol,moves + dir[i]);
                visited[row][col]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        int drow[]={1,0,0,-1};
        int dcol[]={0,-1,1,0};
        if(m[0][0]==1)
            solve(n,0,0,ans,m,visited,drow,dcol,"");
            
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends