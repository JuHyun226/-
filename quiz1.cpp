/*quiz*/


#include <iostream>


/*
	������ �迭�� ����ؼ� �̸�, ����, Ű, ������ ����ϼ���
*/

int main() {

	char name[] = "test";/*���� �Ⱦ��� �׵����� ����ŭ ���� �ڵ�����*/
	int age = 20;
	double height = 123.4;
	//char gender = 'm';
	char gender[5] = "����";	
	char blood[2] = { 'A', 'B' };

	std::cout << "�̸� : " << name << std::endl;
	std::cout << "���� : " << age << " ��" << std::endl;
	std::cout << "Ű   : " << height << " cm" << std::endl;
	std::cout << "���� : " << gender << std::endl;
	std::cout << "������ : " << blood << std::endl;



	/*�ѱ��� �ϳ��� 2����Ʈ�� ������ 5����Ʈ!! �������� �ϳ��� �ᵵ2����Ʈ�ϰ��迭ó���ؾ���*/
}
