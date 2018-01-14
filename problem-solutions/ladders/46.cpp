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
int n;
int v[N], aux[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i]);
		aux[i] = v[i];
	}

	sort(aux, aux+n);

	int diff = 0;
	vector<int> pos;
	For(i,0,n){
		if(v[i] != aux[i]){
			diff++;
			pos.pb(i);
		}
	}

	if(diff == 0){
		printf("YES\n");
	}
	else if(diff == 2){
		swap(v[pos[0]], v[pos[1]]);
		if(aux[pos[0]] == v[pos[0]] and aux[pos[1]] == v[pos[1]]){
			printf("YES\n");
		}
	}
	else printf("NO\n");

	return 0;
}

