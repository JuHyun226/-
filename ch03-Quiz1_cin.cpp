// ch03-Quiz_cin.cpp

#include <iostream>

int main() {

	// 이름, 나이, 키, 성별을 입력받아서 출력하는 코드를 작성하세요
	// - 성별은 'm' or 'f' 로 처리하고, m이면 "남성" f 이면 "여성"으로 출력하세요
	char name[20];
	std::cout << "이름 입력 > ";
	std::cin >> name;

	int age;
	std::cout << "나이 입력  > ";
	std::cin >> age;

	double height;
	std::cout << "키   입력 > ";
	std::cin >> height;

	char gender;
	while (1) {
		std::cout << "성별 입력 > ";
		std::cin >> gender;
		if (gender == 'm' || gender == 'f')
			break;
	}

	std::cout << "--- 입 력 정 보 ---" << std::endl;
	std::cout << "이름 : " << name << std::endl;
	std::cout << "나이 : " << age << " 세" << std::endl;
	std::cout << "키   : " << height << " cm" << std::endl;
	std::cout << "성별 : ";
	if (gender == 'm') std::cout << "남성";
	else std::cout << "여성";
	std::cout << std::endl;
}
