#include <iostream>
#include <cstdio>
#include <queue>
//#include <Stack> use queue not stack
//#include <Stack> use queue not stack


#define  N 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2// d[i]���ж��Ƿ񱻷��ʵĹ���d[i] ! = INFTY�൱���Ѿ������ʹ���

#define INFTY (1<<21)

using namespace std;
//stack <int> S;

int n;
int M[N][N],color[N],d[N];
//void bfs_visit(int u){//����дѭ������������
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
        d[i] = INFTY;//�Ծ�����г�ʼ��
    }
    d[s] = 0;//��ʼ�������Լ��ľ���Ϊ��
    int u;
    while (!Q.empty()){//ֻҪ��������ֵ�������׸���u��Ȼ�������u�Ľڵ���Ƿ�ɴ����ɴｫ��Ž�����
        u =Q.front();//ȡ������
        Q.pop();///�����״Ӷ�����ɾ��
        for(int v = 0 ; v < n ; v++){
//            if(M[u][v] == 0)continue;
//            if(d[v] != INFTY) continue;
            if(M[u][v]!=0&&d[v]==INFTY){
                 d[v] = d[u] + 1;//�ɴ����˼�ǵ�u�ľ��벻Ϊ0�ҵ�δ�������ʣ�d[v]==INFTY��
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
