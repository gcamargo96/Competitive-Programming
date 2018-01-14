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

set<int> jack, jill;
int m, n, x;

int main(void){
	while(scanf("%d%d", &n, &m) and !(n == 0 and m == 0)){
		jack.clear();
		jill.clear();
		For(i,0,n){
			scanf("%d", &x);
			jack.insert(x);
		}
		For(i,0,m){
			scanf("%d", &x);
			jill.insert(x);
		}

		int res = 0;
		for(auto it = jack.begin(); it != jack.end(); it++){
			if(jill.count(*it)) res++;
		}

		printf("%d\n", res);
	}	

	return 0;
}
