#include "func_for_transPark.h"

using std::cout;
using std::cin;
using std::endl;

void addTrans(transPark *trts) {
	try {
		cin >> *trts;
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl;
	}
}
void printTrans(transPark *trts) {
	cout << std::endl;

	if (!(trts->length())) {
		cout << "Парк пуст." << endl << endl;
		return;
	}
	std::cout << *trts;
}
void deleteTrans(transPark *trts) {
	int dec;

	cout << endl;

	if (!(trts->length())) {
		cout << "Порт пуст." << endl << endl;
		return;
	}

	trts->get_Info();

	std::cout << "Введите номер удаляемого корабля: ";
	std::cin >> dec;
	std::cin.get();

	try {
		trts->remove(--dec);
	}
	catch (exceptions &e) {
		cout << e.what() << endl << endl;
		return;
	}
	cout << "Успешно удалено!" << endl << endl;
}

void readsTrans(transPark *trts, std::ifstream &in) {
	in >> *trts;
}
void writeTrans(transPark *trts, string &PathWrite_1, string &PathWrite_2) {
	std::ofstream out;

	out.open(PathWrite_1, std::ios_base::app);

	if (!out.is_open()) {
		throw exceptions("Файл не был открыт");
	}

	out << *trts;
	out << std::endl;

	out.close();
	out.clear();

	out.open(PathWrite_2, std::ios_base::app);

	if (!out.is_open()) {
		throw exceptions("Файл не был открыт");
	}

	trts->save(out);

	out.close();
	out.clear();
}