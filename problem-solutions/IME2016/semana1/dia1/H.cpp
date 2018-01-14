#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define POINT 1
#define LINE 2

struct event{
	int type;
	int x, y;

	event() {
		x = 0;
		y = 0;
	}

	event(int type, int x, int y){
		this->type = type;
		this->x = x;
		this->y = y;
	}
};

int n, m, res;
vector<event> vh, vv;
set<ii> seen;
map<int,int> hori, vert;

bool vcmp(const event& a, const event& b){
	return a.x < b.x;
}

bool hcmp(const event& a, const event& b){
	return a.y < b.y;
}

void init(){
	vv.clear();
	vh.clear();
	res = 0;
	seen.clear();
	hori.clear();
	vert.clear();
}

int main(void){
	ios_base::sync_with_stdio(false);
		
	while(cin >> n >> m, n != 0 and m != 0){
		init();
		int x, y;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			vh.pb(event(POINT, x, y));
			vv.pb(event(POINT, x, y));
		}

		char t, aux;
		int coord;
		for(int i = 0; i < m; i++){
			cin >> t >> aux >> coord;
			event e;
			if(t == 'x'){
				e.type = LINE;
				e.x = coord;
				vv.pb(e);
			}
			if(t == 'y'){
				e.type = LINE;
				e.y = coord;
				vh.pb(e);
			}
		}

		sort(vh.begin(), vh.end(), hcmp);
		sort(vv.begin(), vv.end(), vcmp);
	
		int first = 1;
		for(int i = 0; i < vv.size(); i++){
			if(vv[i].type == LINE){
				first = 0;
				vert.clear();
			}
			if(vv[i].type == POINT and !first){
				if(!vert.count(vv[i].y) and !seen.count(mp(vv[i].x, vv[i].y))){
					//cout << "vv -> " << vv[i].x << " " << vv[i].y << endl;
					res++;
					vert[vv[i].y] = 1;
					seen.insert(mp(vv[i].x, vv[i].y));
				}
				if(!vert.count(vv[i].y)) vert[vv[i].y] = 1;
			}
		}
		first = 1;
		for(int i = vv.size()-1; i >= 0; i--){
			if(vv[i].type == LINE){
				first = 0;
				vert.clear();
			}
			if(vv[i].type == POINT and !first){
				if(!vert.count(vv[i].y) and !seen.count(mp(vv[i].x, vv[i].y))){
					//cout << "vv <- " << vv[i].x << " " << vv[i].y << endl;
					res++;
					vert[vv[i].y] = 1;
					seen.insert(mp(vv[i].x, vv[i].y));
				}
				if(!vert.count(vv[i].y)) vert[vv[i].y] = 1;
			}
		}


		first = 1;
		for(int i = 0; i < vh.size(); i++){
			if(vh[i].type == LINE){
				first = 0;
				hori.clear();
			}
			if(vh[i].type == POINT and !first){
				if(!hori.count(vh[i].x) and !seen.count(mp(vh[i].x, vh[i].y))){
					//cout << "vh cima " << vh[i].x << " " << vh[i].y << endl;
					res++;
					hori[vh[i].x] = 1;
					seen.insert(mp(vh[i].x, vh[i].y));
				}
				if(!hori.count(vh[i].x)) hori[vh[i].x] = 1;
			}
		}
		first = 1;
		for(int i = vh.size()-1; i >= 0; i--){
			if(vh[i].type == LINE){
				first = 0;
				hori.clear();
			}
			if(vh[i].type == POINT and !first){
				if(!hori.count(vh[i].x) and !seen.count(mp(vh[i].x, vh[i].y))){
					//cout << "vh baixo " << vh[i].x << " " << vh[i].y << endl;
					res++;
					hori[vh[i].x] = 1;
					seen.insert(mp(vh[i].x, vh[i].y));
				}
				if(!hori.count(vh[i].x)) hori[vh[i].x] = 1;
			}
		}

		/*cout << "vistos:" << endl;
		for(auto it = seen.begin(); it != seen.end(); it++){
			cout << it->first << " " << it->second << endl;
		}*/
	
		cout << res << endl;
	}

	return 0;
}
