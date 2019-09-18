#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

static const int N =100;

//int lcs_test(string s1,string s2){
//int lcs_test(char s1[],char s2[]){
//    int c[N+1][N+1];
//    //string :: size_type  m,n;
//    int m,n;
////     m = s1.size();
////     n = s2.size();
//    m = strlen(s1);
//    n = strlen(s2);
//    int maxl = 0;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    c[0][0] = 0;
//    for(int i = 1; i <= m; i++){//注意此时是从1开始的
//        c[i][0] = 0;
//    }
//    for(int j = 1; j <= n; j++){
//        c[0][j] = 0;
//    }
//    for(int i =1; i <= m; i++){
//        for(int j = 1; j <= n; j++){
//            if(s1[i] == s2[j]){
//                c[i][j] = c[i-1][j-1] + 1;
//            }else{
//            c[i][j] = max(c[i-1][j],c[i][j-1]);
//            }
//            maxl = max(maxl,c[i][j]);
//        }
//    }
//    return maxl;
//
//}
int main()
{
   freopen("in.txt","r",stdin);
   string s1,s2;
//    char s1[10],s2[10];
    int k;

      cin >> k;
      for(int i = 0; i < k; i++){
        cin >> s1 >> s2;
        int c[N+1][N+1];
    //string :: size_type  m,n;
    int m,n;
     m = s1.size();
     n = s2.size();
//    m = strlen(s1);
//    n = strlen(s2);
    int maxl = 0;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    c[0][0] = 0;
    for(int i = 1; i <= m; i++){//注意此时是从1开始的
        c[i][0] = 0;
    }
    for(int j = 1; j <= n; j++){
        c[0][j] = 0;
    }
    for(int i =1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i] == s2[j]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
            c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
            maxl = max(maxl,c[i][j]);
        }
    }


 //       cout << lcs_test(s1,s2) << endl;
     cout << maxl<< endl;

      }
    return 0;
}
