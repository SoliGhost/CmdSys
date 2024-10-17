#ifndef CMD_SYS_H
#define CMD_SYS_H

#include <string>
#include <map>
#include <vector>

const std::map<std::string, int> cmd_id_map = {
    {"help", 0},
    {"?",    0},
    {"fun1", 1},
    {"1",    1},
    {"fun2", 2},
    {"2",    2}
};

void cmd_fun(std::string cmd, std::vector<std::string> args);

#endif