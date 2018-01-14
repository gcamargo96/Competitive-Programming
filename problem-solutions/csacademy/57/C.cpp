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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define FOX 1
#define HOLE 2

const int N = 100002;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		v[x] = 1;
	}

	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		v[x] = 2;
	}

	int cnt1 = 0;
	for(int i = 1; i < n; i++){
		if(v[i] + v[i+1] == 3){
			cnt1++;
			i++;
		}
	}

	int cnt2 = (v[n] + v[1] == 3 ? 1 : 0);
	for(int i = 2; i < n-1; i++){
		if(v[i] + v[i+1] == 3){
			cnt2++;
			i++;
		}
	}

	int ans = 2*k - max(cnt1, cnt2);
	printf("%d\n", ans);

	return 0;
}