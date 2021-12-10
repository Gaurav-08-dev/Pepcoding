#include<bits/stdc++.h>
using namespace std;


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
    int i=0,j=mat[0].size()-1;

    while(i<n and j>=0){

    	if(target>mat[i][j]){
    		i++;
    	}
    	else if(target < mat[i][j]){
    		j--;
    	}
    	else{
    		res=true;
    		break;
    	}
    }

    if(res) cout<<"true";
    else{ cout<< "false";}
}