#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstdlib>
#include "Person.h"
#include "Goods.h"
#include "Shop.h"
#include"Factor.h"
#include"Request.h"

using namespace std;

const int Buyer=1;
const int Seller=0;

void print_error()
{
  cout<<"Command Failed"<<endl;
}
void add_user(vector<string> commands , Shop* eshop)
{
  int flag;
  string first_name=commands[1];
  string last_name=commands[2];
  string username=commands[3];
  string phone_number=commands[4];
  int money=atoi( commands[5].c_str());
  if(commands[6]=="buyer")
    flag=Buyer;
  else
    flag=Seller;
  eshop -> add_user(first_name,last_name,username,phone_number,money,flag);
}
void add_goods(vector<string> commands , Shop* eshop)
{
  string username=commands[1];
  string goods_name=commands[2];
  int  goods_price=atoi(commands[3].c_str());
  int goods_count=atoi( commands[4].c_str());
  eshop->add_goods(username,goods_name,goods_price,goods_count);
  eshop->check_request();
}
void search(vector<string> commands , Shop* eshop)
{
    string goods_name=commands[1];
    int number=atoi( commands[2].c_str());
    eshop->search_goods(goods_name,number);
}
void buy(vector<string> commands , Shop* eshop)
{
  int d;
  string strr;
  vector <string> commands1;
  int breakk1,breakk;
  string word1;
  string buyer_username=commands[1];
  int index=eshop->new_factor(buyer_username);
  if(index!=-1)
  {string goods_name=commands[2];
  int goods_count=atoi(commands[3].c_str());
  string seller_username=commands[4];
  d=seller_username.length()-1;
  if(seller_username[d]==';')
    {breakk=1;}
  else
    breakk=0;
  seller_username=seller_username.substr(0,d);
  int count=eshop->buy(index,seller_username, goods_name, goods_count);
 if(breakk==0)
  {
    while(getline(cin,strr) && strr.size() > 0)
    {
      istringstream iss(strr);
      while(iss >> word1)
    {
      commands1.push_back(word1);
    }
    string goods_name1=commands1[0];
    int goods_count1=atoi(commands1[1].c_str());
    string seller_username1=commands1[2];
    int d=seller_username1.length()-1;
    if(seller_username1[d]==';')
      {breakk1=1;}
    else
      breakk1=0;
    seller_username1=seller_username1.substr(0,d);
    int count=eshop->buy(index,seller_username1, goods_name1, goods_count1);
    commands1.clear();
    if(breakk1==1)
      break;
}
}}
eshop->print_factor(index);
}

void sale(vector<string> commands , Shop* eshop)
{
  string buyer_username=commands[1];
  string goods_name=commands[2];
  string seller_username=commands[3];
  eshop->sale(buyer_username,goods_name,seller_username);
}
void add_special(vector<string> commands , Shop* eshop)
{
  string seller_username=commands[1];
  string goods_name=commands[2];
  int goods_count=atoi(commands[3].c_str());
  eshop->special(seller_username,goods_name,goods_count);
}
void remove_special(vector<string> commands , Shop* eshop)
{
  string seller_username=commands[1];
  string goods_name=commands[2];
  int goods_count=atoi(commands[3].c_str());
  eshop->remove_special(seller_username,goods_name,goods_count);
}
void add_money(vector<string> commands , Shop* eshop)
{
  string username=commands[1];
  int money=atoi(commands[2].c_str());
  eshop->add_money(username,money);
}
void request(vector<string> commands , Shop* eshop)
{
  int d;
  string strr;
  vector <string> commands1;
  int breakk1,breakk;
  string word1;
  string req_name=commands[1];
  string buyer_username=commands[2];
  eshop->new_request(req_name,buyer_username);
  string goods_name=commands[3];
  int goods_count=atoi(commands[4].c_str());
  string seller_username=commands[5];
  d=seller_username.length()-1;
  if(seller_username[d]==';')
    {breakk=1;}
  else
    breakk=0;
  seller_username=seller_username.substr(0,d);
  eshop->add_goods_to_request(req_name,goods_name,goods_count ,seller_username);
 if(breakk==0)
  {
    while(getline(cin,strr) && strr.size() > 0)
    {
      istringstream iss(strr);
      cout<<"St"<<strr<<endl;
      while(iss >> word1)
    {
      commands1.push_back(word1);
    }
    string goods_name1=commands1[0];
    int goods_count1=atoi(commands1[1].c_str());
    string seller_username1=commands1[2];
    int d=seller_username1.length()-1;
    if(seller_username1[d]==';')
      {breakk1=1;}
    else
      breakk1=0;
    seller_username1=seller_username1.substr(0,d);
    eshop->add_goods_to_request(req_name,goods_name,goods_count,seller_username);
    commands1.clear();
    if(breakk1==1)
      break;
}
}
}
void print_req(vector<string> commands , Shop* eshop)
{
  string buyer_username=commands[1];
  eshop->print_request(buyer_username);
}
void print_fac(vector<string> commands , Shop* eshop)
{
  string buyer_username=commands[1];
  eshop->print_factor(buyer_username);
}
int main()
{
    vector <string> commands;
    int breakk;
    int breakk1;
    string str;
    Shop* shop;
    string strr;
    string word,word1;
    Shop* eshop=new Shop;
    while(getline(cin,str) && str.size() > 0)
    {
      istringstream iss(str);
      while(iss >> word)
    {
      commands.push_back(word);
    }

  if(commands[0] == "add_user")
    {
      if(commands.size() != 7)
        {
          print_error();
         }
        else if(commands.size()==7)
        {
          add_user(commands, eshop);
        }
      }
    else if(commands[0] == "add_goods")
    {
      if(commands.size() != 5)
        {
          print_error();
         }
        else if(commands.size()==5)
        {
          add_goods(commands ,eshop);
        }
      }
    else if(commands[0] == "search")
    {
      if(commands.size() != 3)
        {
          print_error();
         }
      else if(commands.size()==3)
      {search(commands ,eshop);}

    }
    else if(commands[0] == "buy")
    {
      if(commands.size() != 5)
        {
          print_error();
         }
      else if(commands.size()==5)
        {buy(commands ,eshop);
  }}
  else if(commands[0]=="sale")
  {
    if(commands.size() != 4)
      {
        print_error();
       }
      else if(commands.size()==4)
      {sale(commands,eshop);}
}
  else if(commands[0]=="add_special")
  {
    if(commands.size() != 4)
      {
        print_error();
       }
      else if(commands.size()==4)
      {
        add_special(commands,eshop);
      }
  }
  else if(commands[0]=="remove_special")
  {
    if(commands.size() != 4)
      {
        print_error();
       }
      else if(commands.size()==4)
      {
        remove_special(commands,eshop);
      }
  }
/*else if(commands[0]=="search_sale")
{
  //eshop->search_sale();
}*/
else if(commands[0] == "add_money")
{
  if(commands.size()!= 3)
    {
      print_error();
     }
    else if(commands.size()==3)
    {
      add_money(commands,eshop);
    }
}
else if(commands[0] == "request")
{
  if(commands.size() != 6)
    {
      print_error();
     }
  else if(commands.size()==6)
    {
      request(commands ,eshop);
}
}
else if(commands[0] == "print_request")
{
  if(commands.size() != 2)
    {
      print_error();
     }
  else if(commands.size()==2)
    {print_req(commands,eshop);
}
}
else if(commands[0] == "print_factor")
{
  if(commands.size() != 2)
    {
      print_error();
     }
  else if(commands.size()==2)
    {print_fac(commands,eshop);
}
}
commands.clear();
}
  return 0;
}
