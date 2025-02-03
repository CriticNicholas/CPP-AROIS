include_directories(Interface)

add_executable(Server Executable/Server.cpp)
add_executable(Client Executable/Client.cpp)

add_executable(Eva Executable/Eva.cpp)

#target_link_libraries(Server PRIVATE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)
#target_link_libraries(Client PRIVATE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)

#target_link_libraries(Eva PRIVATE OpenSSL::SSL OpenSSL::Crypto OpenSSL::applink)

if(WIN32)
  target_link_libraries(Server PRIVATE wsock32 ws2_32)
  target_link_libraries(Client PRIVATE wsock32 ws2_32)

  target_link_libraries(Eva PRIVATE wsock32 ws2_32)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Server Client Eva PROPERTY CXX_STANDARD 17)
endif()