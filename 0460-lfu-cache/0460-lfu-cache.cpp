class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    Node *head, *tail;
    int size;

    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if(size==0) return nullptr;

        Node* node = tail->prev;
        remove(node);
        return node;
    }
};

class LFUCache {
public:

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyTable;
    unordered_map<int, List*> freqTable;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){

        int f = node->freq;

        freqTable[f]->remove(node);

        if(f==minFreq && freqTable[f]->size==0)
            minFreq++;

        node->freq++;

        if(freqTable.find(node->freq)==freqTable.end())
            freqTable[node->freq] = new List();

        freqTable[node->freq]->addFront(node);
    }

    int get(int key) {

        if(keyTable.find(key)==keyTable.end())
            return -1;

        Node* node = keyTable[key];

        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if(capacity==0)
            return;

        if(keyTable.find(key)!=keyTable.end()){

            Node* node = keyTable[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if(keyTable.size()==capacity){

            Node* node = freqTable[minFreq]->removeLast();
            keyTable.erase(node->key);
            delete node;
        }

        Node* node = new Node(key,value);

        minFreq = 1;

        if(freqTable.find(1)==freqTable.end())
            freqTable[1] = new List();

        freqTable[1]->addFront(node);

        keyTable[key] = node;
    }
};