/*

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
Answers within 10^-5 of the actual value will be accepted as correct.

*/

class Median {
    
    multiset<int> s1;
    multiset<int> s2;
    public:
    
    void insert(int n){
        
        if(s1.empty() && s2.empty()) s1.insert(n);
        else if(s1.empty()) s2.insert(n);
        else if(s2.empty()) s1.insert(n);
        else if( *s1.rbegin() >= n) s1.insert(n);
        else s2.insert(n);
        
        balance();
    }
    
    void remove(int n) {
        if(s1.find(n)!=s1.end()) s1.erase(s1.find(n));
        else s2.erase(s2.find(n));
        balance();
    }
    
    double median(){
        
        if(s1.size() > s2.size()) return *s1.rbegin();
        if(s1.size() < s2.size()) return *s2.begin();
        
        return (0.0 + *s1.rbegin() + *s2.begin())/2.0;
    }
    
    void balance() {
        
        
        
        if(s1.size() > 1 + s2.size()) {
            int v = *s1.rbegin();
            s2.insert(v);
            s1.erase(s1.find(v));
        }
        else if(s2.size() > 1 + s1.size() ) {
            int v = *s2.begin();
            s1.insert(v);
            s2.erase(s2.find(v));
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        Median m1;
        vector<double> ans;
        
        for(int i = 0; i < k; i++)
            m1.insert(nums[i]);
        
        ans.push_back(m1.median());
        
        
        for(int i = k; i < nums.size(); i++){
            m1.insert(nums[i]);
            m1.remove(nums[i-k]);
            ans.push_back(m1.median());
        }
        
        
        return ans;
    }
};