//ch06_class public.cpp
//use "class + public" instead of structure(구조체) 

class Data {
public:
	//구조체를 class 로 바꿀 때 맨 첫줄 에 public 까지 붙혀주면 됨.
	char stb[20];
	int value;
};

void ShowData(Data arg) {
	cout << arg.stn << "," << arg.value << endl;
	//memberfield 사용시에는 .으로 접근 
}
int main() {

	Data data = { "none", 0 };
	//순서: character->number

	ShowData(data);


	//strcpy(data.stn, "추신수"); 왼쪽에는 복사할 공간의 위치, 오른쪽은 복사할 값 적음.  
	strcpy_s(data.stn, sizeof(data.stn), "추신수");
	data.value = 100;
	ShowData(data);
		// _s를 c+에서는 써줘야 함.//함수 strcpy는 문자열 복사 함수

}
