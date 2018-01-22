#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

int x, h, m;

int main(void){
	cin >> x;
	cin >> h >> m;

	int ans = 0;
	while(1){
		int auxm = m;
		int d0 = auxm%10;
		auxm /= 10;
		int d1 = auxm%10;

		int auxh = h;
		int d2 = auxh%10;
		auxh /= 10;
		int d3 = auxh%10;

		if(d0 == 7 or d1 == 7 or d2 == 7 or d3 == 7){
			break;
		}

		if(m < x){
			if(h == 0){
				h = 23;
			}
			else{
				h--;
			}

			int y = x-m;
			m = 60-y;
		}
		else{
			m -= x;
		}
		ans++;
	}

	// cout << h << " " << m << endl;
	cout << ans << endl;

	return 0;
}