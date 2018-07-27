class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> count(26,0);
        int size = s.size();
        for(int i=0; i<size; i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int j=0; j<26; j++){
            if(count[j] != 0)return false;
        }
        return true;
    }
};
