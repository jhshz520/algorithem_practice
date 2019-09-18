#include <iostream>
#include <cstdio>


using namespace std;

struct card{
char suit;
int value;
};

void bubble(struct card A[],int N){
    for(int i = 0;i < N; i++){
        for(int j = N-1; j >= i ; j-- ){//��������Ҫѧϰ�ĵط���ֱ����j��Ϊ��󣬸���ѭ�����������ܵļ��ٴ���
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
            int minj = i;//����һ��minj�����������бȽ��е���СֵԪ�����ڵ�λ��
        for(int j = i; j < N; j++){//ѡ�������ǰ�����ң���jѭ��ʱֱ�ӽ�j = i���룬�������ÿ�λת�潫Ҫ������ľ�Ԫ�ص�ֵ
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
//�ж��㷨���ȶ���
bool isStable(struct card C1[],struct card C2[],int N){//������һ����־λ���۲��־λ�Ƿ���ԭ����ͬ�Ϳ��Եó��Ƿ����ȶ��Ľ���
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
