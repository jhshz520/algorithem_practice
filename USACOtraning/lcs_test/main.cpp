 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<cstdio>
 using namespace std;
 const int N = 1000;
 char a[N],b[N];
 int dp[N][N];
 int main()
 {
     freopen("in.txt","r",stdin);
     int lena,lenb,i,j;
     while(scanf("%s%s",a,b)!=EOF)
     {
         memset(dp,0,sizeof(dp));
         lena=strlen(a);
         lenb=strlen(b);
         for(i=1;i<=lena;i++)
         {
             for(j=1;j<=lenb;j++)
             {
                 if(a[i-1]==b[j-1])
                 {
                     dp[i][j]=dp[i-1][j-1]+1;
                 }
                 else
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
             }
         }
         printf("%d\n",dp[lena][lenb]);
     }
     return 0;
 }
