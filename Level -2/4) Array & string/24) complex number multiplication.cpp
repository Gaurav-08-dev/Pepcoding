   string complexNumberMultiply(string s1, string s2) {
         int pos=s1.find('+');
    string r1=s1.substr(0,pos);
    string i1=s1.substr(pos+1);
    i1.pop_back();
    
    
    int pos1=s2.find('+');
    string r2=s2.substr(0,pos1);
    string i2=s2.substr(pos1+1);
    i2.pop_back();
    
    int a = stoi(r1);
    int b = stoi(i1);
    int x = stoi(r2);
    int y = stoi(i2);
    string aa = to_string(a*x-b*y);
    string bb = to_string(b*x+a*y);
    return aa+"+"+bb+"i";
    }