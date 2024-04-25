#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
using namespace std;

class Goods
{
public:
  Goods(Person* sperson, string sgoods_name, int sgoods_price, int sgoods_count);
  string get_goods_name();
  int get_goods_count();
  string get_goods_username();
  int get_goods_price();
  void request_sale(string buyer);
  void change_price(int percentage);
  void change_count(int number);
  Person* get_person_pointer();
  void set_special_tag(int a);
  int get_special_tag();
  int get_best_seller_tag();
  void set_best_seller_tag(int x);
private:
  Person* seller;
  string goods_name;
  int goods_price;
  int goods_count;
  int special; //0: addi 1:kalaye vije 2:takhfif a0 ta  3:30 ta mojood
  int best_seller_tag;
  vector <string> count_sale;
};
#endif
