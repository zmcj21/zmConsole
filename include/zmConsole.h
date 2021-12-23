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

//namespace start
namespace zmConsole
{
    //declaration:
    class Console
    {
    public:
        static void Write(const std::string& s);

        static std::string Read();
    };

    class String
    {
    public:
        static std::string WstringToString(const std::wstring& ws);

        static std::wstring StringToWstring(const std::string& str);
    };
}
//namespace end

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

        delete[] buf;

        return s;
    }

#endif //__linux__

    //windows:
#ifdef _WIN32
#include <Windows.h>

    HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    void Console::Write(const std::string& s)
    {
        std::wstring ws = String::StringToWstring(s);
        DWORD written = 0;
        WriteConsole(outputHandle, ws.c_str(), ws.size(), &written, nullptr);
    }

    std::string Console::Read()
    {
        wchar_t* buf = new wchar_t[READ_BUF_SIZE];

        DWORD read = 0;
        ReadConsole(inputHandle, buf, READ_BUF_SIZE, &read, nullptr);

        std::string s = String::WstringToString(std::wstring(buf));

        delete[] buf;

        return s;
    }

    std::string String::WstringToString(const std::wstring& ws)
    {
        UINT codePage = CP_UTF8; //CP_ACP

        int len = WideCharToMultiByte(codePage, 0, ws.c_str(), -1, NULL, 0, NULL, NULL);
        char* str = new char[len];
        WideCharToMultiByte(codePage, 0, ws.c_str(), -1, str, len, NULL, NULL);

        std::string return_str(str);
        delete[] str;
        return return_str;
    }

    std::wstring String::StringToWstring(const std::string& s)
    {
        UINT codePage = CP_UTF8; //CP_ACP

        int len = MultiByteToWideChar(codePage, 0, s.c_str(), -1, NULL, 0);
        wchar_t* wstr = new wchar_t[len];
        MultiByteToWideChar(codePage, 0, s.c_str(), -1, wstr, len);

        std::wstring return_wstr(wstr);
        delete[] wstr;
        return return_wstr;
    }

#endif //_WIN32

}
//namespace end

#endif //ZM_CONSOLE

#endif //ZM_CONSOLE_HEADER
