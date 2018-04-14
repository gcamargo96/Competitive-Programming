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

int x, y;
string sx, sy;
string nx, ny;

int main(void){
	cin >> sx >> sy;

	for(int i = 0; i < sx.size(); i++){
		if(sx[i] != '.')
			nx += sx[i];
	}

	for(int i = 0; i < sy.size(); i++){
		if(sy[i] != '.')
			ny += sy[i];
	}

	x = stoi(nx);
	y = stoi(ny);

	// cout << x << " " << y << endl;

	if(x == 0 and y == 0){
		cout << "Origem" << endl;
	}
	else if(y == 0){
		cout << "Eixo X" << endl;
	}
	else if(x == 0){
		cout << "Eixo Y" << endl;
	}
	else if(x > 0 and y > 0){
		cout << "Q1" << endl;
	}
	else if(x < 0 and y > 0){
		cout << "Q2" << endl;
	}
	else if(x < 0 and y < 0){
		cout << "Q3" << endl;
	}
	else if(x > 0 and y < 0){
		cout << "Q4" << endl;
	}

	return 0;
}