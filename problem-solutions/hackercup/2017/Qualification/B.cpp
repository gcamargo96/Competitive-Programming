#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int t, n;
int v[N];

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		memset(v, 0, sizeof v);
		
		scanf("%d", &n);

		For(i,0,n){
			scanf("%d", &v[i]);
		}

		sort(v, v+n);

		int i = 0, j = n-1;
		int res = 0;
		for(j = n-1; j >= i; j--){
			int tam = 1;

			while(j > i and tam*v[j] < 50){
				tam++;
				i++;
			}
			if(tam*v[j] >= 50) res++;
		}
		
		printf("Case #%d: %d\n", caso, res);
	}

	return 0;
}

