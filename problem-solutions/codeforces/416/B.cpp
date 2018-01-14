#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10002;
int n, m, l, r, x;
int v[N], vis[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i,1,n+1){
		scanf("%d", &v[i]);
	}

	For(i,0,m){
		scanf("%d%d%d", &l, &r, &x);
		
		if(x < l or x > r or l == r){
			printf("Yes\n");
			continue;
		}

		bool ok = 1;
	    int	maior = 0, menor = 0;
		for(int i = l; i < x; i++){
			if(v[i] > v[x]){
				maior++;
				//printf("maior: %d\n", v[i]);
				//ok = 0;
				//break;
			}
		}
		for(int i = x+1; i <= r; i++){
			if(v[i] < v[x]){
				menor++;
				//printf("menor: %d\n", v[i]);
				//ok = 0;
				//break;
			}
		}

		//printf("%d %d\n", menor, maior);
		if(maior ==  menor){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}

