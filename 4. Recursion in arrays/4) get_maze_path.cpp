#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) 
{

    
    if(sr==dr and sc==dc)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    vector<string> ans;

    if(sc<dc)
    {
        vector <string> rres=getMazePaths(sr,sc+1,dr,dc);
        for(auto s:rres)
        {
            ans.push_back('h'+ s);
        }

    }

    if(sr<dr)
    {
    
        vector <string> rres=getMazePaths(sr+1,sc,dr,dc);
        for(auto s:rres)
        {
            ans.push_back('v'+ s);
        }

    }


    return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);
    return 0;
}

