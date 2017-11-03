class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ch(26,0);
        int size = s.size();
        for(int i=0; i<size; i++){
            ch[s[i]-'a']++;
        }
        for(int j=0; j<size; j++){
            if(ch[s[j]-'a'] == 1)return j;
        }
        return -1;
    }
};
