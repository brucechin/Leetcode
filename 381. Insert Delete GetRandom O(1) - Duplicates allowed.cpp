/*

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called). The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105  calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

*/


class RandomizedCollection {
public:
 vector<int> v;
  unordered_map<int, unordered_set<int>> m;
  bool insert(int val) {
    v.push_back(val);
    m[val].insert(v.size() - 1);
    return m[val].size() == 1;
  }
  bool remove(int val) {
    auto it = m.find(val);
    if (it != end(m)) {
      auto free_pos = *it->second.begin();
      it->second.erase(it->second.begin());
      v[free_pos] = v.back();
      m[v.back()].insert(free_pos);
      m[v.back()].erase(v.size() - 1);
      v.pop_back();
      if (it->second.size() == 0) m.erase(it);
      return true;
    }
    return false;
  }
  int getRandom() { return v[rand() % v.size()]; }
};
