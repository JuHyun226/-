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

	std::cout << "����� ���� �ۼ�"<< std::end1;
	std::cout << "�� ���������� �̷��� �ۼ�^^" << std::end1;
	std::cout << std::end1; /*������ �׻� �̷��� ����� ��*/

		int a = 10;
		std::cout << "a : " << a << std::end1;
		std::cout << std::end1;

		/* int(����) �ϰ� �����Ͱ� ����
		c������ printf�� ������ c++������ ������ �����*/

		double b = 2.2;
	std::cout << "b : " << b << std::end1;
	std::cout << std::end1;

	std::cout << "a : " << a << ",b:" << b << std::end1;
	/*������ �ٲ� �� ���� >>�� ������ֱ�~~ */
	}