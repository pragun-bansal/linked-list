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
    void Display(Node *p);
    void RDisplay(Node *p);
    void RReverseDisplay(Node *p);
    void create(int A[], int n);
    void create2(int A[], int n);
    int count(Node* p);
    int Rcount(Node* p);
    int Sum(Node* p);
    int RSum(Node* p);
    int Max(Node* p);
    int RMax(Node* p);
    Node* Search(Node *p, int key);
    Node* RSearch(Node *p,int key);
    Node* EnhancedSearch(Node* p,int key);
    void Insert(Node* p, int position,int value);
    int Delete(Node*p , int index);
    bool IsSorted(Node* p);
    void RemoveDuplicate(Node* p);
    void ReverseLLArr(Node* p);
    void ReverseShift(Node* p);
    void RReverse(Node* p,Node* q);
    void Concatenate(Node* p , Node* &q);
    void Merge(Node* p,Node* q,Node* &r);
    bool IsLoop(Node* f);
}*first=NULL,*second=NULL,*third=NULL;

void Node :: Display( Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p= p->next;

    }
    cout<<endl;
}
void Node :: RDisplay(Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        RDisplay(p->next);
    }

}
void Node :: RReverseDisplay(Node *p){
    if(p!=NULL){
        RReverseDisplay(p->next);
        cout<<p->data<<" ";
    }

}
void Node :: create(int A[], int n){
        int i ;
         Node *t,*last;
        first = new Node;
        first -> data = A[0];
        first->next=NULL;
        last = first;

        for(int  i = 1 ; i<n ; i++){
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;

        }
    }
void Node :: create2(int A[], int n){
        int i ;
         Node *t,*last;
        second = new Node;
        second -> data = A[0];
        second->next=NULL;
        last = second;

        for(int  i = 1 ; i<n ; i++){
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;

        }
    }
int Node :: count(Node* p){
    int c = 0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int Node :: Rcount(Node* p){

    static int c = 0;
    if(p!=NULL){
        c++;
        Rcount(p->next);
    }
    return c;

    // OR

    // if(p==0){
    //     return 0;
    // }
    // else{
    //     return 1+ Rcount(p->next);
    // }
}
int Node :: Sum(Node* p){
    int c = 0;
    while(p){
        c+=p->data;
        p=p->next;
    }
    return c;
}
int Node :: RSum(Node* p){

    static int c = 0;
    if(p!=NULL){
        c+=p->data;
        RSum(p->next);
    }
    return c;

    // OR

    // if(p==NULL){
    //     return 0;
    // }
    // else{
    //     return RSum(p->next) + p->data;
    // }
}
int Node :: Max(Node* p){
    int max  = INT16_MIN;
    while(p){
        if(max<p->data){
            max= p->data;
        }
        p=p->next;
    }
    return max;
}
int Node :: RMax(Node* p){
    // static int max = INT32_MIN;
    // if(p!=NULL){
    //     if(max<p->data)
    //     max = p->data;
    //     RMax(p->next);
    // return max;
    // }

    // OR

    int x ;
    if(p==0){
        return INT_MIN;
    }
    x = RMax(p->next);
    return x>p->data?x:p->data;
}
Node* Node :: Search(Node *p, int key){
    while(p!=0){
    if(p->data==key){
        return p;
    }
    p=p->next;
    }
    return NULL;
}
Node* Node :: RSearch(Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    return RSearch(p->next,key);
}
Node* Node :: EnhancedSearch(Node* p,int key){
    Node* q=NULL;
    while(p!=0){
        if(key==p->data){
            q->next = p->next;
            p->next =  first;
            first = p;
        return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Node :: Insert(Node* p, int position,int value){
    if(position<0 || position > count(p))
        return;
   int i;
   Node *t;
   t=new Node;
   t->data=value;
   if(position==0)
   {
    t->next=first;
    first=t;
   }
   else
   {
     for(i=0;i<position-1;i++)
   p=p->next;
   t->next=p->next;
   p->next=t;
   }
}
int Node :: Delete(Node* p , int index){
    Node* q = NULL;
    int x=-1;
    if(index <1 || index>count(p) ){
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
bool Node :: IsSorted(Node* p){
    int x = INT16_MIN;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
        
    }
    return true;
}
void Node :: RemoveDuplicate(Node* p){
    Node* q;
    while(p!=NULL){
        
        
        if(q->data==p->data){
            q->next=p->next;
            delete p;
            p=q->next;
        }
        else{
            q=p;
        p=p->next;
        }
    }
}
void Node:: ReverseLLArr(Node* p){
    int arr[count(p)];
    int i = 0;
    while(p!=NULL){
        arr[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;
    i=count(p)-1;
    while(p!=NULL){
        p->data=arr[i];
        p=p->next;
        i--;
    }
}
void Node :: ReverseShift(Node* p){
Node *q=NULL,*r=NULL;

 while(p!=NULL)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}
void Node :: RReverse(Node* q,Node* p){
   
 if(p)
 {
 RReverse(p,p->next);
 p->next=q;
 }
 else
 first=q;
}
void Node:: Concatenate(Node* p , Node* &q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next =q;
    q=NULL;
}
void Node:: Merge(Node* p,Node* q,Node* &r){
    Node* last=NULL;
    if(p->data<q->data){
        r=p;
        last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        r=q;
        last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            last->next = p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next =q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL){
        last->next = p;
    }
    else{
        last->next = q;
    }
}
bool Node:: IsLoop(Node* f){
    Node*p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:q;
    }while(p && q && p!=q);

    if(p==q)return 1;
    else return 0;

}





int main()
{
    int A[] = {1,3,5,5,5,6,6,6,8,8,10};
    int B[]= {1,3,5,7,9,11};
    Node m;
    m.create(A,(sizeof(A)/sizeof(int)));
    m.create2(B,(sizeof(B)/sizeof(int)));
    // m.RDisplay(first);
    int C[] = {1,3,4,7,11,24,39};
    int D[]={3,6,12,17,25};
    Node n;
    n.create(C,(sizeof(C)/sizeof(int)));
    n.create2(D,(sizeof(D)/sizeof(int)));
   
    n.Merge(first,second,third);
    n.Display(third);

    // Node*t1,*t2;
    // t1=second->next->next->next->next;
    // t2=second;
    // t1->next=t2;
    if(n.IsLoop(second)){
        cout<<endl<<"It is a loop"<<endl;
    }
    else{
        cout<<endl<<"It is not a loop"<<endl;
    }



 // n.RDisplay(first);
    // cout<<"the element deleted is "<<m.Delete(first , 9)<<endl;;
    // m.Display(first);
    // cout<<m.IsSorted(first)<<endl;
    // m.Display(first);
    // m.RemoveDuplicate(first);
    // m.Display(first);
    // m.Concatenate(first,second);
    // m.Display(first);

    // cout<<endl;
    // m.RReverseDisplay(first);
    // cout<<endl;
    // m.Display(first);
    // cout<<endl;
    // cout<<"the number of nodes in linked list are "<<m.count(first)<<endl;
    // cout<<"the number of nodes in linked list are "<<m.Rcount(first)<<endl;
    // cout<<"the sum of value in  nodes in linked list is "<<m.Sum(first)<<endl;
    // cout<<"the sum of value in  nodes in linked list is "<<m.RSum(first)<<endl;
    // cout<<"the max of value in  nodes in linked list is "<<m.Max(first)<<endl;
    // cout<<"the max of value in  nodes in linked list is "<<m.RMax(first)<<endl;
    // cout<<"the key 6 is at location "<<m.Search(first,6)<<endl;
    // cout<<"the key 6 is at location "<<m.RSearch(first,6)<<endl;
    // cout<<"the key 6 is at location "<<m.EnhancedSearch(first,6)<<endl;
    // m.Display(first);
    // m.Insert(first,3,5);
    // m.Display(first);
    // cout<<"the key 6 is at location "<<RSearch(first,6)<<endl;
    // m.Insert(first,0,12);
    // m.Display(first);
    // cout<<first->data<<endl;
    
    // m.ReverseLLArr(first);
    // m.Display(first);
    // m.ReverseShift(first);
    // m.Display(first);
    // m.RReverse(NULL,first);
    // m.Display(first);
    
    return 0;
}