#include "../../headers/utils/debug.hpp"

namespace WS { namespace Utils {

  void   Debug::printConf(const Config::Config &conf)
  {
    int n = (int)conf.server_list.size();

    for (int i = 0; i < n; i++)
    {
      std::cout << "\n ------- SERVER -------" << '\n';
      std::cout << "ip_addr         " << conf.server_list[i].ip_addr << '\n';

      std::cout << "server_name     ";
      int s = (int)conf.server_list[i].server_name.size();
      if (s > 0)
      {
        for (int v = 0; v < s; v++)
          std::cout << conf.server_list[i].server_name[v] << " ";      
      }
      std::cout << std::endl;

      std::cout << "port            " << conf.server_list[i].port << '\n';
      std::cout << "root            " << conf.server_list[i].root << '\n';
      std::cout << "autoindex       " << conf.server_list[i].autoindex << '\n';
      std::cout << "buff_size_body  " << conf.server_list[i].buff_size_body << '\n';
      std::cout << "error_page      " << conf.server_list[i].error_page << '\n';

      int m = (int)conf.server_list[i].location_list.size();
      for (int j = 0; j < m; j++)
      {
        std::cout << "location:" << '\n';
        std::cout << "    path      " << conf.server_list[i].location_list[j].path << '\n';
        std::cout << "    root      " << conf.server_list[i].location_list[j].root << '\n';

        std::cout << "    method    ";
        int l = (int)conf.server_list[i].location_list[j].method.size();
        if (l > 0)
        {
          for (int k = 0; k < l; k++)
            std::cout << conf.server_list[i].location_list[j].method[k] << " ";
        }
        std::cout << std::endl;
      }
    }
    std::cout << std::endl;
  }

}} //!namespace WS::Utils