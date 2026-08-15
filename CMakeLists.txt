cmake_minimum_required(VERSION 4.4.2)

# 定义项目名称
project(SFML_Project)

# 设置使用 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "D:/Lib/SFML-2.6.1/lib/cmake/SFML")
# 寻找系统中的 SFML 库（需要图形、窗口和系统模块）
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# 指定可执行文件的名称和对应的源代码文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 指定头文件的搜索路径
target_include_directories(${PROJECT_NAME} PRIVATE include)

# 将 SFML 的库链接到你的可执行文件
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)