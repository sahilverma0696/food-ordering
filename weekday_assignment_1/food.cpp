#include "food.hpp"

float Food::GetTime()
{
    return vTimeTaken;
}

int Food::GetSlot()
{
    return vSlotsNeeded;
}

Appetizer::Appetizer()
{
    vTimeTaken = 17.0;
    vSlotsNeeded = 1;
}

int Appetizer::GetTime()
{
    return Food::GetTime();
}

int Appetizer::GetSlot()
{
    return Food::GetSlot();
}

MainCourse::MainCourse()
{
    vTimeTaken = 29.0;
    vSlotsNeeded = 2;
}

int MainCourse::GetTime()
{
    return Food::GetTime();
}

int MainCourse::GetSlot()
{
    return Food::GetSlot();
}