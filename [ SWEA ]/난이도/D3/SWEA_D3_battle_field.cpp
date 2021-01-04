#include <iostream>
using namespace std;

char map[21][21];

void move(char direct, int x, int y) {
	map[y][x] = '.';
	switch (direct) {
	case 'U':
		map[y - 1][x] = '^';
		break;
	case 'D':
		map[y + 1][x] = 'v';
		break;
	case 'L':
		map[y][x - 1] = '<';
		break;
	case 'R':
		map[y][x + 1] = '>';
	}
}
void operate(string in, int t_y, int t_x, char dir, int h, int w) {
	char d = dir;
	int x = t_x;
	int y = t_y;
	int shoot = 0;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] != 'S')
			d = in[i];
		switch (in[i]) {
		case 'U':
			if (y > 0 && map[y - 1][x] == '.') {
				move(d, x, y);
				y--;
			}
			else
				map[y][x] = '^';
			break;
		case 'D':
			if (y < h - 1 && map[y + 1][x] == '.') {
				move(d, x, y);
				y++;
			}
			else
				map[y][x] = 'v';
			break;
		case 'L':
			if (x > 0 && map[y][x - 1] == '.') {
				move(d, x, y);
				x--;
			}
			else
				map[y][x] = '<';
			break;
		case 'R':
			if (x < w - 1 && map[y][x + 1] == '.') {
				move(d, x, y);
				x++;
			}
			else
				map[y][x] = '>';
			break;
		case 'S':
			switch (d) {
			case 'U':
				shoot = y - 1;
				while (shoot >= 0) {
					if (map[shoot][x] == '*') {
						map[shoot][x] = '.';
						break;
					}
					else if (map[shoot][x] == '#')
						break;
					shoot--;
				}
				break;
			case 'D':
				shoot = y + 1;
				while (shoot < h) {
					if (map[shoot][x] == '*') {
						map[shoot][x] = '.';
						break;
					}
					else if (map[shoot][x] == '#')
						break;
					shoot++;
				}
				break;
			case 'L':
				shoot = x - 1;
				while (shoot >= 0) {
					if (map[y][shoot] == '*') {
						map[y][shoot] = '.';
						break;
					}
					else if (map[y][shoot] == '#')
						break;
					shoot--;
				}
				break;
			case 'R':
				shoot = x + 1;
				while (shoot < w) {
					if (map[y][shoot] == '*') {
						map[y][shoot] = '.';
						break;
					}
					else if (map[y][shoot] == '#')
						break;
					shoot++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int H, W, tank_x, tank_y;
		char direct;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				switch (map[i][j]) {
				case '<':
					direct = 'L';
					tank_x = j;
					tank_y = i;
					break;
				case '^':
					direct = 'U';
					tank_x = j;
					tank_y = i;
					break;
				case 'v':
					direct = 'D';
					tank_x = j;
					tank_y = i;
					break;
				case '>':
					direct = 'R';
					tank_x = j;
					tank_y = i;
					break;
				}
			}
		}
		int comsize;
		cin >> comsize;
		string command;
		cin >> command;
		operate(command, tank_y, tank_x, direct, H, W);
		cout << '#' << a << ' ';
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}