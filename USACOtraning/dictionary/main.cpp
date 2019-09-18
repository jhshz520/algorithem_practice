#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define M 1046527
#define NIL (-1)
#define L 14


char H[M][L];

int changeChar(char ch){//change char to number
    if(ch=='A') return 1;
    else if( ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

long long changeKey(char str[]){
long long sum = 0,p = 1,i;
for(i = 0 ;i <strlen(str); i++){
    sum += p*(changeChar(str[i]));
    p *= 5;
}
return sum;
}

int h1(int key){
    return key%M;
}

int h2(int key){
    return 1 + (key%(M-1));
}

int finds(char str[]){
    long long key ,i,h;
    key = changeKey(str);
    for(i = 0 ; ;i++){
        h = (h1(key) + i*h2(key)) % M;
        if(strcmp(H[h],str)==0){
                 return 1;
        }
        else if(strlen(H[h]) == 0){
        return 0;
    }
    }
    return 0;

}

int inserts(char str[]){
long long key, i, h;
 key = changeKey(str);
 for(i = 0; ;i++){
    h = (h1(key) + i*h2(key))%M;//必须在%M前加一个大括号，不然会溢出
    if(strcmp(H[h],str) == 0)
        return 1;
    else if (strlen(H[h] )== 0){//error if (strlen(H[h]==0))  括号出错
        strcpy(H[h],str);
        return 0;
    }
 }
 return 0;
}



int main()
{
    int i , n , h;
    char str[L], com[9];
    for(  i = 0;i < M ; i++){
        H[i][0] = '\0';
    }
    freopen("in.txt","r",stdin);
    cin >> n;
    for( i = 0; i < n; i++){
        cin >> com >>str;
        if(com[0]=='i'){
            inserts(str);
        }else{
        if(finds(str)){
            cout << "yes" << endl;
        }else{
        cout << " no " <<endl;
        }
        }
    }
   return 0;
}
