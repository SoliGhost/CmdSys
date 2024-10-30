#ifndef CMD_SYS_H
#define CMD_SYS_H

#include <string>
#include <map>
#include <vector>

class ClassCmd {
public:
    std::string doc;
    void operator()(std::vector<std::string>);
    ClassCmd(std::string doc, void(*func)(std::vector<std::string>)) {
        this->doc = doc;
        this->operator() = &func;
    }
};

extern std::map<std::string, ClassCmd> cmd_dict;

#endif