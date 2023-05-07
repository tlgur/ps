#include <iostream>
#include <queue>

using namespace std;

typedef struct{
	int x;
	int y;
	int z;
	int day;
}pos;

int n, m, h;
int box[100][100][100];
int uneq;
const int dx[6] = {1, 0, -1, 0, 0, 0};
const int dy[6] = {0, 1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int d = 0;
queue<pos> q; 
bool boundCheck(pos p){
	if(p.x < 0 || p.x >= h) return true;
	if(p.y < 0 || p.y >= m) return true;
	if(p.z < 0 || p.z >= n) return true;
	return false;
}

void func(){
	pos p = q.front();
	for(int i = 0; i < 6; i++){
		int nX = p.x + dx[i];
		int nY = p.y + dy[i];
		int nZ = p.z + dz[i];
		pos nP;
		nP.x = nX; nP.y = nY; nP.z = nZ; nP.day = p.day + 1;
		if(boundCheck(nP)) continue;
		if(box[nX][nY][nZ] == 0){
			box[nX][nY][nZ] = 1;
			q.push(nP);
			uneq--;
		}
	}      	

	d = p.day;
	q.pop();
}

int main(){
	cin >> n >> m >> h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < m; j++)
			for(int t = 0; t < n; t++){
				cin >> box[i][j][t];
				if(box[i][j][t] == 0) uneq++;
				if(box[i][j][t] == 1) {
					pos p;
					p.x = i; p.y = j; p.z = t; p.day = 0;
					q.push(p);
				}
			}

	int day = 0;
	while(!q.empty()){
		func();
	}
	if(uneq) cout << -1 << endl;
	else cout << d << endl;

	return 0;
}
