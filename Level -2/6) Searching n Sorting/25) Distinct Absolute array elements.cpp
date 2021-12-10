#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> &arr){
    
    int count=0;
    int left=0, right=arr.size()-1;
    int prev=INT_MIN,next=INT_MAX;
    while(left<=right){
        int lval=abs(arr[left]);
        int rval=abs(arr[right]);
        
        if(lval==rval){
            
            if(lval!=prev and rval!=next){
                count++;
            }
            prev=lval;
            next=rval;
            left++ ;right--;
        }
        else if(lval > rval){
            if(lval!=prev){count++;}
            prev=lval;
            left++;
        }
        else{
            if(rval!=next) count++;
            
            next=rval;
            right--;
        }
    }
    return count;
    
}
int main(){
    
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    cout<<solve(arr);
}