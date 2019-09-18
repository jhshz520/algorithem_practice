#include <iostream>
#include <cstdio>


using namespace std;

struct card{
char suit;
int value;
};

void bubble(struct card A[],int N){
    for(int i = 0;i < N; i++){
        for(int j = N-1; j >= i ; j-- ){//这里是需要学习的地方，直接让j作为最后，更改循环条件尽可能的减少次数
            if(A[j].value < A[i].value){
                card t = A[j];
                A[j] = A[i];
                A[i] = t;
            }
        }
    }

}
void selection(struct card A[],int N){
    for(int i = 0; i < N; i++){
            int minj = i;//定义一个minj用来接收所有比较中的最小值元素所在的位置
        for(int j = i; j < N; j++){//选择排序从前往后找，在j循环时直接将j = i带入，另外利用空位转存将要被替代的旧元素的值
            if(A[j].value < A[i].value){
                minj = j;
            }
            card t = A[i]; A[i] = A[minj]; A[minj] = t;
        }
    }

}
void print(struct card A[],int N){
    for(int i = 0; i < N; i++){
        if(i>0){
            cout <<" ";
        }
        cout << A[i].suit<<A[i].value;
    }
    cout <<endl;
}
//判断算法的稳定性
bool isStable(struct card C1[],struct card C2[],int N){//新增加一个标志位，观察标志位是否如原先相同就可以得出是否是稳定的结论
for(int i = 0 ; i < N ; i++){
    if(C1[i].suit != C2[i].suit){
        return false ;
    }
}
return true;
}
int main()
{
    int N;
    card C1[100],C2[100];
    freopen("in.txt","r",stdin);
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> C1[i].suit >>C1[i].value;
    }
    for(int i = 0; i < N; i++){
        C2[i] = C1[i];
    }
    bubble(C1,N);
    selection(C2,N);
    print(C1,N);
    print(C2,N);
    if(isStable(C1,C2,N)){
        cout <<"stable " << endl;
    }else{
    cout << " not stable" <<endl;
    }
    return 0;
}
