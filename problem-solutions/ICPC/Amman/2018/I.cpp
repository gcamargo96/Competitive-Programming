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

const int N = 1005;
int t;
int x, n;
int v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &x, &n);

		if(n > x){
			printf("-1\n");
		}
		else{
			int q = x/n;
			int r = x%n;

			for(int i = 0; i < n; i++){
				v[i] = q;
			}

			int i = n-1;
			while(r > 0){
				v[i]++;
				i--;
				r--;
			}

			for(int i = 0; i < n; i++){
				printf("%d ", v[i]);
			}
			printf("\n");
		}
	}

	return 0;
}