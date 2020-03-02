#include <iostream>

using namespace std;

void debug_VARIADIC_TEMPLATE()
{	}

template <typename T, typename... Types>
void debug_VARIADIC_TEMPLATE(T var1, Types... var2)
{
	std::cout << var1 << " ";
	debug_VARIADIC_TEMPLATE (var2...) ;
}

int main()
{
	debug_VARIADIC_TEMPLATE (2,2.3,3.678,"abcd");
}
