
// ch01_cin.cpp.quiz

#include <iostream>


int main() {

	int last;
	std::cout << "������ �� �Է� > ";
	std::cin >> last;

	int sum = 0;//��������
	for (int i = 1; i <= last; i++) {

		sum += i;//�����ϴ� i���� ���϶�
	}

	std::cout << "1 ~ " << last << " ������ �� : " << sum << std::endl;

}














