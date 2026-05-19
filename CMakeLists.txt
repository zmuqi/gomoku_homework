cmake_minimum_required(VERSION 3.11)
project(gomoku)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动下载并引入FTXUI库
include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# 添加头文件目录
include_directories(include)

# 编译源文件
file(GLOB SRC_FILES src/*.cpp)
add_executable(gomoku ${SRC_FILES})

# 链接FTXUI库
target_link_libraries(gomoku
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)