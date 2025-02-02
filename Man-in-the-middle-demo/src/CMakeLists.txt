add_executable(Server Server.cpp)
add_executable(Client Client.cpp)

target_link_libraries(Server PRIVATE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)
target_link_libraries(Client PRIVATE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)

if(WIN32)
  target_link_libraries(Server PRIVATE wsock32 ws2_32)
  target_link_libraries(Client PRIVATE wsock32 ws2_32)
endif()