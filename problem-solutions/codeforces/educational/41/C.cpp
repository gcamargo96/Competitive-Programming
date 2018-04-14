#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
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

const int N = 102;
int n;
char a[N][N], b[N][N], c[N][N], d[N][N], t1[N][N], t2[N][N];

// void init(){
// 	bool turn = 0;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			if(turn == 0){
// 				t1[i][j] = '0';
// 				t2[i][j] = '1';
// 			}
// 			else{
// 				t1[i][j] = '1';
// 				t2[i][j] = '0';
// 			}
// 			turn = !turn;
// 		}
// 	}	
// }

int check(vi& p){
	int ret = 0, turn;

	turn = p[0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j]-'0' != turn){
				ret++;
			}
			turn = !turn;
		}
	}

	turn = p[1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j]-'0' != turn){
				ret++;
			}
			turn = !turn;
		}
	}

	turn = p[2];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(c[i][j]-'0' != turn){
				ret++;
			}
			turn = !turn;
		}
	}

	turn = p[3];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(d[i][j]-'0' != turn){
				ret++;
			}
			turn = !turn;
		}
	}

	return ret;
}

int main(void){
	fastcin;
	cin >> n;
	// init();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> d[i][j];
		}
	}

	vi p;
	p.pb(0);
	p.pb(0);
	p.pb(1);
	p.pb(1);

	int ans = INF;
	do{
		ans = min(ans, check(p));
	}while(next_permutation(p.begin(), p.end()));

	cout << ans << endl;

	return 0;
}