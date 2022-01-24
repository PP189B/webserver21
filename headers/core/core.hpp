#pragma once

#include <iostream>

namespace WS::Core
{
  /* @brief General Server class.
  */
  class Server
  {
  /// singleton part
    static Server *instance_;

    Server() {}

  public:
    
	Server(Server& other) = delete;
    
    void operator=(const Server& other) = delete;

    static Server&     getInstance(void);

  /// Logic part
  public:
    
	Server(std::string ip_addr, int port);
	
	/* @brief Server initialization.
    */
    int		init(void);

	/* @brief Runs the server.
    */
    int		run(void);

  private:
    
	/* @brief Preparing Server before work
    *         (set up logger, read config, add thread poll and etc.)
    *  @exception std::exception  Throws when configuration fails 
    *                             (check error message)
    */    
    void	configure(void); // ?

    /* @brief Handler for client connections
    */
    void	handleConnection(int client_socket);

	/* @brief Handler for client disconnections
    */
    void	handleDisconnection(int client_socket);

	/* @brief Send a message to a client
    */
	void	sendMsg(int	socket_to_send, std::string msg, int length);

	/* @brief Recieve a message from a client
    */
	void	recvMsg(int	socket_recv_from, std::string msg, int length);

	/* @brief Handle a message recieved from a client
    */
	void	handleMsg();

  private:
    
	const std::string	ip_addr_;	// ip address from config
	int					port_;		// port from config
	int					socket_;	// listening socket
	

  }; //!class Server
} //!namespace WS::Core