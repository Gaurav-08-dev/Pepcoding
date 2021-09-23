string maxSwap(string s1)
{
    vector<int> digits(10,-1);
    for(int i=0;i<s1.size();i++)
    {
        digits[s1[i]-'0']=i;
    }
    
    
    
    // travel and find swapping point
    
    for(int i=0;i<s1.size();i++)
    {
        int digit=s1[i]-'0';
        
        int index=i;
        for(int j=9;j>digit;j--)
        {
            if(digits[j] > i )
            {
                index=digits[j];
                break;
            }
        }
        
        if(index!=i)
        {
            swap(s1[i],s1[index]);
            break;
        }
    }
    
    return s1;
}