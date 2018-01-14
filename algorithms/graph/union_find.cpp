#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int pai[MAXN], rank[MAXN];
  
int init(int n) {
    for(int i=0;i<n;i++) {
        pai[i] = i;
        rank[i] = 1;
    }
}
 
int find (int x) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
 
int join(int a, int b){
    a = find(a);
    b = find(b);
    if(rank[a] < rank[b]) swap(a,b); //garanto q A é a maior arvore
    if(a != b) {
        if(rank[a] == rank[b]) rank[a]++;
        pai[b] = a;
    }
}