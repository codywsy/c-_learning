#ifndef SERVER_H_
#define SERVER_H_

#include <event.h>
#include <cassert>
#include <functional>
#include <string>
#include <thread>
#include <vector>

class Server {
 public:
  Server();
  virtual ~Server();

  bool Init();
  void Join();

  void OnEvent(int sock_fd, short event);
  void OnRead(bufferevent* bev);
  void OnWrite(bufferevent* bev);
  void OnError(bufferevent* bev, short what);

 private:
  bool Start();
  void Connect();

  bool InitSocket();
  bool InitEvent();

 private:
  int sock_fd_;
  struct event_base* base_;
  struct event* listen_ev_;
  struct bufferevent* buff_ev_;
  std::unique_ptr<std::thread> thread_;
  std::string data_;
  bool quit_;
};

#endif