#include <iostream>
#include <cstdio>
#include <queue>
//#include <Stack> use queue not stack
//#include <Stack> use queue not stack


#define  N 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2// d[i]有判断是否被访问的功能d[i] ! = INFTY相当于已经被访问过了

#define INFTY (1<<21)

using namespace std;
//stack <int> S;

int n;
int M[N][N],color[N],d[N];
//void bfs_visit(int u){//不会写循环结束的条件
//    if(color[u]==WHITE){
// !.       color[u] = GRAY;
//        for(int i = 0;i < n;i++){
//            if(M[u][i]==1){
//                S.push(i);
//                d[i] += 1;
//            }
//        }
//    }
//
//}
void bfs(int s){
    queue <int> Q;
    Q.push(s);
    for(int i = 0; i < n; i++)
    {
        d[i] = INFTY;//对距离进行初始化
    }
    d[s] = 0;//初始化自身到自己的距离为零
    int u;
    while (!Q.empty()){//只要队列中有值，将队首赋给u，然后遍历到u的节点的是否可达，如果可达将其放进队列
        u =Q.front();//取出队首
        Q.pop();///将队首从队列中删除
        for(int v = 0 ; v < n ; v++){
//            if(M[u][v] == 0)continue;
//            if(d[v] != INFTY) continue;
            if(M[u][v]!=0&&d[v]==INFTY){
                 d[v] = d[u] + 1;//可达的意思是到u的距离不为0且到未经过访问（d[v]==INFTY）
            Q.push(v);
            }

        }
    }
    for(int i =0 ;i < n ; i++){
        cout <<i +1<<" " << ((d[i] == INFTY)?(-1) : d[i]) << endl;
    }
}
int main()
{
    int k,v,u;
    for(int i = 0; i < n; i++){
           // color[i] = WHITE;
        //    d[i] = 0;
        for(int j = 0;j < n; j++){
            M[n][n] = 0;
        }
    }
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> u;
        u--;
        cin >> k;
        for(int j =0 ;j < k; j++){
            cin >> v;
            v--;
            M[u][v] = 1;
        }

    }
    bfs(0);
    return 0;
}
