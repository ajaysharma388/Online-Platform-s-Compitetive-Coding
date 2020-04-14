class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct node{
        int val;
        node* next;
        node(){
            val = 0;
            next = nullptr;
        }
        node(int i):val(i),next(nullptr){}
    };
    
    node* Pre;
    node* Tail;
    int Length;
    
    MyLinkedList() {
        node* pre = new node(-1);
        Pre = pre;
        Tail = pre;
        Length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= Length) return -1;
        else{
            node* p = Pre->next;
            while(index){
                p = p->next;
                index--;
            }
            return p->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* new_head = new node(val);
        node* old_head = Pre->next;
        Pre->next = new_head;
        new_head->next = old_head;
        Length++;
        if(Length == 1) Tail = new_head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* new_tail = new node(val);
        Tail->next = new_tail;
        Tail = new_tail;
        Length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > Length || index < 0) return;
        else{
            node* newp = new node(val);
            if(index == Length){
                Tail->next = newp;
                Tail = newp;
            }
            else{
                node* p = Pre;
                while(index){
                    p = p->next;
                    index--;
                }
                newp->next = p->next;
                p->next = newp;
            }
        }
        Length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= Length || index < 0) return;
        node* p = Pre;
        for(int i = 0; i < index; ++i){
            p = p->next;
        }
        if(index == Length-1) Tail = p;
        node* delp = p->next;
        p->next = p->next->next;
        delete delp;
        delp = nullptr;
        Length--;
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
