#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;

void func(int depth, int row, int col, int cur){
	cout << depth << " // " << row << ' ' << col << " : " << cur << endl;
	if(depth == 1) {
		cout << cur << endl;
	}
	else{
		int flag = 0;
		int x =  row;
		depth /= 2;
		if(row + depth <= r){
			flag += 2;
			x = row + depth;
		}
		int y = col;
		if(c >= (col + depth)){
			flag += 1;
			y = col + depth;
		}
		func(depth, x, y, cur + (depth * depth * flag));
	}
}

int main(){
	cin >> n >> r >> c;
	n = pow(2, n);

	func(n, 0, 0, 0);
	return 0;
}
