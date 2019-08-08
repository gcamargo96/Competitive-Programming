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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

struct Bulk{
	vi v, acc;
	int mx = -INF;
};

const int N = 200005;
int t, n, d;
int sz;
vector<Bulk> bulks;

int main(void){
	scanf("%d", &t);

	while(t--){
		bulks.clear();
		scanf("%d%d", &n, &d);
		sz = sqrt(n);

		int x, acc = 0, cur = 0;
		bulks.pb(Bulk());

		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			acc += x;

			if(bulks[cur].v.size() == sz){
				bulks.pb(Bulk());
				cur++;
			}

			bulks[cur].v.pb(x);
			bulks[cur].acc.pb(acc);
			bulks[cur].mx = max(bulks[cur].mx, acc);
		}

		int ans = INF;
		for(int b = 0; b < bulks.size(); b++){ // percorre os bulks
			for(int i = 0; i < bulks[b].v.size(); i++){ // percorre o bulk atual

				bool ok = 0;
				for(int j = i; j < bulks[b].v.size(); j++){ // testa se tem resposta no bulk atual
					if(bulks[b].acc[j] - bulks[b].acc[i] + bulks[b].v[i] >= d){
						ans = min(ans, j-i+1);
						ok = 1;
						break;
					}
				}

				if(ok) continue;

				int aux = bulks[b].v.size() - i;
				for(int b2 = b+1; b2 < bulks.size(); b2++){ // testa os proximos bulks
					if(bulks[b2].mx - bulks[b].acc[i] + bulks[b].v[i] >= d){

						for(int j = 0; j < bulks[b2].v.size(); j++){
							if(bulks[b2].acc[j] - bulks[b].acc[i] + bulks[b].v[i] >= d){
								ans = min(ans, aux + j+1);
								break;
							}
						}

						break;
					}

					aux += bulks[b2].v.size();
				}
			}
		}

		if(ans != INF){
			printf("%d\n", ans);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}