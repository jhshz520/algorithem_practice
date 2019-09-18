#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX 1000
#define INFTY (1 << 21)
queue <int> Q;
int M[MAX][MAX];
int D[MAX];
 int n;

void bfs(int s){
    int u;
    D[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int v = 0; v < n ; v++){
            if((M[u][v] == 1)&&(D[v] == INFTY)){//if(M[u][i] == 1)�������ж����Ƿ����ڲ�δ�жϸýڵ��Ƿ񱻷���
                    //һ��Ҫͬʱ�ж�������������������

                D[v] = D[u]+1;
                   Q.push(v);

            }
        }
    }
    for(int i = 0; i < n;i ++){
            cout << i+1 << " ";
        if(D[i] == INFTY){
            cout << "-1" << endl;
        }else{
        cout << D[i] << endl;
        }
    }

}
int main()
{
    for(int i = 0; i < MAX ;i++){
        for(int j = 0; j < MAX ; j++){
            M[MAX][MAX] = 0;
        }
    }
    for(int i =0; i < MAX ; i ++){
        D[i] = INFTY;
    }
   int k,u,v;
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i =0;i < n; i++){
        cin >> u>> k;
        u--;
        for(int j =0; j < k; j++){
                cin >> v;
        v--;
            M[u][v] = 1;
        }
    }
    bfs(0);
    return 0;
}
