void rev(string &s)
{
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]=='a' or s[l]=='A' or s[l]=='e' or s[l]=='E' or s[l]=='i' or s[l]=='I' or s[l]=='o' or s[l]=='O' or s[l]=='u' or s[l]=='U')
        {
            if(s[r]=='a' or s[r]=='A' or s[r]=='e' or s[r]=='E' or s[r]=='i' or s[r]=='I' or s[r]=='o' or s[r]=='O' or s[r]=='u' or s[r]=='U')
            {
                char t=s[l];
                s[l]=s[r];
                s[r]=t;
                l++; r--;
            }
            else
            {
                r--;
            }
        }
        else
        {
            l++;
        }
    }
    
    // return s;
    
}

