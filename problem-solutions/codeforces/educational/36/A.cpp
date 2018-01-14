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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	int ans = 1000000000;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		
		if(v[i] <= k and k%v[i] == 0){
			ans = min(ans, k/v[i]);
		}
	}

	printf("%d\n", ans);

	return 0;
}