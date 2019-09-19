#include <iostream>
#include <cstdio>

#define MAX 11

using namespace std;
struct card {
char suit;
int value;
};

void bubblesort(struct card T[],int n){
    int minj;
    card temp;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j --){
            if(T[j].value < T[i].value ){

                 temp = T[j];
                T[j] = T[i];
                T[i] = temp;
            }
        }
    }
}
void selectionsort(struct card T[],int n){//选择排序的重点在于找出i 后面所有数的最小值包括i，将其与i交换，最主要是用minj来标识这个最小值

    card temp;
    for(int i = 0 ;i < n ;i++){
                int minj = i;
        for(int j = i ; j < n ; j++){
            if(T[j].value < T[minj].value){
//                minj = j;
//                T[j] = T[i];
//                T[i] = T[minj];
                  minj = j;
            }

        }
                temp = T[i];
                T[i] = T[minj];
                T[minj] = temp;

    }
}
bool isStable(struct card C1[],struct card C2[],int n ){
    for(int i = 0; i < n; i++){
        if(C1[i].suit != C2[i].suit){
            return false;
        }
    }
    return true;
}
void print_sort(struct card T[],int n){
    for(int i = 0; i < n; i++){
        if(i>0){
            cout << " ";
        }
        cout << T[i].suit << T[i].value;
    }
    cout << endl;
}


int main()
{
    int n;
    card C1[MAX],C2[MAX];

    freopen("in.txt","r",stdin);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> C1[i].suit >> C1[i].value;
    }

    for(int i = 0;i < n; i++){
        C2[i] = C1[i];
    }

    bubblesort(C1,n);
    print_sort(C1,n);

    selectionsort(C2,n);
    print_sort(C2,n);

    cout << "stable"<<endl;

     if(isStable(C1,C2,n)){
        cout << "not stable";
     }else{
     cout << "stable";
     }




    return 0;
}
