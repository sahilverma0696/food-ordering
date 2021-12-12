#pragma once

/*
Time class 
    This class contains various times which affects the order.
    currently works on float minutes.
*/
class Time
{

    float vPrepTime;
    float vDeliveryTime;
    float vWaitingTime;

public:
    float vTotalTime;
    Time();
    Time(float preptime, float deliverytime, float waitingtime);

    void SetPrepTime(float pPreptime);
    float GetPrepTime();
    void SetDeliveryTime(float pDeliveryTime);
    float GetDeliveryTime();
    void SetWaitingTime(float pWaitingTime);
    float GetWaitingTime();
    void CalTotalTime();
    float GetTotalTime();
};
