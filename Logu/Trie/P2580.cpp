#include "bits/stdc++.h"
#include <iomanip>
using namespace std;


typedef long long Long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii>  vii;
#define  xx    first
#define  yy    second

#define MAXN 1000100

int kase;
int son[MAXN][26], cnt[MAXN], fst[MAXN], idx;
char str[55];
//下标为零的结点代表root结点，也是一个空节点

void insert(char str[]){
    int t, p = 0;
    for (int i = 0; str[i]; i++){
        t = str[i] - 'a';
        if(!son[p][t])
            son[p][t] = ++idx;
        p = son[p][t];
    }
    cnt[p]++;
}

int query(char str[]){
    int t,p = 0;
    for (int i = 0; str[i]; i++){
        t = str[i] - 'a';
        if(!son[p][t])
            return 0;
        p = son[p][t];
    }
    fst[p]++;
    return fst[p] <= 1 ? cnt[p] : -cnt[p];
}



int main(){ 
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        insert(str);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%s", &str);
        if(query(str) > 0){
            printf("OK\n");
        }else if(query(str) < 0){
            printf("REPEAT\n");
        }else{ // query(str)==0
            printf("WRONG\n");
        }
    }
    return 0;
}
