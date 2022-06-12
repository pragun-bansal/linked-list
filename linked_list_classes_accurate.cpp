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
    int Delete(int index);
    void insert(int position , int data);
    void Display();
    int count();
};
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
    }
}



int main(){
    int A[]={1,2,3,4,5};
    Linkedlist l(A,sizeof(A)/sizeof(int));
    l.Display();
    return 0;
}