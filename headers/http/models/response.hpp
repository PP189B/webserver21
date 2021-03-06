#pragma once

#include <string>
#include <stdint.h>

#include "codes.hpp"

namespace WS { namespace Http
{
  /* @brief Http response class
  */
  class Response
  {
    //  Helpful docs:
    //      https://www.ibm.com/docs/en/cics-ts/5.2?topic=protocol-http-responses

  public:
  /// General
    // start-line
    std::string   version;        //> http version of response
    StatusCode    status_code;    //> status code of response

    // headers
    std::map<std::string, std::string>  headers;    //> full list of headers

    // body
    std::string body;   //> body of response (can be empty)


  /// Constructors
    Response() : version("HTTP/1.1") {}

    Response(StatusCode status) : version("HTTP/1.1"), status_code(status) {}

  }; //!class Response
}} //!namespace WS::Http
