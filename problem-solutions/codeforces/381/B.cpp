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
int n, m;
int v[N], sum[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i,1,n+1){
		scanf("%d", &v[i]);
	}

	For(i,1,n+1){
		sum[i] = sum[i-1] + v[i];
	}

	int l, r, res = 0;
	For(i,0,m){
		scanf("%d%d", &l, &r);
		if(sum[r] - sum[l-1] > 0){
			res += sum[r] - sum[l-1];
		}
	}

	printf("%d\n", res);
	
	return 0;
}

