#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

namespace WS { namespace Utils {
  /* @brief Static class for String processing
  */
  class String
  {
  public:
    /*  @brief Split string by delimeter
        @param source       string to split
        @param delim        delimiter as string
    */
    static std::vector<std::string>  split(const std::string& source, const std::string& delim);

    /*  @brief Split string by delimeter
        @param source       string to split
        @param delim        delimiter as char
    */
    static std::vector<std::string>  split(const std::string& source, char delim);


    /*  @brief Split string to two parts by delimeter (if it exists in string)
        @param source       string to split
        @param delim        delimiter as string
    */
    static std::vector<std::string>  splitOnce(const std::string& source, const std::string& delim);

    /*  @brief Split string to two parts by delimeter (if it exists in string)
        @param source       string to split
        @param delim        delimiter as char
    */
    static std::vector<std::string>  splitOnce(const std::string& source, char delim);

    /* @brief Split string for parsing. Separate by spaсe.
      */
    static std::vector<std::string>  splitStr(std::string line);

    /* @brief Some type to string
      */
    template <typename T>
    static std::string  to_string(T data);

    /* @brief Convert entire string to lowercase (ASCII only)
    */
    static std::string  toLower(std::string text);

  }; //!class String
  
  template <typename T>
  std::string                          Utils::String::to_string(T data)
  {
    std::ostringstream result;

    result << data;
    return result.str();
  }
  
}} //!namespace WS::Utils
