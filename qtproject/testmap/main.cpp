#include <iostream>

using namespace std;
#include <map>
#include <vector>

int main1()
{
    int num;

    int a=100;
    //cout<<(int)a<<std::endl;

//    for (i = 0, len = strlen(str); i < len; i++) {
//        if (isdigit(str[i])) {



//    while(1)
//    {
//     std::cout<<"please insert num:"<<std::endl;

//     cin>>num;

//     cout<<(int)num<<std::endl;
//    }



}

int main0()
{
    cout << "Hello World!" << endl;

    //std::map<int, double*> wobjmap;

    std::map<int, std::array<double, 7> > wobjmap;

    double target1[7] = {1,2,3,4,5,6,7};

    std::array<double, 7> tt = {1,2,3,1,2,3,1};
    wobjmap[0]=tt;

    std::cout<<wobjmap[0][0]<<std::endl;
    std::cout<<wobjmap[0][1]<<std::endl;

//    map<int, vector <double>> someMap;
//     someMap[5] = {5, 2, 3, 7};
//     someMap[151] = {5, 9, 20};
//     //iterate through each element of the map
//     for(const std::pair<int, std::vector<double>> &myPair: someMap)
//     {
//         //make sure the vector is not empty
//         //assert(!myPair.second.empty());

//         //print the last element in the vector
//         std::cout << myPair.second.back() <<std::endl;
//     }




    return 0;
}




#include <iostream>
#include <map>
#include <string>
#include <string_view>

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    // iterate using C++17 facilities
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";

// C++11 alternative:
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 alternative
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
//      std::cout << it->first << " = " << it->second << "; ";

    std::cout << '\n';
}

int main()
{
    // Create a map of three (string, int) pairs
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};

    print_map("1) Initial map: ", m);

    m["CPU"] = 25; // update an existing value
    m["SSD"] = 30; // insert a new value
    print_map("2) Updated map: ", m);

    // using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) Updated map: ", m);

    m.erase("GPU");
    print_map("5) After erase: ", m);

    std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
    print_map("6) After erase: ", m);
    std::cout << "7) m.size() = " << m.size() << '\n';

    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}







