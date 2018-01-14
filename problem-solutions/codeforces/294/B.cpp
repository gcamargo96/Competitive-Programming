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

map<int,int> s, aux;
int n;

int main(void){
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		s[x]++;
	}

	For(i,0,n-1){
		scanf("%d", &x);
		aux[x]++;
		s[x]--;
		if(s[x] == 0) s.erase(x);
	}

	int r1 = s.begin()->fi;
	s.clear();

	for(auto it : aux){
		s[it.fi] = it.se;
	}

	aux.clear();

	For(i,0,n-2){
		scanf("%d", &x);
		aux[x]++;
		s[x]--;
		if(s[x] == 0) s.erase(x);
	}

	int r2 = s.begin()->fi;

	cout << r1 << endl << r2 << endl;

	return 0;
}

