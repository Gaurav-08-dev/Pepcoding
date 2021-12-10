bool compare(string a, string b){
        return a+b > b+a;
    }
class Solution {
public:
    
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> container;
        
        for(int i:nums){
            container.push_back(to_string(i));
        }
        
        sort(container.begin(),container.end(),compare);
        string result;
        for(string i: container){
            result+=i;
        }
        
        return result[0]=='0'?"0":result;
        
    }
};