#include<Interface.hpp>

#define Ip "127.0.0.1"
#define Port 65432

void ServerToClient(Network::Socket* Server, Network::Socket* Client)
{
    while(true)
    {
        Client->Write(Server->Read());
    }
}
int main()
{
    Network::Socket Server(Ip, Port);
    Network::Socket Client(Ip, Port);

    Client.Host();

    Server.Connect();

    std::thread Thread(ServerToClient, &Server, &Client);

    while(true)
    {
        Server.Write(Client.Read());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Thread.detach();

    Server.Close();
    Client.Close();
}