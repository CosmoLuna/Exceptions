// ������������ ������ ������� �++
#include <iostream>
#include <string>
#include <fstream> // ��� ������ � �������
using namespace std;

double division(double num1, double num2) {
	if (num2 == 0)
		throw invalid_argument("���������� ������� �� ����");
	return num1 / num2;
}




int main() {
	setlocale(LC_ALL, "Russian");
	

	try { // ����, � ������� ���������� ��������� ����� ���������, � ������� ����� ���������� �������������� ��������
		cout << "������� ����� �� 1 �� 10 -> ";
		int x;
		cin >> x;
		// ���� ��������� ����� ���� ���������� ���������, �� ������� (throw) ���������� �� ��������� 0
		if (x < 1)
			throw 0;
		// ���� ��������� ����� ���� ���������� ���������, �� ��������� ���������� �� ��������� ���������
		if (x > 10)
			throw "������� ����� ������ ���������� ���������";
		// ������� throw ������������ ���������� ���������� ����� try
		cout << "������� ���������� �����\n";
	}
	catch (const int ex) { // ���� catch ������� ����� ���������� �� ��������� int � �����������, ���� ����� ���������� ���� �������
		if (ex == 0)
		cout << "������\n������� ����� ������ ���������� ���������\n";
		if (ex == 11)
			cout << "������\n������� ����� ������ ���������� ���������\n";
	}
	catch (const char ex[]) { // ���� catch ����� ��������� ������ � �����������, ���� ����� �������� ���� �������
		cout << "������\n" << ex << endl;
	}






	bool err = true;
	do {
		try {
			string nStr;
			cout << "������� �����: ";
			getline(cin, nStr); // ���������� string
			int num = stoi(nStr); //stoi ��������� ������ � ����������� � �����
			cout << "�������: " << num << endl;
			err = false;
		}
		catch (const exception& ex) { // ex - ������ ������ exception � ������� ����������� ���� ������
			string err = ex.what();
			if (err == "invalid stoi argument")
				cout << "������: " << err << endl;
		}

	} while (err);




	int n, m;
	try {
		cout << "������� ��� �����: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "������: " << ex.what() << endl;
	}



	string path = "file.txt";
	ifstream in;
	in.exceptions(ios::badbit | ios::eofbit | ios::failbit);

	try {
		cout << "������� �������� �����...\n";
		in.open(path);
		cout << "���� ������ ��� ������\n";
		cout << "���������� �����: \n";
		string str;
		in.seekg(0, ios::beg);
		getline(in, str);
		cout << str << endl;
		in.close();
	}
	catch (const ifstream::failure &ex) {
		cout << "������: " << ex.what() << endl;
		cout << "��� ������: " << ex.code() << endl;
	}

	return 0;
}