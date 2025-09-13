#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr t;
  t.push_back("7");
  t.push_front("8");
  t.push_back("3");
  cout << t.get(0) << " " << t.get(1) << " " << t.get(2) << endl;
  cout << t.size() << endl;
  t.pop_back();
  cout << t.back() <<endl;
  t.pop_front();
  cout << t.front() << endl;
  t.pop_back();
  cout << t.size() << endl;
  return 0;
}
