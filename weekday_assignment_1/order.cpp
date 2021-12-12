#include "order.hpp"

int gTotalSlots = 7;

float gDeliveryTime = 8; //8 minutes/km
float gMaxTime = 130;    //130 minutes

Order::Order()
{
    vOrderID = 0;
    vDistance = 0;
    isValid = true;
}

void Order::AddFood(Food pFood)
{
    vFoodList.push_back(pFood);
}

vector<Food> Order::GetFoodList()
{
    return vFoodList;
}

float Order::GetTotalTime()
{
    return vTime.vTotalTime;
}

void Order::SetOrderID(int pID)
{
    vOrderID = pID;
}

void Order::SetDistance(float pDistance)
{
    vDistance = pDistance;
}

int Order::GetOrderID()
{
    return vOrderID;
}

void Order::SetValid(bool pFlag)
{
    isValid = pFlag;
}

void Order::TotalSlots()
{
    vTime.SetDeliveryTime(gDeliveryTime * vDistance);
    for (auto item : vFoodList)
    {
        vSlots += item.GetSlot();
    }
}

bool Order::IsValid()
{
    for (auto item : vFoodList)
    {

        if (vSlots > gTotalSlots || vTime.GetTotalTime() > gMaxTime)
        {
            SetValid(false);
        }
    }
    return isValid;
}

int Order::GetSlots()
{
    return vSlots;
}
void Order::ProcessPrepTime()
{
    float aptTime;
    float mcTime;
    float stdApptime = 17.0;
    float stdMctime  = 29.0;
    for (auto item : vFoodList)
    {
        aptTime = 0.0;
        mcTime = 0.0;
        if (item.GetTime() == stdApptime)
            aptTime += item.GetTime();
        else if (item.GetTime() == stdMctime)
        {
            mcTime += item.GetTime();
        }

        float time = max(aptTime, mcTime);
        vTime.SetPrepTime(time);
        vTime.CalTotalTime();
    }
}

void Order::Process()
{
    TotalSlots();
    ProcessPrepTime();
    IsValid();
}
