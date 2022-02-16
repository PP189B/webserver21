#pragma once

#include <iostream>
#include <vector>
#include <sys/select.h> 

#define CLIENT_DISCONNECTED -1

#include "../../headers/config/config.hpp"

namespace WS { namespace Core
{
  /* @brief General Server class.
  */
  class Server
  {
  
  public:

    static Server instance_;

  private:

    Server() { }
    Server(Server&) { }
    Server& operator=(const Server&) { return *this; }

  public:

    static Server &  getInstance();
    
    /* @brief Server initialization.
      *  @exception std::exception  Throws when function fails 
      *                             (check error message)
      */
    void    init(const char* config_path);

    /* @brief Runs the server.
      *  @exception std::exception  Throws when function fails 
      *                             (check error message)
      */
    int     run(void);
    
    /* @brief Preparing Server before work
      *         (set up logger, read config, add thread poll and etc.)
      *  @exception std::exception  Throws when configuration fails 
      *                             (check error message)
      */    
    void    configure(void); // ?

  private:

    /* @brief Tells if the socket is a listening socket
      */
    bool  isListening(int socket) const;

    /* @brief Function for accepting client connection
      *  @exception std::exception  Throws when accept() fails 
      *                             (check error message)
      */
    int   acceptConnection(int listening_socket) const;

    /* @brief Handler for client connections
      */
    void  handleConnection(int client_socket, fd_set& writefds);

    /* @brief Handler for client disconnections
      */
    void  handleDisconnection(int client_socket);

    /* @brief Recieve a message from a client
      */
    int   recvMsg(int socket_recv_from);

    /* @brief Handle a message recieved from a client
      */
    void  handleMsg(std::string msg, int msg_owner) const;

    /* @brief Send a message to a client
      */
    void  sendMsg(int socket_to_send, const char* msg, int msg_size) const;

    /* @brief Close all listening sockets
      */
    void  closeListeningSockets() const;

  private:

    std::vector<int>      listening_socket_; // mb change on simple int*
    fd_set                master_set_;
    const Config::Config  conf_;

  }; //!class Server
}} //!namespace WS::Core