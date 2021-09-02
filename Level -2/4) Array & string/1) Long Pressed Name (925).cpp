bool isLongPressedName(string name, string typed) {
        
        
        if(name.size() > typed.size()) return false;
        
        int i=0; int j=0;
        
        while(i<name.size() and j<typed.size())
        {
            if(name[i]==typed[j])
            {
                i++; j++;
            }
            else if(0<=i-1 and name[i-1]==typed[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        
        
        while(j < typed.size())
        {
            if(typed[j] != name[i-1])
            {
                return false;
            }
            j++;
        }
        
        return i<name.size() ? false  : true;
    }