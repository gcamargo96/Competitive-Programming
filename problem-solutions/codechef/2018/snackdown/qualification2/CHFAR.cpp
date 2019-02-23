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

const int N = 100005;
int t, n, k;
int v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);
		
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		sort(v, v+n);

		for(int i = 0; i < k; i++){
			v[n-1-i] = 1;
		}

		int sum = 0, sum2 = 0;
		for(int i = 0; i < n; i++){
			sum += v[i];
			sum2 += v[i]*v[i];
		}

		if(sum2 <= sum){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}