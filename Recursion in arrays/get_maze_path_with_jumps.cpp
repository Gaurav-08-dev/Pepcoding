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

    // Horizontal
    for(int jumps=1;jumps+sc<=dc;jumps++)
    {

        vector<string> rres=getMazePaths(sr,sc+jumps,dr,dc);
        for(auto s:rres)
        {
            ans.push_back("h" + to_string(jumps) + s );
        }
    }

    // Vertical
    for(int jumps=1;jumps+sr<=dr;jumps++)
    {

        vector<string> rres=getMazePaths(sr+jumps,sc,dr,dc);
        for(auto s:rres)
        {
            ans.push_back("v" + to_string(jumps) + s);
        }
    }

    // Diagonal

    for(int jumps=1;jumps+sc<=dc and jumps+sr<=dr;jumps++)
    {

            vector<string> rres=getMazePaths(sr+jumps,sc+jumps,dr,dc);
            for(auto s:rres)
            {
                ans.push_back("d" + to_string(jumps) + s);
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

