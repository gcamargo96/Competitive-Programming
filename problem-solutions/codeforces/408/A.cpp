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

const int N = 102;
int n, m, k;
int a[N];

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	int dist = 0;
	for(int i = 1; i <= n; i++){
		if(m-i >= 1){
			if(a[m-i] > 0 and a[m-i] <=  k){
				dist = i*10;
				break;
			}
		}
		if(m+i <= n){
			if(a[m+i] > 0 and a[m+i] <= k){
				dist = i*10;
				break;
			}
		}
	}

	printf("%d\n", dist);

	return 0;
}

