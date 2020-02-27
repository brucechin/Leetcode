/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 )

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/
class LRUCache {
private:
    // A list of (key, value) pairs
    list<pair<int, int>> items;
    // Map items to iterators (pointers) to list nodes
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    // The capacity of the list
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // If key is not found in hash map, return -1
        if (cache.find(key) == cache.end())
            return -1;
        // Move the (key, value) pair to the beginning of the list
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;
    }

    void set(int key, int value) {
        // The key is not in the hash table
        if (cache.find(key) == cache.end()) {
            // If the cache is full then delete the least recently
            // used item, which is at the end of the list
            if (items.size() == capacity) {
                cache.erase(items.back().first);
                items.pop_back();
            }
            items.push_front(make_pair(key, value));
            cache[key] = items.begin();
        } else {
            // Update the value associated with the key
            cache[key]->second = value;
            // Move the (key, value) pair to the beginning of the list
            items.splice(items.begin(), items, cache[key]);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */