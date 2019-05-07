#include "FFun.h"
#include <stdlib.h>




int get_dec_int(std::ifstream &ifs, char sep) {
	string tmp;
	for (char c; (c = ifs.get()) != sep; tmp += c);
	return atoi(tmp.c_str());
}
double get_dec_db(std::ifstream &ifs, char sep) {
	string tmp;
	for (char c; (c = ifs.get()) != sep; tmp += c);
	return atof(tmp.c_str());
}
string get_string(std::ifstream &ifs, char sep) {
	string tmp;
	for (char c; (c = ifs.get()) != sep; tmp += c);
	return tmp;
}
