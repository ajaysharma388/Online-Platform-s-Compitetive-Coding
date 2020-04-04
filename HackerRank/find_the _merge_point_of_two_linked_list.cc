#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

int length(SinglyLinkedListNode*head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
} 

// This Solution is of the oreder.
// Time Complexity = O(m*n)
// Space Complexity = O(1)

int findMergeNodeA(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // Takes O(m) time to calculate the length for first List.
    int m = length(head1);
    // Takes O(n) time to calculate the length for second List.
    int n = length(head2);
    // Takes O(m*n) time to find the merge point if any.
    for(int i = 0; i < m; ++i) {
        SinglyLinkedListNode* head = head2;
        for(int j = 0; j < n; ++j) {
            // Merge Exist.
            if(head1 == head) {
                return head->data;
            }
            head = head->next;
        }
        head1 = head1->next;
    }
    // Merge Dorsn't Exist
    return -1;
}

// This Solution is of the oreder.
// Time Complexity = O(m logn + n logn)
// Space Complexity = O(n)

int findMergeNodeB(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    set<SinglyLinkedListNode*> List;
    // Let n be the length of List who's head is head2.
    // Then this will store the every node of second List in O(n) time.
    while(head2) {
        List.insert(head2);
        head2 = head2->next;
    }
    // Let m be the length of List who's head is head1.
    // Then this will iterate over every node of first List in O(m) time.
    // To check if there is any merge point.
    while(head1) {
        if(List.find(head1) != List.end()){
            return head1->data;
        }
        head1 = head1->next;
    }
    return -1;
}

// This Solution is of the oreder.
// Time Complexity = O(m + n)
// Space Complexity = O(1)

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // Takes O(m) time to calculate the length for first List.
    int m = length(head1);
    // Takes O(n) time to calculate the length for second List.
    int n = length(head2);
    // considering the first list as the longer.
    int d = abs(m - n); 
    // if first list is not longer then we will swap.
    if(m < n) {
        swap(head1,head2);
    }
    for(int i = 0; i < d; ++i) {
        head1 = head1->next;
    }
    while(head1 and head2) {
        if(head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }
      
        SinglyLinkedListNode* ptr1 = llist1->head;
        SinglyLinkedListNode* ptr2 = llist2->head;
      
        for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
                ptr1 = ptr1->next;
            }
        }
      
        for (int i = 0; i < llist2_count; i++) {
            if (i != llist2_count-1) {
                ptr2 = ptr2->next;
            }
        }
      
        ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
