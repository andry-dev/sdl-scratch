#ifndef LOG_H
#define LOG_H

#include <exception>
#include <string>
#include <iostream>

namespace Log
{

	void warning(const std::string& str)
	{
		std::cout << "[W] " + str << '\n';
	}

	void error(const std::string& str)
	{
		std::cerr << "[E] " + str << '\n';
	}

	void info(const std::string& str)
	{
		std::cout << "[I] " + str << '\n';
	}

#ifndef NDEBUG
	#define Expects(cond, msg) \
		if (!(cond)) { \
			Log::error(msg); \
			std::terminate(); \
		}
	
	#define Ensures(cond, msg) \
		if (!(cond)) { \
			Log::error(msg); \
			std::terminate(); \
		}
#else
	#define Expects(cond, msg)
	#define Ensures(cond, msg)
#endif

#define STRINGIFY(x) #x
}



#endif /* LOG_H */
