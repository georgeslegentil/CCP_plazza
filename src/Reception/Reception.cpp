/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#include "IPC.hpp"
#include "Plazza.hpp"
#include "Kitchen.hpp"
#include "Command.hpp"
#include "Reception.hpp"

char is_Number(char c) {return (c < '0' || c > '9');}

Reception::Reception(float m, int c, int s)
{
    this->_cooks = c;
    this->_multiplier = m;
    this->_refresh = s;
    this->_open = false;
}

void Reception::open()
{
    _open = true;
    _acceptOrders();
}

void Reception::_acceptOrders()
{
    IPC ipc(this->_multiplier, this->_cooks, this->_refresh);
    Busy busy(nullptr);

    ipc.link(busy);
    while (true) {
        std::string command;
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "exit")
            break;
        if (!_parser.isValidCommand(command)) {
            std::cerr << "Invalid command, retry. Example : \"regina XXL x2; fantasia M x3; margarita S x1\""
                    << std::endl;
            continue;
        }
        _currentCommand = _parser.splitCommand(command);
        ArrayOfCommands Command = getCommand();
        for (auto i : Command)
            for (int j = 0; j < i[2][1] - '0'; j++) {
                CCommand c(i[0], i[1]);
                ipc.setSmemory(c.getCommandProperties().first,
                c.getCommandProperties().second);
                _createKitchen(c, busy, ipc.getSmemory());
            }
    }
    ipc.unlink();
}

void Reception::_createKitchen(CCommand cmd, Busy &busy, int *sMem)
{
    pid_t pid = fork();

    (void)sMem;

    if (pid == 0) {
        Kitchen k(cmd, this->_multiplier, this->_cooks, this->_refresh);
        busy.doNotDisturb();
        k.takecommand(cmd.getPizzaProperties().first);
        busy.avaible();
        exit(0);
    }
}

template <class Container>
void my_parse(const std::string &str, Container &cont,
              const std::string &delims = " ")
{
    if (str.empty())
        return;
    auto itBeginToken = str.begin();
    auto itEndToken = str.begin();
    cont.clear();

    while (itEndToken != str.end()) {
        std::size_t indexBeginToken =
            str.find_first_not_of(delims, itEndToken - str.begin());
        itBeginToken = str.begin() + indexBeginToken;
        if (itBeginToken == str.end() || indexBeginToken == std::string::npos)
            break;
        itEndToken = std::find_first_of(itBeginToken, str.end(),
                                        delims.begin(), delims.end());
        cont.push_back(std::string(itBeginToken, itEndToken));
    }
}

using ArrayOfCommands = std::vector<std::vector<std::string>>;
ArrayOfCommands Reception::Parser::splitCommand(std::string const &commands) const
{
    std::vector<std::vector<std::string>> parts;
    std::vector<std::string> splitCommands;

    my_parse(commands, splitCommands, ";");
    for (auto it = splitCommands.begin(); it != splitCommands.end(); ++it) {
        auto &command = *it;
        std::vector<std::string> words;
        my_parse(command, words, " ");
        parts.push_back(words);
    }
    return (parts);
}

bool Reception::Parser::isValidCommand(const std::string &command) const
{
    std::vector<std::string> orders;
    my_parse(command, orders, ";");
    if (orders.empty())
        return (false);
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        auto &order = *it;
        std::vector <std::string> parts;
        my_parse(order, parts, " ");
        if (! _isPizzaTypeValid(parts.at(0)) ||
            !_isPizzaSizeValid(parts.at(1)) ||
            !_isPizzaNumberValid(parts.at(2)))
            return (false);
    }
    return (true);
}

bool Reception::Parser::_isPizzaTypeValid(const std::string &pizzaType) const
{
    std::vector<std::string> types = {"regina", "margarita", "fantasia", "americana"};
    for (auto it = types.begin(); it != types.end(); ++it)
        if (*it == pizzaType)
            return (true);
    return (false);
}

bool Reception::Parser::_isPizzaSizeValid(const std::string &pizzaSize) const
{
    std::vector<std::string> size = {"S", "M", "L", "XL", "XXL"};
    for (auto it = size.begin(); it != size.end(); ++it)
        if (*it == pizzaSize)
            return (true);
    return (false);
}

bool Reception::Parser::_isPizzaNumberValid(std::string const &pizzaNumber) const
{
    if (pizzaNumber.size() < 2)
        return (false);
    if (pizzaNumber.at(0) != 'x')
        return (false);
    else if (pizzaNumber.find('.') != std::string::npos)
        return (false);
    else if (pizzaNumber.at(1) < '1' || pizzaNumber.at(1) > '9')
        return (false);

    for (auto it = pizzaNumber.begin(); it != pizzaNumber.end();) {
        it = std::find_if(it + 2, pizzaNumber.end(), is_Number);
        return *it == END_OF_STRING;
    }
    return (true);
}