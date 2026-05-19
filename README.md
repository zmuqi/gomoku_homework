# gomoku_homework
# AI 驱动开发实践 —— 五子棋游戏

## 项目介绍
本项目是**AI驱动开发实践**大作业成果。
使用 **C++** 开发，基于 **FTXUI** 库实现终端图形界面，
全程由 **AI 辅助生成、优化、调试代码**，完成可交互五子棋游戏。

## 游戏功能
15×15 标准五子棋棋盘  
双人交替落子  
方向键移动光标，空格落子  
自动判断胜负（横、竖、斜五子连珠）  
按 R 键重新开始游戏  
全屏彩色界面  

## 技术栈
- 语言：C++17
- 界面库：FTXUI（终端UI库）
- 构建工具：CMake
- 开发模式：AI 驱动开发

## 运行环境
Windows / Linux / macOS 支持 ANSI 颜色的终端均可运行。

## 编译与运行
### 编译步骤
```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j4
./gomoku.exe
