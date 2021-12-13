#pragma once

#include <vector>

#include "./server.hpp"

namespace WS::Config
{
  /* @brief Config structure that contains 
            all settings and servers of WebServer
  */
  struct Config 
  {
    
    // < list of servers
    static std::vector<ServerConfig> server_list; 

  }; //!class Config
} //!namespace WS::Config
