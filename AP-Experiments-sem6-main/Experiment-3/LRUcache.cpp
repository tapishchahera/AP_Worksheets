/*
Design a data structure that follows the constraints 
of a Least Recently Used (LRU) cache.
*/

// Time Complexity: O(1) for both get and put operations.
// Space Complexity: O( n ), 
#include<bits/stdc++.h>
using namespace std;

class LRUcache {
    public:
        int key;
        int val;
        LRUcache* prev;
        LRUcache* next;
        LRUcache(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    
    class LRUCache {
    public:
    private:
        int cap;
        unordered_map<int, LRUcache*> cache;
        LRUcache* oldest;
        LRUcache* latest;
    
    public:
        LRUCache(int capacity) : cap(capacity) {
            oldest = new LRUcache(0, 0);
            latest = new LRUcache(0, 0);
            oldest->next = latest;
            latest->prev = oldest;
        }
    
        int get(int key) {
            if (cache.find(key) != cache.end()) {
                LRUcache* LRUcache = cache[key];
                remove(LRUcache);
                insert(LRUcache);
                return LRUcache->val;
            }
            return -1;
        }
    
    private:
        void remove(LRUcache* cache) {
            LRUcache* prev = cache->prev;
            LRUcache* next = cache->next;
            prev->next = next;
            next->prev = prev;
        }
    
        void insert(LRUcache* cache) {
            LRUcache* prev = latest->prev;
            LRUcache* next = latest;
            prev->next = next->prev = cache;
            cache->next = next;
            cache->prev = prev;
        }
    
    public:
        void put(int key, int value) {
            if (cache.find(key) != cache.end()) {
                remove(cache[key]);
            }
            LRUcache* newNode = new LRUcache(key, value);
            cache[key] = newNode;
            insert(newNode);
    
            if (cache.size() > cap) {
                LRUcache* lru = oldest->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    
        // Destructor to release memory used by the nodes
        ~LRUCache() {
            LRUcache* curr = oldest;
            while (curr != nullptr) {
                LRUcache* next = curr->next;
                delete curr;
                curr = next;
            }
        }
};

int main() {
    LRUCache cache(2); // Create a cache with a capacity of 2
    cache.put(1, 1); // Cache is {1=1}
    cache.put(2, 2); // Cache is {1=1, 2=2}
    cout << cache.get(1) << endl; // Return 1
    cache.put(3, 3); // Cache is {1=1, 3=3}
    cout << cache.get(2) << endl; // Return -1
    cache.put(4, 4); // Cache is {3=3, 4=4}
    cout << cache.get(1) << endl; // Return -1
    cout << cache.get(3) << endl; // Return 3


    return 0;
}