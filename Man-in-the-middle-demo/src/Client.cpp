#include"Interface/Interface.hpp"

int main()
{
    Network::Socket Socket("127.0.0.1", 2001);

    Socket.Connect();

    std::string Message;
    std::getline(std::cin, Message, '\n');

    Socket.Write(Message);

    Socket.Close();

    return 0;
}