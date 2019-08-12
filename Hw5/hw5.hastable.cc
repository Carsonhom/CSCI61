#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TABLE_SIZE 16

struct Student {
  string name;
  int score;
};

class Hashtable {
public:
  Hashtable() {};

  // (a) [20 points]
  // Hash function from string to int. Sum the ASCII values of all the
  // characters in the string, and return (Sum % TABLE_SIZE).
  int Hash(string s) {
    int sum = 0;
    for(int i = 0; i < s.length(); ++i)
    {
      sum += s[i];
    }
    sum = sum % TABLE_SIZE;
    return sum; 
  };

  // (b) [20 points]
  // Insert Student s into the Hashtable. First find the key using Hash of the
  // Student's name, and then insert it into the vector at that entry.
  void Insert(Student s) {
    int ind = Hash(s.name);
    data[ind] = new Student;
    return;

    // int ind = Hash(s.name);
    // while(true)
    // {
    //   if(data[ind] == nullptr)
    //   {
    //     data[ind] = s;
    //     return;
    //   }
    //   else
    //   {
    //     ind++;
    //     if(ind >= TABLE_SIZE)
    //     {
    //       ind = 0;
    //     }
    //   }
    // }
  };

  // (c) [30 points]
  // Find Student with the given name. If found, return pointer to the Student.
  // If not found, return nullptr.
  Student* Find(string name) {
    int ind = Hash(name);
    int ntries = 0;
    while(true)
    {
      if(data[ind].name == name)
      {
        return data[ind];
      }
      else
      {
        ind++;
        if(ind >= TABLE_SIZE)
        {
          ind = 0;
        }
        ntries++;
        if(ntries >= TABLE_SIZE) 
        {
          return nullptr;
        }
      }
    }
  };

  // (d) [30 points]
  // Print all entries in the Hashtable. For each entry, print the key,
  // the number of Students stored at that entry, and all the Students
  // (name,score) in the entry.
  void Print(){

  };

private:
  vector<Student> data[TABLE_SIZE];
};

int main() {

  string names[] = { "Alice", "Bob", "Carrie", "Diane", "Ethan", "Frank",
		     "George", "Henry", "Irene", "Joseph", "Kristy", "Liam",
		     "Monica", "Nancy" };

  Hashtable t;
  for (int i = 0; i < 14; i++) {
    Student s = { names[i], rand() % 100 };
    t.Insert(s);
  }
  t.Print();
  cout << endl;

  cout << "Give Diane 10 more points." << endl;
  Student* sptr = t.Find("Diane");
  if (sptr != nullptr) {
    sptr->score = sptr->score + 10;
  }
  t.Print();
  cout << endl;

  sptr = t.Find("Tom");
  if (sptr == nullptr) {
    cout << "Tom not found" << endl;
  } else {
    cout << "Tom found. Score is: " << sptr->score << endl;
  }
  
  return 0;
}

/*
Sample results:

Entry 0 size 1 Ethan,0
Entry 1 size 1 Diane,29
Entry 2 size 1 Frank,8
Entry 3 size 3 Bob,43 Irene,56 Liam,51
Entry 4 size 0
Entry 5 size 0
Entry 6 size 3 Carrie,62 Henry,56 Kristy,11
Entry 7 size 1 Monica,43
Entry 8 size 0
Entry 9 size 3 George,52 Joseph,19 Nancy,5
Entry 10 size 0
Entry 11 size 0
Entry 12 size 0
Entry 13 size 0
Entry 14 size 1 Alice,33
Entry 15 size 0

Give Diane 10 more points.
Entry 0 size 1 Ethan,0
Entry 1 size 1 Diane,39
Entry 2 size 1 Frank,8
Entry 3 size 3 Bob,43 Irene,56 Liam,51
Entry 4 size 0
Entry 5 size 0
Entry 6 size 3 Carrie,62 Henry,56 Kristy,11
Entry 7 size 1 Monica,43
Entry 8 size 0
Entry 9 size 3 George,52 Joseph,19 Nancy,5
Entry 10 size 0
Entry 11 size 0
Entry 12 size 0
Entry 13 size 0
Entry 14 size 1 Alice,33
Entry 15 size 0

Tom not found
*/
