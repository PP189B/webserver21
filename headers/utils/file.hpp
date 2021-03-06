#pragma once

#include <string>
#include <sys/stat.h>

namespace WS { namespace Utils
{
  /* @brief Utils for file processing
  */
  class File
  {
  private:
    File(void) {}

  public:
    /* @brief Read entire file to std::string container

      @param filepath   path to target file

      @return All bytes of file in std::string
    */
    static std::string  readFile(const char *filepath);

    /* @brief Write or override (if flag `override` enabled) file `filepath`
              with specified `data` content.

      @param data       data to write
      @param filepath   path to target file
      @param override   append data to file or override entire file
    */
    static void         writeFile(const std::string& data, const char *filepath, bool override=true);


    /* @brief Create all directories given in `path`
              i.e. "tmp/a/b/c"

      @param path Path with directory(-ies) to create\
      @param mode Mode for created directories
    */
    static void         createPath(const char* path, mode_t mode = 0700);

    /* @brief Create single directory given as `dir`

      @param dir  Path to directory to create
      @param mode Mode for created dir
    */
    static void         createDir(const char* dir, mode_t mode = 0700);

    /* @brief Check if path is a directory
    */
    static bool         isDir(const char *path);

    /* @brief Check if path is a directory
    */
    static bool         isFile(const char *path);

    /* @brief Check is file exists
    */
    static bool         pathExists(const char *path);
    
    /* @brief Get current work directory (exec pwd)
    */
    static std::string  getCurrentDir(void);

  }; //!class File
}} //!namespace WS::Utils
