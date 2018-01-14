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

const int N = 1001000;
int n, m;
bool v[N];

bool check(int l, int r){
	for(int i = l; i < r and i <= 1000001; i++){
		if(v[i] == 1){
			//printf("pos = %d\n", i);
			return 0;
		}
		v[i] = 1;
	}
	return 1;
}

int main(void){
	while(scanf("%d%d", &n, &m), !(n == 0 and m == 0)){
		memset(v, 0, sizeof v);
		int l, r, p;
		bool ok = 1;
		
		For(i,0,n){
			scanf("%d%d", &l, &r);
			if(!check(l, r)) ok = 0;
		}

		For(i,0,m){
			scanf("%d%d%d", &l, &r, &p);
			for(int j = 0; l+j <= 1000001; j += p){
				if(!check(l+j, r+j)) ok = 0;
			}
		}

		if(ok) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}

	return 0;
}
