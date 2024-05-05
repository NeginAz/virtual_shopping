#include <iostream>
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

Person :: Person(string f_name, string l_name, string user, string phone, int money_s, int flag_s)
{
  first_name=f_name;
  last_name=l_name;
  username=user;
  phone_number=phone;
  money=money_s;
  flag=flag_s;
}

string Person ::  get_username()
{
  return username;
}

int Person :: get_buyer_seller()
{
  return flag;
}

string Person :: get_first_name()
{
  return first_name;
}

string Person :: get_last_name()
{
  return last_name;
}

string Person :: get_phone_number()
{
  return phone_number;
}

int Person :: get_money()
{
  return money;
}
void Person :: add_money(int x)
{
  money=money+x;
}
void Person :: set_buyer_seller()
{
  flag=2;
}
