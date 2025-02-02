#include"Interface/Interface.hpp"

int main()
{
    Network::Socket Server("127.0.0.1", 2001);
    Network::Socket Client("127.0.0.1", 2001);

    Server.Host();

    Client.Connect();

    std::cout << Server.Read() << std::endl;
    
    Server.Close();
    Client.Close();
}