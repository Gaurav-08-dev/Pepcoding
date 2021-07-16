#include<bits/stdc++.h>

using namespace std;

int any_base_add(int ans,int prod,int b)
{

    // cout<<ans<<"\n"<<prod<<"\n";

    int sum=0;
    int carry=0;
    int exp1=0;
    while(ans>0 or prod>0 or carry!=0)
    {
            int t1=ans%10;
            ans/=10;
    
            int t2=prod%10;
            prod/=10;
            
            
            int add=t1+t2+carry;
            int val=add%b;
            carry=add/b;
            sum+=val * pow(10,exp1);
            exp1++;
    }
    
    return sum;
}

int getSum(int b, int n1, int n2) {
    // write your code here
    
    int ans=0;
    int exp_out=0;    
    
    while(n2>0)
    {
        int ln2=n2%10;
        n2/=10;
        
        int c_n1=n1;
        int prod=0;
        int exp1=0,carry=0;
        while(c_n1!=0 or carry!=0)
        {
            int ln1=c_n1%10;
            c_n1/=10;
            
            int mul=ln2 * ln1 + carry;
            int val=mul%b;
            carry=mul/b;
            prod+=val * pow(10,exp1);
            exp1++;
        }
        prod=prod * pow(10,exp_out);
        // cout<<prod<<"\n";
        ans=any_base_add(ans,prod,b);
        exp_out++;
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