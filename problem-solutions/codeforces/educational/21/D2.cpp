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

const int N = 100002;
ll a[N];
map<ll,ll> m;
ll total;
int n;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lld", &a[i]);
		total += a[i];
	}

	if(total%2 == 1){
		printf("NO\n");
		return 0;
	}

	ll sum = 0;
	For(i,0,n){
		m[a[i]]++;
	}

	For(i,0,n){
		if(m.count((total/2LL-sum))){
			printf("YES\n");
			return 0;
		}

		//if(sum + a[i] > total/2LL) break;

		sum += a[i];
		m[a[i]]--;
		if(m[a[i]] == 0){
			m.erase(a[i]);
		}
	}


	sum = 0;
	m.clear();

	For(i,0,n){
		m[a[i]]++;
	}

	for(int i = n-1; i >= 0; i--){
		if(m.count((total/2LL-sum))){
			printf("YES\n");
			return 0;
		}

		//if(sum + a[i] > total/2LL) break;

		sum += a[i];
		m[a[i]]--;
		if(m[a[i]] == 0){
			m.erase(a[i]);
		}
	}

	printf("NO\n");

	return 0;
}

