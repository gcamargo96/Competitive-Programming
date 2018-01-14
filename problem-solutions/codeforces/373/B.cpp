#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define R 0
#define B 1

const int N = 100002;
int n;
int v[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	char c;
	For(i,0,n){
		cin >> c;
		if(c == 'r') v[i] = R;
		else if(c == 'b') v[i] = B;
	}

	int cor = R;
	int difr = 0, difb = 0, diff1 = 0, diff2 = 0;

	For(i,0,n){
		if(v[i] == R and cor == B) difr++;
		if(v[i] == B and cor == R) difb++;
		cor = !cor;
	}

	diff1 = min(difr, difb) + max(difr, difb) - min(difr, difb);

	difr = 0, difb = 0;
	cor = B;
	For(i,0,n){
		if(v[i] == R and cor == B) difr++;
		if(v[i] == B and cor == R) difb++;
		cor = !cor;
	}

	diff2 = min(difr, difb) + max(difr, difb) - min(difr, difb);
	
	int ans = min(diff1, diff2);

	cout << ans << endl;

	return 0;
}

