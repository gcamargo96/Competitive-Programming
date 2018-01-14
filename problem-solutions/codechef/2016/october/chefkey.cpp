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

int t, n, m, c;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d%d", &n, &m, &c);

		int res = 0;
		for(int i = 1; i <= c; i++){
			if(c%i == 0){
				if(i <= n and c/i <= m) res++;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
