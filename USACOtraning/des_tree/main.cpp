#include <iostream>
#include <cstdio>

#define MAX 10000
#define NIL -1

using namespace std;
struct Node {
int parent,l,r;
};

Node T[MAX];
int n;
int D[MAX],h[MAX];

void setDepth(int u,int d){
    if(u == NIL)
        return ;
    D[u] = d;
    setDepth(T[u].l,d+1);
    setDepth(T[u].r,d+1);

}

int setHeight(int u){
int h1 = 0,h2 = 0;
if(T[u].l != NIL)
    h1 = setHeight(T[u].l) + 1;
if(T[u].r != NIL)
    h2 = setHeight(T[u].r) + 1;
    return h[u] = (h1 > h2 ? h1 : h2);
}

int getsibling(int u){
    if(T[u].parent == NIL)
        return NIL;
    if(T[T[u].parent].l != u &&T[T[u].parent].l !=NIL)
        return T[T[u].parent].l;
    if(T[T[u].parent].r != u &&T[T[u].parent].r !=NIL)
        return T[T[u].parent].r;
}

void print(int u){
    cout << "Node" << " " << u <<"  " <<"parent="<< T[u].parent << "sibiling = " << getsibling(u) << endl;
    int deg = 0;
    if(T[u].l != NIL)
        deg++;
    if(T[u].r != NIL)
        deg++;
    cout<< "degree = " <<deg << "depath" << D[u] << "height" << h[u] << endl;

}


int main()
{
    int v,l,r,root =0;
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0 ;i < n; i++){
        T[i].parent = NIL;
    }
    for(int i=0; i < n ; i++){
        cin >> v >> l >> r;
        T[v].l = l;
        T[v].r = r;
    if(T[v].l != NIL)
        T[l].parent = v;
    if(T[v].r != NIL)
        T[r].parent = v;
    }

    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL)
            root = i;
    }
    setDepth(root,0);
    setHeight(root);
    for(int i = 0; i < n; i++){
        print(i);
    }
    return 0;
}
