#include<iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

int ncnt(int num) {
	int cnt = 0;

	while (num) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

string totime(int raw_time) {
	int hours, minutes, seconds;
	string s_hours = "", s_minutes = "", s_seconds = "";
	string time;

	hours = raw_time / 3600;
	minutes = (raw_time % 3600) / 60;
	seconds = (raw_time % 3600) % 60;

	if (ncnt(hours) < 2) s_hours = "0" + to_string(hours);
	else s_hours = to_string(hours);

	if (ncnt(minutes) < 2) s_minutes = "0" + to_string(minutes);
	else s_minutes = to_string(minutes);

	if (ncnt(seconds) < 2) s_seconds = "0" + to_string(seconds);
	else s_seconds = to_string(seconds);

	time = s_hours + ":" + s_minutes + ":" + s_seconds;

	return time;
}

int main() {
	int duration = 0;
	while (true) {
		cout << totime(duration) << endl;

		std::this_thread::sleep_for(std::chrono::seconds(1));

		duration++;
		system("cls");
	}

	system("pause");
	return 1;
}