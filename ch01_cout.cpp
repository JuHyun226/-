// �ּ�ó�� : Ctrl + k + c
// �ּ����� : Ctrl + k + u
// �����ܰ� : Ctrl + z
// �ǵ����� : Ctrl + y

// build   : Ctrl + Shift + b
// execute : Ctrl + F5

#include<iostream>
/*
cout
- cout�� ���� ����Ʈ ������(<<)�ڿ� �ִ� ������ ����մϴ�

:: => scope ������;Ư�������� ������ �� ���

end1; ���κ���

*/
int main() {

	std::cout << "����� ���� �ۼ�" << std::endl;
	std::cout << "�� ���������� �̷��� �ۼ�^^" << std::endl;
	std::cout << std::endl; /*������ �׻� �̷��� ����� ��*/

	int a = 10;
	std::cout << "a : " << a << std::endl;
	std::cout << std::endl;

	/* int(����) �ϰ� �����Ͱ� ����
	c������ printf�� ������ c++������ ������ �����*/

	double b = 2.2;
	std::cout << "b : " << b << std::endl;
	std::cout << std::endl;

	std::cout << "a : " << a << ",b:" << b << std::endl;
	/*������ �ٲ� �� ���� >>�� ������ֱ�~~ */
}
