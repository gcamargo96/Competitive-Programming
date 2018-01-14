#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

const int N = 1002;
int n, m;
int a[N], b[N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}

	int ans = 0;
	for(int i = 0; i <= m-n; i++){
		bool ok = 1;
		for(int j = 0; j < n; j++){
			if(a[j] == b[i+j]){
				ok = 0;
				break;
			}
		}

		if(ok){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}