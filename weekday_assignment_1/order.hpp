#pragma once
#include "food.hpp"
#include "time.hpp"
#include "vector"
#pragma once
#include "iostream"

using namespace std;

/*
ORDER class 
This class keeps the information about the order 
which currently holds 
    - OrderID
    - The list of food
    - The delivery distance
This class uses time and food class to compute different functional requirements of the order
and can process if the order is valid or not.

*/
class Order
{

    int vOrderID;
    float vDistance;
    vector<Food> vFoodList;

    bool isValid;
    int vSlots;

public:
    Time vTime;
    Order();

    void AddFood(Food pFood);

    vector<Food> GetFoodList();

    float GetTotalTime();

    void SetOrderID(int pID);

    void SetDistance(float pDistance);

    int GetOrderID();

    void SetValid(bool pFlag);

    void TotalSlots();

    bool IsValid();

    int GetSlots();

    void ProcessPrepTime();

    void Process();
};
