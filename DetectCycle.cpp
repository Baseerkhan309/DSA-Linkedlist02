#include<iostream>
using namespace std;

// Floyed's Cycle Finding Algorithm

// Node 
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
    data = val;
    next = NULL;
    }
};

// Linkedlist 
class Linkedlist{
    public:
    Node* head;
    Node* tail;

    Linkedlist(){
    head = NULL;
    tail = NULL;

    }
void push_front(int val){
    Node* newnode = new Node(val);
    if(head == NULL){
      head  = tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}
void push_Back(int val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = tail = newnode;

    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void pop_front(){
    if(head == NULL){
        return;
    }else{
        Node* temp = head;
       head = head->next;
       temp->next = NULL;
       delete temp;
    }
}
    
};

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data<< "-->";
        temp = temp->next;
    }
    cout << "NULL\n";
}


// Is Cycle Exist 
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next; // +1;
        fast = fast->next->next; // +2

    if(slow == fast){ // If we  first check the condition so it will be true on HEAD
        cout << "Cycle Exist \n";
        return true;
    }
    }
    cout << "Cycle Doesn't Exist \n";
    return false;
}
// Function For Removing a Cycle

void  removeCycle(Node* head){
    // Detect Cycle 
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle Exist \n";
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
        cout << "Cycle Does't Exist "<< endl;
        return;
    }

     // special case : tail->head
    slow = head;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL; //remove cycle 
    }else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; //remove cycle 
    }

}
// Merge Sort ... Split At Middle
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL; // Split At Middle
    }
    return slow; // slow = rightHead;

}
// Merge Sort Merge Function
Node* merge(Node* left, Node* right){
    Linkedlist ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_Back(i->data);
            i = i->next;
        }else{
            ans.push_Back(j->data);
            j = j->next;

        }
    }
    while(i != NULL){
        ans.push_Back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_Back(j->data);

    }
     return ans.head;

}

// Merge Sort 
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);
    
   Node* left = mergeSort(head); // left head;
   Node* right = mergeSort(rightHead); // right Head;

   return merge(left, right);
}

// ZigZag Reverse Method for Linkedlist...
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

    }

    return prev; // prev is head of reverse ll
}


// ZigZag Linkedlist 
Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    //Alternate Merging...
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;

    }
    if(right != NULL){
        tail->next = right;

    }
    return head;
}

int main(){
Linkedlist ll;
ll.push_front(1);
ll.push_front(2);
ll.push_front(3);
ll.push_front(4);
ll.push_front(5);
//ll.tail->next = ll.head;
//isCycle(ll.head);
//removeCycle(ll.head);
printList(ll.head);
//ll.head = mergeSort(ll.head);

ll.head = zigZagLL(ll.head);
printList(ll.head);
    return 0;
}