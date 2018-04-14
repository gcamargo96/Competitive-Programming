#include <bits/stdc++.h>
using namespace std;
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

const int N = 100005, INF = 1000000000;
int n;
int a[N], b[N];

int get_max(int i){
	int mx = -INF;
	mx = max(mx, a[i]);
	mx = max(mx, a[i-1]);
	mx = max(mx, a[i-2]);
	mx = max(mx, a[i-3]);
	mx = max(mx, a[i-4]);
	return mx;
}

int get_min(int i){
	int mx = INF;
	mx = min(mx, a[i]);
	mx = min(mx, a[i-1]);
	mx = min(mx, a[i-2]);
	mx = min(mx, a[i-3]);
	mx = min(mx, a[i-4]);
	return mx;	
}

int main(void){
	fastcin;
	// scanf("%d", &n);
	cin >> n;

	for(int i = 0; i < n; i++){
		// scanf("%d", &a[i]);
		cin >> a[i];
	}

	char c;
	for(int i = 0; i < n; i++){
		// scanf("%d", &b[i]);
		cin >> c;
		b[i] = c-'0';
	}

	int l = -1000000000, r = 1000000000;

	for(int i = 4; i < n; i++){
		if(b[i] == 0){
			if(b[i-1] == 0){
				continue;
			}
			else{
				int mx = get_min(i);
				r = min(r, mx-1);
				l = min(l, r);
			}
		}
		else{
			if(b[i-1] == 1){
				continue;
			}
			else{
				int mx = get_max(i);
				l = max(l, mx+1);
				r = max(l, r);
			}
		}
	}

	// printf("%d %d\n", l, r);
	cout << l << " " << r << endl;

	return 0;
}