
// ch02_Quiz.cin.cpp

#include <iostream>


int main() {

	int last;
	std::cout << "마지막 수 입력 > ";
	std::cin >> last;

	int sum = 0;//누적변수
	for (int i = 1; i <= last; i++) {

		sum += i;//증가하는 i값을 더하라
	}

	std::cout << "1 ~ " << last << " 까지의 합 : " << sum << std::endl;

}














