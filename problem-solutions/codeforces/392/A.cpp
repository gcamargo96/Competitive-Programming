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
int v[N];
int n;

int main(void){
	scanf("%d", &n);

	int x, maior = -1;;
	For(i,0,n){
		scanf("%d", &v[i]);
		maior = max(maior, v[i]);
	}

	ll res = 0;
	For(i,0,n){
		res += maior-v[i];
	}

	cout << res << endl;

	return 0;
}

