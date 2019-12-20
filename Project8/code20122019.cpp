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
		case 'т': return 2;
		case 'а': return 3;
		case 'ь': return 4;
		case 'з': return 11;

		}
}
int Black_Jack(koza kz)
{	
	vector <string> koloda = 
	{
		"бубна 6",
		"бубна 7",
		"бубна 8", 
		"бубна 9", 
		"бубна 10", 
		"бубна Валет", 
		"бубна Дама", 
		"бубна Король", 
		"бубна Туз",

		"черва 6",
		"черва 7",
		"черва 8",
		"черва 9",
		"черва 10",
		"черва Валет",
		"черва Дама",
		"черва Король",
		"черва Туз",

		"креста 6",
		"креста 7",
		"креста 8",
		"креста 9",
		"креста 10",
		"креста Валет",
		"креста Дама",
		"креста Король",
		"креста Туз",

		"пика 6",
		"пика 7",
		"пика 8",
		"пика 9",
		"пика 10",
		"пика Валет",
		"пика Дама",
		"пика Король",
		"пика Туз",	
	
	};

	
	


	string karta;
	int score = 0;
	string command="да";
	while (command == "да")
	{
		int index = rand() % koloda.size();
		karta = koloda[index];

		koloda.erase(karta);
		//koloda.erase(index);
		cout << "Вы достали " << karta << endl;
		score += nominal(karta);
		cout << "В сумме очков" << score << endl;

		cout << "Взять еще карту или закончить?";

		while (true)
		{
			cin >> command;
			if (command == "да")
			{
				break;
			}
			if (command == "нет")
			{
				return 0;
			}
		}

	}

	cout << "вы решили закончить раунд, у вас " << score << " очков" << endl;
	cout << "у вашего соперника " << rand() % 25 + 2;
	//раунд закончился
	while (true)
	{
		
		type_text("Играем дальше?");
		cin >> command;
		while (true)
		{
			if (command == "да")
			{	
				Black_Jack(kz);
				break;
			}
			if (command == "нет")
			{
				type_text("конец");
				return 0;
			}
		}
		return 0;
	}
}

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
	string name;
	string girlfriend = "";

	koza(int maney_2 = 1000, int brain_2 = 100, int hp_2= 50, int happy_2 = 100, int happy_brother_2 = 100, int nam_day_2 = 0)
	{
		 maney= maney_2;
		 brain= brain_2;
		 hp= hp_2;
		 happy= happy_2;
		 happy_brother= happy_brother_2;
		 nam_day = nam_day_2;
		 srand(time(0));
		 vector <string> names = { "Анатолий","Вениамин","Сергей","Дамир","Даня" };
		 name= names[rand() % names.size()];//выбор случайного имени из сиска
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

void hapy_birthday(koza kz)
{
	srand(time(0));

	//vector <string> addresses = { "Пирогова 16 дом 2 квартира 7","Пирогова 16 дом 6 квартира 32","Пирогова 16 дом 2 квартира 2","Пирогова 16 дом 3 квартира 54","Пирогова 11 дом 23 квартира 64","Пирогова 16 дом 23 квартира 5","Пирогова 16 дом 12 квартира 112", "серёжена 12 дом 13 квартира 34","серёжена 15 дом 13 квартира 42","серёжена 9 дом 2 квартира 361","данилова 1 дом 25 квартира 227","данилова 12 дом 3 квартира 119","Маркса К. дом 20, кв. 16" };
	vector <string> podruzhki = { "Влада","Лиля","Нора","Василиса","Вероника","Вика","Света Кобейн","Вера" };
	type_text("проверяя почтоый ящик, вы нашли письмо");
	//string address = addresses[rand() % addresses.size()];
	string podruzhka = podruzhki[rand() % podruzhki.size()];
	type_text("Ваша одногруппница " + podruzhka + " позвала вас на день рождения");
	type_text("будем брать с собой брата?");
	string command;
	while (true)
	{

		cin >> command;
		while (true)
		{
			if (command == "да")
			{
				kz.happy -= 50;
				kz.happy_brother += 50;
				type_text("Помочь одеться брату?");
				cin >> command;
				while (true)
				{
					if (command == "да")
					{
						type_text("Вы онаружили, что брат одел папин пиджак и мамину шляпу. После короткой схватки, вам удалось вернуть родительские вещи в шкаф и одеть брата в приличный комбенизон. Пора в путь.");
						type_text(podruzhka + " обнимает вас и говорит: \'Привет, " + kz.name + "! проходи в зал, все уже собрались");
						break;
					}
					if (command == "нет")
					{
						type_text("Брат оделся самостоятельно и вы отправились в гости");
						type_text(podruzhka + " обнимает вас и говорит: \'Привет, " + kz.name + "! Почему твой брат в одном носке и шляпе? Ладно, неважно, проходи в зал, все уже собрались");
						kz.happy -= 10;
						break;
					}
				}
				//угощение
				type_text("Вы оказались в просторном светлом помещении. На старом продавленном кресле закрыв глаза с газетой в руках спит усатый старик. ");
				type_text("-Это мой дедушка, он очень устал, ему нужно отдохнуть. - сказала " + podruzhka+".");
				type_text("Именинница помогла вам снять верхнюю одежду и усадила за стол");
				type_text("Что будете есть? 1. Клубничный торт");
				type_text("1.Клубничный торт");
				type_text("2.Узбекский плов");
				type_text("3.Пицца");
				cin >> command;
				while (true)
				{
					if (command == "1")
					{
						type_text("Вы выбрали торт, забыв, про аллергию брата.");
						kz.brain -= 25;
						kz.maney -= 600;
						kz.happy -= 10;
						kz.happy_brother -= 50;
						
						type_text("Врачи из скорой вкололи брату эпинефрин и на этот раз все обошлось. С вас взяли 600р за вызов");
						kz.nam_day += 1;
						type_text("Весь остаток дня вы провели в больнице, к вечеру вас отпустили домой");
						break;
					}
					if (command == "2")
					{
						type_text("Вы выбрали плов и не прогадали! Этот плов, приготовленный настоящими узбеками, в настоящем узбекистане из настоящего узбекского барана неописуемо прекрасен и волшебно пахнет узбеком");
						kz.happy += 50;
						kz.brain + 30;
						kz.hp += 10;
						break;
					}
					if (command == "3")
					{
						type_text("Вы выбрали пиццу. Неплохой выбор. Ничего особенного. Съедобно. Вы скучный.");
						kz.happy += 1;
						break;
					}
				}

				break;
			}
			if (command == "нет")
			{

				type_text("Вы решили не брать брата на день рождения, чем его займем в наше отсутствие?");
				cout << "1. Чтение книг" << endl;
				cout << "2. Поставить брату вашу любюимую кассету с крепким орешком Брюса Уиллиса" << endl;

				cout << "3. Игрушка (если есть в инвентаре)" << endl;
				if (kz.girlfriend != "")
					cout << "4. Попросить девушку посидеть с братом" << endl;
				while (true)
				{
					if (command == "1")
					{
						type_text("Мы оставили брата наедине с большой компьютерной энциклопедией. Возможно, стоило дать ему почитать что-то более безобидное...");
						mciSendString("open \"00165.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3", NULL, 0, NULL);
						type_text("Проходя под окном своей комнаты вы услышали шум, неожиданно перед вами приземляется то, что совсем недавно было большой компьютерной энциклопедией");
						type_text("Вы поддались страху и пробежали не останавливаясь с добрых полмили, прежде чем осознали произошедшее. Возвращаться не было времени и ");
						type_text( "поставив в ежедневнике напоминание рассказать брату о пользе книг отправились на день рождения");
						
						break;
					}
					if (command == "1")
					{
						type_text("Мы оставили брата наедине с большой компьютерной энциклопедией. Возможно, стоило дать ему почитать что-то более безобидное...");
						/*LPCWSTR a = L"open 00165.mp3 type mpegvideo";//звук стекла
						mciSendString(a, NULL, 0, 0);
						LPCWSTR b = L"play 00165.mp3";
						int error2 = mciSendString(b, NULL, 0, 0);*/						
						type_text("Проходя под окном своей комнаты вы услышали шум, неожиданно перед вами приземляется то, что совсем недавно было большой компьютерной энциклопедией");
						type_text("Вы поддались страху и пробежали не останавливаясь с добрых полмили, прежде чем осознали произошедшее. Возвращаться не было времени и ");
						type_text("поставив в ежедневнике напоминание рассказать брату о пользе книг отправились на день рождения");

						break;
					}
					if (command == "2")
					{
						type_text("");
						

						break;
					}

				}
				break;
			}
			cin >> command;
		}

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
