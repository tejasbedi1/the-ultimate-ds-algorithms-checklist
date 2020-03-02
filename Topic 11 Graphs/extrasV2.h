// Priority
// 1 hightest, 3 lowest
	
int LOG_LEVEL;

template <class T>
void debug(int priority, T variable)
{
	if (priority <= LOG_LEVEL)
		std::cout << variable << "\n";
}

template <class T>
void debug(int priority, T variable, bool dontEndLine)
{
	if (priority <= LOG_LEVEL)
		std::cout << variable;
}


template <class T>
void debug(int priority, const char *c, T variable)
{
	if (priority <= LOG_LEVEL)
		std::cout << c << variable << "\n";
}

template <class T>
void debug(int priority, const char *c, T variable, bool dontEndLine)
{
	if (priority <= LOG_LEVEL)
		std::cout << c << variable;
}


template <class T>
void debug(int priority, T vairable, const char *sentence)
{
	if (priority <= LOG_LEVEL)
		std::cout << vairable << sentence;
}


template <class T>
void debug(int priority, const char *c, T variable, const char *seperator)
{
	if (priority <= LOG_LEVEL)
		std::cout << c << seperator << variable << "\n";
}

template <class T>
void debug(int priority, const char *c, T variable, const char *seperator, bool dontEndLine)
{
	if (priority <= LOG_LEVEL)
		std::cout << c << seperator << variable;
}
