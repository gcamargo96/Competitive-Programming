#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define POS 0
#define NEG 1
const int N = 200002;
int n, k;
int v[N];
int neg = 0, pos = 0, res = 0, ult = -1;
set<pair<int,ii>> seg;

int main(void){
	scanf("%d%d", &n, &k);

	int flag = -1;
	int ini = -1, fim = -1, tam = 0;
	For(i,0,n){
		scanf("%d", &v[i]);
		
		if(v[i] >= 0 and flag == NEG) res += 2;
		
		if(v[i] >= 0){
			if(flag == NEG){
				ini = i;
			}
			flag = POS;
		}
		else if(v[i] < 0){
			if(flag == POS and ini != -1){
				fim = i-1;
				seg.insert(mp(fim-ini+1, mp(ini,fim)));
			}
			flag = NEG;
			neg++;
			ult = i;
		}
	}
	if(v[n-1] < 0) res ++;

	if(neg > k){
		printf("-1\n");
		return 0;
	}
	if(neg == 0){
		printf("0\n");
		return 0;
	}
	if(neg == k and k == n){
			printf("1\n");
		return 0;
	}

	/*for(auto it = seg.begin(); it != seg.end(); it++){
		printf("%d a %d, tam = %d\n", it->se.fi, it->se.se, it->fi);
	}*/

	if(neg < k){
		for(auto it = seg.begin(); it != seg.end() and neg < k; it++){
			if(it->fi <= k-neg){
				res -= 2;
				neg += it->fi;
			}
		}
	}

	if(n-1 - ult <= k-neg) res--;

	printf("%d\n", res);

	return 0;
}

