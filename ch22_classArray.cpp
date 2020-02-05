/*
	ch22_classArray.cpp
	- 같은 타입의 데이터 여러개 -> 배열
	- 객체도 배열로 처리 가능.
*/

#include <iostream>
#include <string>

using namespace std;

class Data {
public:
	void info() {
		cout << valueA << " - " << valueB << endl;
	}

	void setValueB(const int& valueB) { this->valueB = valueB; }
	int getValueB() { return valueB; }

	void setValueA(const string& valueA) { this->valueA = valueA; }
	string getValueA() { return valueA; }

	~Data() { cout << valueA << " 삭제" << endl; }

	Data(const string& valueA = "none", const int& valueB = 0)
		: valueA(valueA), valueB(valueB) {
		cout << "- Data 객체 생성 -" << endl;
	}

private:
	string valueA;
	int valueB;
};


int main() {

	//Data data("test", 10);
	//data.info();
	//cout << endl;


	//Data ar[2];

	//Data ar2[2] = { Data("objA", 11), Data("objB", 22) };//첫번째 공간에 하나 생성 - 클래스 명으로 생성자 불러들여도 됨.
	//													 
	//// 배열을 출력할 때에는 for문 사용!
	//for (int i = 0; i < sizeof(ar2) / sizeof(Data); i++) {
	//	ar2[i].info();//info메소드 사용
	//}
	//cout << endl;

	//Data* p;
	//p = new Data("data", 100);
	//p -> info();
	//delete p;

	////----------- 객체를 하나씩 동적할당하여 배열포인터에 저장하는 방법 -->
	//Data* par[2]; // 객체 만든게 아닌, 데이터 클래스 객체의 주소값을 처리하는 포인터 변수를 배열처리한것.
	//par[0] = new Data("data-1", 111);
	//par[1] = new Data("data-2", 222);

	//par[0]->info();
	//par[1]->info();

	//delete par[0];
	//delete par[1];

	//
	
	//-------------heap에다가 데이터 클래스 객체 배열을 만드는 방법
	Data* list = new Data[2]; //2대신 100적으면 개많이 나옴 ㅋㅋ
	for (int i = 0; i < 2; i++) {
		string dataA;
		cout << "단어입력> "; cin >> dataA;
		int dataB;
		cout << "숫자입력> "; com >> dataB;
		list[i].setValueA(dataA);//list 배열의 i번째 객체의 setvalueA 메소드를 사용해서 dataA의 값을 설정
		list[i].setValueB(dataB);
	}
	cout << endl;

	for (int i = 0; i < 2; i++) {
		list[i].info();
	}
	cout << endl;

	delete[] list;

}
