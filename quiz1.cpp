/*quiz*/


#include <iostream>


/*
	변수와 배열을 사용해서 이름, 나이, 키, 성별을 출력하세요
*/

int main() {

	char name[] = "test";/*숫자 안쓰면 그데이터 수만큼 공간 자동생성*/
	int age = 20;
	double height = 123.4;
	//char gender = 'm';
	char gender[5] = "남성";	
	char blood[2] = { 'A', 'B' };

	std::cout << "이름 : " << name << std::endl;
	std::cout << "나이 : " << age << " 세" << std::endl;
	std::cout << "키   : " << height << " cm" << std::endl;
	std::cout << "성별 : " << gender << std::endl;
	std::cout << "혈액형 : " << blood << std::endl;



	/*한글은 하나당 2바이트라서 남성은 5바이트!! 자음모음 하나만 써도2바이트니가배열처리해야함*/
}
