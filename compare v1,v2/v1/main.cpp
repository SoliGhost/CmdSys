#include <iostream>
#include <windows.h>    // for SetConsoleOutputCP
#include <vector>
#include <string>
#include <cstring>    //for std::strtok
#include "cmd_sys_v1.h"

#include <chrono>    //test

//using namespace std;    //与byte冲突
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string test_cmds[8] = {"?", "help", "? help", "fun1 qwerty wasd", "fun2 a b c d e f g h i j k l m n", "help fun1", "help fun2"};    //test
std::map<string, int> test_cnt;    //test

const int test_time = 100000;

void mainloop_null(void) {
    for (int _ = 0; _ < test_time; _++) {
        string full_cmd;
        string cmd;
        char *arg_;
        vector<string> args;

        //cout << "> ";

        full_cmd = test_cmds[rand()%8];    // test
        test_cnt[full_cmd]++;    // test
        if (full_cmd == "")
            continue;

        cmd = std::strtok(full_cmd.data(), " ");
        arg_ = std::strtok(NULL, " ");
        while (arg_ != NULL)
        {
            args.push_back(arg_);
            arg_ = strtok(NULL, " ");
        }
    }
}

void mainloop_v1(void) {
    for (int _ = 0; _ < test_time; _++) {
        string full_cmd;
        string cmd;
        char* arg_;
        vector<string> args;

        //cout << "> ";

        full_cmd = test_cmds[rand()%8];    //test
        test_cnt[full_cmd]++;    // test
        if (full_cmd == "") continue;

        cmd = std::strtok(full_cmd.data(), " ");
        arg_ = std::strtok(NULL, " ");
        while (arg_!=NULL) {
            args.push_back(arg_);
            arg_ = strtok(NULL, " ");
        }
        cmd_fun_v1(cmd, args);
    }
}

int main(void) {
    SetConsoleOutputCP(65001);    //中文输出
    cout << "命令系统 - Command System\nBy: SoliGhost\nTest for: v1, v2\n\n";

    unsigned int seed = time(NULL);
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();

    srand(seed); // test
    cout << "Test for \"null\":\n";
    for (string test_cmd : test_cmds) test_cnt[test_cmd] = 0; // test
    start = std::chrono::high_resolution_clock::now();
    mainloop_null();
    stop = std::chrono::high_resolution_clock::now();
    for (std::map<string, int>::iterator it = test_cnt.begin(); it!=test_cnt.end(); it++) cout << "    " << it->second << " - \"" << it->first << "\"\n";
    cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms\n\n";

    srand(seed); // test
    cout << "Test for \"v1\":\n";
    for (string test_cmd : test_cmds) test_cnt[test_cmd] = 0; // test
    start = std::chrono::high_resolution_clock::now();
    mainloop_v1();
    stop = std::chrono::high_resolution_clock::now();
    for (std::map<string, int>::iterator it = test_cnt.begin(); it != test_cnt.end(); it++) cout << "    " << it->second << " - \"" << it->first << "\"\n";
    cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms\n";

    cin.get();
    return 0;
    }