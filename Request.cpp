#include <iostream>
#include <vector>
#include <string>
#include"Request.h"

using namespace std;


Request:: Request(string nreq_name, Person* nbuyer)
{
  buyer=nbuyer;
  req_name=nreq_name;
}
void Request:: add_request(string goods_name, int goods_count, string seller_username)
{
  goods_names.push_back(goods_name);
  goods_counts.push_back(goods_count);
  seller_usernames.push_back(seller_username);
}
string Request::  get_request_name()
{return req_name;}
string Request :: get_req_buyer()
{
  return buyer->get_username();
}
int Request :: get_request_length()
{return goods_names.size();}
string Request :: get_req_goods(int i)
{return goods_names[i];}
int Request :: get_req_count(int i)
{return goods_counts[i] ;}
string Request :: get_req_seller(int i)
{return seller_usernames[i];}
