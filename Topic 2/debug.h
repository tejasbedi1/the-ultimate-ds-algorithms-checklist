// Priority
// 1 hightest, 3 lowest
	
int LOG_LEVEL;

void debug_VARIADIC_TEMPLATE()
{	}

template <typename T, typename... Types>
void debug_VARIADIC_TEMPLATE(T var1, Types... var2)
{
	std::cout << var1;
	debug_VARIADIC_TEMPLATE (var2...) ;
}

template <typename T, typename... Types>
void debug(int priority, T var1, Types... var2)
{
	if (priority <= LOG_LEVEL)
		debug_VARIADIC_TEMPLATE(var1, var2...);
}
