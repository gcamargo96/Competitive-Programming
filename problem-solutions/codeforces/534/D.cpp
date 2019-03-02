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

string status, ans;

void check(string ans){
	if(ans == "e") exit(0);
}

void bin_search(int l, int r){
	int a = r, x = l;
	while(l < r){
		// cout << "l, r = " << l << ", " << r << endl;
		int mid = (l+r)/2;
		cout << "? " << mid/2 << " " << mid << endl;

		cin >> ans; check(ans);

		if(ans == "y"){
			// a = mid+1;
			l = mid+1;
		}
		else{
			a = mid;
			r = mid;
		}
	}

	cout << "! " << a << endl;
}

int main(void){
	fastcin;

	while(cin >> status and status == "start"){
		int x = 1, y = 2;

		while(1){
			cout << "? " << x << " " << y << endl;
			
			cin >> ans; check(ans);

			if(ans == "y"){
				x = y;
				y *= 2;
			}
			else if(x == 1 and y == 2){
				cout << "? 2 1" << endl;
				cin >> ans; check(ans);

				int a;
				if(ans == "y") a = 2;
				else a = 1;

				cout << "! " << a << endl;
				break;
			}
			else{
				bin_search(x, y);
				break;
			}
		}
	}

    return 0;
}