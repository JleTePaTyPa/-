#include <iostream>
#include "windows.h" 
#include <clocale>


using namespace std;

void type_text(string str) { // для написания текста 

	for (auto ch : str) {
		cout << ch;
		Sleep(30);
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



	void kozaa(int maney_2, int brain_2, int hp_2, int happy_2, int happy_brother_2) {

		
		maney = maney_2 = 1000;
		brain_2 = 100;
		hp_2 = 50;
		happy_2 = 100;
		happy_brother_2 = 100;


		char swt;


		string str = "для начала игры пройди тест К.О.З.А.";
		type_text(str);
		Sleep(700);
		system("cls");
		str = "брат зашёл в твою комнату, что будешь делать?";
		type_text(str);
		cout << "1)ничего" << endl << "2)даш ему поиграть в компютер" << endl << "3)выгонишь" << endl << "4)ударишь" << endl;
		cin >> swt;
		switch (swt) {
		case '1': break;
		case '2': brain_2 = brain_2 - 5; break;
		case '3': brain_2 = brain_2 + 10; hp_2 = hp_2 - 5; break;
		case '4': brain_2 = brain_2 - 10; hp_2 = hp_2 + 5; break;
		}
		system("cls");
		str = "мама позванила, и спрасила как дела?";
		type_text(str);
		cout << "1)сказать что всё хорошо" << endl << "2)раскритиковать брата" << endl << "3)сказать правду" << endl << "4)дать брату сказать" << endl;
		cin >> swt;
		switch (swt) {
		case '1': brain_2 = brain_2 + 5; break;
		case '2': hp_2 = hp_2 + 5; maney_2 = maney_2 + 200;  break;
		case '3': brain_2 = brain_2 - 10; maney_2 = maney_2 - 200; break;
		case '4': brain_2 = brain_2 - 10; happy_brother_2 = happy_brother_2 + 10; break;
		}
		system("cls");
		str = "пришла тётка из жека";
		type_text(str);
		cout << "1)сказать что никого нет дома" << endl << "2)дать ей деняг" << endl << "3)провести и показать счетчики" << endl << "4)слить её на брата" << endl;
		cin >> swt;
		switch (swt) {
		case '1': brain_2 = brain_2 + 10; happy_2 = happy_2 + 10; break;
		case '2': happy_2 = happy_2 - 10; maney_2 = maney_2 - 500; brain_2 = brain_2 + 20; break;
		case '3': break;
		case '4': happy_brother_2 = happy_brother_2 - 10; break;
		}
		system("cls");
		str = "с братом пошли гулять куда?";
		type_text(str);
		cout << "1)в кино" << endl << "2)на заброшку" << endl << "3)просто шляться по городу" << endl << "4)пойти в музей и другие умные места" << endl;
		cin >> swt;
		switch (swt) {
		case '1': maney_2 = maney_2 - 600; happy_2 = happy_2 + 50; happy_brother_2 = happy_brother_2 + 50; break;
		case '2': maney_2 = maney_2 - 200; happy_2 = happy_2 + 50; happy_brother_2 = happy_brother_2 + 50; brain_2 = brain_2 - 40; break;
		case '3': happy_2 = happy_2 + 20; happy_brother_2 = happy_brother_2 + 20; break;
		case '4': happy_2 = happy_2 - 20; happy_brother_2 = happy_brother_2 - 20; maney_2 = maney_2 - 500; brain_2 = brain_2 + 50; break;
		}
		system("cls");
		str = "закончилась еда";
		type_text(str);
		cout << "1)голодать" << endl << "2)сказать родителям и взять деняг" << endl << "3)пойти работать" << endl << "4)попросить соседей дать еды" << endl;
		cin >> swt;
		switch (swt) {
		case '1': happy_2 = happy_2 - 20; happy_brother_2 = happy_brother_2 - 20; brain_2 = brain_2 + 5; break;
		case '2': maney_2 = maney_2 + 500; happy_2 = happy_2 + 20; happy_brother_2 + 20; brain_2 = brain_2 - 20; break;
		case '3': maney_2 = maney_2 - 200; brain_2 = brain_2 + 5; happy_2 = happy_2 = happy_brother_2 - 15; break;
		case '4': happy_2 = happy_2 + 15; brain_2 = brain_2 + 20; break;
		}
		system("cls");
		str = "брат заболел";
		type_text(str);
		cout << "1)ничего не делать" << endl << "2)позванить родителям" << endl << "3)позванить в скорую" << endl << "4)гуглить симпотмы " << endl;
		cin >> swt;
		switch (swt) {
		case '1': happy_2 = happy_2 - 10; happy_brother_2 - 20; break;
		case '2': maney_2 = maney_2 + 500; brain_2 = brain_2 + 20; happy_brother_2 + 20; break;
		case '3': maney_2 = maney_2 - 500; brain_2 = brain_2 + 10; happy_2 = happy_2 + 20; happy_brother_2 = happy_brother_2 + 50; break;
		case '4': happy_brother_2 = happy_brother_2 - 30; brain_2 = brain_2 - 20; break;
		}
		system("cls");
		str = "сламалась раковина";
		type_text(str);
		cout << "1)вызвать сантехника" << endl << "2)починить самому с помошью гугла" << endl << "3)сказать родителям" << endl << "4)попросить брата починить " << endl;
		cin >> swt;
		switch (swt) {
		case '1': maney_2 = maney_2 - 800;  brain_2 = brain_2 + 15; happy_2 = happy_2 + 20; break;
		case '2': maney_2 = maney_2 + 500; brain_2 = brain_2 + 10; happy_2 = happy_2 + 20; break;
		case '3': maney_2 = maney_2 - 500; brain_2 = brain_2 + 10; happy_2 = happy_2 + 20; happy_brother_2 = happy_brother_2 + 50; break;
		case '4': happy_brother_2 = happy_brother_2 - 30; brain_2 = brain_2 - 20; break;
		}


	}
	void maney_3(int maney_3){

		maney_3 = maney;
		return maney;
	}
};
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");

	koza kz;
	
	 cout << maney;
	system("pause >> NUL");
	return 0;
}