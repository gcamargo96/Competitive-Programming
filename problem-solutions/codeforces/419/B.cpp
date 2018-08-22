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

const int N = 200005;
int acum[N], ac[N];
int n, k, q;

int main(void){
	scanf("%d%d%d", &n, &k, &q);

	int l, r;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l, &r);
		acum[l]++;
		acum[r+1]--;
	}

	for(int i = 1; i < N; i++){
		acum[i] += acum[i-1];

		ac[i] = ac[i-1];
		if(acum[i] >= k) ac[i]++;
	}

	int a, b;
	for(int i = 0; i < q; i++){
		scanf("%d%d", &a, &b);
	
		printf("%d\n", ac[b] - ac[a-1]);
	}

	return 0;
}