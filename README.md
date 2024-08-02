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




