#include<bits/stdc++.h>
#include<set>
#define LL long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        int A[k];
        for(int i = 0 ; i<k ; i++){
            cin>>A[i];
        }
        set <pair<int,int>> F;
        int count =0;
        for(int i = 0 ; i<k ; i++){
            int check = i-A[i]+1>0?i-A[i]+1:0;
            while((check<=i) && (check+A[i]-1<k)){
                F.insert({check,check+A[i]-1});
                check++;
            }
        }
        cout<<F.size()<<endl;
    }
    return 0;
}