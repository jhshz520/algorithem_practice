#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define N 100
using namespace std;

int lcs(string X,string Y){
    int c[N+1][N+1];
    int m,n;

    int maxl = 0;
    m = X.size();
    n = Y.size();

    X = ' ' + X;
    Y = ' ' + Y;

    for(int i = 1; i < m; i++)
        c[i][0] = 0;
    for(int j = 1; j < m; j++)
        c[0][j] = 0;
    for(int i = 1; i <= m ; i++){
        for(int j = 1; j <=n; j++){
                if(X[i] == Y[j]){
                    c[i][j] = c[i-1][j-1] + 1;
                }else{
                    c[i][j] = max(c[i-1][j],c[i][j-1]);
                }
                maxl = max(maxl,c[i][j]);
        }

    }
    return maxl;
}
int main()
{
    int n;
    string s1, s2;
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        cout << lcs(s1,s2) <<endl;
    }
    return 0;
}
