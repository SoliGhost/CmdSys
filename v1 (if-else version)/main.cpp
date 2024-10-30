#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <cstring>    //for std::strtok
#include "cmd_sys.h"

//using namespace std;    //byte冲突，在后续项目中要用到
//封装成模块时，应删掉所有下面的using，避免冲突
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void mainloop(void) {
    string full_cmd;
    string cmd;
    char* arg_;    //个人习惯使用"<变量名>_"作为临时变量名
    vector<string> args;
    while (1) {
        cout << "> ";
        std::getline(cin, full_cmd);
        if (full_cmd == "") {
            continue;
        }

        cmd = std::strtok(full_cmd.data(), " ");
        arg_ = std::strtok(NULL, " ");
        while (arg_ != NULL) {
            args.push_back(arg_);
            arg_ = strtok(NULL, " ");
        }
        cmd_fun(cmd, args);
        args.clear();
    }
}

int main(void) {
    SetConsoleOutputCP(65001);  //中文输出
    cout << "命令系统 - Command System" << endl << "By: SoliGhost" << endl << endl;
    mainloop();
    return 0;
}