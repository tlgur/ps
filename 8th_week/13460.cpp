#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
char board[10][10];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef struct{
	int x;
	int y;
}pos;

typedef struct{
	pos r;
	pos b;
	int cnt;
}step;

queue<step> q;
bool move(const int d, step s){
	bool r = false;
	step next = s;
	next.cnt++;	
	while(board[next.r.x][next.r.y] != '#'){
		if(next.r.x == next.b.x && next.r.y == next.b.y) break;
		if(board[next.r.x][next.r.y] == 'O') {
			r = true;
			next.r.x = 0;
			next.r.y = 0; 
			break;
		}
		next.r.x+=dx[d]; next.r.y+=dy[d];
	}
	next.r.x -= dx[d]; next.r.y -= dy[d];
	while(board[next.b.x][next.b.y] != '#'){
		if(next.r.x == next.b.x && next.r.y == next.b.y) break;
		if(board[next.b.x][next.b.y] == 'O'){
			return false;
		}
		next.b.x+=dx[d]; next.b.y += dy[d];
	}
	next.b.x -= dx[d]; next.b.y -= dy[d];
	while(board[next.r.x][next.r.y] != '#'){
		if(next.r.x == next.b.x && next.r.y == next.b.y) break;
		if(board[next.r.x][next.r.y] == 'O') {
			r = true;
			next.r.x = 0;
			next.r.y = 0;
			break;
		}
		next.r.x+=dx[d]; next.r.y+=dy[d];
	}
	next.r.x -= dx[d]; next.r.y -= dy[d];
	while(board[next.b.x][next.b.y] != '#'){
		if(next.r.x == next.b.x && next.r.y == next.b.y) break;
		if(board[next.b.x][next.b.y] == 'O'){
			return false;
		}
		next.b.x+=dx[d]; next.b.y += dy[d];
	}
	next.b.x -= dx[d]; next.b.y -= dy[d];
	q.push(next);
	return r;
}

int main(){
	cin >> n >> m;
	step s;
	s.cnt = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			if(board[i][j] == 'R'){
				s.r.x = i;
				s.r.y = j;
			}
			else if(board[i][j] == 'B'){
				s.b.x = i;
				s.b.y = j;
			}
		}
	q.push(s);
	while(!q.empty()){
		step s = q.front();
		if(q.back().cnt > 10){
			cout << -1 << endl;
			return 0;
		}

		for(int i = 0; i < 4; i++){
			bool r = move(i, s);
			if(r) {
				cout << q.back().cnt << endl;
				return 0;
			}
		}
		q.pop();
	}
	return 0;
}
