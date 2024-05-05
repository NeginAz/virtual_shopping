#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

class Request
{
public:
  Request(string nreq_name, Person* nbuyer) ;
  void add_request(string goods_name, int goods_count, string seller_username);
  string get_request_name();
  string get_req_buyer();
  int get_request_length();
  string get_req_goods(int i);
  int get_req_count(int i);
  string get_req_seller(int i);
private:
  string req_name;
  Person* buyer;
  vector<string>goods_names;
  vector<int> goods_counts;
  vector<string> seller_usernames;
};
#endif
