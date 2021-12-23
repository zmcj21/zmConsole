//Author:zmcj21
//Date:2021/12/23

#ifndef ZM_CONSOLE_HEADER
#define ZM_CONSOLE_HEADER

#ifndef LEN
#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#endif //LEN

#ifndef READ_BUF_SIZE
#define READ_BUF_SIZE 2048
#endif //READ_BUF_SIZE

#include <string>

//namespace:
namespace zmConsole
{
//declaration:
	class Console
	{
	public:
		static void Write(const std::string& s);

		static std::string Read();
	};
}

//implemetation:
#ifdef ZM_CONSOLE

//namespace start
namespace zmConsole
{

//linux:
#ifdef __linux__
#include <unistd.h>

void Console::Write(const std::string& s)
{
	write(STDOUT_FILENO, s.c_str(), s.size());
}

std::string Console::Read()
{
	char* buf = new char[READ_BUF_SIZE];
	
	read(STDIN_FILENO, buf, READ_BUF_SIZE);

	std::string s(buf);

	delete buf;
	
	return s;
}

#endif //__linux__

//windows:
#ifdef _WIN32
#include <Windows.h>
//todo

#endif //_WIN32

} //namespace end

#endif //ZM_CONSOLE

#endif //ZM_CONSOLE_HEADER
