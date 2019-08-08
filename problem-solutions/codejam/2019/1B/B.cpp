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

int t, w;
int n;
ll pot[65];

void precalc(){
	pot[0] = 1;
	for(int i = 1; i <= 63; i++){
		pot[i] = 2LL*pot[i-1];
	}
}

int main(void){
	precalc();
	cin >> t >> w;

	ll sum;
	while(t--){
		cout << 200 << endl;
		cin >> sum;

		ll R6A = sum%pot[40];
		ll R6 = R6A/pot[33];

		ll R5A = (sum-R6A)%pot[50];
		ll R5 = R5A/pot[40];

		ll R4A = sum-R6A-R5A;
		ll R4 = R4A/pot[50];

		cout << 56 << endl;
		cin >> sum;
		sum -= pot[14]*R4 + pot[11]*R5 + pot[9]*R6;

		ll R3A = sum%pot[28];
		ll R3 = R3A/pot[18];

		ll R2A = (sum-R3A)%pot[56];
		ll R2 = R2A/pot[28];

		ll R1A = sum-R3A-R2A;
		ll R1 = R1A/pot[56];

		cout << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << endl;

		int feedback;
		cin >> feedback;
		if(feedback == -1) return 0;
	}

	return 0;
}