#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int arr[101][101] = {0,};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int direct = 1;
vector<pair<int, char>> pos;

void print(int n){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++)
			if(arr[i][j] == 1) cout << 'O' << ' ';
			else if(arr[i][j] == -1) cout << 'A' << ' ';
			else cout << '-' << ' ';
		cout << endl << endl;
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	for(int i = 0, r, c; i < k; i++){
		cin >> r >> c;
		arr[r][c] = -1;
	}

	//BACK == HEAD
	queue<pair<int, int>> snake;
	snake.push({1, 1});
	arr[1][1] = 1;
	int l;
	cin >> l;
	int timer = 0;
	for(int i = 0; i < l; i++){
		int x; char c;
		cin >> x >> c;
		pos.push_back({x, c});
		
	}
	int seq = 0;
	while(1){
		timer++;
		//HEAD MOVE
		int nR = snake.back().first + dx[direct];
		int nC = snake.back().second + dy[direct];
		snake.push({nR, nC});

		//GAME OVER CHECKING
		if(nR < 1 || nC < 1){
			cout << timer<< endl;
			return 0;
		}
		if(nR > n || nC > n){
			cout << timer<< endl;
			return 0;
		}
		if(arr[nR][nC] == 1){
			cout << timer<< endl;
			return 0;
		}

		//CHECK NO APPLE
		if(arr[nR][nC] == 0){
			//REMOVE TAIL
			arr[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		//HEAD MARKING
		arr[nR][nC] = 1;
		if(timer == pos[seq].first){
		switch(pos[seq].second){
			case 'L':
				direct = (3 + direct) % 4;
				break;
			case 'D':
				direct = (5 + direct) % 4;
				break;
		}
		seq++;
		}
		printf("TIME : %d \n", timer);
		print(n);
		cout << "==========================" <<endl;
	}




	cout << timer << endl;
	return 0;
}
