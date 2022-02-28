#pragma once

#include "../http/http.hpp"
#include "../config/models/server.hpp"
#include "../config/models/location.hpp"
#include "../config/models/config.hpp"

namespace WS { namespace Core
{
  /* @brief Handler for client's requests
  */
  class RequestHandler
  {
  private:
    RequestHandler() {}

  /// General
  public:
    /* @brief Handle one request from specific ip and port

      @return Serialized response
    */
    static std::string  handle(const std::string& raw_request, 
                                const std::string& ip, 
                                const std::string& port, 
                                const Config::Config& conf);

  private:
    /* @brief Select server from global config for specified client's request
    */
    static const Config::ServerConfig&    selectServer(const Http::Request& request,
                                                        const std::string& ip,
                                                        const std::string& port,
                                                        const Config::Config& conf);

    /* @brief Select location from targeted server for specified client's request
    */
    static const Config::ServerLocation&  selectLocation(const Http::Request& request,
                                                          const Config::ServerConfig& server);

    /* @brief Creates response based on client's request for targeted server and location inside it
    */
    static const std::string              createResponse(const Http::Request& request, 
                                                          const Config::ServerConfig& server,
                                                          const Config::ServerLocation& location);

    /* @brief Creates response with error page specified in server's config 
    */
    static const std::string              createErrorResponse(Http::StatusCode code,
                                                              const Http::Request& request, 
                                                              const Config::ServerConfig& server);


  /// Utils
    static bool   methodIsAllowed(const Http::Request& request, const Config::ServerLocation& location);


  /// Exceptions
  public:
    /* @brief Exception if location not found
    */
    struct	ServerNotFoundException: public std::exception {
      virtual const char  *what() const throw();
    };

    /* @brief Exception if location not found
    */
    struct	LocationNotFoundException: public std::exception {
      virtual const char  *what() const throw();
    };

  }; //!class RequestHandler
}} //!namespace WS::Core