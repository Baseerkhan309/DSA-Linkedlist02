#include<iostream>
using namespace std;

// Doubly Linkedlist 
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
    data = val;
    prev = next = NULL;
      
    }

};

class DoublyLL{
    public:
      Node* head;
      Node* tail;

      DoublyLL(){
        head = tail = NULL;

      }

// Push Node At Start
      void Push_front(int val){
         Node* newnode = new Node(val);

         if(head == NULL){
            head = tail = newnode;
         }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
         }
      }

      void PopFront(){
        Node* temp = head;
        if(head != NULL){
            head->prev = NULL;
        }
        head = head->next;
       temp->next = NULL;
       delete temp;
      }

      void PrintList(){
        Node* temp = head;

        while(temp){
            cout << temp->data << " <=> " ;
            temp = temp->next;
        }
        cout << "NULL\n";
      }
};

int main(){
  DoublyLL dbll;
dbll.Push_front(5);
dbll.Push_front(4);
dbll.Push_front(3);
dbll.Push_front(2);
dbll.Push_front(1);

dbll.PrintList();
dbll.PopFront();
dbll.PrintList();
    return 0;
}