#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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
int v[N];
map<int,int> extra;

int main(void){
	scanf("%d", &n);

	int last = 0;
	bool increasing = 1;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] <= last)
			increasing = 0;
		last = v[i];
	}

	if(increasing){
		printf("%d\n", n-1);
		return 0;
	}

	int m1 = 0, m2 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > m2 and v[i] > m1){
			ans++;
		}
		else if(v[i] > m2 and v[i] <= m1){
			extra[m1]++;
		}

		if(v[i] > m1){
			m2 = m1;
			m1 = v[i];
		}
		else if(v[i] > m2){
			m2 = v[i];
		}

		// printf("(%d,%d)\n", m2,m1);
	}

	int maior = 0;
	for(auto it = extra.begin(); it != extra.end(); it++){
		maior = max(maior, it->se);
	}

	if(maior > 0)
		ans = ans + maior - 1;

	printf("%d\n", ans);

	return 0;
}