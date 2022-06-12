#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define PB push_back
#define MP make_pai
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Linkedlist{
    private:
    Node* first;
    public:
    Linkedlist(){first=NULL;};
    Linkedlist(int A[],int n);
    ~Linkedlist();
    Node* Rfirst();
    int Delete(int index);
    void insert(int position , int data);
    void Display();
    int count();
};
Linkedlist::~Linkedlist()
{
 Node *p=first;
 while(first)
 {
 first=first->next;
 delete p;
 p=first;
 }
}
Linkedlist :: Linkedlist(int A[],int n)
{
 Node *last,*t;
 int i=0;

 first=new Node;
 first->data=A[0];
 first->next=NULL;
 last=first;
 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
Node* Linkedlist:: Rfirst(){
        Node*p=first;
        return p;
    }
int Linkedlist:: count(){
    int count = 0;
    Node*p=first;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
int Linkedlist:: Delete(int index){
    Node* q = NULL,*p=first;
    int x=-1;
    if(index <1 || index>count() ){
        return -1;
    }
    if(index==1){
        first = p->next;
        x=p->data;
        delete p;
        p=NULL;

    }
    else{
        for(int i = 0 ; i<index-1;i++){
            q=p;
            p=p->next;
            

        }
    q->next = p->next;
    x=p->data;
    delete p;
    p=NULL;
    }
    return x;
}
void Linkedlist:: Display(){
    Node*p=first;
    while(p!=NULL){
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<endl;
}



int main(){
    int A[]={1,2,3,4,5};
    Linkedlist l1(A,sizeof(A)/sizeof(int));
    l1.Display();
    int B[]={1,2,3,4,5,8,2145,32};
    Linkedlist l2(B,sizeof(B)/sizeof(int));
    l2.Display();
    // Linkedlist l3();
    // l3.Rfirst()=NULL;
    return 0;
}