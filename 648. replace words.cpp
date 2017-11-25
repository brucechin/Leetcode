/*

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000

*/

//不用trie树的简单做法
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.size() == 0) return sentence;
        set<string> s;
        for(string i : dict) s.insert(i);
        string result;
        vector<string> words;
        istringstream iss(sentence);
        do
        {
            string subs;
            iss >> subs;
            words.push_back(subs);
        } while (iss);
        for(string word : words){
            string prefix = "";
            for(int i=0; i<word.size(); i++){
                prefix = word.substr(0,i+1);
                if(s.find(prefix) != s.end()) break;
            }
            result.append(prefix + " ");
        }
        result = result.substr(0,result.size()-2);
        return result;
    }
};