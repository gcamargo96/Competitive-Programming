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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int g1, p1, g2, p2;

int main(void){
	fastcin;
	cin >> g1 >> p1 >> g2 >> p2;

	int cnt1 = 0;
	for(cnt1 = 0; cnt1 <= g1; cnt1++){
		int paux = (100*cnt1)/g1;
		if(paux == p1){
			break;
		}
	}

	int cnt2 = 0;
	for(int i = g1+1; i <= g2; i++){
		if((100*(cnt1+1))/g2 <= p2){
			cnt1++;
			cnt2++;
		}
		else{
			break;
		}
	}

	cout << cnt2 << endl;

	return 0;
}