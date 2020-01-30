/*
	ch15-Quiz_class-access.cpp
*/

#include <iostream>	
#include <string>

using namespace std;

// Computer class를 정의하고 main()에서 테스트하세요
// - 필드 : 모델명, cpu, ram, 가격
//   기능 : 각각의 필드값 설정, 수정, 사용 가능
//          > 모델명 : 20자 이내
//            ram    : 단위 G(기가)
//            가격   : -(마이너스) 설정 불가, 단위 만원
//          정보 확인 가능

class Computer {
private:
	string model;
	string cpu;
	int ram;
	int price;

public:

	string getModel() { return model; }
	void setModel(string _model) {
		if (_model.length() < 21) {
			model = _model;
		}
	}

	string getCpu() { return cpu; }
	void setCpu(string _cpu) {
		cpu = _cpu;
	}

	int getRam() { return ram; }
	void setRam(int _ram) {
		if (_ram >= 0) {
			ram = _ram;
		}
	}

	int getPrice() { return price; }
	void setPrice(int _price) {
		if (_price >= 0) {
			price = _price;
		}
	}

	void info() {
		cout << "----- 컴퓨터 사양 -----" << endl;
		cout << "모델명 : " << model << endl;
		cout << "CPU    : " << cpu << endl;
		cout << "RAM    : " << ram << " G" << endl;
		cout << "가격   : " << price << endl;
	}

};


int main() {

	Computer proA;
	proA.setModel("1234ksdajdfkl;ja;klsdf");
	proA.setModel("2020 gram");
	proA.setCpu("i7");
	proA.setRam(8);
	proA.setPrice(122);
	proA.info();

}

