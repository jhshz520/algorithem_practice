#include <iostream>
#include <cstdio>

#define N 1000
using namespace std;

int n;

int A[N];

int banary_search(int key){
    int left = 0 ;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(key==A[mid]){
            return 1;
        }

        if(key > A[mid]){
            left = mid + 1;
        }else if(key < A[mid]){
            right = mid ;

        }
}
    return 0;
}
int main()
{
    int q,k,sum = 0;
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i =0 ; i < n ;i++){
        cin >> A[i];
    }
    cin >> k;
    for(int i = 0; i < k; i ++){
        cin >> q;
        if(banary_search(q)){
            sum+=1;
        }
    }
    cout << sum ;

    return 0;
}
