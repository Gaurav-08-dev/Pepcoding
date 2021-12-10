/****** using priority queue ****/
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min-heap
        
    for(int i=0;i<arr.size();i++){
        pq.push({abs(arr[i]-x),arr[i]});
    }
    
    vector<int> ans;
    
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    
    for(int i: ans)
    {
        cout<<i<<" ";
    }


/***************** using binary search *********/
    class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        
        
        
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
        
    }
};