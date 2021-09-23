void solve(string& dominoes,int i, int j)
    {
        if(dominoes[i]=='L' and dominoes[j]=='L')
        {
            for(int k=i+1;k<j;k++)
            {
                dominoes[k]='L';
            }
        }
        else if(dominoes[i]== 'R' and dominoes[j]=='R')
        {
             for(int k=i+1;k<j;k++)
            {
                dominoes[k]='R';
            }
        }
        else if(dominoes[i]=='R' and dominoes[j]=='L')
        {
            i++; j--;
            while(i<j)
            {
                dominoes[i]='R';
                dominoes[j]='L';
                i++; j--;
            }
            
        }
    }
    string pushDominoes(string& dominoes) {
        
        dominoes.insert(0,"L");
        dominoes.insert(dominoes.size(),"R");
        // cout<<dominoes;
        int i=0,j=1;
        int n=dominoes.size();
        
        while(j<n)
        {
            while(dominoes[j]=='.')
            {
                j++;
            }
            
            if(j-i>1)
            {
                solve(dominoes,i,j);
            }
            i=j;
            j++;
            
        }
        
        dominoes.erase(dominoes.begin());
        dominoes.pop_back();
        

        
    return dominoes;
        
    }