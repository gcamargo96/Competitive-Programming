#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 5002;
int n;
int v[N];
set<int> tem;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i]);
		tem.insert(v[i]);
	}

	int res = 0, i, j;
	for(auto it = tem.begin(); it != tem.end(); it++){
		for(i = 0; i < n; i++){
			for(j = i; j < n; j++){
				if(v[j] < *it) break;
			}
			if(j > i){
				//printf("*it = %d: %d %d\n", *it, i, j);
				res++;
			}
			i = j;
		}
	}

	printf("%d\n", res);

	return 0;
}
