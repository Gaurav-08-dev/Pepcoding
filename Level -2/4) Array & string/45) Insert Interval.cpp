  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            return vector<vector<int>>(1, newInterval);
        }
        
        vector<vector<int>> ans;
        int firstIdx, lastIdx;
        // search the first possible overlap intervals
        firstIdx = binarySearchIntverals(intervals, newInterval[0]);
        // search the last possible overlap intervals
        lastIdx = binarySearchIntverals(intervals, newInterval[1]);

        // No the key is to arrange 3 intervals - first, new, last 
        for(int i=0; i<intervals.size(); i++) {
            if(i < firstIdx || i > lastIdx) {
                ans.push_back(intervals[i]);
            }
            else {
                // firstIdx <= i <= lastIdx
                if(firstIdx == lastIdx) {
                    // two cases in this probrom 
                    // 1. new has no overlap with others, unable to find
                    // 2. overlap only one interval
                    if(intervals[firstIdx][1] < newInterval[0]) {
                        // no overlap, with the first possible
                        ans.push_back(intervals[firstIdx]);
                        ans.push_back(newInterval);
                    }
                    else if(intervals[lastIdx][0] > newInterval[1]) {
                        // no overlap, with the last possible
                        ans.push_back(newInterval);
                        ans.push_back(intervals[lastIdx]);
                    }
                    else {
                        // over laps
                        newInterval[0] = min(intervals[lastIdx][0], newInterval[0]);
                        newInterval[1] = max(intervals[lastIdx][1], newInterval[1]);
                        ans.push_back(newInterval);
                    }
                }
                else {
                    // arrange 3 intervals - first, new, last 
                    if(i == firstIdx) {
                        // first interval overlap or not
                        if(intervals[firstIdx][1] < newInterval[0]) {
                            ans.push_back(intervals[firstIdx]);
                        }
                        else {
                            // merge into newInterval
                            newInterval[0] = min(intervals[firstIdx][0], newInterval[0]);
                            newInterval[1] = max(intervals[firstIdx][1], newInterval[1]);
                        }
                    }
                    else if(i == lastIdx) {
                        // check last interval overlap or not
                        if(intervals[lastIdx][0] > newInterval[1]) {
                            ans.push_back(newInterval);
                        }
                        else {
                            // merge into lastIdx
                            intervals[lastIdx][0] = min(intervals[lastIdx][0], newInterval[0]);
                            intervals[lastIdx][1] = max(intervals[lastIdx][1], newInterval[1]);
                        }
                        ans.push_back(intervals[lastIdx]);
                    }
                } 
            }
        }
        return ans;
    }

    int binarySearchIntverals(vector<vector<int>>& intervals, int val) {
        int left = 0, right = intervals.size()-1;

        while(left < right) {
            int mid = left + (right-left) / 2;

            vector<int> targetIntervals = intervals[mid];
            if(targetIntervals[0] <= val && val <= targetIntervals[1]) {
                return mid;
            }
            else if(val > targetIntervals[1]) {
                // continue search right
                left = mid + 1;
            }
            else if(val < targetIntervals[0]) {
                // continue search left 
                right = mid - 1;
            }
        }
        return left;
    }