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

struct event{
	int tests, tipo;

	event() {}
	event(int tests, int tipo) : tests(tests), tipo(tipo);
};

const int N = 1005;
int n, k;
vector<event> e;

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		e.eb(x);
	}

	return 0;
}