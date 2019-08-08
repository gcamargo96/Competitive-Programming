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

// #define A 0
// #define B 1
#define H 2
#define V 3

const int N = 17;
char g[N][N];
int t;
int r, c;
int ans;

bool canH(int x, int y){
	if(g[x][y] != '.') return 0;

	for(int i = y+1; i <= c; i++){
		if(g[x][i] == '#') return 0;
		if(g[x][i] != '.') break;
	}

	for(int i = y-1; i >= 1; i--){
		if(g[x][i] == '#') return 0;
		if(g[x][i] != '.') break;
	}

	return 1;
}

bool canV(int x, int y){
	if(g[x][y] != '.') return 0;

	for(int i = x+1; i <= r; i++){
		if(g[i][y] == '#') return 0;
		if(g[i][y] != '.') break;
	}

	for(int i = x-1; i >= 1; i--){
		if(g[i][y] == '#') return 0;
		if(g[i][y] != '.') break;
	}

	return 1;
}

void paintH(int x, int y, char color){
	g[x][y] = color;
	for(int i = y-1; i >= 1 and g[x][i] == '.'; i--){
		g[x][i] = color;
	}
	for(int i = y+1; i <= c and g[x][i] == '.'; i++){
		g[x][i] = color;
	}
}

void clearH(int x, int y, char color){
	g[x][y] = '.';
	for(int i = y-1; i >= 1 and g[x][i] == color; i--){
		g[x][i] = '.';
	}
	for(int i = y+1; i <= c and g[x][i] == color; i++){
		g[x][i] = '.';
	}
}

void paintV(int x, int y, char color){
	g[x][y] = color;
	for(int i = x-1; i >= 1 and g[i][y] == '.'; i--){
		g[i][y] = color;
	}
	for(int i = x+1; i <= r and g[i][y] == '.'; i++){
		g[i][y] = color;
	}
}

void clearV(int x, int y, char color){
	g[x][y] = '.';
	for(int i = x-1; i >= 1 and g[i][y] == color; i--){
		g[i][y] = '.';
	}
	for(int i = x+1; i <= r and g[i][y] == color; i++){
		g[i][y] = '.';
	}
} 

char nextTurn(char turn){
	if(turn == 'A') return 'B';
	return 'A';
}

bool hasMoves(){
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			if(g[i][j] == '.') return 1;
		}
	}
	return 0;
}

void print(){
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cout << g[i][j];
		}
		cout << endl;
	}
}

int move(char turn){
	// cout << "beg" << endl;
	// print();
	if(!hasMoves()){
		// print();
		// cout << turn << " has no moves" << endl;
		return 0;
	}

	int result = 0;
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			if(canH(i,j)){
				paintH(i,j,turn == 'A' ? 'D' : 'F');
				result |= (!move(nextTurn(turn)));
				clearH(i,j,turn == 'A' ? 'D' : 'F');
			}
			if(canV(i,j)){
				paintV(i,j,turn == 'A' ? 'C' : 'E');
				result |= (!move(nextTurn(turn)));
				clearV(i,j,turn == 'A' ? 'C' : 'E');
			}
		}
	}

	// cout << "end" << endl;
	// print();

	return result;
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> r >> c;

		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				cin >> g[i][j];
			}
		}

		// int ans = move('A');

		int ans = 0;
		int turn = 'A';
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				if(canH(i,j)){
					paintH(i,j,turn == 'A' ? 'D' : 'F');
					ans += (!move(nextTurn(turn)));
					clearH(i,j,turn == 'A' ? 'D' : 'F');
				}
				if(canV(i,j)){
					paintV(i,j,turn == 'A' ? 'C' : 'E');
					ans += (!move(nextTurn(turn)));
					clearV(i,j,turn == 'A' ? 'C' : 'E');
				}
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
		// cout << ans << endl;

		// if(ans > 0){
		// 	cout << "wins" << endl;
		// }
		// else{
		// 	cout << "loses" << endl;
		// }
	}

	return 0;
}