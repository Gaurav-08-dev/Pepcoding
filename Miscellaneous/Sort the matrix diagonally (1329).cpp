

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=mat.size()-1;i>=0;i--)
        {
            int row=i,col=0;
            while(row<mat.size() and col<mat[0].size())
            {
                temp.push_back(mat[row][col]);
                col++;
                row++;
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        
        for(int i=1;i<mat[0].size();i++)
        {
            int row=0,col=i;
            while(row<mat.size() and col<mat[0].size())
            {
                temp.push_back(mat[row][col];
                col++;
                row++;
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        
        return mat;
    }
};