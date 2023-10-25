#include<iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

int ncnt(int num) { //функция, считающая количество цифр в числе
	int cnt = 0;

	while (num) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

string totime(int raw_time) { //функция, переводящая целое число секунд в формат времени ЧЧ:ММ:СС
	int hours, minutes, seconds; //переменные количества часов, минут и секунд
	string s_hours = "", s_minutes = "", s_seconds = ""; //те же самые переменные, что и выше, но их "строчная" версия
	string time; //строка, которая будет содержать число в формате ЧЧ:ММ:СС

	//неотформатированное число секунд мы разбиваем на часы, минуты и секунды с помощью следующих формул:
	hours = raw_time / 3600;
	minutes = (raw_time % 3600) / 60;
	seconds = (raw_time % 3600) % 60;

	//дальше проверяем, состоит ли количество часов/минут/секунд из одной цифры, если да, то дописываем 0 перед числом количества
	//проверенные числа часов/минут/секунд записываем в соответствующую строчную переменную
	if (ncnt(hours) < 2) s_hours = "0" + to_string(hours);
	else s_hours = to_string(hours);

	if (ncnt(minutes) < 2) s_minutes = "0" + to_string(minutes);
	else s_minutes = to_string(minutes);

	if (ncnt(seconds) < 2) s_seconds = "0" + to_string(seconds);
	else s_seconds = to_string(seconds);

	//после всех проверок записываем результат в строку результата, получая время в формате ЧЧ:ММ:СС
	time = s_hours + ":" + s_minutes + ":" + s_seconds;

	return time;
}

int main() {
	int duration = 0; //основная переменная, накапливающая значение времени в секундах
	while (true) {
		cout << totime(duration) << endl; //выводим время в стандартном для всех формате (ЧЧ:ММ:СС)

		std::this_thread::sleep_for(std::chrono::seconds(1)); //используем метод sleep_for для того
		//чтобы основной поток "уснул"на секунду

		duration++; //после секунды задержки прибавляем 1 к переменной времени
		system("cls"); //Очищаем консоль. Иллюзия меняющихся цифр достигается путём чередования вывода и очистки текста в консоли
	}

	system("pause");
	return 1;
}
