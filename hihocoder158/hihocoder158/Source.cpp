#include<iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
using namespace std;

int M, N;
vector<vector<int> > zone;
vector<vector<int> > isvisited;
int bound;
int flag;

void recur(int x, int y) {
	isvisited[x][y] = 1;
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx<M && ny >= 0 && ny<N && isvisited[nx][ny] == 0 && zone[nx][ny] == flag)
			recur(nx, ny);
		else if(nx < 0 || nx>=M || ny < 0 || ny>=N){
			bound++;
		}
		else if (isvisited[nx][ny] != 1) {
			bound++;
		}
	}
	return;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int x, y;
	bound = 0;
	cin >> M >> N >> x >> y;
	vector<vector<int> > v(M, vector<int>(N, 0));
	zone = v;
	isvisited = v;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			zone[i][j] = tmp;
		}
	}
	flag = zone[x][y];
	recur(x, y);
	cout<<bound<<endl;
	return 0;
}