@echo off
echo ========================================
echo Visual Studio C++ 调试环境测试
echo ========================================

echo.
echo 1. 检查项目文件...
if exist "CL23-0320250613.sln" (
    echo [✓] 解决方案文件存在
) else (
    echo [✗] 解决方案文件不存在
    goto :error
)

if exist "CL23-0320250613.vcxproj" (
    echo [✓] 项目文件存在
) else (
    echo [✗] 项目文件不存在
    goto :error
)

echo.
echo 2. 检查源代码文件...
if exist "main.cpp" (
    echo [✓] main.cpp 存在
) else (
    echo [✗] main.cpp 不存在
    goto :error
)

if exist "guild.cpp" (
    echo [✓] guild.cpp 存在
) else (
    echo [✗] guild.cpp 不存在
    goto :error
)

if exist "player.cpp" (
    echo [✓] player.cpp 存在
) else (
    echo [✗] player.cpp 不存在
    goto :error
)

if exist "menu.cpp" (
    echo [✓] menu.cpp 存在
) else (
    echo [✗] menu.cpp 不存在
    goto :error
)

echo.
echo 3. 检查头文件...
if exist "guild.h" (
    echo [✓] guild.h 存在
) else (
    echo [✗] guild.h 不存在
    goto :error
)

if exist "player.h" (
    echo [✓] player.h 存在
) else (
    echo [✗] player.h 不存在
    goto :error
)

if exist "menu.h" (
    echo [✓] menu.h 存在
) else (
    echo [✗] menu.h 不存在
    goto :error
)

echo.
echo 4. 检查输出目录...
if exist "x64\Debug\" (
    echo [✓] Debug输出目录存在
) else (
    echo [!] Debug输出目录不存在，需要编译项目
)

if exist "x64\Debug\CL23-0320250613.exe" (
    echo [✓] 可执行文件存在
) else (
    echo [!] 可执行文件不存在，需要编译项目
)

echo.
echo ========================================
echo 调试环境配置完成！
echo ========================================
echo.
echo 使用说明：
echo 1. 在Visual Studio中打开 CL23-0320250613.sln
echo 2. 选择 Debug 配置和 x64 平台
echo 3. 按 F5 开始调试
echo 4. 在代码中设置断点进行调试
echo.
echo 详细说明请查看 调试指南.md 文件
echo.
pause
goto :end

:error
echo.
echo ========================================
echo 发现错误！请检查项目文件完整性
echo ========================================
pause

:end 