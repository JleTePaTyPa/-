#include <iostream>
#include "windows.h" 
#include <clocale>
#include <string>
#include <vector>
#include "time.h"
#include <fstream>
#include <string>
#include <clocale>
#include "windows.h"
#include "conio.h"
#include <cstdlib>
	
using namespace std;
COORD get_cursor_position()
{
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO bi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
  //bi.dwCursorPosition - ���p������ ��p��p� 
  return bi.dwCursorPosition;
}
//gotoxy(get_cursor_position())
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void gotoxy(COORD coord)
{	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

char vvod_var(int n)
{
	string str;
	cin >> str;
	int number = stoi(str);
	while ((number > n || number < 1))
	{
		cout << "��� ������ ��������" << endl;
		cin >> str;
		number = stoi(str);
	}
	return str[0];

}
	
void set_color(int back_color, int text_color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//���� �������� - ������. ���� ���� - �����-�����
	SetConsoleTextAttribute(hConsole, (WORD)((back_color << 4) | text_color));
}

void type_text(string str) { // ��� ��������� ������ 
	int i = 0;
	for (auto ch : str) {
		cout << ch;
		i++;
		if (i > 40 && ch == ' ')
		{
			cout << endl;
			i = 0;
		}
		Beep(rand()%100+185, 30);
		//Sleep(3000);
	}
	cout << endl;
}

// ���� �� ��������� �����
class koza {
public:
	int maney;
	int brain;
	int hp;
	int happy;
	int happy_brother;
    int nam_day;

	koza(int maney_2 = 1000, int brain_2 = 100, int hp_2= 50, int happy_2 = 100, int happy_brother_2 = 100, int nam_day_2 = 0)
	{
		 maney= maney_2;
		 brain= brain_2;
		 hp= hp_2;
		 happy= happy_2;
		 happy_brother= happy_brother_2;
		 nam_day = nam_day_2;
	}
	void kozaa() {
		char swt;
		/*show_stats();
		for (int i = 0; i < 7; i++)
		{
			cout << ".";
			Sleep(700);
		}*/
		string str = "������� ������� ������� ������ ����� � ������...";
		type_text(str);
		Sleep(700);
		system("cls");
		//set_color(Black, Yellow);
		str = "���� ����� � ���� �������, ��� ������ ������?";

		type_text(str);
		//set_color(Black, White);
		cout << "1)������" << endl << "2)��� ��� �������� � ��������" << endl << "3)��������" << endl << "4)�������" << endl;
		
		swt = vvod_var(4);
		switch (swt) {
		case '1': break;
		case '2': brain = brain - 5; break;
		case '3': brain = brain + 10; hp = hp - 5; break;
		case '4': brain = brain - 10; hp = hp + 5; break;
		}
		system("cls");
		str = "���� ���������, � �������� ��� ����?";
		type_text(str);
		cout << "1)������� ��� �� ������" << endl << "2)�������������� �����" << endl << "3)������� ������" << endl << "4)���� ����� �������" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': brain = brain + 5; break;
		case '2': hp = hp + 5; maney = maney + 200;  break;
		case '3': brain = brain - 10; maney = maney - 200; break;
		case '4': brain = brain - 10; happy_brother = happy_brother + 10; break;
		}
		system("cls");
		str = "������ ���� �� ����";
		type_text(str);
		cout << "1)������� ��� ������ ��� ����" << endl << "2)���� �� �����" << endl << "3)�������� � �������� ��������" << endl << "4)����� � �� �����" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': brain = brain + 10; happy = happy + 10; break;
		case '2': happy = happy - 10; maney = maney - 500; brain = brain + 20; break;
		case '3': break;
		case '4': happy_brother = happy_brother - 10; break;
		}
		system("cls");
		str = "� ������ ����� ������ ����?";
		type_text(str);
		cout << "1)� ����" << endl << "2)�� ��������" << endl << "3)������ ������� �� ������" << endl << "4)����� � ����� � ������ ����� �����" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': maney = maney - 600; happy = happy + 50; happy_brother = happy_brother + 50; break;
		case '2': maney = maney - 200; happy = happy + 50; happy_brother = happy_brother + 50; brain = brain - 40; break;
		case '3': happy = happy + 20; happy_brother = happy_brother + 20; break;
		case '4': happy = happy - 20; happy_brother = happy_brother - 20; maney = maney - 500; brain = brain + 50; break;
		}
		system("cls");
		str = "����������� ���";
		type_text(str);
		cout << "1)��������" << endl << "2)������� ��������� � ����� �����" << endl << "3)����� ��������" << endl << "4)��������� ������� ���� ���" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': happy = happy - 20; happy_brother = happy_brother - 20; brain = brain + 5; break;
		case '2': maney = maney + 500; happy = happy + 20; happy_brother + 20; brain = brain - 20; break;
		case '3': maney = maney - 200; brain = brain + 5; happy = happy = happy_brother - 15; break;
		case '4': happy = happy + 15; brain = brain + 20; break;
		}
		system("cls");
		str = "���� �������";
		type_text(str);
		cout << "1)������ �� ������" << endl << "2)��������� ���������" << endl << "3)��������� � ������" << endl << "4)������� �������� " << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': happy = happy - 10; happy_brother - 20; break;
		case '2': maney = maney + 500; brain = brain + 20; happy_brother + 20; break;
		case '3': maney = maney - 500; brain = brain + 10; happy = happy + 20; happy_brother = happy_brother + 50; break;
		case '4': happy_brother = happy_brother - 30; brain = brain - 20; break;
		}
		system("cls");
		str = "��������� ��������";
		type_text(str);
		cout << "1)������� ����������" << endl << "2)�������� ������ � ������� �����" << endl << "3)������� ���������" << endl << "4)��������� ����� �������� " << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': maney = maney - 800;  brain = brain + 15; happy = happy + 20; break;
		case '2': maney = maney + 500; brain = brain + 10; happy = happy + 20; break;
		case '3': maney = maney - 500; brain = brain + 10; happy = happy + 20; happy_brother = happy_brother + 50; break;
		case '4': happy_brother = happy_brother - 30; brain = brain - 20; break;
		}


	}
	void show_stats()
	{
		cout << "���� �����: " << endl;
		cout<<"maney: "<<maney<< endl;
		cout<<"brain: "<<brain<< endl;
		cout<<"hp: "<<hp<< endl;
		cout<<"happy: "<<happy<< endl;
		cout<<"happy_brother: "<<happy_brother<< endl;

	}
	void progress_bar(int seconds)
	{
		cout << endl;
		COORD coord = get_cursor_position();
		COORD coords_pb = get_cursor_position();
		coords_pb.Y += 1;
		for (int i = 0; i < 101;i++)
		{
			gotoxy(coord);
			cout << i<<"%";
			if (i % 3)
			{
				gotoxy(coords_pb);
				cout << "-";
				coords_pb.X += 1;
			}
			


			Sleep(seconds);
		}
		cout << endl<<endl;
	}
	void delivery()
	{
		srand(time(0));
		vector <string> addresses = { "�������� 16 ��� 2 �������� 7","�������� 16 ��� 6 �������� 32","�������� 16 ��� 2 �������� 2","�������� 16 ��� 3 �������� 54","�������� 11 ��� 23 �������� 64","�������� 16 ��� 23 �������� 5","�������� 16 ��� 12 �������� 112", "������� 12 ��� 13 �������� 34","������� 15 ��� 13 �������� 42","������� 9 ��� 2 �������� 361","�������� 1 ��� 25 �������� 227","�������� 12 ��� 3 �������� 119","������ �. ��� 20, ��. 16" };
		vector <string> posylki = { "Playstation IV","�����","����","�������","��������","�����","���� �������","���","��������","������","������","�����","�����","������ ���������","�������","������","��","��������� ���������","�������","����","����","�������","������������","�����","����","����","�������","��������","����","����������","��� ��","���� �� ������� ����","�������� ��� �����","��� �� � �����","�������","�������","���������","���������","������","������","�������","��������","�������","�������","����" };
		type_text( "�� ������ �� ������ � �������� �����.");
		string address = addresses[rand() % addresses.size()];
		string posylka = posylki[rand() % posylki.size()];		
		type_text("����� ��������� "+ posylka+"\n�� ������ "+ address);
		type_text("���� ��������");
		progress_bar(address.length());
		type_text("�� �������� " + to_string(address.length() * 3)+" Rub.");
		maney += address.length() * 3;

	}
	void show_commands() {

		cout << "������� ��� ����:\n1)help - �������� ��� ������� \n2)�����,����,�������������� - ���������� ��������������\n3)������ - �������� �������� �������\n4)������� - �������� ��������\n";

	}
	void brein_up() {
		srand(time(0));
		vector <string> addresses = { "����� �������","���","�������� ��������� ���������� � �����","� �����" };
		vector <string> posylki = { "������������ ������������","��������� ��","��������� windows","�����","������ ����������","������������ ����������","��������� ������� � ���������� D/ ","��������� ������","����� ������","��������� ���","�������������� ������� �����","���������������� �� �++","�������� �������","�������� ������","DDOS","" };
		type_text("�� ������ ����� �������	");
		string address = addresses[rand() % addresses.size()];
		string posylka = posylki[rand() % posylki.size()];
		type_text("�� ����� �������� ����� " + posylka + "\n� ������� ��������� " + address);
		type_text("�� �������");
		progress_bar(posylka.length());
		type_text("�� �������� " + to_string(posylka.length() * 1) + " � ���������");
		brain += posylka.length() * 1;
	}
	void day() {
		string pn = "�����������";
		string wt = "�������";
		string sr = "�����";
		string ch = "�������";
		string pt = "�������";
		string sb = "�������";
		string ws = "�����������";
		nam_day++;

	}
	void bratzer() {

	}
};
void vvedenie()
{
	string str = "�� - ������� ����. ������ ������� �� ������� �� ��������� � ����������� �������� � ���������� �������� � ������������� ������������� �����. �� �������� ������ � ������������ �� 3 ������ � ������� ��������� �� ����� ������...";
	type_text(str);
}


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	system("chcp 1251>nul");
	koza kz;
	string command;
	
	vvedenie();
	Sleep(500);
	system("cls");
	kz.kozaa();
	
	while (true)
	{
		 
		cin >> command;
		//cout << command;
		if ((command == "������ �����") || (command == "�����") || (command == "��������������") || (command == "����") || (command == "����") || (command == "����"))
		{
			kz.show_stats();
		}
		if ((command == "������") || (command == "work") || (command == "������")) {
			
				kz.delivery();
			
		}
		if ((command == "help") || (command == "����") || (command == "������"))
		{
			kz.show_commands();
		}
		if ((command == "�������") || (command == "��������") || (command == "�����������")) {
			kz.brein_up();
		}



		 system("pause>null");
		 system("cls");
	}



	system("pause >> NUL");
	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
