// ch13.1_new_delete.cpp

// 동적으로 할당한 변수는 반드시 해제해줘야 한다.

/*
함수에서 선언된 변수는 함수가 종료되면서 같이 자동으로 해제되지만,
동적으로 할당한 변수는 해제되지 않고 직접 해제해줘야 한다.

new : 변수 동적 할당
delete : 동적 할당 변수 해제

new[] : 배열 동적 할당
delete[] : 동적 할당 배열 해제

만약 int형 하나를 동적으로 할당하고 싶다면
int* grade = new int;
이런식으로 사용하면된다.

동적으로 배열을 만들고 싶으면 -인덱스! 클래스 객체 안에 공간있는거. 
int* grade = new int[<number>];
여기서 동적할당은 런타임중에 만들어지기때문에 [] (배열첨자) 안에 들어갈 숫자는 변수여도 된다.


*/
int InputInt(string message) {
	int value;
	cout << message; cin >> value;
	return value;

}

int* MakeArray(int size) {
	return new int[size]; // size공간만큼 발생
}

void InputArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "번째 입력 < "; cin >> arr[i];
	}
	cout << endl;
}

void OutputArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
	cout << endl;
}
int main() {

//	int size = 3;
//	int ar[size]; error // 지역변수는 한번 설정하면 변경이 불가능

	const int size = 3;
	int ar[size]; // c+에서 const로 정의한 애는 허용함. 수정할 수 없기 때문에. 근데 c에서는 허용불가.

	//동적할당은 배열 크기를 그때그때 설정가능
	int arraySize = 0;
	int* arr = NULL;

	arraySize = InputInt("크기 입력 >> ");
	arr = MakeArray(arraySize);

	InputArray(arr, arraySize); //위치와 크기 넘김.
	OutputArray(arr, arraySize);

	delete[] arr;
}
