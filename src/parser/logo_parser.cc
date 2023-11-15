#include <parser/logo_parser.h>

//commands = fd, bk, lt, rt, cs, pu, pd, ht, st

Parser::Parser (std::string fileContents) {
    this->data = std::stringstream(fileContents);
}

void Parser::next() {
    getline(data,buf);
    std::string commandStr;
    std::string magnitudeStr;
    if (buf.find(' ') == std::string::npos) {
        commandStr = buf;
        magnitude = 0;
    }
    else {
        commandStr = buf.substr(0, buf.find(' '));
        magnitudeStr = buf.substr(buf.find(' ') + 1, buf.back());
        this->magnitude = stoi(magnitudeStr);
    }
    std::map<std::string, int> commandMap;
    commandMap["fd"] = KEY_UP;
    commandMap["bk"] = KEY_DOWN;
    commandMap["lt"] = KEY_LEFT;
    commandMap["rt"] = KEY_RIGHT;
    // to be written
    // commandMap["cs"];
    // commandMap["pu"];
    // commandMap["pd"];
    // commandMap["ht"];
    // commandMap["st"];
    //

    command = commandMap[commandStr];

//     if (!commandStr.compare("fd")) {
//         command = KEY_UP;
//     }
//     else if (!commandStr.compare("bk")) {
//         command = KEY_DOWN;
//     }
//     else if (!commandStr.compare("lt")) {
//         command = KEY_LEFT;
//     }
//     else if (!commandStr.compare("rt")) {
//         command = KEY_RIGHT;
//     }
//     else if (!commandStr.compare("cs")) {
//         //command = clearscreen (to be written)
//     }
//     else if (!commandStr.compare("pu")) {
//         //command = KEY_SPACE;
//     }
//     else if (!commandStr.compare("pd")) {
//         //command = KEY_SPACE;
//     }
//     else if (!commandStr.compare("ht")) {
//         //to be written
//     }
//     else {
//         std::cout << "Invalid command: " + commandStr << std::endl;
//     }

}

int Parser::getCommand() { return command; }
int Parser::getMagnitude() { return magnitude; }
