#include "transPark.h"



transPark::transPark() {
	init();
}

transPark::~transPark() {
	delete[] trts;
}

void transPark::operator+=(const transport &sp) {
	if (size >= reserve) {
		trts = realloc(trts, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	trts[size++] = sp;
}
void transPark::operator+=(transport *sp) {
	if (size >= reserve) {
		trts = realloc(trts, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	move(trts[size++], *sp);
}
transport& transPark::operator[](int i) {
	return trts[i];
}

int transPark::length() const {
	return size;
}
void transPark::remove(int n) {
	if (n >= size)
		throw exceptions("Ошибка, корабля с таким номером не содержится в библиотеке");
	--size;
	for (int i = n; i < size; ++i)
		move(trts[i], trts[i + 1]);
}
void transPark::get_Info() {
	for (int i = 0; i < size; ++i) {
		std::cout << i + 1 << ") Номер маршрута: " + trts[i].getNumber() + " Число пассажиров: ";
		std::cout << trts[i].getPass() << std::endl;
	}
	std::cout << std::endl;
}

std::istream& operator>>(std::istream &is, transPark &Obj) {
	transport trt;
	int dec; 
	std::cout << "Введите кол-во добавляемого транспорта: ";
	std::cin >> dec;
	std::cin.get();
	if (dec < 1)
		throw exceptions("Кол-во < 1.");
	for (int i = 0; i < dec; ++i) {
		std::cout << '|' << i + 1 << '|';
		std::cout << std::endl;
		try {
			is >> trt;
		}
		catch (exceptions &e) {
			std::cout
				<< "Ошибка добавления в парк: "
				<< e.what() << std::endl << std::endl;
			continue;
		}
		Obj += &trt;
		std::cout << "Парк обновлён!";
		std::cout << std::endl << std::endl;
	}
	return is;
}
std::ostream& operator<<(std::ostream &os, const transPark &Obj) {
	for (int i = 0; i < Obj.size; ++i) {
		os << '|' << i + 1 << '|';
		os << std::endl;
		os << Obj.trts[i];
		os << std::endl;
	}
	return os;
}

std::ifstream& operator>>(std::ifstream& ifs, transPark &Obj) {
	char c;
	transport trt;
	while ((c = ifs.get()) != '\n' && c != EOF) {
		ifs.unget();
		ifs >> trt;
		Obj += &trt;
	}
	if (c == EOF)
		ifs.unget();
	return ifs;
}
std::ofstream& operator<<(std::ofstream& ofs, const transPark &Obj) {
	for (int i = 0; i < Obj.size; ++i) {
			ofs << '|' << i + 1 << '|';
			ofs << std::endl;
			ofs << Obj.trts[i];
			ofs << std::endl;
	}
	std::cout << std::endl;
	return ofs;
}

void transPark::save(std::ofstream& ofs) {
	for (int i = 0; i < size; ++i)
		trts[i].save(ofs);
	ofs << std::endl;
}

void transPark::init() {
	reserve = PHASE;
	size = 0;
	trts = new transport[reserve];
}