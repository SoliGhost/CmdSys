#include <iostream>
#include <map>
#include "cmd_sys.h"

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

    if (args[0] == "help" || args[0] == "?") {
        cout << R"TAG(命令名: help 别称: ?
用途: 查看帮助
用法:
    generatesbox (<command_name>)
参数说明:
    command_name 要查看帮助的命令名，不写则输出总帮助文档
)TAG";
    } else if (args[0] == "fun1" || args[0] == "1") {
        cout << R"TAG(Document of fun1)TAG" << endl;
    } else if (args[0] == "fun2" || args[0] == "2") {
        cout << R"TAG(Document of fun2)TAG" << endl;
    } else {
        cout << "不存在命令: \"" << args[0] << "\"，或该命令没有帮助文档。需要帮助请输入\"help help\"\n";
    }
}

void cmd_fun1_fun(vector<string> args) {
    cout << "fun1 called.\nArgs: ";
    for (string arg : args.) {
        cout << arg << ", ";
    }
    cout << "\b\b \b\b\n";
}

void cmd_fun2_fun(vector<string> args) {
    cout << "fun2 called.\nArgs: ";
    for (string arg : args) {
        cout << arg << ", ";
    }
    cout << "\b\b  \b\b\n";
}

void cmd_fun(string cmd, vector<string> args) {
    if (cmd == "help" || cmd == "?") {
        cmd_help_fun(args);
    } else if (cmd == "fun1" || cmd == "1") {
        cmd_fun1_fun(args);
    } else if (cmd == "fun2" || cmd == "2") {
        cmd_fun2_fun(args);
    } else {
        cout << "不存在该命令: \"" << cmd << "\"" << endl;
    }
}