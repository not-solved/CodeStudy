#include <iostream>
using namespace std;

char result[8];

void time(string in1, string in2) {
	int s1 = (in1[6] - 48) * 10 + in1[7] - 48;
	int s2 = (in2[6] - 48) * 10 + in2[7] - 48;
	int m1 = (in1[3] - 48) * 10 + in1[4] - 48;
	int m2 = (in2[3] - 48) * 10 + in2[4] - 48;
	int h1 = (in1[0] - 48) * 10 + in1[1] - 48;
	int h2 = (in2[0] - 48) * 10 + in2[1] - 48;

	int second = s2 - s1;
	int minute = m2 - m1;
	int hour = h2 - h1;
	if (second < 0) {
		second += 60;
		minute--;
	}
	result[7] = second % 10 + '0';
	result[6] = second / 10 + '0';
	if (minute < 0) {
		minute += 60;
		hour--;
	}
	result[4] = minute % 10 + '0';
	result[3] = minute / 10 + '0';
	if (hour < 0) {
		hour += 24;
	}
	result[1] = hour % 10 + '0';
	result[0] = hour / 10 + '0';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	result[2] = ':';
	result[5] = ':';
	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input[2];
		cin >> input[0] >> input[1];
		time(input[0], input[1]);
		cout << '#' << a << ' ' << result << '\n';
	}
	return 0;
}