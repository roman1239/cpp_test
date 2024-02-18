#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <thread>
#include <chrono>
#include <tuple>
#include <future>
#include <vector>
#include <memory>
#include <cstring>
#include <algorithm>

#include "test.h"
#include "String.h"
#include "Car.h"
#include "Array.h"
#include "Vector.h"
#include "Vector3.h"

//for map, you either must specify copmarator fcn and pass it as 3rd template argument
//or operator < in class
struct CopmaratorFcn_test
{
    bool operator()(const test& param1, const test& param2) const
    {
        return param1.m_str < param2.m_str;
    }
};
/*
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
*/

struct Vector22
{
    int x,y;

    Vector22(int x, int y) :
        x(x), y(y)
    {
        std::cout << "Vector22:param ctr" << std::endl;
    }

    Vector22(Vector22&& other) noexcept
            :
        x(other.x),
        y(other.y)
    {
        std::cout << "Vector22:move" << std::endl;
    }

    Vector22(const Vector22& other) :
        x(other.x),
        y(other.y)
    {
        std::cout << "Vector22:copy" << std::endl;
    }
};

class V2
{
private:

public:

    Vector22 m_v2;

    V2(const Vector22& v2) :
                m_v2(v2)
    {
        std::cout << "V2:copied" << std::endl;
    }

    V2(Vector22&& v2) :
                m_v2(std::move(v2))
    {
        std::cout << "V2:moved" << std::endl;
    }
};

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

static int keyPressed = 0;

void WorkingFcnThread()
{
    using namespace std::literals::chrono_literals;
    while(!keyPressed)
    {
        std::cout << "Working !" << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
    std::chrono::duration<float> m_duration;

public:
    Timer()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        m_duration = std::chrono::high_resolution_clock::now() - m_start;
        std::cout << "Timer took " << m_duration.count()*1000.0f << "ms" << std::endl;
    }
};

std::tuple<std::string, int> Person()
{
    return {"Veko", 4};
}

//Multithreading

std::vector<std::future<void>> futures;

static int tmp = 0;
static std::mutex mtx;

void AsyncFcn()
{
    using namespace std::literals::chrono_literals;

    std::cout << "work !" << std::endl;
    std::lock_guard<std::mutex> lock(mtx);
    tmp++;
    mtx.unlock();
    std::this_thread::sleep_for(1s);
}

//singleton

class RandomGenerator
{
private:
    //static RandomGenerator s_rg;
    RandomGenerator(){}

    static RandomGenerator& Get()
    {
        static RandomGenerator s_rg;
        return s_rg;
    }

    int Integer_I()
    {
        return 14;
    }

public:
    RandomGenerator(const RandomGenerator& other) = delete;
    RandomGenerator operator=(const RandomGenerator& other) = delete;

    static int Integer()
    {
        return Get().Integer_I();
    }
};

static int s_alloc_counter = 0;

void* operator new(size_t size)
{
    //std::cout << "Allocating " << size << " Bytes" << std::endl;
    s_alloc_counter++;
    return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
    //std::cout << "Freeing " << size << " Bytes" << std::endl;
    free(ptr);
}


void operator delete(void* ptr)
{
    //std::cout << "Freeing " << std::endl;
    free(ptr);
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
    stream << str.GetStr();
    return stream;
}

int main()
{
    using namespace std;
/*
    vector<int> v1;
    v1.push_back(12);
    v1.push_back(22);
    v1.push_back(32);
    for(int i = 0; i < v1.size(); i++)
        cout << v1[i] << " " << endl;
    cout << endl;
*/

/*
    Vector<int> v2;

    for(int i = 0; i < v2.Size(); i++)
        cout << v2[i] << " " << endl;
    cout << endl;
*/

    Vector<Vector3> v3;

    v3.EmplaceBack(1.0f,2.0f,3.0f);
    v3.EmplaceBack();

    v3.PushBack(Vector3(1.0f,2.0f,3.0f));
    v3.PushBack(Vector3());
    v3.PushBack(Vector3(1.0f,2.0f,3.0f));
    v3.PushBack(Vector3());
    v3.PushBack(Vector3(1.0f,2.0f,3.0f));
    v3.PushBack(Vector3());

    //v3.PopBack();
    v3.Clear();

    for(int i = 0; i < v3.Size(); i++)
        cout << v3[i].GetX() << " " <<
        v3[i].GetY() << " " << v3[i].GetZ() << " " << endl;
    cout << endl;


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
/*
    std::unordered_map<test, int> mapa;
    mapa[test{"XXX", 42, 14.2}] = 5;
    mapa[test{"BBB", 56, 5.32}] = 2;
    mapa[test{"TTT", 3, 334.8}] = 567;
    mapa[test{"BSF", 32, 65.2}] = 23;
    mapa[test{"GRE", 43, 82.0}] = 0;

    for(auto& i:mapa)
        std::cout << i.second << " : " << i.first.m_str << std::endl;
*/

/*
    std::thread t1(WorkingFcnThread);

    std::cout << "Press any key !\n";
    std::cin.get();
    keyPressed = 1;
    t1.join();
*/
/*
    using namespace std::literals::chrono_literals;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 2147483647;)
    {
        i++;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    std::cout << duration.count()*1000 << "ms" << std::endl;
*/

/*
    {
        Timer t1;
        for(int i = 0; i < 2147483647;)
        {
            i++;
        }
    }
*/

/*
    using namespace std;
    auto[str, num] = Person();
    cout << str << " : " << num << endl;
*/

/*
    Timer t2;
    for(int i = 0; i < 9; i++)
    {
        futures.push_back(std::async(std::launch::async, AsyncFcn));
    }
    futures[0].get();

    std::cout << "tmp: " << tmp << std::endl;
*/

    //singleton
    //std::cout << RandomGenerator::Integer() << std::endl;

/*
    //to allocate on heap, it needs to be at least 16 chars long
    std::string str("ASDFASDASDASasDQ");

    {
        std::unique_ptr<Vector2> v2 = std::make_unique<Vector2>();
    }
*/

    //using namespace std;
/*
    String str("string");
    String str1(str);

    str[1] = 'c';
    char c = str[1];

    cout << "*****************\n";

    String sq;
    sq = str1;
    cout << "//////////////////\n";

    String sq1;
    sq1 = "asdas";
    cout << "-----------------\n";

    String sq2 = "asdas";
    cout << "++++++++++++++++++++++\n";

    str1[1] = 'q';

    cout << str << " : " << str1 << " : " << sq << endl;

    String& ref = str1;
    cout << ref << endl;
*/

    //Car c1(String("asdl"));


/*
    V2 v2(Vector22(1,3));

    cout << v2.m_v2.x << v2.m_v2.y << endl;
*/

/*
    //move assignment operator:
    String s1 = String("ASDFQ");
    String s2;
    cout << "==================\n";
    //this calls assignement operator
    //s2 = s1;

    //this calls move assignement operator
    s2 = std::move(s1);

    cout << "total allocations: " << s_alloc_counter << endl;
*/

/*
    Array<int, 5> a1;

    memset(a1.GetData(), 0, a1.Size()*sizeof(int));


    a1[0] = 0;
    a1[1] = 1;
    a1[2] = 2;
    a1[3] = 3;
    a1[4] = 4;



    const int val = 17;
    a1[0] = val;

    Array<int,5>::Iterator it = a1.begin();

    std::fill(a1.begin(), a1.end(), 5);

    it[1] = 1;

    for(int i = 0; i < a1.Size(); i++)
        cout << a1[i] << " ";
    cout << endl;

    for (auto i = a1.begin(); i != a1.end(); i++)
    {
        cout << *i << " ";
    }

    it.at(3) = 85;
    cout << it[3] << it.at(3);

    cout << endl;
    for(auto i:a1)
        cout << i << " ";
    cout << endl;

    Array<std::string,5> a2;
    a2[0] = "asdads";
    a2[1] = "rde23";
    a2[2] = "gd thg";
    a2[3] = "fh hh";
    a2[4] = "j78k";

    for(auto i:a2)
        cout << i << endl;

    cout << endl;

    for(auto i = a2.begin(); i != a2.end(); i++)
        cout << *i << endl;
*/
    return 0;
}


