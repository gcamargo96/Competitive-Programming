#include <bits/stdc++.h>
using namespace std;

int main(void){
	int x1 = 0, x2 = c1;
			int y1 = s1, y2 = s1 + c2;
			int z1 = s2, z2 = s2 + c3;
			priority_queue <pii, vector<pii>, greater<pii> > pq;
			pq.emplace(x1, 0);
			pq.emplace(x2, 1);
			pq.emplace(y1, 0);
			pq.emplace(y2, 1);
			pq.emplace(z1, 0);
			pq.emplace(z2, 1);
			int last = 0;
			int t[4] = {0};
			int on = 0;
			while (!pq.empty()) {
				int tipo, minuto;
				tie (minuto, tipo) = pq.top();
				pq.pop();
				t[on] += minuto - last;
				if (!tipo) {
					on++;
					last = minuto;
				} else {
					on--;
					last = minuto;
				}
			}

	return 0;
}