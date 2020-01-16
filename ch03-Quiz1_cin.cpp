
// ch03-Quiz_cin.cpp

#include <iostream>

int main() {

	//이름,나이,키,성별을 입력받아 출력하는 코드 작성
	//-성별은 'm' or 'f'로 처리하고,m이면 "남성", f이면 "여성"으로 출력

	char name[] = "정주현";
	int age = 22;
	int height = 168;
	char gender[] = 'f';

	std::cout << "이름 : " << name << std::endl;
	std::cout << "나이 : " << age << " 세" << std::endl;
	std::cout << "키 : " << height << " cm" << std::endl;
	std::cout << "성별 : " << gender << std::endl;

}
