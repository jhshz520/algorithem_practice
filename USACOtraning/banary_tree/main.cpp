#include <iostream>
#include <cstdio>

#define MAX 100
#define NIL -1
using namespace std;

struct Node{
int parent,l,r;
};
struct Node T[MAX];

void preorder(int u){
    if(u==NIL)
        return;
    cout << u << " ";
    preorder(T[u].l);
    preorder(T[u].r);

}
void midorder(int u){
    if(u==NIL)
        return;
    midorder(T[u].l);
    cout << u <<" ";
    midorder(T[u].r);

}
void afterorder(int u){
    if(u==NIL)
        return;
    afterorder(T[u].l);
    afterorder(T[u].r);
    cout << u << " ";
}


int main()
{
    int n,u,l,r,root;
freopen("in.txt","r",stdin);
cin >> n;
for(int i = 0; i < n; i++){
    T[i].parent = NIL;
}

for(int i = 0; i < n; i++){
        cin >> u >> l >> r;
    T[u].l = l;
    T[u].r = r;
  if(l != NIL)
        T[l].parent = l;//需要考虑子节点为空，即l或r为-1的情况
  if(r != NIL)
       T[r].parent = u;

}
for(int i = 0; i < n; i++){
    if(T[i].parent == NIL){
        root = i;
    }
}
cout << "preorder" << endl;
preorder(root);
cout <<endl;
cout << "midorder" <<endl;
midorder(root);
cout <<endl;
cout << "afterorder" <<endl;
afterorder(root);
cout <<endl;

    return 0;
}
