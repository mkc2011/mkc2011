#include <iostream>
#include <iomanip>
#include <sstream>
#include <nlohmann/json.hpp>

#include <string>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;


using json = nlohmann::json;

int main()
{
clock_t start, end;
start = clock();




    // Load a .json file into an std::string

    std::ifstream myFile("sample4.json");
    std::ostringstream tmp;
    tmp << myFile.rdbuf();
    std::string s = tmp.str();
    

    // parse and serialize JSON
    json j_complete = json::parse(s);

    std::cout << std::setw(4) << j_complete << "\n\n";


    // define parser callback
    json::parser_callback_t cb = [](int depth, json::parse_event_t event, json & parsed)
    {
        // skip object elements with key "Thumbnail"
        if (event == json::parse_event_t::key and parsed == json("Thumbnail"))
        {
            return false;
        }
        else
        {
            return true;
        }
    };
  

    // parse (with callback) and serialize JSON
    json j_filtered = json::parse(s, cb);
    std::cout << std::setw(4) << j_filtered << '\n';


end = clock();

   // to get type of variable
   cout << typeid(j_complete).name() << endl;

// Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\n\n Time taken by this program is : " << fixed 
         << time_taken*1000 << setprecision(5);
    cout << "  milli seconds " << endl;
    cout<<" \n"<<" \n";
    return 0;



}