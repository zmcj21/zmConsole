# zmConsole

2021/12/26 圣诞快乐 Merry Christmas С Рождеством

造梦控制台是一个单个头文件解决方案，目的是提供跨平台的控制台函数，你只需添加单个头文件到你的项目！

### 用法

对于Windows用户使用Visual Studio：
将代码库中include文件夹内的zmConsole.h复制到你的项目中并添加引用。

对于Linux用户使用Cmake：
将代码库中include文件夹内的zmConsole.h复制到你的项目中并修改Cmake生成文件。

示例代码：

``` cpp
#define ZM_CONSOLE; //该宏只能在.cpp文件中被定义一次
#include "zmConsole.h"
using namespace zmConsole;

int main()
{
    Console::Write("hello zmConsole!");
    Console::Read();
    return 0;
}

```
