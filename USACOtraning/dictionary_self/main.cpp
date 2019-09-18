#include <iostream>
#include <string.h>
#include <cstdio>


using namespace std;

#define NIL (-1)
#define M 10000
#define L  14
char H[M][L];
int changeChar(char ch){
    if(ch == 'A')
        return 1;
    else if(ch == 'C')
        return 2;
    else if(ch == 'G')
        return 3;
    else if(ch == 'T')
        return 4;
    else
        return 0;
}

long long  changeKey(char str[]){
    long long  p = 1,sum = 0;
    for(int i = 0;i < strlen(str); i++){
         sum += p*(changeChar(str[i]));// sum += p*changeChar(str[i]);
        p *= 5;
    }
    return sum;
}
int h1(int key){
   return key%M;
}
int h2(int key){
return 1+(key%(M-1));
}

void inserts(char str[]){//循环条件有误
    long long key = changeKey(str),h;
    for(int i = 0; ;i ++){
        h = (h1(key) +i*h2(key))%M;

        if(strlen(H[h]) == 0){//不能单纯的看是否为空，还要看是否赋值上了
          strcpy(H[h],str);
        if(strcmp(H[h],str) == 0)
            break;
        }
    }
}
void finds(char str[]){
    long long key = changeKey(str),h;
     for(int i = 0; ;i ++){
        h = (h1(key) +i*h2(key))%M;
        if(strcmp(H[h],str) == 0){
                cout <<"yes" << endl;
                break;
        }
        if(strlen(H[h]) == 0){
             cout <<"no" << endl;
            break;
        }
    }

}

int main()
{
    int n;
    char com[9],str[L];// string com,str; error
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < M ; i++){
        H[i][0] == '\0';

    }
    for(int i = 0; i < n ; i++){
        cin >> com >> str;
        if(com[0] == 'i'){//strcmp(com[0] == 'i') error
            inserts(str);
        }else{
            finds(str);
        }
    }
    return 0;
}
