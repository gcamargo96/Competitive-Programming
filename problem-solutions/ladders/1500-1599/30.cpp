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

const int N = 102;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int ones = 0;
	For(i,0,n){
		scanf("%d", &v[i]);
		if(v[i] == 1) ones++;
	}

	int mx = -1;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = i; j < n; j++){
			if(v[j] == 0) cnt++;
			else cnt--;
			mx = max(mx, cnt);
		}
	}

	printf("%d\n", ones+mx);

	return 0;
}

