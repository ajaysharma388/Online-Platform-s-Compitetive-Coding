class Node {
public:    
    int val;
    Node *next;  
    Node(int val) {
        this->val = val;
        next = NULL;
    }
    
};

class MyLinkedList {
    Node *head;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;
        
        Node *cur = head;
        int i = 0;
        while (cur) {
            if (index == i)
                break;
            cur = cur->next; i++;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        size++;
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *newNode = new Node(val); size++;
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        Node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        
        cur->next = newNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        
        Node *newNode = new Node(val); size++;
        
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        Node *cur = head;        
        for (int i = 0; i < index - 1; i++)            
            cur = cur->next;
        
        newNode->next = cur->next;
        cur->next = newNode;        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size)
            return;
        
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp; size--;
            return;
        }
        
        Node *cur = head, *prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = cur->next;
        delete cur; size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */