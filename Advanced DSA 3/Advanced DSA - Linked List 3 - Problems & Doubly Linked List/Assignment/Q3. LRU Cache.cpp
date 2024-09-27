/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of "least recently used" : An access to an item is defined as a get or a set operation of the item. "Least recently used" item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
*/

struct DLL {
    int key;
    int val;
    DLL * prev;
    DLL * next;

    DLL (int _key, int _value) {
        key = _key;
        val = _value;
        prev = nullptr;
        next = nullptr;
    }
};

DLL * head;
DLL * tail;

unordered_map<int, DLL*> hm;
int max_capacity;

void remove_node(DLL *node){
    if ( head == node) {
        // delete LRU element
        head = head->next;
        // If only one element, set tail to NULL.
        if (head != NULL) head->prev = NULL; 
        else tail = NULL;
    } else {
        // delete from mid
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
}

void add_node( DLL *node){
    // Add at tail if capacity is > 1
    if ( tail){
        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    } else {
        // when capacity == 1
        node->next = nullptr;
        node->prev = nullptr;
        head = node;
        tail = node;
    }
}

LRUCache::LRUCache(int capacity) {
    head = nullptr;
    tail = nullptr;
    max_capacity = capacity;
    hm = {};
}

int LRUCache::get(int key) {
    if ( hm.find(key) != hm.end()) {
        DLL *node = hm[key];
        // means if not at back
        if ( node != tail) {
            remove_node(node);
            add_node(node);
        }
        return node->val;
    }

    return -1;
}

void LRUCache::set(int key, int value) {
    if ( hm.find(key) != hm.end()){
        DLL *node = hm[key];
        node->val = value;
        // means if not at tail
        if ( node != tail) {
            remove_node(node);
            add_node(node);
        }
    } else {

        DLL *nn = new DLL(key, value);
        hm[key] = nn;
        add_node(nn);
        if ( hm.size() > max_capacity){
            // remove front & cache
            hm.erase(head->key);
            remove_node(head);
        }
    }
}
