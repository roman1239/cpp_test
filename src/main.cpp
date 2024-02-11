#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>

#include "test.h"

//for map, you either must specify copmarator fcn and pass it as 3rd template argument
//or operator < in class
struct CopmaratorFcn_test
{
    bool operator()(const test& param1, const test& param2) const
    {
        return param1.m_str < param2.m_str;
    }
};

//for unordered map a hash function must be specified
namespace std{
    template<>
    struct hash<test>
    {
        size_t operator()(const test& key)
        {
            return hash<string>()(key.m_str);
        }
    };
}

struct Vector2
{
    int x,y;
};

struct Vector4
{
    union
    {
        struct
        {
            int a,b,c,d;
        };
        struct
        {
            Vector2 v1,v2;
        };
    };
};

void PrintVector2(const Vector2& v1)
{
    std::cout << v1.x << ":" << v1.y << std::endl;
}

int main()
{
/*
    //Unions members occupie the same memorry
    using namespace std;
    Vector4 v = {1,2,3,4};
    std:: cout << v.a << v.b << v.c << v.d << std::endl;
    std::cout << "------------" << std::endl;
    PrintVector2(v.v1);
    PrintVector2(v.v2);

    std::cout << "\nType punning:" << std::endl;
    Vector2 v2 = {7,16};
    int* v2_ = ((int*)&v2);
    cout << v2_[0] << " : " << v2_[1] << endl;

    int& v2_x = *((int*)&v2);
    int& v2_y = *((int*)((char*)&v2+4));
    cout << v2_x << " : " << v2_y << endl;
*/


	//std::map<int, test> mapa;
	//mapa[0];
	//mapa[14];
	//mapa[1] = test{"first", 1,14.2};
	//std::pair<int const,test> toInsert = std::make_pair(1,test("first", 1,14.2));
	//mapa.insert(std::make_pair(1,test("first", 1,14.2)));
	//mapa[5] = test{"second", 2,5.32};
	//mapa[3] = test{"third", 3,52.3};

	//this will insert element, if it is not present
	//test& ref = mapa[2];
	//this will not insert element, but throw an  exception
	//auto& ref1 = mapa.at(84);

	//const std::map<int, test> mapa_const = mapa;
	//can not do this, when map is const, because [] will insert element, if it is not present
	//test& t1 = mapa_const[54];
	//so we have to use .at()
	//const test& t2 = mapa_const.at(18);
/*
	for(std::map<int, test>::iterator it = mapa.begin(); it != mapa.end(); it++)
		std::cout << it->first << std::endl;
*/

/*
    std::map<int, test> mapa;
    mapa[4] = test{"XXX", 42, 14.2};
    mapa[3] = test{"BBB", 56, 5.32};
    mapa[1] = test{"TTT", 3, 334.8};
    mapa[5] = test{"BSF", 32, 65.2};
    mapa[2] = test{"GRE", 43, 82.0};
*/
	/*
    std::map<test, int, CopmaratorFcn_test> mapa;
    mapa[test{"XXX", 42, 14.2}] = 5;
    mapa[test{"BBB", 56, 5.32}] = 2;
    mapa[test{"TTT", 3, 334.8}] = 567;
    mapa[test{"BSF", 32, 65.2}] = 23;
    mapa[test{"GRE", 43, 82.0}] = 0;
    for(auto i:mapa)
        std::cout << i.second << " : " << i.first.m_str << std::endl;
*/

    std::unordered_map<test, int> mapa;
    mapa[test{"XXX", 42, 14.2}] = 5;
    mapa[test{"BBB", 56, 5.32}] = 2;
    mapa[test{"TTT", 3, 334.8}] = 567;
    mapa[test{"BSF", 32, 65.2}] = 23;
    mapa[test{"GRE", 43, 82.0}] = 0;

    for(auto& i:mapa)
        std::cout << i.second << " : " << i.first.m_str << std::endl;

	return 0;
}
