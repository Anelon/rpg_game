#include <iostream>
#include <string>
using namespace std;

int main() {
	string test = "test";
	const char* testptr= test.c_str();
	cout << testptr << endl;
	return 0;
}
