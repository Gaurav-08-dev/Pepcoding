
#include<bits/stdc++.h>

using namespace std;


void print(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}


void countsort(vector<string> &arr,int div,int mod,int range)
{

    vector<int> fmap(range,0);

    for(int i=0;i<arr.size();i++)
    {
        int index=(stoi(arr[i],nullptr,10)/div) % mod;
        fmap[index]++;
    }

    fmap[0]--;

    for(int i=1;i<fmap.size();i++)
    {
        fmap[i]+=fmap[i-1];

    }
    string narr[arr.size()];

    for(int i=arr.size()-1;i>=0;i--)
    {
    int val=(stoi(arr[i],nullptr,10) / div) % mod;
    int index=val;
    int pos=fmap[index];
    narr[pos]=arr[i];
    fmap[index]--;
    }

    for(int i=0;i<arr.size();i++)
    {
        arr[i]=narr[i];
    }
}

void sort01(vector<string> &arr)
{
    countsort(arr,1000000,100,32);    //days
    countsort(arr,10000,100,13);    //month
    countsort(arr,1,10000,2501);    //Year
    print(arr);

}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    vector<string> arr;

    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort01(arr);
    return 0;
}