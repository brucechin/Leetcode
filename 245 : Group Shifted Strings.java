/*

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],

Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.

*/

//用diff做key来存着在c++里就是map<string, vector<string>>.
public List<List<String>> groupStrings(String[] strs) {
    HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
    Arrays.sort(strs);      
    for (String s : strs) {
        String key = "";
        for (int i = 1; i < s.length(); i++) 
            key += String.format("%2d", (s.charAt(i) - s.charAt(i-1) + 26) % 26);//Difference from the previous char.
        if (!map.containsKey(key)) map.put(key, new ArrayList<String>());
        map.get(key).add(s);            
    } 
    return new ArrayList<List<String>>(map.values());
}