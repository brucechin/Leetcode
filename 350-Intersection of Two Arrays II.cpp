class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count;
        vector<int> result;
        int size1 = nums1.size(),size2 = nums2.size();
        for(int i = 0; i < size1; i++){
            int tmp = nums1[i];
            if(count.find(tmp) == count.end()){
                count[tmp] = 1;
            }else{
                count[tmp]++;
            }

        }
        for(int j=0; j<size2; j++){
            int tmp =nums2[j] ;
            if(count.find(tmp) != count.end()){
                if(count[tmp]-- >  0){
                    result.push_back(tmp);
                }
            }
        }
        return result;

    }
};
