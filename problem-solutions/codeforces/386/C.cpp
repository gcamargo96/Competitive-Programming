#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define E -1
#define D 1

int s, x1, x2;
int t1, t2;
int p, d;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> x1 >> x2;
	cin >> t1 >> t2;
	cin >> p >> d;

	int distp = abs(x1-x2);
	int distt;
	if(d == E){
		if(p >= x1){
			distt += p-x1;
			if(x1 >= x2) distt += x1-x2;
			else distt += x1 + x2;
		}
		else{ // p < x1
			distt += p + x1;
			if(x2 >= x1) distt += x2-x1;
			else distt += s-x1 + s-x2;
		}
	}
	else{ // d == D
		if(x1 >= p){
			distt += x1-p;
			if(x2 >= x1) distt += x2-x1;
			else distt += s-x1 + s-x2;
		}
		else{ // x1 < p
			distt += s-p + s-x1;
			if(x2 <= x1) distt += x1-x2;
			else distt += x1 + x2;
		}
	}

	double vt = 1.0/t1;
	double vp = 1.0/t2;

	if(distp/vp <=  distt/vt){
		cout << distp/vp << endl;
	}
	else{
		cout << distt/vt << endl;
	}

	return 0;
}

