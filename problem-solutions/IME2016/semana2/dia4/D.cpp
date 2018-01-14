#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

ii iw, ib, fw, fb;
map<ii, ii> pai;
map<ii, bool> vis;

int dir[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void bfs(){
	queue<ii<ii,ii> > q;
	q.push(mp(iw,ib));

	while(!q.empty()){
		ii<ii,ii> u = q.front();
		q.pop();
		vis[u.fi] = 1;
		vis[u.se] = 1;
	
		//cout << u.fi << " " << u.se << endl;

		/*if(u.fi == fim.fi and u.se == fim.se){
			break;
		}*/

		for(int i = 0; i < 8; i++){
			ii v1 = u.fi;
			ii v2 = u.se;

			v1.fi += dir[i][0];
			v1.se += dir[i][1];
			v2.fi += dir[i][0];
			v2.se += dir[i][1];

			if(v.fi > 0 and v.fi <= 8 and v.se > 0 and v.se <= 8 and !vis.count(v)){
				pai[v] = u;
				if(v.fi == ib.fi and v.se == ib.se) q.push(ib);
				q.push(v);
			}
		}
	}
}

int main(void){
	string s;
	
	cin >> s;
	iw.fi = s[0] - 'a'+1;
	iw.se = s[1] - '0';

	cin >> s;
	ib.fi = s[0] - 'a'+1;
	ib.se = s[1] - '0';
	
	cin >> s;
	fw.fi = s[0] - 'a'+1;
	fw.se = s[1] - '0';
	
	cin >> s;
	fb.fi = s[0] - 'a'+1;
	fb.se = s[1] - '0';
	
	bfs(iw, fw);

	if(!pai.count(fw)){
		cout << "-1" << endl;
		return 0;
	}

	vector<ii> mw;
	for(ii v = fw; v.fi != iw.fi or v.se != iw.se; v = pai[v]){
		mw.pb(v);
	}

	vis.clear();
	pai.clear();
	bfs(ib, fb);

	if(!pai.count(fb)){
		cout << "-1" << endl;
		return 0;
	}

	vector<ii> mb;
	for(ii v = fb; v.fi != ib.fi or v.se != ib.se; v = pai[v]){
		mb.pb(v);
	}

	int tam = mw.size() + mb.size();
	
	cout << tam << endl;

	for(int i = mw.size()-1; i >= 0; i--){
		printf("W %c%c\n", mw[i].fi+'a'-1, mw[i].se+'0');
	}

	for(int i = mb.size()-1; i >= 0; i--){
		printf("B %c%c\n", mb[i].fi+'a'-1, mb[i].se+'0');
	}

	return 0;
}
