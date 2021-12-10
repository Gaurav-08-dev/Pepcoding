#include<bits/stdc++.h>
using namespace std;



bool solve(vector<int> &arr, int target){
    
    int l=0, r=arr.size();
    
    while(l<=r){
         int mid=l + (r-l)/2;
         
         if(arr[mid]==target){
             return true;
         }
         else if (arr[mid]<target){
             l=mid+1;
         }
         else{
             r=mid-1;
         }
    }
    return false;
    
}
int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> mat;
    
    for(int i=0;i<n;i++){
        
        vector<int> temp;
        
        for(int j=0;j<m;j++){
            
            int temp1;
            cin>>temp1;
            temp.push_back(temp1);
        }
        mat.push_back(temp);
    }
    
    
    int target;
    cin>>target;
    
    bool res=false;
    for(int i=0;i<n;i++){
        
        res=solve(mat[i],target);
        
        if(res==true) {
            cout<<"true";
            break;
        }
    }
    
    if(res==false) cout<<"false";
}

/*************************************************************/

int findRowIndex(vector<vector<int>> &mat, int target){
    
    int index=-1;
    int l=0, r=mat.size()-1;
    
    while(l<=r){
         int mid=l + (r-l)/2;
         
         if(mat[mid][0]<=target and target<=mat[mid][mat[0].size()-1]){
             
             index=mid;
             break;
         }
         else if (target>mat[mid][0]){
             l=mid+1;
         }
         else{
             r=mid-1;
         }
    }
    return index;
}

int findInIthRow(vector<vector<int>> &mat,int target, int row){
     int index=-1;
    int l=0, r=mat[0].size()-1;
    
    while(l<=r){
         int mid=l + (r-l)/2;
         
         if(mat[row][mid]==target){
             index=mid;
             break;
         }
         else if (target>mat[row][mid]){
             l=mid+1;
         }
         else{
             r=mid-1;
         }
    }
    return index;
    
}

bool solve(vector<vector<int>> &mat, int target){
    
   int rowIndex=findRowIndex(mat,target);
   if(rowIndex== -1) return false;
   int colIndex=findInIthRow(mat,target,rowIndex);
   return colIndex!=-1;
    
}