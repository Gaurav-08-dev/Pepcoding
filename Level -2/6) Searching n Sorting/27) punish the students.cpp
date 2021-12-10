#include<bits/stdc++.h>
using namespace std;


void swap(int i,int j,int &swapcount){
    swapcount+=2;
    swap(i,j);
}
bool solve(vector<int> &arr,vector<int> &marks,int minAvg){
    
    int swapCount=0;
    for(int i=0;i<arr.size();i++){
        for(int j=1;j<arr.size() - i;j++){
            
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1],swapCount);
        }
    }
    // cout<<swapCount;
    int totalMarks=0;
    for(int i:marks){
        totalMarks+=i;
    }
    
    if((totalMarks - swapCount)/arr.size() < minAvg) return false;
    return true;
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
    
    vector<int> marks;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        marks.push_back(temp);
    }
    int minAvg;
    cin>>minAvg;

    
    if(solve(arr,marks,minAvg)){cout<<"true";}
    else{
        cout<<"false";
    }
}