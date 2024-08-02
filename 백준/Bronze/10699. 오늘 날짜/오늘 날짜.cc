#include <iostream>
#include <ctime>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	struct tm *t;
	time_t timer = time(NULL);
	t = localtime(&timer);
	cout << t->tm_year + 1900 << "-";
	if ((t->tm_mon + 1) < 10)
		cout << "0" << t->tm_mon + 1;
	else
		cout << t->tm_mon + 1;
	cout << "-" << t->tm_mday;
}