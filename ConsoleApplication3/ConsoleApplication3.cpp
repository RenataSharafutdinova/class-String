#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
using namespace std;

class String {
	
	char* arr;
	size_t lenght;
	static int count;

public:
	String() : String{ 80 } {};

	String(size_t lenght) : lenght{ lenght } {
		arr = new char[lenght+1];
		++count;
	}

	String(const char* String) :lenght{strlen(String)} {
		arr = new char[lenght + 1];
		strcpy_s(arr, lenght + 1,String);
		++count;
	}

	String(const String& object) : lenght{ object.lenght } { //конструктор копирования
		arr = new char[lenght + 1];
		strcpy_s(arr, lenght + 1, object.arr);
		++count;
	}

	~String() {
		delete[] arr;
		--count;
	}

	void input() {
		cout << "Введите строку:";
		char buffer[500];
		cin.getline(buffer, 500);

		lenght = strlen(buffer);
		arr = new char[lenght + 1];

		strcpy_s(arr, lenght + 1, buffer);
	}

	void output() {
		cout << arr << endl;
	}
	static int getCount() { return count; }

};
int String::count = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Rus");

	String s1; //конструктор по умолчанию
	s1.output();//вывод

	String s2(55);//конструктор произвольного размера
	s2.output();

	String s3("Привет, меня зовут Рената!");//конструктор от пользователя
	s3.output();

	String s4;
	s4.input();//ввод с клавиатуры
	s4.output();

	cout << "Количество созданных экземпляров: " << String::getCount() << endl;

}