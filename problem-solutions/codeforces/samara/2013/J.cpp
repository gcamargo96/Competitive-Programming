#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
int n;
int a[N], b[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}

	int k = 0, best = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > k){
			best = max(best, b[i]);
		}
		k = max(k, a[i]);
	}

	printf("%d\n", best);

	return 0;
}