#include <iostream>
#include <windows.h>
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

void check_dir_and_files()
{
    //check and create
}

void mainloop(void){
    while (1) {
        string full_cmd;
        string cmd;
        char* arg_;
        vector<string> args;

        cout << "> ";
        std::getline(cin, full_cmd);

        cmd = std::strtok(full_cmd.data(), " ");
        arg_ = std::strtok(NULL, " ");
        while (arg_!=NULL) {
            args.push_back(arg_);
            arg_ = strtok(NULL, " ");
        }

        for (int i=0; i<args.size(); ++i) {
            cout << args[i] << endl;
        } //debug
        if (cmd_dict.find(cmd)!=cmd_dict.end()) { 
            (cmd_dict.at(cmd))(args);
        }
    }
}

int main(void) {

    SetConsoleOutputCP(65001);  //中文输出
    cout << "Command System" << endl << "By: 墨行" << endl << endl;

    check_dir_and_files();

    mainloop();

    return 0;
}