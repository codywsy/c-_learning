#include <iostream>
#include <tuple>
#include <memory>

// ****************************************************
// 一般的type_traits
template<typename Type>
struct GetLeftSize : std::integral_constant<int, 20> {
};
// ****************************************************

// ****************************************************
// 可变函数
template<class... T>
void Print(T... args){
    std::cout << sizeof...(args) << std::endl;
}
// ****************************************************

// ****************************************************
// 判断类型的type_traits
void JudgeTypeNameConvert(){
    std::cout << std::is_same<const int, std::remove_const<const int>::type>::value << std::endl;
    std::cout << std::is_same<const int, std::add_const<int>::type>::value << std::endl;
    std::cout << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << std::endl;
    std::cout << std::is_same<int&&, std::add_rvalue_reference<int>::type>::value << std::endl;
    std::cout << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;
    std::cout << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;

    // common type
    typedef std::common_type<unsigned char, short, int>::type NumericType;
    std::cout << std::is_same<int, NumericType>::value << std::endl;
}
// ****************************************************

// ****************************************************
// 类型转换的type_traits
template<typename T>
typename std::remove_reference<T>::type* Create(){
    typedef typename std::remove_reference<T>::type U;
    return new U(); // type() --> value 
}

template <class T>
struct Construct
{
	typedef typename std::remove_reference<T>::type U;
	Construct() : m_ptr(new U){}

	typename std::add_lvalue_reference<U>::type Get() const
	{
		*m_ptr = 100;  
		return *m_ptr.get();
	}

private:
	std::unique_ptr<U> m_ptr;
};
// ****************************************************

int main(int argc, char* argv[]){
    // std::cout << GetLeftSize<bool>::value << std::endl;
    // std::cout << GetLeftSize<bool>::type() << std::endl;
    // std::cout << GetLeftSize<bool>::value_type;
    // std::cout << GetLeftSize<bool>::value_type() << std::endl;

    // std::cout << std::is_object<GetLeftSize<int>>::value << std::endl;

    // JudgeTypeNameConvert();
    
    // std::tuple<int, int> two; // two is a object with two data
    // std::cout << typeid(two).name() << std::endl;
    // two = std::make_tuple(2,3);
    // std::cout << std::get<0>(two) << std::endl;
    // std::cout << std::get<1>(two) << std::endl;

    return 0;
}