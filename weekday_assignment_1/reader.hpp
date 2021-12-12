#pragma once
#include "order.hpp"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>

using namespace std;

/*
JSON reader class
Uses third party lib jsoncpp to parse the document
*/

class JsonReader
{
public:
    vector<Order *> parse(string pFilename);
};
