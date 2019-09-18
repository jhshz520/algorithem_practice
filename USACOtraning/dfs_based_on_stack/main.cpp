#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,M[N][N];
int color[N],d[N],f[N],tt;
int nt[N];

int next(int u){
for( int v = nt[u];v < n; v++){
    nt[u] = v + 1;//nt[u]也保存了相邻结点中最小序号的结点，下次再次访问相邻结点时不用每次都从零开始计数
    if(M[u][v])
        return v;
}
return -1;
}

void dfs_visit(int r){
    //此处对nt数组进行了初始化
for(int i = 0; i < n; i++){
    nt[i] = 0;
}
stack<int> S;
S.push(r);
color[r] = GRAY;
d[r] = ++tt;
while(!S.empty()){
    int u = S.top();
    int v = next(u);
    if(v != -1 ){
        if(color[v] == WHITE){
            color[v] = GRAY;
            d[v] = ++ tt;
            S.push(v);

        }
    } else {
        S.pop();
        color[u] = BLACK;
        f[u] = ++tt;
    }
}
}

void dfs(){
for(int i = 0; i < n; i++){
    color[i] = WHITE;
    nt[i] = 0;
}
tt = 0;//从零号结点开始进行深度优先遍历的访问
 for(int u = 0;u < n; u++){
    if(color[u] == WHITE)
        dfs_visit(u);
    }
    for( int i = 0 ;i < n; i++){
        cout << i+1 << " " << d[i] << " "<<f[i]<<endl;
    }
}


int main()
{
    freopen("in.txt","r",stdin);

    int u,k,v;

    cin >> n;
    for(int i = 0 ;i < n; i++){
        for(int j =0; j < n; j++){
            M[i][j] = 0;
        }
    }

    for(int i = 0;i < n ; i++){
        cin >> u>> k;
        u--;
        for(int j =0 ; j < k; j++){
                cin >> v;
                v--;
            M[u][v] = 1;
        }
    }
    dfs();
    return 0;
}
