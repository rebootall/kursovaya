#include "transFactory.h"
#include "func_for_transPark.h"


#define AMOUNT_OF_ITEM 3

void trans_action(transPark *trt);


int main() {
	int i;
	transFactory *f = transFactory::getInstance();
	transPark *trtONE = f->createMachine();
	transPark *trtTWO = f->createTruck();
	transPark *trtTHREE = f->createTram();

	string PathRead_1, PathRead_2;

	setlocale(LC_ALL, "Russian");


	string TypeTrans[AMOUNT_OF_TRANS_TYPES] = {
		"�������� ������",
		"�������� ������",
		"�������"
	};

	std::cout << "��������� �� ����� ����?(1 - y/ 0 - n) ";
	std::cin >> i;
	std::cin.get();

	if (i) {
		std::cout << std::endl;
		std::cout << "������� ��� �����" << std::endl;
		std::cout << ROAD;
		std::cin >> PathRead_1;
		PathRead_1 = ROAD + PathRead_1;

		std::ifstream in(PathRead_1);

		if (in.is_open()) {
			readsTrans(trtONE, in);
			readsTrans(trtTWO, in);
			readsTrans(trtTHREE, in);
		}
		else {
			std::cout << "���� �� ��� ������" << std::endl;
		}

		in.close();
		in.clear();
	}

	while (1) {
		usrmenu(AMOUNT_OF_TRANS_TYPES, TypeTrans, trans_action,
			trtONE,
			trtTWO,
			trtTHREE
		);
		std::cout << "���������� ������?(0 - ���) ";
		std::cin >> i;
		std::cin.get();
		if (!i) {
			std::cout << "��������� ���� � �������� �����?(0 - ���) ";
			std::cin >> i;
			std::cin.get();
			if (i) {
				transPark trt;

				std::cout << std::endl;
				std::cout << "������� ��� �����" << std::endl;
				std::cout << ROAD;
				std::cin >> PathRead_1;
				PathRead_1 = ROAD + PathRead_1;

				std::cout << "������� ��� ����� ��� ���������� �������� �����" << std::endl;
				std::cout << ROAD;
				std::cin >> PathRead_2;
				PathRead_2 = ROAD + PathRead_2;

				writeTrans(trtONE, PathRead_1, PathRead_2);
				writeTrans(trtTWO, PathRead_1, PathRead_2);
				writeTrans(trtTHREE, PathRead_1, PathRead_2);
			}
			break;
		}
	}
	delete f;
	delete trtONE;
	delete trtTWO;
	delete trtTHREE;
	return 0;
}

void trans_action(transPark *trt) {
	string menu[AMOUNT_OF_ITEM] = {
		"�������� ���������",
		"������� ���������",
		"������� ��������� �� �����",
	};
	int ch;
	while (1) {
		try {
			usrmenu(AMOUNT_OF_ITEM, menu, trt,
				addTrans,
				deleteTrans,
				printTrans
			);
		}
		catch (exceptions &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << "���������� ��������� �����?(0 - ���) ";
		std::cin >> ch;
		std::cin.get();
		if (!ch) break;
	}
}