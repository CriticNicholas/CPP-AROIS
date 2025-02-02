#include"Interface/Interface.hpp"

int main()
{
    Network::Socket Socket("127.0.0.1", 2001);

    Socket.Host();

    std::cout << Socket.Read() << std::endl;
    
    Socket.Close();
}