#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &mat){
    
    int count=0;
    int i=0,j=mat[0].size()-1;
    
    while(i<mat.size() and j>=0){
        
        while(mat[i][j]>0){
            j--;
        }
        count+=j+1;
        i++;
    }
    return count;
}
int main(){
    
    int n;
    cin>>n;
    
    vector<vector<int>> mat;
    
    for(int i=0;i<n;i++){
        
        vector<int> temp;
        
        for(int j=0;j<n;j++){
            
            int temp1;
            cin>>temp1;
            temp.push_back(temp1);
        }
        mat.push_back(temp);
    }
    
    cout<<solve(mat);
    
}