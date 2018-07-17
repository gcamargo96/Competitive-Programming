#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define BEG 0
#define END 1

struct event{
	int x, tipo;

	event() {}

	event(int _x, int _tipo){
		x = _x;
		tipo = _tipo;
	}

	bool operator<(const event& b) const{
		if(x == b.x) return tipo < b.tipo;
		return x < b.x;
	}
};

const int N = 200005;
vector<event> v;
int ans[N];
int n;

int main(void){
	scanf("%d", &n);

	int l, r;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l, &r);
		v.emplace_back(l, BEG);
		v.emplace_back(r, END);
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for(int i = 0; i < v.size();){
		int x = v[i].x;
		while(i < v.size() and v[i].x == x and v[i].tipo == BEG){
			cnt++;
			i++;
		}

		printf("x = %d, ans[%d]++\n", x, cnt);
		ans[cnt]++;
		
		while(i < v.size() and v[i].x == x and v[i].tipo == END){
			cnt--;
			i++;
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}