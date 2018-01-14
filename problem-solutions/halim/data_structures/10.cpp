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
#define popcount __builtin_popcount

const int N = 40002;
int n;
int peso[N], pot[N];

int main(void){
	while(scanf("%d", &n) != EOF){
		memset(peso, 0, sizeof peso);
		memset(pot, 0, sizeof pot);
		int t = (1 << n);
		For(i,0,t){
			scanf("%d", &peso[i]);
		}

		For(i,0,t){
			For(j,0,n){
				int aux = (1 << j);
				pot[i] += peso[i^aux];
			}
		}

		int res = 0;
		For(i,0,t){
			For(j,0,n){
				int aux = (1 << j);
				if(pot[i]+pot[i^aux] > res){
					res = pot[i] + pot[i^aux];
				}
			}
		}
	
		printf("%d\n", res);
	}

	return 0;
}
