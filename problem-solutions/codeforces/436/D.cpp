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

const int N = 200002;
int n;
int v[N], cnt[N];
set<int> s;
bool flag[N];

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		s.insert(i);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		s.erase(v[i]);
		cnt[v[i]]++;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(flag[v[i]]){ // precisa trocar
			int aux = *s.begin(); // menor disponivel
			v[i] = aux;
			s.erase(aux);
			ans++;
			continue;
		}
		if(cnt[v[i]] > 1){
			int aux = *s.begin();
			if(aux > v[i]){
				flag[v[i]] = 1;
			}
			else{
				cnt[v[i]]--;
				v[i] = aux;
				s.erase(aux);
				ans++;
			}
		}
	}

	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}