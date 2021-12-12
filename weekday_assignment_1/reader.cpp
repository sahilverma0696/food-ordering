#include "reader.hpp"

vector<Order*> JsonReader::parse(string pFilename)
{
    ifstream file(pFilename);
    Json::Value actualJson;
    Json::Reader reader;
    vector<Order*> orders;

    reader.parse(file, actualJson);

    for (auto order : actualJson)
    {
        Order* new_order = new Order();

        new_order->SetOrderID(order["orderId"].asInt());

        for (auto meal : order["meals"])
        {
            if (meal.asString() == "A")
            {
                Appetizer new_appetizer;
                new_order->AddFood(new_appetizer);
            }
            else if (meal.asString() == "M")
            {
                MainCourse new_maincourse;
                new_order->AddFood(new_maincourse);
            }
        }

        new_order->SetDistance(order["distance"].asFloat());

        orders.push_back(new_order);
    }
    return orders;
}
