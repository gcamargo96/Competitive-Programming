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

map<int, int> m;
int n, p, q;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &p, &q);
		if(!m.count(p)){
			m[p] = q;
		}
		else{
			m[p] = max(m[p], q);
		}
	}

	int maior = -1;
	bool ok = 0;
	for(auto it = m.begin(); it != m.end(); it++){
		if(it->se < maior){
			ok = 1;
			break;
		}
		maior = max(maior, it->se);
	}

	if(ok) printf("Happy Alex\n");
	else printf("Poor Alex\n");

	return 0;
}

