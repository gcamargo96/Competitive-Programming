#include <bits/stdc++.h>
using namespace std;
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
#define INF 0x3f3f3f3f

const int N = 100002;
int n;
vi v1, v2, v3;
map<int,int> cnt1, cnt2, cnt3;

int main(void){
	scanf("%d", &n);

	int x, mx = -INF, mn = INF;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		v1.pb(x);
		mx = max(mx, x);
		mn = min(mn, x);
	}

	if(mx-mn < 2){
		printf("%d\n", n);
		for(int i = 0; i < n; i++){
			printf("%d ", v1[i]);
		}
		printf("\n");
		return 0;
	}

	sort(v1.begin(), v1.end());
	v2 = v1;
	v3 = v1;

	int cmn = 0, cmx = 0, cmd = 0;
	for(int i = 0; i < n; i++){
		if(v1[i] == mn)
			cmn++;
		else if(v1[i] == mx)
			cmx++;
		else
			cmd++;
	}

	// if(min(cmn, cmx) >= cmd){
		for(int i = 0; i < n/2; i++){
			if(v2[n-1-i]-v2[i] == 2){
				v2[i]++;
				v2[n-1-i]--;
			}
		}
	// }
	// else{
		for(int i = 0; i < n-1; i++){
			if(v3[i] != mn and v3[i] != mx and v3[i] == v3[i+1]){
				v3[i]--;
				v3[i+1]++;
			}
		}
	// }

	for(int i = 0; i < n; i++){
		cnt1[v1[i]]++;
		cnt2[v2[i]]++;
		cnt3[v3[i]]++;
	}

	int ans1 = 0;
	for(auto it = cnt1.begin(); it != cnt1.end(); it++){
		ans1 += min(it->se, cnt2[it->fi]);
	}

	int ans2 = 0;
	for(auto it = cnt1.begin(); it != cnt1.end(); it++){
		ans2 += min(it->se, cnt3[it->fi]);
	}


	if(ans1 <= ans2){
		printf("%d\n", ans1);
		for(int i = 0; i < n; i++){
			printf("%d ", v2[i]);
		}
		printf("\n");
	}
	else{
		printf("%d\n", ans2);
		for(int i = 0; i < n; i++){
			printf("%d ", v3[i]);
		}
		printf("\n");		
	}

	return 0;
}