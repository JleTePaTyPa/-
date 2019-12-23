#include <iostream>
#include "windows.h" 
#include <clocale>
#include <string>
#include <vector>
#include "time.h"
#include <fstream>
#include <string>
#include "conio.h"
#include <cstdlib>
#include <Mmsystem.h>
#include <mciapi.h>
#include <map>
#pragma comment(lib, "Winmm.lib")
using namespace std;
string yes_or_no();
int integer();
int integer()
{
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error!" << endl;
	}
	return a;
}
int nominal(string karta)
{

	char last = karta[karta.length() - 1];
	switch (last)
	{
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 10;
	case '�': return 2;
	case '�': return 3;
	case '�': return 4;
	case '�': return 11;

	}
}



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
		Beep(rand() % 100 + 185, 30);
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
	string name;
	string girlfriend = "";

	koza(int maney_2 = 1000, int brain_2 = 100, int hp_2 = 50, int happy_2 = 100, int happy_brother_2 = 100, int nam_day_2 = 0)
	{
		maney = maney_2;
		brain = brain_2;
		hp = hp_2;
		happy = happy_2;
		happy_brother = happy_brother_2;
		nam_day = nam_day_2;
		srand(time(0));
		vector <string> names = { "��������","��������","������","�����","����" };
		name = names[rand() % names.size()];//����� ���������� ����� �� �����
		girlfriend = "";
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
		cout << "maney: " << maney << endl;
		cout << "brain: " << brain << endl;
		cout << "hp: " << hp << endl;
		cout << "happy: " << happy << endl;
		cout << "happy_brother: " << happy_brother << endl;

	}
	void progress_bar(int seconds)
	{
		cout << endl;
		COORD coord = get_cursor_position();
		COORD coords_pb = get_cursor_position();
		coords_pb.Y += 1;
		for (int i = 0; i < 101; i++)
		{
			gotoxy(coord);
			cout << i << "%";
			if (i % 3)
			{
				gotoxy(coords_pb);
				cout << "-";
				coords_pb.X += 1;
			}



			Sleep(seconds);
		}
		cout << endl << endl;
	}
	void delivery()

	{
		srand(time(0));
		vector <string> addresses = { "�������� 16 ��� 2 �������� 7","�������� 16 ��� 6 �������� 32","�������� 16 ��� 2 �������� 2","�������� 16 ��� 3 �������� 54","�������� 11 ��� 23 �������� 64","�������� 16 ��� 23 �������� 5","�������� 16 ��� 12 �������� 112", "������� 12 ��� 13 �������� 34","������� 15 ��� 13 �������� 42","������� 9 ��� 2 �������� 361","�������� 1 ��� 25 �������� 227","�������� 12 ��� 3 �������� 119","������ �. ��� 20, ��. 16" };
		vector <string> posylki = { "Playstation IV","�����","����","�������","��������","�����","���� �������","���","��������","������","������","�����","�����","������ ���������","�������","������","��","��������� ���������","�������","����","����","�������","������������","�����","����","����","�������","��������","����","����������","��� ��","���� �� ������� ����","�������� ��� �����","��� �� � �����","�������","�������","���������","���������","������","������","�������","��������","�������","�������","����" };
		type_text("�� ������ �� ������ � �������� �����.");
		string address = addresses[rand() % addresses.size()];
		string posylka = posylki[rand() % posylki.size()];
		type_text("����� ��������� " + posylka + "\n�� ������ " + address);
		type_text("���� ��������");
		progress_bar(address.length());
		type_text("�� �������� " + to_string(address.length() * 3) + " Rub.");
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
	void Black_Jack()
	{
		type_text("������ �� ��������� ������?");
		bool real_money;
		int game_money, stavka;
		if (yes_or_no() == "��")		
			real_money = true;		
		else
			real_money = false;
		if (real_money)
			game_money = maney;
		else
			game_money = 100000;
		cout << "� ��� " << game_money << endl;
		cout << "������� ���� ������" << endl;
		
		stavka = integer();
		while (stavka > game_money)
		{
			cout << "������������ �����, ������� ������ �� ����� "<<game_money<<  endl;
			stavka = integer();
		}
		
		
		vector <string> koloda =
		{
			"����� 6",
			"����� 7",
			"����� 8",
			"����� 9",
			"����� 10",
			"����� �����",
			"����� ����",
			"����� ������",
			"����� ���",

			"����� 6",
			"����� 7",
			"����� 8",
			"����� 9",
			"����� 10",
			"����� �����",
			"����� ����",
			"����� ������",
			"����� ���",

			"������ 6",
			"������ 7",
			"������ 8",
			"������ 9",
			"������ 10",
			"������ �����",
			"������ ����",
			"������ ������",
			"������ ���",

			"���� 6",
			"���� 7",
			"���� 8",
			"���� 9",
			"���� 10",
			"���� �����",
			"���� ����",
			"���� ������",
			"���� ���",

		};


		string karta;
		int score = 0;
		string command = "��";
		
		while (command == "��")
		{
			int index = rand() % koloda.size();
			karta = koloda[index];

			koloda.erase(koloda.begin() + index);//������� ����� �� ������
			//koloda.erase(index);
			cout << "�� �������: " << karta << endl;
			score += nominal(karta);
			cout << "� ����� �����: " << score << endl;

			cout << "����� ��� �����?";
			if (yes_or_no() == "��")
				command = "��";
			else
				command = "���";



		}

		cout << "�� ������ ��������� �����, � ��� " << score << " �����" << endl;
		int enemy_score =   15+ rand() % 12;
		cout << "� ������ ��������� " << enemy_score;
		if (score > 21)
		{
			if (enemy_score > 21)
				cout << "�����, � ����� ������� �����" << endl;
			else
			{
				cout << endl<<"�� ��������� " << stavka << endl;
				game_money -= stavka;
				cout << "� ��� �������� " << game_money << endl;
			}
		}
		else
		{
			if (enemy_score > 21 || score>enemy_score)
			{
				cout << "�� �������� " << stavka << endl;
				game_money += stavka;
				cout << "� ���  " << game_money << endl;
			}
			if (enemy_score == score)
			{
				cout << "�����, ������ ���������� �����" << endl;
			}
		}
		if (real_money)
			maney = game_money;
		//����� ����������
		while (true)
		{

			type_text("������ ������?");			
			if (yes_or_no() == "��")
			{
				Black_Jack();
			}
			else
			{
				type_text("�����");
				return ;
			}

			return ;
		}
	}
};
void vvedenie()
{
	string str = "�� - ������� ����. ������ ������� �� ������� �� ��������� � ����������� �������� � ���������� �������� � ������������� ������������� �����. �� �������� ������ � ������������ �� 3 ������ � ������� ��������� �� ����� ������...";
	type_text(str);
}
string yes_or_no()
{
	string command;
	while (true)
	{
		cin >> command;
		if (command == "��")
			return "��";
		if (command == "���")
			return "���";

	}
}

void hapy_birthday(koza kz)
{
	srand(time(0));

	//vector <string> addresses = { "�������� 16 ��� 2 �������� 7","�������� 16 ��� 6 �������� 32","�������� 16 ��� 2 �������� 2","�������� 16 ��� 3 �������� 54","�������� 11 ��� 23 �������� 64","�������� 16 ��� 23 �������� 5","�������� 16 ��� 12 �������� 112", "������� 12 ��� 13 �������� 34","������� 15 ��� 13 �������� 42","������� 9 ��� 2 �������� 361","�������� 1 ��� 25 �������� 227","�������� 12 ��� 3 �������� 119","������ �. ��� 20, ��. 16" };
	vector <string> podruzhki = { "�����","����","����","��������","��������","����","����� ������","����" };
	type_text("�������� ������� ����, �� ����� ������");
	//string address = addresses[rand() % addresses.size()];
	string podruzhka = podruzhki[rand() % podruzhki.size()];
	type_text("���� ������������� " + podruzhka + " ������� ��� �� ���� ��������");
	type_text("����� ����� � ����� �����?");
	string command;
	if (yes_or_no() == "��")
	{
		kz.happy -= 50;
		kz.happy_brother += 50;
		type_text("������ ������� �����?");
		cin >> command;
		while (true)
		{
			if (command == "��")
			{
				type_text("�� ���������, ��� ���� ���� ����� ������ � ������ �����. ����� �������� �������, ��� ������� ������� ������������ ���� � ���� � ����� ����� � ��������� ����������. ���� � ����.");
				type_text(podruzhka + " �������� ��� � �������: \'������, " + kz.name + "! ������� � ���, ��� ��� ���������");
				break;
			}
			if (command == "���")
			{
				type_text("���� ������ �������������� � �� ����������� � �����");
				type_text(podruzhka + " �������� ��� � �������: \'������, " + kz.name + "! ������ ���� ���� � ����� ����� � �����? �����, �������, ������� � ���, ��� ��� ���������");
				kz.happy -= 10;
				break;
			}
		}
		//��������
		type_text("�� ��������� � ���������� ������� ���������. �� ������ ������������ ������ ������ ����� � ������� � ����� ���� ������ ������. ");
		type_text("-��� ��� �������, �� ����� �����, ��� ����� ���������. - ������� " + podruzhka + ".");
		type_text("���������� ������� ��� ����� ������� ������ � ������� �� ����");
		type_text("��� ������ ����? 1. ���������� ����");
		type_text("1.���������� ����");
		type_text("2.��������� ����");
		type_text("3.�����");
		cin >> command;
		while (true)
		{
			if (command == "1")
			{
				type_text("�� ������� ����, �����, ��� �������� �����.");
				kz.brain -= 25;
				kz.maney -= 600;
				kz.happy -= 10;
				kz.happy_brother -= 50;

				type_text("����� �� ������ ������� ����� ��������� � �� ���� ��� ��� ��������. � ��� ����� 600� �� �����");
				kz.nam_day += 1;
				type_text("���� ������� ��� �� ������� � ��������, � ������ ��� ��������� �����");
				break;
			}
			if (command == "2")
			{
				type_text("�� ������� ���� � �� ���������! ���� ����, �������������� ���������� ��������, � ��������� ����������� �� ���������� ���������� ������ ���������� ��������� � �������� ������ �������");
				kz.happy += 50;
				kz.brain + 30;
				kz.hp += 10;
				break;
			}
			if (command == "3")
			{
				type_text("�� ������� �����. �������� �����. ������ ����������. ��������. �� �������.");
				kz.happy += 1;
				break;
			}
		}

		
	}
	else
			{

				type_text("�� ������ �� ����� ����� �� ���� ��������, ��� ��� ������ � ���� ����������?");
				cout << "1. ������ ����" << endl;
				cout << "2. ��������� ����� ���� �������� ������� � ������� ������� ����� �������" << endl;

				cout << "3. ������� (���� ���� � ���������)" << endl;
				if (kz.girlfriend != "")
					cout << "4. ��������� ������� �������� � ������" << endl;
				while (true)
				{
					if (command == "1")
					{
						type_text("�� �������� ����� ������� � ������� ������������ �������������. ��������, ������ ���� ��� �������� ���-�� ����� ����������...");
						/*mciSendString("open \"00165.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3", NULL, 0, NULL);*/
						type_text("������� ��� ����� ����� ������� �� �������� ���, ���������� ����� ���� ������������ ��, ��� ������ ������� ���� ������� ������������ �������������");
						type_text("�� ��������� ������ � ��������� �� �������������� � ������ �������, ������ ��� �������� ������������. ������������ �� ���� ������� � ");
						type_text("�������� � ����������� ����������� ���������� ����� � ������ ���� ����������� �� ���� ��������");

						break;
					}
					if (command == "1")
					{
						type_text("�� �������� ����� ������� � ������� ������������ �������������. ��������, ������ ���� ��� �������� ���-�� ����� ����������...");
						/*LPCWSTR a = L"open 00165.mp3 type mpegvideo";//���� ������
						mciSendString(a, NULL, 0, 0);
						LPCWSTR b = L"play 00165.mp3";
						int error2 = mciSendString(b, NULL, 0, 0);*/
						type_text("������� ��� ����� ����� ������� �� �������� ���, ���������� ����� ���� ������������ ��, ��� ������ ������� ���� ������� ������������ �������������");
						type_text("�� ��������� ������ � ��������� �� �������������� � ������ �������, ������ ��� �������� ������������. ������������ �� ���� ������� � ");
						type_text("�������� � ����������� ����������� ���������� ����� � ������ ���� ����������� �� ���� ��������");

						break;
					}
					if (command == "2")
					{
						type_text("");


						break;
					}

				}
				
	}		

}
	int main(int argc, char* argv[]) {
		setlocale(LC_ALL, "ru");
		system("chcp 1251>nul");
		koza kz;
		string command;

		/*vvedenie();
		Sleep(500);
		system("cls");
		kz.kozaa();*/
		kz.Black_Jack();

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
