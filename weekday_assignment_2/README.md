# Weekday assignment 2
### Tables for extension of ordering system

### Approach 1 : SQL method 

- This approach is done according to SQL tables and using them for the same

- Tables 
    -  UserTable
    -  OrderTable
    -  FoodTable
    -  SubscribeTable
```
As we look into the same we can see the following relations in same:
    - Food can be of multiple types (appetizer/Main Course) etc increasing 
    - User can provide custom recipes 
    - N users can have M food orders 
    - Orders can be used as per users requirement
    - N users can subscribe to M Foods

UserTable 
    Contains the information about the user
    - u_id           // UserID                          (primary key) (number)
    - u_name         // UserName                        (varchar2)
    - u_phone_number // User Phone Number               (varchar2)
    - u_information  // User Information                (varchar2)

FoodTable
    Contains different types of food that can be ordered
    - f_id          //FoodID                            (primary_key) (number)
    - f_name        //FoodName                          (varchar2)
    - f_type        //Food Type (appetizer/Main Course) (varchar2)
    - f_recipe     //Food Recipe                        (varchar2)

OrderTable
    Mapping table used to map N users ordering M foods and generating orderID
    - ord_id        //OrderID                           (primary_key)   (number)
    - u_id          //UserID                            (foreign_key)   (number)
    - f_id          //FoodID                            (foreign_key)   (number)
    - isRecurring   //IsRecurring                       (number)
    - time          //Time of order                     (time)
    - u_recipe     //Custom recipe                      (varchar2)

SubscribeTable
    Mapping table to keep an index of Users creating repeating orders for food
    - sub_id        //SubscribeID                       (primary_key)   (number)
    - u_id          //UserID                            (foreign_key)   (number)
    - f_id          //FoodID                            (foreign_key)   (number)
    - u_recipe     //UserCustomRecipe                   (varchar2)
    - time          //OrderTime                         (time)
```
---
---
Flows

Creation of Users
  - An entry can be made in users by the time of signup 

Creation of Food 
  - An entry can be made for the list of items ordering system is providing 

Creation of Order 
  - When a user creates a request for an order 
      - containing list of foodIDs 
      - the timing of process
      - if it is recurring 
      - And any custom recipe  
  - If any order is recurring it can be enter into the subscribing table 

Creation of Subscription
  - A user can create the recurring order updating 
      - userID to FoodID
      - custom recipe
      - time of process
---

Read/Update Operation 

Order
  - An order can be processed using the orderID and getting the information entry 
    - based on the UserID and FoodID
    - Update operation can be performed on the basis of OrderID provided by the user changing the associated information 

Subscription    
   - Based on the subscriptionID the information can be received for the user or food

Delete Operation 

Order
   - Delete operation can be performed on the basis of OrderID provided by the user
   - By the same the entry can be removed from the user table  

Subscription
   - Delete operation can be performed by deleting the specific SubscribeID
   - Resulting in removal of the ID from the table

- The above method provides a structured way of representing the data.
- Since the data is organized in an SQL environment it, it had low latency and ACID properties by default.
- The scaling of SQL databases can be relied upon the product being used, as PostGreSQL

---
---

### Approach 2 : NOSQL method ( Object oriented method)

The following design focuses more as object oriented database 
This design will be holding information as separate objects as compared to SQL tables 
```
Objects 
    - User 
    - Order
    - Food

User {
    - User_name
    - User_information
    - Subscription_list
      - FoodName
      - Timings
      - Custom Recipe
    - Order_history
}

Food {
    - FoodName
    - Type
    - Recipe
}

Order {
    - User_name
    - list of food
    - Timings
}
```
This can also be viewed as separate objects which do not hold a high relations 

- Each object when created, generates a unique hashID which can be used for find the object ( even in shared environments)
- The Subscription_list is taken into the user object since it can be taken as a feasible choice, and holds usually less parsing 
- The objects are created minimal nested, which results in a faster query of the obj

Any CRUD operation can be performed based on the objectID produced and with minimal parsing can be Read/Update and can also be deleted

- Since the program developed is already in similar footsteps each order created can be directly added is the same
- The NOSQL method is effective in case of increase in data and sharded databases.
- As it can provide medium latency, and each object can be operated in a locked environment( either by application or DB level)


