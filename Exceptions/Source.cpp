// Персональный шаблон проекта С++
#include <iostream>
#include <string>
#include <fstream> // для работы с файлами
using namespace std;

double division(double num1, double num2) {
	if (num2 == 0)
		throw invalid_argument("обнаружено деление на ноль");
	return num1 / num2;
}




int main() {
	setlocale(LC_ALL, "Russian");
	

	try { // блок, в который необходимо поместить часть программы, в которой может возникнуть исключительная ситуация
		cout << "Введите число от 1 до 10 -> ";
		int x;
		cin >> x;
		// если введенное число ниже указанного диапазона, то бросаем (throw) исключение со значением 0
		if (x < 1)
			throw 0;
		// если введенное число выше указанного диапазона, то бросается исключение со строковым значением
		if (x > 10)
			throw "Введено число больше указанного диапазона";
		// команда throw отанавливает дальнейшее выполнение блока try
		cout << "Введено правильное число\n";
	}
	catch (const int ex) { // блок catch который ловит исключение со значением int и выполняется, если такое исключение было брошено
		if (ex == 0)
		cout << "Ошибка\nВведено число меньше указанного диапазона\n";
		if (ex == 11)
			cout << "Ошибка\nВведено число больше указанного диапазона\n";
	}
	catch (const char ex[]) { // блок catch ловит строковый массив и выполняется, если такое значение было брошено
		cout << "Ошибка\n" << ex << endl;
	}






	bool err = true;
	do {
		try {
			string nStr;
			cout << "Введите число: ";
			getline(cin, nStr); // библиотека string
			int num = stoi(nStr); //stoi принимает строку и преобразует в число
			cout << "Введено: " << num << endl;
			err = false;
		}
		catch (const exception& ex) { // ex - объект класса exception в котором описывается суть ошибки
			string err = ex.what();
			if (err == "invalid stoi argument")
				cout << "Ошибка: " << err << endl;
		}

	} while (err);




	int n, m;
	try {
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Ошибка: " << ex.what() << endl;
	}



	string path = "file.txt";
	ifstream in;
	in.exceptions(ios::badbit | ios::eofbit | ios::failbit);

	try {
		cout << "Попытка открытия файла...\n";
		in.open(path);
		cout << "Файл открыт для чтения\n";
		cout << "Содержимое файла: \n";
		string str;
		in.seekg(0, ios::beg);
		getline(in, str);
		cout << str << endl;
		in.close();
	}
	catch (const ifstream::failure &ex) {
		cout << "Ошибка: " << ex.what() << endl;
		cout << "Код ошибки: " << ex.code() << endl;
	}

	return 0;
}