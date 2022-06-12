#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p= p->next;

    }
    cout<<endl;
}
void RDisplay(struct Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        RDisplay(p->next);
    }

}
void RReverseDisplay(struct Node *p){
    if(p!=NULL){
        RReverseDisplay(p->next);
        cout<<p->data<<" ";
    }

}
void create(int A[], int n){
        int i ;
        struct Node *t,*last;
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
int count(struct Node* p){
    int c = 0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int Rcount(struct Node* p){

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
int Sum(struct Node* p){
    int c = 0;
    while(p){
        c+=p->data;
        p=p->next;
    }
    return c;
}
int RSum(struct Node* p){

    // static int c = 0;
    // if(p!=NULL){
    //     c+=p->data;
    //     RSum(p->next);
    // }
    // return c;

    // OR

    if(p==NULL){
        return 0;
    }
    else{
        return RSum(p->next) + p->data;
    }
}
int Max(struct Node* p){
    int max  = INT16_MIN;
    while(p){
        if(max<p->data){
            max= p->data;
        }
        p=p->next;
    }
    return max;
}
int RMax(struct Node* p){
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
struct Node* Search(struct Node *p, int key){
    while(p!=0){
    if(p->data==key){
        return p;
    }
    p=p->next;
    }
    return NULL;
}
struct Node* RSearch(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    return RSearch(p->next,key);
}
struct Node* EnhancedSearch(struct Node* p,int key){
    struct Node* q=NULL;
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
void Insert(struct Node* p, int position,int value){
    if(position==0){
        struct Node *k= new Node;
        k->data=value;
        k->next=p;
        p = k;
    }
    else{
        while(--position){
            p=p->next;
        }
        struct Node *k= new Node;
        k->data=value;
        k->next=p->next;
        p->next=k;
    }
}

int main(){
    int A[] = {1,3,5,8,6};
    create(A,5);
    RDisplay(first);
    cout<<endl;
    // RReverseDisplay(first);
    // cout<<endl;
    // Display(first);
    // cout<<endl;
    // cout<<"the number of nodes in linked list are "<<count(first)<<endl;
    // cout<<"the number of nodes in linked list are "<<Rcount(first)<<endl;
    // cout<<"the sum of value in  nodes in linked list is "<<Sum(first)<<endl;
    // cout<<"the sum of value in  nodes in linked list is "<<RSum(first)<<endl;
    // cout<<"the max of value in  nodes in linked list is "<<Max(first)<<endl;
    // cout<<"the max of value in  nodes in linked list is "<<RMax(first)<<endl;
    // cout<<"the key 6 is at location "<<Search(first,6)<<endl;
    // cout<<"the key 6 is at location "<<RSearch(first,6)<<endl;
    // cout<<"the key 6 is at location "<<EnhancedSearch(first,6)<<endl;
    // Display(first);
    Insert(first,0,4);
    Display(first);
    // cout<<"the key 6 is at location "<<RSearch(first,6)<<endl;
    return 0;
}