#pragma once


/*
Base class for food,
In case of increase in the type of food,
New classes can be made on the same.
And if anything common is added to food, i.e, Name, or recipie, special request 
that can be directly added in the food class
*/
class Food
{

public:
    float vTimeTaken;
    int vSlotsNeeded;

    float GetTime();
    int GetSlot();
};

class Appetizer : public Food
{

public:
    Appetizer();

    int GetTime();

    int GetSlot();
};

class MainCourse : public Food
{

public:
    MainCourse();

    int GetTime();

    int GetSlot();
};
