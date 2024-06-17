#!/bin/zsh 

# shell脚本批量格式化源代码格式

  
# 指定目录路径，例如当前目录或其子目录  
DIR="./"  
  
# 使用find命令递归搜索指定目录及其子目录中的C++文件  
find "$DIR" -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" -o -name "*.cc" -o -name "*.cxx" \) -exec clang-format -i -style=Google {} +  
  
# 如果上面的find命令返回非零状态码，则打印错误消息  
if [ $? -ne 0 ]; then  
    echo "Error occurred while formatting files."  
else  
    echo "All C++ files have been formatted."  
fi