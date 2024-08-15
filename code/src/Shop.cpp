#include <iostream>
#include <vector>
#include <string>
#include "Shop.h"

using namespace std;

int Shop :: search_persons(string username,int flag_s)
{
  for(int i=0;i<persons.size();i++)
    {
      if(persons[i] -> get_username() == username && (persons[i]-> get_buyer_seller() == flag_s || persons[i]-> get_buyer_seller()==2))
      {
          cout<<"Command Failed"<<endl;
          return -1;
        }
        else if (persons[i] -> get_username() == username && persons[i]-> get_buyer_seller() != flag_s)
          {persons[i]->set_buyer_seller();
          cout<<"Command Ok"<<endl;
          return -1;}
      }
  return 1;
}
int Shop :: is_seller(string user)
{
  for(int i=0;i < persons.size();i++)
  {
    if(persons[i] -> get_username()==user&& (persons[i] -> get_buyer_seller()==0 || persons[i] -> get_buyer_seller()==2))
      {
        return i;
      }
  }
    cout<<"Command Failed"<<endl;
    return -1;
}
int Shop :: is_buyer(string user)
{
  for(int i=0;i < persons.size();i++)
  {
    if(persons[i] -> get_username()==user&& (persons[i] -> get_buyer_seller()==1 || persons[i] -> get_buyer_seller()==2))
      {
        return i;
      }
  }
    cout<<"Command Failed"<<endl;
    return -1;
}
void Shop :: add_user(string f_name, string l_name, string user, string phone, int money_s, int flag_s)
{
  int x=search_persons(user, flag_s);
  if(x==1)
  {
  Person* p=new Person(f_name, l_name, user, phone, money_s, flag_s);
  persons.push_back(p);
  cout<<"Command Ok"<<endl;
}
}
void Shop :: add_goods(string username, string sgoods_name, int  sgoods_price, int sgoods_count)
{
    int i=is_seller(username);
    if(i!=-1)
    {
      Goods* good=new Goods(persons[i], sgoods_name, sgoods_price, sgoods_count);
    goods.push_back(good);
    cout<<"Command Ok"<<endl;
    return;
    }
}
int Shop :: find_min_goods(vector <int> show_goods,int index,int number)
{
  int count_min=goods[show_goods[index]]-> get_goods_count();
  int index_min=index;
  for(int i=index ; i < show_goods.size() ; i++)
  {
    if(goods[show_goods[i]] -> get_goods_count() < count_min)
    {
      index_min=i;
      count_min=goods[show_goods[i]] -> get_goods_count();
    }
    else if(goods[show_goods[i]] -> get_goods_count() == count_min)
    {
      if(goods[show_goods[i]]-> get_goods_price () < goods[show_goods[index_min]]-> get_goods_price())
      {
        index_min=i;
        count_min=goods[show_goods[i]] -> get_goods_count();
      }
      else if(goods[show_goods[i]]-> get_goods_price () == goods[show_goods[index_min]]-> get_goods_price())
      {
         if(goods[show_goods[i]]-> get_goods_username () <=  goods[show_goods[index_min]]->get_goods_username())

              {
                index_min=i;
                count_min=goods[show_goods[i]] -> get_goods_count();
              }
      }
    }
  }
  return index_min;
}

void Shop :: search_goods(string goods_name, int number)
{
  vector <int> show_goods;
  int ind;
  int temp;
  for(int i=0; i < goods.size() ; i++)
  {
    if(goods[i] -> get_goods_name() == goods_name &&  goods[i] -> get_goods_count() >= number )
    {
      show_goods.push_back(i);
    }
}
for (int i=0 ; i< show_goods.size() ; i++)
{
  ind=find_min_goods(show_goods,i,number);
  temp=show_goods[i];
  show_goods[i]=show_goods[ind];
  show_goods[ind]=temp;
  cout<<i<<". "<<goods[show_goods[i]] -> get_goods_name()<<" "<<goods[show_goods[i]] -> get_goods_count()<<" "<<goods[show_goods[i]] -> get_goods_price()<<" "<<goods[show_goods[i]] -> get_goods_username()<<endl;
}
}

void  Shop :: sale(string buyer_username, string goods_name, string seller_username)
{
      int index=is_buyer(buyer_username);
      if(index!=-1)
    {  for(int j=0; j< goods.size(); j++)
          {
            if(goods[j]-> get_goods_name() == goods_name && goods[j]-> get_goods_username() == seller_username)
                {
                  goods[j]->request_sale(buyer_username);
                  return ;
                }
          }
      }
      else
        return;
    cout<<"Command Failed"<<endl;
}

void Shop :: special(string seller_username, string goods_name, int goods_count)
{
  int index=is_seller(seller_username);
  if(index==-1)
  {return ;}
  else{
  for(int i=0;i < goods.size() ;i++)
  {
    if(goods[i] -> get_goods_name() == goods_name && goods[i] -> get_goods_username() == seller_username && goods_count <=goods[i] -> get_goods_count() )
    {
      goods[i]->change_count(goods_count);
      Goods* good=new Goods(goods[i]->get_person_pointer(), goods_name, 0.9*goods[i]->get_goods_price() ,goods_count);
      good->set_special_tag(1);
      goods.push_back(good);
      return;
    }
  }
  cout<<"Command Failed"<<endl;
  return;
  }
}
void Shop:: remove_special(string seller_username, string goods_name, int goods_count)
{
  int index=is_seller(seller_username);
  if(index==-1)
  {return;}
  index=-1;
  for(int i=0;i < goods.size() ;i++)
  {
    if(goods[i] -> get_goods_name() == goods_name && goods[i] -> get_goods_username() == seller_username && goods_count <=goods[i] -> get_goods_count() )
    {  index=i;
      if(goods[i]-> get_special_tag() ==1)
        goods[i] -> change_count(goods_count);
      else
        goods[i] -> change_count(-1*goods_count);
    }
  }
    if(index==-1)
    {cout<<"Command Failed"<<endl;}
    else
    {cout<<"Command Ok"<<endl;}

return ;
}
void  Shop :: add_sale()
{
  for(int i=0; i< goods.size() ;i++)
  {
    if(goods[i] -> get_goods_count() >= 30 && goods[i]->get_special_tag() !=2 )
    {
      goods[i]->change_price(10);
    }
    else if(goods[i] -> get_goods_count() < 30 && goods[i]->get_special_tag() ==2)
      goods[i]->change_price(-10);
  }
}
void Shop :: add_money(string username,int money)
{
  for(int i=0 ; i < persons.size() ; i++)
  {
    if(persons[i]->get_username()== username)
      {
        persons[i]->add_money(money);
        cout<<"Command Ok"<<endl;
        return;
    }
  }
cout<<"Command Failed"<<endl;
}

int Shop :: buy(int index,string seller_username, string goods_name, int goods_count)
{
  int special=1;
  int count=goods_count;
  while(count > 0)
{
  for(int i=0 ; i < goods.size() ; i++)
  {
    if(goods[i]-> get_goods_username() == seller_username && goods[i]-> get_goods_name() == goods_name && goods[i]->get_special_tag()==special )
    {
      if(goods[i]->get_goods_count()  >=  count)
        {
          goods[i]->change_count(count);
          add_to_factor(index,goods[i],count);
          count=0;
      }
      else if(goods[i]->get_goods_count()>0)
        {
          count=goods_count - goods[i]->get_goods_count();
          add_to_factor(index,goods[i],goods[i]->get_goods_count());
          goods[i]->change_count(goods[i]->get_goods_count());
        }
      }
    }
    special++;
    if(special ==3)
      special=0;
    if(special=0 && count >0 )
        cout<<"Command Failed"<<endl;
  }

}
int Shop :: new_factor(string buyer_username)
{
  int i=is_buyer(buyer_username);
  if(i!=-1)
    {
      Factor* n = new Factor (persons[i]);
    factors.push_back(n);
    return factors.size()-1;
  }
  else
   {
     cout<<"Command Failed"<<endl;
     return -1;
   }
  }

void Shop ::  add_to_factor(int index,Goods* goods, int goods_count)
{
            factors[index]->add_goods_to_factor(goods);
            factors[index]->add_number(goods_count);

}
/*void Shop :: add_bestseller()
{
  int count;
  for(int i=0 ; i < goods.size() ; i++)
  { count=0;
    for(int j=0;j<factors.size(); j++)
    {
      for(int k=0;k< (factors[j]-> get_goods().size());k++)
      {
        if(goods[i]-> get_goods_name () == (factors[j]-> get_goods())[k]->get_goods_name () && goods[i]-> get_goods_username () == (factors[j]-> get_goods())[k]->get_goods_username () )
          count++;
      }
      if(count >10 )
        goods[i]->set_best_seller_tag(1);

    }
  }
}*/
/*void Shop :: search_sale()
{
  vector <int> show_goods;
  int ind;
  int temp;
  for(int i=0; i < goods.size() ; i++)
  {
    if(goods[i] -> get_special_tag() !=0 )
    {
      show_goods.push_back(i);
    }
}
for (int i=0 ; i< show_goods.size() ; i++)
{
  ind=find_min(show_goods,i,number);
  temp=show_goods[i];
  show_goods[i]=show_goods[ind];
  show_goods[ind]=temp;
  cout<<i<<". "<<goods[show_goods[i]] -> get_goods_name()<<" "<<goods[show_goods[i]] -> get_goods_count()<<" "<<goods[show_goods[i]] -> get_goods_price()<<" "<<goods[show_goods[i]] -> get_goods_username()<<endl;
}
}
}*/
void Shop :: new_request(string req_name, string buyer_username)
{
  int index=is_buyer(buyer_username);
  if(index!=-1)
  {
  for(int i=0; i < requests.size() ; i++)
  {
    if(req_name == requests[i]->get_request_name())
      {cout<<"Command Failed"<<endl;
      return;}
  }
 }
  Request* req=new Request(req_name,persons[index]);
  requests.push_back(req);
  cout<<"Command Ok"<<endl;
}


void Shop :: add_goods_to_request(string req_name, string goods_name, int goods_count , string seller_username)
{
  int index=-1;
  for(int i=0; i < requests.size() ; i++)
  {
    if(req_name == requests[i]->get_request_name())
      {
        index=i;
    }
  }
  if(index==-1)
    cout<<"Command Failed"<<endl;
  else
    {
      requests[index]->add_request(goods_name,goods_count,seller_username);}
}


void Shop :: print_factor(int index)
{
  for(int i=0;i < (factors[index]->factor_size());i++)
  {
     cout<<factors[index]->factor_get_goods_count(i)<<" ";
     cout<<factors[index]->factor_get_goods_seller(i)<<" ";
    cout<< factors[index]->factor_get_goods_price(i)<<endl;
  }
}
void Shop :: print_request(string buyer_username)
{
  int index=is_buyer(buyer_username);
  for(int i=0; i < requests.size() ; i++)
  {
    if(requests[i]->get_req_buyer() == buyer_username)
    {
      for(int j=0;j< (requests[i]->get_request_length()); j++)
      {
        cout<<j+1<<requests[i]->get_req_goods(j)<<requests[i]->get_req_count(j)<<requests[i]->get_req_seller(j)<<endl;
      }
    }
  }
}


int Shop :: benefit(int price, int shop_money, int count)
{
  int added=0.9*price+0.05*0.9*price;
  int subtr=price;
  if(shop_money >  count *(added -subtr))
    return 1;
  else
  return 0;
}

void Shop :: check_request()
{
  for(int i=0; i < requests.size(); i++)
  {
      for(int k=0; k < requests[i]->get_request_length();k++)
      {
        for(int j=0;j<goods.size();j++)
        {
          if(requests[i]-> get_req_goods(k) == goods[j]-> get_goods_name() && requests[i]->get_req_seller(k) == goods[j]->get_goods_username () && requests[i]-> get_req_count(k) < goods[j]->get_goods_count() )
            {
            int index=new_factor( requests[i]->get_req_buyer());
            buy(index,requests[i]->get_req_seller(k),goods[j]-> get_goods_name(),requests[i]-> get_req_count(k));
            print_factor(index);
            return;
        }
      }
  }
}
}
void Shop :: print_factor(string buyer_username)
{
  int index=is_buyer(buyer_username);
  for(int i=0; i < factors.size() ; i++)
  {
    if(factors[i]->get_buyer_username() == buyer_username)
    {
      for(int j=0;j< factors[i]->factor_size(); j++)
      {
        cout<<factors[i]-> factor_get_goods(j)<<factors[i]->factor_get_goods_count(j)<<factors[i]->factor_get_goods_seller(j)<<endl;
      }
    }
  }
}


/*int Shop :: find_min(vector <int> show_goods,int index,int number)
{
  string string_min=goods[show_goods[index]]-> get_goods_name();
  int index_min=index;
  for(int i=index ; i < show_goods.size() ; i++)
  {
    if(goods[show_goods[i]] -> get_goods_name() < string_min)
    {
      index_min=i;
      count_min=goods[show_goods[i]] -> get_goods_name();
    }
    else if(goods[show_goods[i]] -> get_goods_name() == string_min)
    {
      if(goods[show_goods[i]]-> get_goods_count () < goods[show_goods[index_min]]-> get_goods_count())
      {
        index_min=i;
        string_min=goods[show_goods[i]] -> get_goods_name();
      }
      else if(goods[show_goods[i]]-> get_goods_count () == goods[show_goods[index_min]]-> get_goods_count())
      {  if(goods[show_goods[i]]-> get_goods_price () < goods[show_goods[index_min]]-> get_goods_price())
        {
          index_min=i;
          string_min=goods[show_goods[i]] -> get_goods_name();
        }

      else if(goods[show_goods[i]]-> get_goods_price () == goods[show_goods[index_min]]-> get_goods_price())
      {
         if(goods[show_goods[i]]-> get_goods_username () <=  goods[show_goods[index_min]]->get_goods_username())

              {
                index_min=i;
                count_min=goods[show_goods[i]] -> get_goods_name();
              }
            }
      }
    }
  }
  return index_min;
*/
