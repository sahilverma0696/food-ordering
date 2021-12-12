#include "time.hpp"

Time::Time()
{
    vPrepTime = 0.0;
    vDeliveryTime = 0.0;
    vWaitingTime = 0.0;
    vTotalTime = 0.0;
}

Time::Time(float preptime, float deliverytime, float waitingtime)
{
    vPrepTime = preptime;
    vDeliveryTime = deliverytime;
    vWaitingTime = waitingtime;
    CalTotalTime();
}

void Time::SetPrepTime(float pPreptime)
{
    vPrepTime = pPreptime;
}

float Time::GetPrepTime()
{
    return vPrepTime;
}

void Time::SetDeliveryTime(float pDeliveryTime)
{
    vDeliveryTime = pDeliveryTime;
}

float Time::GetDeliveryTime()
{
    return vDeliveryTime;
}
void Time::SetWaitingTime(float pWaitingTime)
{
    vWaitingTime += pWaitingTime;
}

float Time::GetWaitingTime()
{
    return vWaitingTime;
}

void Time::CalTotalTime()
{
    vTotalTime = vPrepTime + vDeliveryTime + vWaitingTime;
}

float Time::GetTotalTime()
{
    return vTotalTime;
}