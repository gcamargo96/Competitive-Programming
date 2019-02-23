#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10005;
int t, n, x;
int p[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			scanf("%d", &p[i]);
		}

		vi v;
		for(int i = 1; i <= n; i++){
			v.pb(p[i]-p[i-1]-1);
		}

		reverse(v.begin(), v.end());

		// for(int i = 0; i < v.size(); i++){
		// 	printf("%d ", v[i]);
		// }
		// printf("\n");

		int g = 0;
		for(int i = 0; i < v.size(); i += 2){
			g ^= v[i];
		}

		if(g){
			printf("Mary wins\n");

			int a, b;
			for(int i = 0; i < v.size(); i++){
				if(i%2 == 0){ // diminui a propria pilha
					int y = g^v[i];
					int take = v[i]-y;
					int j = v.size()-i;
					if(v[i] > y and p[j]-take > p[j-1]){
						a = p[j];
						b = p[j]-take;
					}
				}
				else{ // aumenta a pilha do proximo
					int y = g^v[i-1];
					int take = y-v[i-1];
					int j = v.size()-i;
					if(take > 0 and take <= v[i] and p[j]-take > p[j-1]){
						a = p[j];
						b = p[j]-take;
					}
				}
			}

			printf("Move %d to %d\n", a, b);
		}
		else{
			printf("Johnny wins\n");
		}
		printf("\n");
	}

	return 0;
}