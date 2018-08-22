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

const int N = 52;
char g[N][N];
int n, k;
char cur = 'a';

void init(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 9; j++){
			g[i][j] = '-';
		}
	}
}

bool balance(){
	int left = 0, right = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 3; j++){
			if(g[i][j] != '-') left++;
		}
		for(int j = 5; j <= 8; j++){
			if(g[i][j] != '-') right++;
		}
	}

	return left <= right;
}

void seat(int row){
	if(g[row][3] == '-' and g[row][5] == '-'){
		if(balance()) g[row][3] = cur++;
		else g[row][5] = cur++;
	}
	else if(g[row][3] == '-' and g[row][5] != '-'){
		g[row][3] = cur++;
	}
	else if(g[row][3] != '-' and g[row][5] == '-'){
		g[row][5] = cur++; 
	}
	else if(g[row][2] == '-' and g[row][6] == '-'){
		if(balance()) g[row][2] = cur++;
		else g[row][6] = cur++;
	}
	else if(g[row][2] == '-' and g[row][6] != '-'){
		g[row][2] = cur++;
	}
	else if(g[row][2] != '-' and g[row][6] == '-'){
		g[row][6] = cur++;
	}
	else if(g[row][0] == '-' and g[row][8] == '-'){
		if(balance()) g[row][0] = cur++;
		else g[row][8] = cur++;
	}
	else if(g[row][0] == '-' and g[row][8] != '-'){
		g[row][0] = cur++;
	}
	else if(g[row][0] != '-' and g[row][8] == '-'){
		g[row][8] = cur++;
	}
	else if(g[row][4] == '-'){
		g[row][4] = cur++;
	}
	else if(g[row][1] == '-' and g[row][7] == '-'){
		if(balance()) g[row][1] = cur++;
		else g[row][7] = cur++;
	}
	else if(g[row][1] == '-' and g[row][7] != '-'){
		g[row][1] = cur++;
	}
	else{
		g[row][7] = cur++;
	}
}

void read_line(){
	string s;
	cin >> s;
}

void print_line(){
	for(int i = 0; i < 11; i++){
		cout << '.';
	}
	cout << endl;
}

void read_matrix(){
	char c;
	
	read_line();

	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < 3; j++){
			cin >> g[i][j];
		}
		cin >> c;
		for(int j = 3; j < 6; j++){
			cin >> g[i][j];
		}
		cin >> c;
		for(int j = 6; j < 9; j++){
			cin >> g[i][j];
		}
	}

	read_line();

	for(int i = n/2; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> g[i][j];
		}
		cin >> c;
		for(int j = 3; j < 6; j++){
			cin >> g[i][j];
		}
		cin >> c;
		for(int j = 6; j < 9; j++){
			cin >> g[i][j];
		}
	}

	read_line();
}

void print_matrix(){
	print_line();

	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < 3; j++){
			cout << g[i][j];
		}
		cout << '.';
		for(int j = 3; j < 6; j++){
			cout << g[i][j];
		}
		cout << '.';
		for(int j = 6; j < 9; j++){
			cout << g[i][j];
		}
		cout << endl;
	}

	print_line();

	for(int i = n/2; i < n; i++){
		for(int j = 0; j < 3; j++){
			cout << g[i][j];
		}
		cout << '.';
		for(int j = 3; j < 6; j++){
			cout << g[i][j];
		}
		cout << '.';
		for(int j = 6; j < 9; j++){
			cout << g[i][j];
		}
		cout << endl;
	}

	print_line();
}

int count_empty(int row){
	int cnt = 0;
	for(int i = 0; i < 9; i++){
		if(g[row][i] == '-')
			cnt++;
	}
	return cnt;
}

int dist(int row){
	int d = 1000;
	d = min(d, abs(row+1));
	d = min(d, abs(n-row));

	if(row < n/2){
		d = min(d, n/2-row);
	}
	else{
		d = min(d, row-n/2+1);
	}

	return d;
}

void assign(){
	if(count_empty(0) > 0 and count_empty(n/2) > 0){
		if(count_empty(0) >= count_empty(n/2)){
			seat(0);
		}
		else{
			seat(n/2);
		}
	}
	else if(count_empty(0) > 0){
		seat(0);
	}
	else if(count_empty(n/2) > 0){
		seat(n/2);
	}
	else{ // se nao tem vaga nas fileiras depois das saidas de emergencia
		int r, mx = 0, closest = 1000;
		for(int i = 1; i < n/2; i++){
			if(count_empty(i) > mx){
				mx = count_empty(i);
				r = i;
				closest = dist(i);
			}
			else if(count_empty(i) == mx and dist(i) < closest){
				r = i;
				closest = dist(i);
			}
		}
		for(int i = n/2+1; i < n; i++){
			if(count_empty(i) > mx){
				mx = count_empty(i);
				r = i;
				closest = dist(i);
			}
			else if(count_empty(i) == mx and dist(i) < closest){
				r = i;
				closest = dist(i);
			}
		}

		seat(r);
	}
}

int main(void){
	cin >> n >> k;

	read_matrix();

	for(int i = 0; i < k; i++){
		assign();
	}

	print_matrix();

	return 0;
}