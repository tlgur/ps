#include <iostream>

using namespace std;

int dp[28] = {3, 0,};

char func(int cur){
	int t = 0;
	while(dp[t] < cur) t++;
	
	cur -= dp[t - 1];
	
	if(cur == 1) return 'm';
	else if(cur <= t + 3) return 'o';
	else return func(cur - t - 3);
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i < 29; i++)
		dp[i] = 2 * dp[i - 1] + i + 3;
	
	cout << func(n) << endl;
	return 0;
}
