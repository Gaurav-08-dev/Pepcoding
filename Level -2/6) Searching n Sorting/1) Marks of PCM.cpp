#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            else {
                return a[1]>b[1];
            }
        }
        else {
            return a[0]<b[0];
        }
    }
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        vector<vector<int>> res;
        
        for(int i=0;i<N;i++){
            vector<int> temp;
            temp.push_back(phy[i]);
            temp.push_back(chem[i]);
            temp.push_back(math[i]);
            res.push_back(temp);
        }
        
        sort(res.begin(),res.end(),cmp);
        for(int i=0;i<res.size();i++){
            phy[i]=res[i][0];
            chem[i]=res[i][1];
            math[i]=res[i][2];
        }
    } 
};

// { Driver Code Starts.

int main () 
{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i];
		for (int i = 0; i < n; ++i)
		cin >> chem[i];
		for (int i = 0; i < n; ++i)
		cin >> math[i];
			
			
			
			
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 

}
