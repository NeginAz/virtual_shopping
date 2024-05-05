#ifndef FACTOR_H
#define FACTOR_H
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include"Goods.h"


using namespace std;

class Factor
{
public:
  Factor(Person* nbuyer);
  void add_goods_to_factor(Goods* newgoods);
  string get_buyer_username();
  void  add_number(int num);
  string factor_get_goods(int i);
  int factor_get_goods_count(int i);
  string factor_get_goods_seller(int i);
  int factor_get_goods_price(int i);
  int factor_size();
private:
  Person* buyer;
  //vector<Goods*> goods;
  vector<string> goods;
  vector<string> seller;
  vector<int>number;
  vector<int>price;
};
#endif
