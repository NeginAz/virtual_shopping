#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Goods.h"
#include"Factor.h"
#include"Request.h"

using namespace std;

class Shop
{
public:
  void add_user(string f_name, string l_name, string user, string phone, int money_s, int flag_s);
  void add_goods(string username, string sgoods_name, int sgoods_price, int sgoods_count);
  void search_goods(string goods_name, int number);
  int find_min_goods(vector <int> show_goods,int index,int number);
  void sale(string buyer_username, string goods_name, string seller_username);
  void special(string seller_username, string goods_name, int goods_count);
  void remove_special(string seller_username, string goods_name, int goods_count);
  void add_sale();
  void add_money(string username,int money);
  int buy(int index,string seller_username, string goods_name, int goods_count);
  int new_factor(string buyer_username);
  void  add_to_factor(int index,Goods* goods, int goods_count);
  void  add_bestseller();
  int search_persons(string username,int flag_s);
  int is_seller(string username);
  int is_buyer(string user);
  void search_sale();
  void add_goods_to_request(string req_name, string goods_name, int goods_count , string seller_username);
  void new_request(string req_name, string buyer_username);
  void print_request(string buyer_username);
  void print_factor(int index);
  int get_index_factor(string buyer_username);
  void check_request();
  int benefit(int price, int shop_money, int count);
  int find_min(vector <int> show_goods,int index,int number);
  void print_factor(string buyer_username);
private:
  vector < Person*>persons;
  vector < Goods*>goods;
  vector <Factor*>factors;
  vector <Request*> requests;
  int shop_money;
};
#endif
