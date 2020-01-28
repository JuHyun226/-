// ch13.1_new_delete.cpp
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
