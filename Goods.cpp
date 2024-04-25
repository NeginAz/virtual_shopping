#include <iostream>
#include <vector>
#include <string>
#include "Goods.h"


using namespace std;

Goods :: Goods (Person* sperson, string sgoods_name, int sgoods_price, int sgoods_count)
{
    seller=sperson;
    goods_name=sgoods_name;
    goods_price=sgoods_price;
    goods_count=sgoods_count;
    best_seller_tag=0;
}
string Goods :: get_goods_name()
{
  return goods_name;
}
int Goods :: get_goods_count()
{
  return goods_count;
}
string Goods :: get_goods_username()
{
  return seller -> get_username();
}
int Goods :: get_goods_price()
{
  return goods_price;
}
void Goods :: request_sale(string buyer)
{
  for(int i=0; i< count_sale.size();i++)
  {
    if(count_sale[i]==buyer)
      {cout<<"Command Failed"<<endl;
      return;}
  }
  count_sale.push_back(buyer);
  if(count_sale.size()==1)
    goods_price=goods_price - 0.1*goods_price;
  cout<<"Command Ok"<<endl;
}
void Goods :: change_price(int percentage)
{
 goods_price=goods_price - percentage*goods_price/100;
}
void Goods :: change_count(int number)
{
  goods_count=goods_count - number;
}
Person* Goods :: get_person_pointer()
{return seller;}
int  Goods :: get_special_tag()
{return special;}
void Goods :: set_special_tag(int a)
{special=a;}
int Goods :: get_best_seller_tag()
{return  best_seller_tag;}
void Goods ::  set_best_seller_tag(int x)
{best_seller_tag=x;}
