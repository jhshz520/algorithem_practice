#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 15
#define SENTINEL 200000

int A[MAX];
int L[MAX/2+1];//直接在函数外开辟两个空间用来分别存储两个序列
int R[MAX/2+1];
int cnt = 0;
void merge_sort(int A[],int n,int left, int mid,int right){

    //用n1和n2来分别保存两个子数组中的个数
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
// 比较两个子数组中的较小值然后插入到原数组中，思路有问题，应该考虑个数作为循环的条件，将A[]从left，插到right为止

  /*  for(int i = 0;i < n1;i++){
            for(int j = mid; j < n2; j++)
        if(L[i] <= R[j]){
                cnt++;
//            A[left++] = L[i];//此时left是形参不会变化故不能用left++

        }else{
        A[left++] = R[j];
        cnt++;
        }
    }
    */
    L[n1] = R[n2] = SENTINEL;//这是非常关键的一步，既可以防止两个标记相比较又可以防止循环变量 i j超过 n1和n2
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
