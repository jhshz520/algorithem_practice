#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 15
#define SENTINEL 200000

int A[MAX];
int L[MAX/2+1];//ֱ���ں����⿪�������ռ������ֱ�洢��������
int R[MAX/2+1];
int cnt = 0;
void merge_sort(int A[],int n,int left, int mid,int right){

    //��n1��n2���ֱ𱣴������������еĸ���
    int n2,n1;
     n1 = mid - left;
    n2 = right - mid;
    for(int i = 0;i < n1; i++){
//        L[i] = A[left++];
        L[i] = A[left + i];
    }

    for(int j = 0; j < n2; j++){
//        R[j] = A[mid++];
            R[j] = A[mid + j];
    }
// �Ƚ������������еĽ�СֵȻ����뵽ԭ�����У�˼·�����⣬Ӧ�ÿ��Ǹ�����Ϊѭ������������A[]��left���嵽rightΪֹ

  /*  for(int i = 0;i < n1;i++){
            for(int j = mid; j < n2; j++)
        if(L[i] <= R[j]){
                cnt++;
//            A[left++] = L[i];//��ʱleft���ββ���仯�ʲ�����left++

        }else{
        A[left++] = R[j];
        cnt++;
        }
    }
    */
    L[n1] = R[n2] = SENTINEL;//���Ƿǳ��ؼ���һ�����ȿ��Է�ֹ���������Ƚ��ֿ��Է�ֹѭ������ i j���� n1��n2
    int i = 0, j = 0;
    for(int k =left; k < right; k++){
        cnt++;
        if(L[i] <=R[j]){
            A[k] = L[i];
            i++;
        }else{
        A[k] = R[j];
        j++;
        }
    }
}
void merge(int A[],int n,int left,int right){

    if(left+1<right){
   int  mid = (left + right) / 2;
    merge(A,n,left,mid);
    merge(A,n,mid,right);
    merge_sort(A,n,left,mid,right);
    }
}
using namespace std;

int main()
{
    int n;
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> A[i];
    }
    merge(A,n,0,n);
    for(int i = 0 ;i < n; i++){
        cout << A[i]<<" ";
    }
    cout <<endl;
    cout << cnt;
    return 0;
}
