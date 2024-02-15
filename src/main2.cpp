//#include "test.h"

#include <iostream>
#include <vector>
#include <memory>

/*
extern "C"
{
    #include "c_src_file.h"
}
*/

//extern int s_variable;

#include "base.h"
#include "sub.h"
#include "sub2.h"

std::ostream& operator<<(std::ostream& stream, const sub& obj);

class Device
{
private:
    std::string m_name;
    int m_prize;

public:
    Device() : m_name("Empty"),
                m_prize(0)
    {}

    Device(std::string name, int prize) : m_name(name),
                                          m_prize(prize)
    {}

    void DeviceInit(std::string name, int prize)
    {

    }
    const std::string& GetName() const
    {
        return m_name;
    }

    const int& GetPrize() const
    {
        return m_prize;
    }
};

class DeviceSmartPtr
{
private:
    Device* m_ptr;
public:
    DeviceSmartPtr() : m_ptr(nullptr)
    {
        std::cout << "default constructor" << std::endl;
    }

    DeviceSmartPtr(Device* ptr) : m_ptr(ptr)
    {
        std::cout << "param constructor" << std::endl;
    }

    DeviceSmartPtr(const DeviceSmartPtr&) = delete;

    DeviceSmartPtr& operator=(const DeviceSmartPtr&) = delete;

    ~DeviceSmartPtr()
    {
        std::cout << "destructor" << std::endl;
        delete m_ptr;
    }

    Device* GetDevice()
    {
        return m_ptr;
    }
};

#if 0
int main()
{
    DeviceSmartPtr* ptr_device;
    {
        //DeviceSmartPtr ptr_sd0;

        DeviceSmartPtr ptr_sd = new Device("test", 12);

        //scoped ptr cannot be copied
        /*
        DeviceSmartPtr ptr_device(ptr_sd);
        DeviceSmartPtr ptr_device1;
        ptr_device1 = ptr_sd;
        */
        std::unique_ptr<Device> ptr;


        std::cout << ptr_sd.GetDevice()->GetName() << " : " << ptr_sd.GetDevice()->GetPrize() << std::endl;

    }
    //std::cout << "end of scope\n" << ptr_device->GetName();

    //std::cout << ptr_device.GetDevice()->GetName() << " : " << ptr_device.GetDevice()->GetPrize() << std::endl;

/*
    base base1;

    base base3(3, "base1");
    base base4 = base(4,"123");

    base base5 = base4;
    base base6(base4);
    base base7(base(7,"zx"));
*/

/*
    sub sub1;
    std::cout << std::endl;

    sub sub3(3.3);
    std::cout << std::endl;
    sub sub4 = sub(4.4);
    std::cout << std::endl;

    sub sub5 = sub4;
    std::cout << std::endl;
    sub sub6(sub4);
    std::cout << std::endl;
    sub sub7(sub(7.7));
    std::cout << std::endl;
*/

//virtual functions + interface
/*
    base* ptr_s1 = new sub;
    base* ptr_s2 = new sub2;
    base* ptr_s3 = new sub;

    //can not instantiate sub2, because it does not implement pure virtual function !
    //base* ptr_s2 = new sub2;

    ptr_s1->PrintMsg();

    //ptr_s1->base::PureVirtualFcn();
    ptr_s1->PureVirtualFcn();

    std::vector<base*> v;
    v.reserve(4);
    v.push_back(ptr_s1);
    v.push_back(ptr_s2);
    v.push_back(ptr_s3);
    v.push_back(ptr_s2);

    //this will always call the appropriate fcn
    for(auto& i:v)
        i->PureVirtualFcn();

    delete ptr_s1;
    delete ptr_s2;
    delete ptr_s3;
*/
/*
    sub s1(14.4);
    sub s2(0.6);
    sub s3 = s1 + s2;
    sub2 ss2;
    std::cout << "s3: " << s3 << " !" << std::endl;
    std::cout << "ss2: " << ss2 << s3 << " !" << std::endl;
*/


/*
    test test1(13);
    std::cout << test1.GetId() << std::endl;
    std::cout << test1.count << std::endl;
    PrintVar();
    std::cout << "s_var: " << s_variable << std::endl;
*/
    //sub s1 = 14.8;
	return 0;
}
#endif
std::ostream& operator<<(std::ostream& stream, const sub& obj)
{
    stream << obj.m_length;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const sub2& obj)
{
    stream << obj.m_number << " : " << obj.m_str;
    return stream;
}
