This project is an implementation of an online store.

There are two types of users, sellers and buyers. 
Each user needs to sign up first and enter their first name, last name, username, some money and whether they are sellers or buyers. 
<!-- ###### *add_user first_name last_name username phone_number money seller/buyer*
###### *output: command ok/command failed* --!>

Sellers can add goods, to the shop. 
###### *add_goods seller_username goods_name goods_price goods_count*
###### *output: command ok/command failed*

Users can search for goods in the shop.
###### *search goods_name goods_count*
###### *output: number goods_name goods_count goods_price seller_username*

Users with the buyer tag can buy goods and offer prices (sale command). 
###### *buy buyer_username goods_name goods_count seller_username goods_name goods_count seller_username* 
...
###### *goods_name goods_count seller_username* 
###### *output: command ok/command failed*

Sellers can add/remove a good from the special offer list and offer a 10% discount. 
###### *sale buyer_username goods_name seller_username* 
###### *output: command ok/command failed*

sellers can add/remove special offers on goods:
###### *add_special seller_username goods_name goods_count*  
###### *remove_special seller_username goods_name goods_count*
###### *output: command ok/failed*

Users can search for bestseller goods and offer 10% discount.
###### *search_sale*
###### *search_bestseller*
###### *output:* 
###### *1. watch 5 5000 s_smith*
###### *2. watch 10 10000 a_smith*

Users can add money. 
###### *add_money username money*
###### *output: command ok/command failed*

Buyers can request goods.
###### *request request_name buyer_name goods_name goods_count seller_username,* 
###### *goods_name goods_count seller_username*
###### *output: command ok/command failed*

After every sale, a factor is printed. 
###### *Factor number #n*
###### *buyer_first_name buyer_last_name buyer_username buyer_phone_number* 
###### *#n goods_name goods_count goods_price seller_username sum*

All requests can be printed as well. 
###### *print_request buyer_username*
###### *output: Request 1 request_name buyer_username* 
###### *#n goods_name goods_count seller_username*

All the factors can be printed. 
###### *print_factor buyer_username*
###### *Factor factor_number buyer_username*
###### *#n goods_name goods_count goods_price seller_username sum*
###### *Goods sum = sum of all iterms*
###### *total sum = sum of all iterms + 5% sum of all items*

## Classes:
For this project, 5 classes were designed. Person (buyer, seller), goods, factors, requests and the shop that entails all classes. 
The file.txt includes some test cases. 


