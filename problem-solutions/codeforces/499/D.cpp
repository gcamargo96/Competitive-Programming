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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int m, n;
bool p[35];

int main(void){
	cin >> m >> n;

	int ans;
	for(int i = 0; i < n; i++){
		cout << 1 << endl;
		cin >> ans;

		if(ans == 0){
			return 0;
		}
		else if(ans == -1){
			p[i] = true;
		}
		else if(ans == 1){
			p[i] = false;
		}
	}

	int l = 1, r = m;
	for(int i = 0; i < 60-n; i++){
		int mid = (l+r)/2;

		cout << mid << endl;
		cin >> ans;

		if(ans == 0){
			return 0;
		}

		if(p[i%n] == true){
			if(ans == -1){
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		else{
			if(ans == -1){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
	}

	return 0;
}