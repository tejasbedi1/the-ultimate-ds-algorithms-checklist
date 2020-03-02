
int LOG_LEVEL;

template <class T>
void debug(int priority, T c)
{
	// Priority
	// 1 hightest, 3 lowest
	if (priority <= LOG_LEVEL)
		std::cout << c;
}

template <class T>
void debug(int priority, T c, bool endLine)
{
	// Priority
	// 1 hightest, 3 lowest
	if (priority <= LOG_LEVEL)
		std::cout << c;
	if (endLine == true)
		std::cout<<"\n";
}

template <class T>
void debug(int priority, T c, const char *space)
{
	// Priority
	// 1 hightest, 3 lowest
	if (priority <= LOG_LEVEL)
		std::cout << c << space;
}
