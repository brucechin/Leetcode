/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.


*/


class Solution 
{
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st (wordList.begin(),wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr_path = q.front();
                q.pop();
                string last = curr_path.back(); //其实就是利用q里记录的path的末尾word顺便来dfs，其长度就是level
                for(int i = 0 ; i < last.size() ; ++i){
                    auto temp = last;
                    for(char ch = 'a' ; ch <= 'z' ; ++ch){
                        temp[i] = ch;
                        if(st.find(temp) != st.end()){
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp); //这里不能直接从st中erase掉，因为其他同长度的path可能也会走这条路。
                            if(temp == endWord)
                                ans.push_back(new_path);
                            else
                                q.push(new_path);
                        }
                    }
                }
            }
            for(auto& str : visited)
                    st.erase(str);
        }
        return ans;
    }
};