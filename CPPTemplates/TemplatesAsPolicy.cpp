#include "TemplatesAsPolicy.h"
#include <string>

class CaseSenCmp {
public:
	static int isEqual(char x, char y) {
		return x == y;
	}
};

class NonCaseSenCmp {
public:
	static int isEqual(const char x, const char y) {		
		return toupper(x) == toupper(y);
	}
};

template<typename C = CaseSenCmp>
int compare(const char* s1, const char* s2) {
	for(int i=0; i<strlen(s1) && i<strlen(s2); i++) {				
		if (!C::isEqual(s1[i], s2[i])) { // No intellisense will be provided here, as in C#
			return s1[i] - s2[i];
		}
	}

	return strlen(s1) - strlen(s2);
}

TemplatesAsPolicy::TemplatesAsPolicy() {
	int i, j;
	const char* x = "hello", * y = "HELLO";
	i = compare(x, y);
	j = compare<NonCaseSenCmp>(x, y);
	cout << "Case Sensitive: " << i;
	cout << "\nNon-Case Sensitive: " << j << endl;
}