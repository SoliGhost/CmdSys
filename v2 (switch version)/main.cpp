#include <iostream>
#include <windows.h>    // for SetConsoleOutputCP
#include <vector>
#include <string>
#include <cstring>    //for std::strtok
#include "cmd_sys.h"

//using namespace std;    //与byte冲突
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void mainloop(void){
    while (1) {
        string full_cmd;
        string cmd;
        char* arg_;
        vector<string> args;

        cout << "> ";
        std::getline(cin, full_cmd);
        if(full_cmd=="") continue;

        cmd = std::strtok(full_cmd.data(), " ");
        arg_ = std::strtok(NULL, " ");
        while (arg_!=NULL) {
            args.push_back(arg_);
            arg_ = strtok(NULL, " ");
        }
        cmd_fun(cmd, args);
    }
}

int main(void) {
    SetConsoleOutputCP(65001);  //中文输出
    cout << "命令系统 - Command System\nBy: SoliGhost\n\n";

    mainloop();
    return 0;
}