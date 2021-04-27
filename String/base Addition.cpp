#include<bits/stdc++.h>

using namespace std;



int getSum(int b, int n1, int n2) {
    // write your code here
    
   int tsum; 
   int carry=0;
   int ans=0;
   int exp1=0;
   while(n1>0 or n2>0 or carry!=0)
   {

    int t1=n1%10;
    n1/=10;
    int t2=n2%10;
    n2/=10;
    tsum=t1+t2+carry;
    int val=tsum%b;
    carry=tsum/b;
    ans+=val*pow(10,exp1);
    exp1++;
    }
return ans;
    
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getSum(b, n1, n2) << endl;
}