#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(){head = NULL;};
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node* p);
    Node* getHead(){ return head; }
    ~CircularLinkedList();
    void Insert(int index, int value);
    int Delete(int index);
    int Length();
    
};
 
CircularLinkedList::CircularLinkedList(int *A, int n) {
 
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
 
void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}
 
void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}
 
CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
 
    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
 
    if (p == head){
        delete head;
        head = nullptr;
    }
 
}
int CircularLinkedList:: Delete(int index){
    int x =-1;
    if (index==1){
        Node*p = head;
        while(p->next!=head){
            p=p->next;
        }
        p->next = head->next;
    x=head->data;
        delete(head);
        head=p->next;
    }
    else{
        Node*p =head;
        for(int  i=0; i<index-2 ; i++ ){
            p=p->next;
        }
        Node*  q=p->next;
        p->next = q->next;
        x=q->data;
        delete(q);
        q=NULL;
    }
    return x;
}
void CircularLinkedList:: Insert(int index,int value){
    Node* t = new Node;
        t->data = value;
    if (index==1){
        if(head==NULL){
            head = new Node;
            head->data = value;
            head->next = head;
        }
        t->next  = head;
        Node*p =head;
        do{
            p=p->next;
        }while(p->next!=head);
        p->next =t;
        head = t;
    }
    else{
        Node*p =head;
        for(int  i=0; i<index-2 ; i++ ){
            p=p->next;
        }
        
        t->next = p->next;
        p->next  = t;
    }
}
 
int CircularLinkedList:: Length(){
    int length = 0;
    Node* p = head;
    do{
        length++;
        p=p->next;
    }while(p!=head);
    return length;
 }
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
 
    cl.Display();
 
    Node* h = cl.getHead();
    cl.recursiveDisplay(h);
    cout<<endl;
    cl.Insert(3,4);
    cl.Display();
    cl.Insert(1,1);
    cl.Display();
    cout<<"element deleted: "<<cl.Delete(4)<<endl;
    // cl.Delete(4);
    cl.Display();
    cout<<"element deleted: "<<cl.Delete(1)<<endl;
    cl.Display();
    cout<<endl<<cl.Length()<<endl;
    return 0;
}