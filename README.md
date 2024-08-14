# Virtual Store: 
This project is a C++ implementation of a virtual store with two types of users: sellers and buyers.

## Features:

### User Registration:
Users need to sign up by entering their first name, last name, username, phone number, initial money balance, and whether they are sellers or buyers.
```console
add_user first_name last_name username phone_number money seller/buyer
```
Output: command ok/command failed

### Adding Goods:
```console
add_goods seller_username goods_name goods_price goods_count
```
Output: command ok/command failed


### Searching Goods:
Users can search for goods in the shop.
```console
search goods_name goods_count
```

Output: number goods_name goods_count goods_price seller_username


### Buying Goods:
Users with the buyer tag can buy goods and offer prices.

```console
buy buyer_username goods_name goods_count seller_username goods_name goods_count seller_username
```
Output: command ok/command failed

### Special Offers:
Sellers can add or remove goods from the special offer list and offer a 10% discount.

```console
add_special seller_username goods_name goods_count
remove_special seller_username goods_name goods_count
```

### Searching Special Offers and Bestsellers:
Users can search for special offers and bestsellers.

```console
search_sale
search_bestseller
```
Output:
1. watch 5 5000 s_smith
2. watch 10 10000 a_smith


### Adding Money:
Users can add money to their account.
```console
add_money username money
```
Output: command ok/command failed


### Requesting Goods:
Buyers can request goods.
```console
request request_name buyer_name goods_name goods_count seller_username
```
Output: command ok/command failed


### Printing Factor:
After every sale, a factor (invoice) is printed.

```console
Factor number #n
buyer_first_name buyer_last_name buyer_username buyer_phone_number
#n goods_name goods_count goods_price seller_username sum
```

### Printing Requests:
All requests can be printed.
```console
print_request buyer_username
```

Output:
Request 1 request_name buyer_username
#n goods_name goods_count seller_username


### Printing Factors:
All factors can be printed.
```console
print_factor buyer_username
```
Output: 
Factor factor_number buyer_username
#n goods_name goods_count goods_price seller_username sum
Goods sum = sum of all items
Total sum = sum of all items + 5% sum of all items


### Classes:
This project consists of the following classes:

* Person (includes buyer and seller)
* Goods
* Factors
* Requests
* Shop (entails all other classes)

### Design: 

```mermaid
Factor : -Person* buyer
Factor : -vector<string> goods
Factor : -vector<string> seller
Factor : -vector<int>number
Factor : -vector<int>price

 Goods : -Person* seller
 Goods : -string goods_name
 Goods : -int goods_price
 Goods : -int goods_count
 Goods : -int special
 Goods : -int best_seller_tag
 Goods : - vector <string> count_sale

 Person: -string first_name
 Person: -string last_name
 Person: -string username
 Person: -string phone_number
 Person: -int money
 Person: -int flag
 Person: -int get_money()
 Person: -string get_phone_number()
 Person: -string get_last_name()
 Person: -string get_first_name()

 Request :-string req_name
 Request: -Person* buyer
 Request: -vector<string>goods_names
 Request: -vector<int> goods_counts
 Request: -vector<string> seller_usernames
 Shop: -vector < Person*>persons
 Shop: -vector < Goods*>goods
 Shop: -vector <Factor*>factors
 Shop: -vector <Request*> requests
 Shop: -int shop_money
class Request{
  +Request(string nreq_name, Person* nbuyer) 
  +void add_request(string goods_name, int goods_count, string seller_username)
  +string get_request_name()
  +string get_req_buyer()
  +int get_request_length()
  +string get_req_goods(int i)
  +int get_req_count(int i)
  +string get_req_seller(int i)
}

class Shop{
 -void add_user(string f_name, string l_name, string user, string phone, int money_s, int flag_s)
  -void add_goods(string username, string sgoods_name, int sgoods_price, int sgoods_count)
  -void search_goods(string goods_name, int number)
  -int find_min_goods(vector <int> show_goods,int index,int number)
  -void sale(string buyer_username, string goods_name, string seller_username)
  -void special(string seller_username, string goods_name, int goods_count)
  -void remove_special(string seller_username, string goods_name, int goods_count)
  -void add_sale()
  -void add_money(string username,int money)
  -int buy(int index,string seller_username, string goods_name, int goods_count)
  -int new_factor(string buyer_username)
  -void  add_to_factor(int index,Goods* goods, int goods_count)
  -void  add_bestseller()
  -int search_persons(string username,int flag_s)
  -int is_seller(string username)
  -int is_buyer(string user)
  -void search_sale()
  -void add_goods_to_request(string req_name, string goods_name, int goods_count , string seller_username)
  -void new_request(string req_name, string buyer_username)
  -void print_request(string buyer_username)
  -void print_factor(int index)
  -int get_index_factor(string buyer_username)
  -void check_request()
  -int benefit(int price, int shop_money, int count)
  -int find_min(vector <int> show_goods,int index,int number)
  -void print_factor(string buyer_username)
}

class Factor {
Factor(Person* nbuyer);
  +void add_goods_to_factor(Goods* newgoods)
  +string get_buyer_username()
  +void  add_number(int num)
  +string factor_get_goods(int i)
  +int factor_get_goods_count(int i)
  +string factor_get_goods_seller(int i)
  +int factor_get_goods_price(int i)
  +int factor_size()
}

class Person{
  +Person(string f_name, string l_name, string user, string phone, int money_s, int flag_s)
  +string get_username()
  +int get_buyer_seller()
  +void set_buyer_seller()
  +void add_money(int x)
}


class Goods{
  +Goods(Person* sperson, string sgoods_name, int sgoods_price, int sgoods_count)
  +string get_goods_name()
  +int get_goods_count()
  +string get_goods_username()
  +int get_goods_price()
  +void request_sale(string buyer)
  +void change_price(int percentage)
  +void change_count(int number)
  +Person* get_person_pointer()
  +void set_special_tag(int a)
  +int get_special_tag()
  +int get_best_seller_tag()
  +void set_best_seller_tag(int x)
}


```






