#include <iostream>
#include <tuple>
#include <initializer_list>


// ****************************************************
// 迭代输出函数模板print中的可变参数包
// 此函数是必须的，因为如果没有，I == std::tuple_size<Tuple>::value情况下，会出现
// no matching function的错误
template<size_t I = 0, typename Tuple>
typename std::enable_if<(I == std::tuple_size<Tuple>::value)>::type printtp(Tuple t){
}

template<size_t I = 0, typename Tuple>
typename std::enable_if<(I < std::tuple_size<Tuple>::value)>::type printtp(Tuple t){
    std::cout << std::get<I>(t) << std::endl;
    printtp<I+1>(t);
}  

template<typename... Args>
void print1(Args... args){
    printtp(std::make_tuple(args...));
}
// ******************************************************

// ******************************************************
// 通过逗号表达式和初始化列表打印可变参数包
template<typename T>
void printargs(T arg){
    std::cout << arg << std::endl;
}

template<typename... Args>
void print2_1(Args... args){
    int arr[] = { (printargs(args),0)... };
}

template<typename... Args>
void print2_2(Args... args){
    std::initializer_list<int>{ (printargs(args),0)... };
}

// lambda函数中使用可变参数，在g++ 4.9.0之前的版本是一个bug，无法编译通过
// template<typename... Args>
// void print2_3(Args... args){
    //  std::initializer_list<int>{ ([&]{ std::cout << args << std::endl;}(), 0)... };
// }
// ******************************************************

// ******************************************************
template<typename T, typename... Args>
T* Instance(Args... args){
    return new T(args...);
}

struct A{
    A(int){}
};

struct B{
    B(int, int){}
};

// ******************************************************

int main(int argc, char* argv[]){
    A* ptr_a = Instance<A>(1);
    B* ptr_b = Instance<B>(1,2);
    // print2_3(1,2,3,4);
    return 0;
}