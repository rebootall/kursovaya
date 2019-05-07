#include "exceptions.h"

using std::string;

exceptions::exceptions(const string &s) {
	mesg = s;
}
exceptions::exceptions(string &&s) {
	mesg = std::move(s);
}
exceptions::exceptions(const exceptions &e) {
	mesg = e.mesg;
}
exceptions::exceptions(exceptions &&e) {
	mesg = std::move(e.mesg);
}
const string& exceptions::what() {
	return mesg;
}
