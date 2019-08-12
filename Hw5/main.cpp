#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
  string name;
  int score;
};

class HashTable {
public:
	vector<Student> data(3, Student());
}

int main() {
	// vector<Student> data(3, Student());
	Student s = Student();
	s.name = "hi";
	s.score = 33;
	data[0] = s;
	cout << data[0].name << endl;
	return 0;
}