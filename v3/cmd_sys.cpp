#include <iostream>
#include <map>
#include "cmd_sys.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::map;

string doc_help = R"TAG(命令名: help 别称: ?
用途: 查看帮助
用法:
    generatesbox (<command_name>)
参数说明:
    command_name 要查看帮助的命令名，不写则输出总帮助文档)TAG";
void fun_help(vector<string> args)
{
    if (args.size() > 1)
    {
        cout << "[ERROR] help只需要0或1个参数，输入了" << args.size() << "个参数。需要帮助请输入help help" << endl;
    }
    else if (args.size() == 0)
    {
        cout << "Program General Help Document" << endl;
    }
    else
    {
        cout << cmd_dict.at(args[0]).doc << endl;
    }
}
ClassCmd Cmd_help(doc_help, fun_help);

string doc_fun1 = R"TAG(Document of fun1)TAG";
void fun_fun1(vector<string> args) {}
ClassCmd Cmd_fun1(doc_fun1, fun_fun1);

string doc_fun2 = R"TAG(Document of fun1)TAG";
void fun_fun2(vector<string> args) {}
ClassCmd Cmd_fun2(doc_fun2, fun_fun2);

std::map<std::string, ClassCmd> cmd_dict = {
    {"fun1",    Cmd_fun1},
    {"1",       Cmd_fun1},
    {"fun2",    Cmd_fun2},
    {"2",       Cmd_fun2},
    {"help",    Cmd_help},
    {"?",       Cmd_help}
};