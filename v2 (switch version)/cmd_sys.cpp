#include <iostream>
#include <map>
#include "cmd_sys_v1.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::map;

void cmd_help_fun(vector<string> args) {
    if (args.size() > 1) {
        cout << "[ERROR] help只需要0或1个参数，输入了" << args.size() << "个参数。需要帮助请输入\"help help\"\n";
        return;
    } else if (args.size() == 0) {
        cout << "<Program General Help Document>" << endl;
        return;
    }
    if (cmd_id_map.find(args[0]) == cmd_id_map.end()) {
        cout << "不存在命令: \"" << args[0] << "\"。需要帮助请输入\"help help\"\n";
        return;
    }
    int cmd_id = cmd_id_map.at(args[0]);
    switch (cmd_id) {
    case 0:
        cout << R"TAG(命令名: help 别称: ?
用途: 查看帮助
用法:
    generatesbox (<command_name>)
参数说明:
    command_name 要查看帮助的命令名，不写则输出总帮助文档
)TAG";
        break;
    case 1:
        cout << R"TAG(Document of fun1)TAG" << endl;
        break;
    case 2:
        cout << R"TAG(Document of fun2)TAG" << endl;
        break;
    default:
        cout << "命令\"" << args[0] << "\"没有帮助文档\n";
        break;
    }
}

void cmd_fun1_fun(vector<string> args) {
    cout << "fun1 called.\nArgs: ";
    for (string arg : args) {
        cout << arg << ", ";
    }
    cout << "\b \b";
}

void cmd_fun2_fun(vector<string> args) {
    cout << "fun2 called.\nArgs: ";
    for (string arg : args) {
        cout << arg << ", ";
    }
    cout << "\b \b";
}

void cmd_fun_v1(string cmd, vector<string> args) {
    if (cmd_id_map.find(cmd) == cmd_id_map.end()) {
        cout << "不存在该命令: \"" << cmd << "\"" << endl;
        return;
    }
    int cmd_id = cmd_id_map.at(cmd);
    switch (cmd_id) {
    case 0:
        cmd_help_fun(args);
        break;
    case 1:
        cmd_fun1_fun(args);
        break;
    case 2:
        cmd_fun2_fun(args);
        break;
    default:
        cout << "[ERROR] ID为" << cmd_id << "的命令\"" << cmd << "\"没有对应的执行函数，请检查你的源代码" << endl;
        break;
    }
}