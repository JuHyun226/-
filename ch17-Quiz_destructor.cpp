/*
	ch17-Quiz_destructor.cpp
*/

#include <iostream>
#include <string>

using namespace std;

/*
Book class 를 정의하고 main() 에서 test 하세요
- 도서명, 지은이, 가격, 진열 위치( A, B, C ) 값을 사용해서 관리합니다
  > char*  : 도서명, 지은이
- 도서명, 가격, 진열위치는 수정이 가능합니다

*/
class Book {
private:
	char* title;
	char* author;
	int price;
	char area;

public:

	Book(const char* _title = "none", const char* _author = "none", int _price = 0, char _area = ' ') {
		title = new char[strlen(_title) + 1];
		strcpy_s(title, strlen(_title) + 1, _title); // 왜 이렇게 적은 거지??
		author = new char[strlen(_title) + 1];
		strcpy_s(author, strlen(_title) + 1, _author);
		price = _price;
		area = _area;
	}

	~Book() {
		cout << title << " 삭제" << endl;
		delete[] title;
		delete[] author;
	}

	void setTitle(const char* _title) {
		if (title != NULL)
			delete[] title;
		title = new char[strlen(_title) + 1];
		strcpy_s(title, strlen(_title) + 1, title);
	}

	void setPrice(int _price) {
		if (_price >= 0)
			price = _price;
		else
			price = 0;
	}

	void setArea(char _area) {
		if (_area >= 'A' && _area <= 'C')
			area = _area;
		else
			area = ' ';
	}

	void infoBook() {
		cout << "----- 도 서 정 보 -----" << endl;
		cout << "도서명   : " << title << endl;
		cout << "지은이   : " << author << endl;
		cout << "가격     : " << price << " 원" << endl;
		cout << "진열지역 : " << area << " 구역" << endl;
	}
};

int main() {

	Book bookA;
	bookA.setTitle("2020 토지"); // 공간이 바뀔 수 있으니까 수정가능한 코드를 넣으라고 한 것임.
	bookA.setPrice(22000);
	bookA.setArea('A');
	bookA.infoBook();
	cout << endl;

	Book* pb = new Book("2020 cpp", "비얀 스트룹스트롭", 45000, 'B');
	pb->infoBook();

	delete pb;
}
