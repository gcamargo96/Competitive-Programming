#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
//#define pii pair<int,int>

struct Event{
	int p;
	int t;

	bool operator <(const Event &e) const{
		if(p < e.p) return 1;
		else if(p == e.p){
			if(t == 2 and e.t == 1) return 1;
			if(t == 1 and e.t == 3) return 1;
		}
		return 0;
	}
};

class SegmentsAndPoints{
public:
	string isPossible(vector<int> p, vector<int> l, vector <int> r){
		vector<Event> v;
		
		for(int i = 0; i < p.size(); i++){
			Event e;
			e.p = p[i];
			e.t = 1;
			v.pb(e);
		}
		for(int i = 0; i < l.size(); i++){
			Event e;
			e.p = l[i];
			e.t = 2;
			v.pb(e);
		}
		for(int i = 0; i < r.size(); i++){
			Event e;
			e.p = r[i];
			e.t = 3;
			v.pb(e);
		}

		sort(v.begin(), v.end());
		
		int ps = 0, ls = 0, rs = 0, res = 1;
		for(int i = 0; i < v.size(); i++){
			if(v[i].t == 1){ 
				if(ls == 0){
					res = 0;
					break;
				}
				ps++;
			}
			if(v[i].t == 2){
				ls++;
			}
			if(v[i].t == 3){
				if(ps == 0){
					res = 0;
					break;
				}
				ps--;
				ls--;
			}
		}

		if(res) return "Possible";
		else return "Impossible";
	}	

};

int main(void){
	ios_base::sync_with_stdio(false);

	SegmentsAndPoints S;

	int n, x; cin >> n;
	vector <int> vp, vl, vr;
	for(int i = 0; i < n; i++){
		cin >> x;
		vp.pb(x);
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		vl.pb(x);
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		vr.pb(x);
	}

	string res = S.isPossible(vp, vl, vr);

	cout << res << endl;
	
	return 0;
}
