
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
  Person(string f_name, string l_name, string user, string phone, int money_s, int flag_s);
  string get_username();
  int get_buyer_seller();
  void set_buyer_seller();
  void add_money(int x);
private:
  string first_name;
  string last_name;
  string username;
  string phone_number;
  int money;
  int flag;
  int get_money();
  string get_phone_number();
  string get_last_name();
  string get_first_name();
};
#endif
