#include "order.hpp"
#include "reader.hpp"
#include "utility.cpp"

using namespace std;

//Handler function 

int main()
{
    JsonReader reader;
    vector<Order *> order_list;
    order_list = reader.parse("input.json");

    set<Order *> result = order_processing(order_list);

    for (auto order : result)
    {
        if (!order->IsValid())
        {
            cout << "Order " << order->GetOrderID() << " is denied because the restaurant cannot accommodate it.\n";
        }
        else
        {
            cout << "Order " << order->GetOrderID() << " will get delivered in " << order->vTime.GetTotalTime() << " minutes\n";
        }
    }
    return 0;
}
