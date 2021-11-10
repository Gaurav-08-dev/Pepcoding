/**************** USING DOUBLY LINKED LIST & HASHMAP *********/

class LRUCache {
public:
    
    class Node{
        public:
            int key;
            int val;

            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key=key;
                this->val=val;
            }
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    int capacity;
    unordered_map<int,Node*> map; //key n node
    
    
    LRUCache(int capacity) {
        
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(Node* currNode)
    {
        Node* prevNode=currNode->prev;
        Node* nextNode=currNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    void addNode(Node* currNode)
    {
        currNode->next=head->next;
        currNode->prev=head;
        currNode->next->prev=currNode;
        head->next=currNode;
    }
    
    
    int get(int key) {
        
        if(map.find(key)==map.end()) return -1;
        Node* currNode=map[key];
        
        int result=currNode->val;
        map.erase(key);
        deleteNode(currNode);
        addNode(currNode);
        map[key]=head->next;
        return result;
    }
    
    void put(int key, int value) {
        
        if(map.find(key)!=map.end())
        {
//             perform updation
            Node* currNode=map[key];
            map.erase(key);
            deleteNode(currNode);
        }
    
        if(map.size()==capacity)
        {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //             perform insertion            
        addNode(new Node(key,value));
        map[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */