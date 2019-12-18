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
  //bi.dwCursorPosition - кооpдинаты куpсоpа 
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
		cout << "Нет такого варианта" << endl;
		cin >> str;
		number = stoi(str);
	}
	return str[0];

}
	
void set_color(int back_color, int text_color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Цвет символов - желтый. Цвет фона - темно-серый
	SetConsoleTextAttribute(hConsole, (WORD)((back_color << 4) | text_color));
}

void type_text(string str) { // для написания текста 
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

// тест на стартовые статы
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
		string str = "краткая история первого месяца жизни с братом...";
		type_text(str);
		Sleep(700);
		system("cls");
		//set_color(Black, Yellow);
		str = "брат зашёл в твою комнату, что будешь делать?";

		type_text(str);
		//set_color(Black, White);
		cout << "1)ничего" << endl << "2)даш ему поиграть в компютер" << endl << "3)выгонишь" << endl << "4)ударишь" << endl;
		
		swt = vvod_var(4);
		switch (swt) {
		case '1': break;
		case '2': brain = brain - 5; break;
		case '3': brain = brain + 10; hp = hp - 5; break;
		case '4': brain = brain - 10; hp = hp + 5; break;
		}
		system("cls");
		str = "мама позванила, и спрасила как дела?";
		type_text(str);
		cout << "1)сказать что всё хорошо" << endl << "2)раскритиковать брата" << endl << "3)сказать правду" << endl << "4)дать брату сказать" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': brain = brain + 5; break;
		case '2': hp = hp + 5; maney = maney + 200;  break;
		case '3': brain = brain - 10; maney = maney - 200; break;
		case '4': brain = brain - 10; happy_brother = happy_brother + 10; break;
		}
		system("cls");
		str = "пришла тётка из жека";
		type_text(str);
		cout << "1)сказать что никого нет дома" << endl << "2)дать ей деняг" << endl << "3)провести и показать счетчики" << endl << "4)слить её на брата" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': brain = brain + 10; happy = happy + 10; break;
		case '2': happy = happy - 10; maney = maney - 500; brain = brain + 20; break;
		case '3': break;
		case '4': happy_brother = happy_brother - 10; break;
		}
		system("cls");
		str = "с братом пошли гулять куда?";
		type_text(str);
		cout << "1)в кино" << endl << "2)на заброшку" << endl << "3)просто шляться по городу" << endl << "4)пойти в музей и другие умные места" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': maney = maney - 600; happy = happy + 50; happy_brother = happy_brother + 50; break;
		case '2': maney = maney - 200; happy = happy + 50; happy_brother = happy_brother + 50; brain = brain - 40; break;
		case '3': happy = happy + 20; happy_brother = happy_brother + 20; break;
		case '4': happy = happy - 20; happy_brother = happy_brother - 20; maney = maney - 500; brain = brain + 50; break;
		}
		system("cls");
		str = "закончилась еда";
		type_text(str);
		cout << "1)голодать" << endl << "2)сказать родителям и взять деняг" << endl << "3)пойти работать" << endl << "4)попросить соседей дать еды" << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': happy = happy - 20; happy_brother = happy_brother - 20; brain = brain + 5; break;
		case '2': maney = maney + 500; happy = happy + 20; happy_brother + 20; brain = brain - 20; break;
		case '3': maney = maney - 200; brain = brain + 5; happy = happy = happy_brother - 15; break;
		case '4': happy = happy + 15; brain = brain + 20; break;
		}
		system("cls");
		str = "брат заболел";
		type_text(str);
		cout << "1)ничего не делать" << endl << "2)позванить родителям" << endl << "3)позванить в скорую" << endl << "4)гуглить симпотмы " << endl;
		swt = vvod_var(4);
		switch (swt) {
		case '1': happy = happy - 10; happy_brother - 20; break;
		case '2': maney = maney + 500; brain = brain + 20; happy_brother + 20; break;
		case '3': maney = maney - 500; brain = brain + 10; happy = happy + 20; happy_brother = happy_brother + 50; break;
		case '4': happy_brother = happy_brother - 30; brain = brain - 20; break;
		}
		system("cls");
		str = "сламалась раковина";
		type_text(str);
		cout << "1)вызвать сантехника" << endl << "2)починить самому с помошью гугла" << endl << "3)сказать родителям" << endl << "4)попросить брата починить " << endl;
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
		cout << "Ваши статы: " << endl;
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
		vector <string> addresses = { "Пирогова 16 дом 2 квартира 7","Пирогова 16 дом 6 квартира 32","Пирогова 16 дом 2 квартира 2","Пирогова 16 дом 3 квартира 54","Пирогова 11 дом 23 квартира 64","Пирогова 16 дом 23 квартира 5","Пирогова 16 дом 12 квартира 112", "серёжена 12 дом 13 квартира 34","серёжена 15 дом 13 квартира 42","серёжена 9 дом 2 квартира 361","данилова 1 дом 25 квартира 227","данилова 12 дом 3 квартира 119","Маркса К. дом 20, кв. 16" };
		vector <string> posylki = { "Playstation IV","пицца","суши","коктель","макароны","дошик","курт кобейна","чай","зарплату","котика","гитару","рамен","чипсы","важные документы","посылку","письмо","мёд","маленькую собочёнку","картину","колу","часы","ноутбук","одногрупника","лампу","шкаф","стол","кровать","тоблетки","соль","видеокарту","что то","коды от ядерных бомб","бомбочки для ванны","что то с алика","тарелки","зеркало","телевизор","компьютер","куртку","гитару","колонки","наушники","коробку","футолку","пилу" };
		type_text( "Вы пришли на работу и получили заказ.");
		string address = addresses[rand() % addresses.size()];
		string posylka = posylki[rand() % posylki.size()];		
		type_text("Нужно доставить "+ posylka+"\nПо адресу "+ address);
		type_text("Идет доставка");
		progress_bar(address.length());
		type_text("Вы получили " + to_string(address.length() * 3)+" Rub.");
		maney += address.length() * 3;

	}
	void show_commands() {

		cout << "команды для игры:\n1)help - показать все команды \n2)статы,инфо,характеристики - посмотреть характеристики\n3)работа - получить немножко шекилей\n4)учиться - получить интелект\n";

	}
	void brein_up() {
		srand(time(0));
		vector <string> addresses = { "имени балмана","пту","институт экономики упровления и права","у ашота" };
		vector <string> posylki = { "компьютерная граммотность","устоновка ПО","устоновка windows","пайка","сборка компьютера","обслужевание компьютера","устоновка системы в дирикторию D/ ","настройки прокси","взлом сайтов","настройка впн","форматирование жоского диска","программирование на с++","создание сервера","удаленый доступ","DDOS","" };
		type_text("Вы решили пойти учиться	");
		string address = addresses[rand() % addresses.size()];
		string posylka = posylki[rand() % posylki.size()];
		type_text("вы пошли отточить навык " + posylka + "\nв учебное заведение " + address);
		type_text("вы учитесь");
		progress_bar(posylka.length());
		type_text("Вы получили " + to_string(posylka.length() * 1) + " к интелекту");
		brain += posylka.length() * 1;
	}
	void day() {
		string pn = "понедельник";
		string wt = "вторник";
		string sr = "среда";
		string ch = "четверг";
		string pt = "пятница";
		string sb = "суббота";
		string ws = "воскресение";
		nam_day++;

	}
	void bratzer() {

	}
};
void vvedenie()
{
	string str = "Вы - старший брат. Совсем недавно вы съехали от родителей в собственную квартиру и устроились курьером в развивающуюся перспективную фирму. но родители уехали в командировку на 3 месяца и сказали последить за вашим братом...";
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
		if ((command == "покажи статы") || (command == "статы") || (command == "характеристики") || (command == "стат") || (command == "инфа") || (command == "инфо"))
		{
			kz.show_stats();
		}
		if ((command == "работа") || (command == "work") || (command == "деньги")) {
			
				kz.delivery();
			
		}
		if ((command == "help") || (command == "хелп") || (command == "помощь"))
		{
			kz.show_commands();
		}
		if ((command == "учиться") || (command == "интелект") || (command == "развиваться")) {
			kz.brein_up();
		}



		 system("pause>null");
		 system("cls");
	}



	system("pause >> NUL");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
