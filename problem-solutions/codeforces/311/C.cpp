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

const int N = 100002;
ii v[N];
int sum[N];
int d[202], cnt[N];
int n;


int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i].fi);
	}

	For(i,0,n){
		scanf("%d", &v[i].se);
	}

	sort(v, v+n);

	
	for(int i = n-1; i >= 0; i--){
		sum[i] = sum[i+1] + v[i].se;
	}

	int res = 0, ans = INF;
	vector<int> aux;
	For(i,0,n){
		aux.pb(v[i].se);
		//d[v[i].se]++;
		cnt[v[i].fi]++;
		if(v[i+1].fi != v[i].fi){
			res = sum[i+1];
			if(cnt[v[i].fi] <= (i+1) - cnt[v[i].fi]){
				int precisa = cnt[v[i].fi] - 1;
				int tirar = (i+1) - cnt[v[i].fi] - precisa;
				/*cout << "precisa tirar " << tirar << endl;
				for(int j = 1; j <= 5; j++){
					cout << d[j] << " ";
				}
				cout << endl;
				*/
				for(int j = 1; j <= 200 and tirar > 0; j++){
					res += j * min(d[j], tirar);
					tirar -= min(d[j], tirar);
				}
			}
			//cout << res << endl;
			ans = min(res, ans);
			For(j,0,aux.size()){
				d[aux[j]]++;
			}
			aux.clear();
		}
	}

	printf("%d\n", ans);
	
	return 0;
}

