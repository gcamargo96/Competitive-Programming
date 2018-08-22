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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n;
int t[N];

int main(void){
	scanf("%d", &n);

	int x;
	stack<int> s;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);

		t[x] = 1;
		while(!s.empty() and x > s.top()){
			t[x] = max(t[x], t[s.top()]+1);
			s.pop();
		}

		if(s.empty()){
			t[x] = INF;
		}

		s.push(x);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(t[i] == INF)
			continue;
		ans = max(ans, t[i]);
	}

	printf("%d\n", ans);

	return 0;
}