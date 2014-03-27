#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef struct DoublyLinkedNode {
    string value;
    DoublyLinkedNode* next;
    DoublyLinkedNode* prev;
} DoublyLinkedNode;

typedef struct CacheValue {
    int value;
    DoublyLinkedNode* nodePtr;
} CacheValue;

class DoublyLinkedList{

    private:
        DoublyLinkedNode* root;
        DoublyLinkedNode* curr;

    public:
        DoublyLinkedList(){
            root = NULL;
            curr = NULL;
        }

        DoublyLinkedNode* insert(string val){
            if (curr == NULL){
                curr = new DoublyLinkedNode;
                curr->value = val;
                curr->next = NULL;
                curr->prev = NULL;
                root = curr;
            } else {
                curr->next = new DoublyLinkedNode;
                DoublyLinkedNode* temp = curr->next;
                temp->prev = curr;
                temp->value = val;
                curr = temp;
            }
            return curr;
        }

        string dequeue(){
            string value;
            if (curr == NULL) {
                return "";
            } else {
                DoublyLinkedNode* temp = root;
                value = temp->value;
                root = root->next;

                if (root)
                    root->prev = NULL;
                delete temp;
            }
            return value;
        }

        void print(){
            DoublyLinkedNode* iter = root;
            while(iter != NULL){
                cout << iter->value << endl;
                iter = iter->next;
            }
        }

        DoublyLinkedNode* end(){
            return curr;
        }
};

class Cache {
    private:
        std::unordered_map<string, CacheValue> elements;
        int count;
        DoublyLinkedList evictionList;
        int capacity;
        string lastUsedKey;
        bool lru;
    public:
        Cache(){
            lru = false;
            count = 0;
            capacity = 5;
        }

        Cache(bool isLru){
            lru = isLru;
            count = 0;
            capacity = 5;
        }

        void insert(string key, int val){
            if (count < capacity) {
                CacheValue cacheValue;
                cacheValue.nodePtr = evictionList.insert(key);
                cacheValue.value = val;
                elements.insert(std::make_pair(key, cacheValue));
                count++;
            } else {
                string temp = evictionList.dequeue();
                elements.erase(temp);
                CacheValue cacheValue;
                cacheValue.nodePtr = evictionList.insert(key);
                cacheValue.value = val;
                elements.insert(std::make_pair(key, cacheValue));
            }
        }

        int getValueForKey(string key){
            if (lru) {
                DoublyLinkedNode* back = elements[key].nodePtr;
                if (back->next)
                    back->next->prev = back->prev;
                if (back->prev) {
                    back->prev->next = back->next;
                    delete back;
                } else
                    evictionList.dequeue();
                elements[key].nodePtr = evictionList.insert(key);
            }
            return elements[key].value;
        }

        void print(){
            cout << "Printing Cache" << endl;
            for (unordered_map<string, CacheValue>::iterator i = elements.begin() ; i != elements.end(); i++) {
                cout << "first: " << i->first << " second: " << i->second.value << endl;
            }
        }
};

int main () {
    Cache cache(true);
    cache.insert("A",1);
    cache.insert("B",2);
    cache.insert("C",3);
    cache.insert("D",4);
    cache.insert("E",5);

    cache.print();

    cache.insert("F",6);
    cache.insert("G",7);
    cache.insert("H",8);
    cache.insert("I",9);
    cache.insert("J",10);

    cache.print();

    cache.getValueForKey("F");
    cache.getValueForKey("H");
    cache.insert("K",11);
    cache.insert("L",12);

    cache.print();


}
