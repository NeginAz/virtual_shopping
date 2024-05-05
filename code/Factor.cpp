#include <iostream>
#include <vector>
#include <string>
#include "Factor.h"


using namespace std;

 Factor :: Factor(Person* nbuyer)
 {
   buyer=nbuyer;
 }
void Factor :: add_goods_to_factor(Goods* newgoods)
{
  goods.push_back(newgoods->get_goods_name());
  seller.push_back(newgoods->get_goods_username());
  price.push_back(newgoods->get_goods_price());
}
void Factor :: add_number(int num)
{
  number.push_back(num);
}
string Factor :: get_buyer_username()
{
  return buyer->get_username();
}
 string Factor :: factor_get_goods(int i)
{return goods[i];}
int Factor :: factor_get_goods_count(int i)
{return number[i];}
string Factor :: factor_get_goods_seller(int i)
{return seller[i];}
int Factor :: factor_size()
{return goods.size();}
int Factor :: factor_get_goods_price(int i)
{return price[i];}
