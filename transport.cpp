#include "transport.h"
#include "FFun.h"



transport& transport::operator=(const transport &trt) {
	if (this != &trt) {
		this->color = trt.color;
		this->cost = trt.cost;
		this->capacity = trt.capacity;
		this->number = trt.number;
		this->year = trt.year;
		this->start = trt.start;
		this->type = trt.type;
		this->pass = trt.pass;
		this->weight = trt.weight;
	}
	return *this;
}

std::istream& operator>>(std::istream &is, transport &trt) {
	string
		color,
		number,
		type;
	int
		year,
		start,
		pass;
	double
		cost,
		capacity,
		weight;

	transport *ptr;

	std::cout << "Введите цвет: ";
	is >> color;

	std::cout << "Введите стоимость(млн. рублей): ";
	is >> cost;
	if (cost < 0) throw exceptions("Стоимость не может быть отрицательной!");

	std::cout << "Введите объем двигателя(литры): ";
	is >> capacity;
	if (capacity < 0) throw exceptions("Объем двигателя не может быть отрицательный!");

	std::cout << "Введите номер маршрута: ";
	is >> number;

	std::cout << "Введите год производства: ";
	is >> year;
	if (year < 1) throw exceptions("Год производтства не может быть меньше 1!");

	std::cout << "Введите год запуска в эксплатацию: ";
	is >> start;
	if (start < year) throw exceptions("Год запуска в эксплатацию не может быть меньше года выпуска!");

	std::cout << "Введите тип топлива: ";
	is >> type;

	std::cout << "Введите кол-во пассажиров: ";
	is >> pass;
	if (pass < 0) throw exceptions("Кол-во пассажиров не может быть отрицытельным!");

	std::cout << "Введите перевозимый вес(в тоннах): ";
	is >> weight;
	if (weight < 0) throw exceptions("Перевозимый вес не может быть отрицательным!");

	ptr =
		transport::builder()
		.color(color)
		.cost(cost)
		.capacity(capacity)
		.number(number)
		.year(year)
		.start(start)
		.type(type)
		.pass(pass)
		.weight(weight)
		.build();

	move(trt, *ptr);

	return is;
}
std::ostream& operator<<(std::ostream &os, const transport &trt) {
	int width_one = 28;
	int width_two = 15;


	os.width(width_one);
	os << "Цвет: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.color;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Цена(в млн. рублях): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.cost;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "Объем двигателя(в литр.): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.capacity;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Номер маршрута: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.number;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "Год выпуска: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.year;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Год введения в эксплатацию: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.start;
	os.unsetf(std::ios::left);
	os << std::endl;


	os.width(width_one);
	os << "Тип топлива: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.type;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Число пассажиров: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.pass;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << std::endl;

	os << "Перевозимый вес(тонны): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << trt.weight;
	os.unsetf(std::ios::left);
	os << std::endl;

	os << std::endl;

	return os;
}

std::ifstream& operator>>(std::ifstream &ifs, transport &trt) {

	transport *ptr;

	string
		color,
		number,
		type;
	int
		year,
		start,
		pass;
	double
		cost,
		capacity,
		weight;

	color = get_string(ifs, ';');
	number = get_string(ifs, ';');
	type = get_string(ifs, ';');

	year = get_dec_int(ifs, ';');
	start = get_dec_int(ifs, ';');
	pass = get_dec_int(ifs, ';');

	cost = get_dec_db(ifs, ';');
	capacity = get_dec_db(ifs, ';');
	weight = get_dec_db(ifs, ';');

	ptr =
		transport::builder()
		.color(color)
		.cost(cost)
		.capacity(capacity)
		.number(number)
		.start(start)
		.type(type)
		.pass(pass)
		.weight(weight)
		.year(year)
		.build();

	move(trt, *ptr);

	return ifs;
}
std::ofstream& operator<<(std::ofstream &ofs, const transport &trt) {
	int width_one = 28;
	int width_two = 15;


	ofs.width(width_one);
	ofs << "Цвет: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.color;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Цена(в млн. рублях): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.cost;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs.width(width_one);
	ofs << "Объем двигателя(в литр.): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.capacity;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Номер маршрута: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.number;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs.width(width_one);
	ofs << "Год выпуска: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.year;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Год введения в эксплатацию: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.start;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;


	ofs.width(width_one);
	ofs << "Тип топлива: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.type;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Число пассажиров: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.pass;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << std::endl;

	ofs << "Перевозимый вес(тонны): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << trt.weight;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs << std::endl;

	return ofs;
}

void transport::save(std::ofstream &ofs) {
	ofs << color << ';';
	ofs << number << ';';
	ofs << type << ';';
	ofs << year << ';';
	ofs << start << ';';
	ofs << pass << ';';
	ofs << cost << ';';
	ofs << capacity << ';';
	ofs << weight << ';';
}

void move(transport &trt1, transport &trt2) {
	if (&trt1 != &trt2) {

		trt1.color = move(trt2.color);
		trt1.cost = trt2.cost;
		trt1.capacity = trt2.capacity;
		trt1.number = move(trt2.number);
		trt1.year = trt2.year;
		trt1.start = trt2.start;
		trt1.type = move(trt2.type);
		trt1.pass = trt2.pass;
		trt1.weight = trt2.weight;
	}
}

const std::string& transport::getColor() const {
	return color;
}
double transport::getCost() const {
	return cost;
}
double transport::getCapacity() const {
	return capacity;
}
const std::string& transport::getNumber() const {
	return number;
}
int transport::getYear() const {
	return year;
}
int transport::getStart() const {
	return start;
}
const std::string& transport::getType() const {
	return type;
}
int transport::getPass() const {
	return pass;
}
double transport::getWeight() const {
	return weight;
}


transportBuilder transport::builder() {
	return transportBuilder();
}
transportBuilder::transportBuilder() {
	trt = new transport();
}
transportBuilder& transportBuilder::color(const std::string& color) {
	trt->color = color;
	return *this;
}
transportBuilder& transportBuilder::cost(double cost) {
	trt->cost = cost;
	return *this;
}
transportBuilder& transportBuilder::capacity(double capacity) {
	trt->capacity = capacity;
	return *this;
}
transportBuilder& transportBuilder::number(const std::string& number) {
	trt->number = number;
	return *this;
}
transportBuilder& transportBuilder::year(int year) {
	trt->year = year;
	return *this;
}
transportBuilder& transportBuilder::start(int start) {
	trt->start = start;
	return *this;
}
transportBuilder& transportBuilder::type(const std::string& type) {
	trt->type = type;
	return *this;
}
transportBuilder& transportBuilder::pass(int pass) {
	trt->pass = pass;
	return *this;
}
transportBuilder& transportBuilder::weight(double weight) {
	trt->weight = weight;
	return *this;
}
transport* transportBuilder::build() {
	return trt;
}