#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <event.h>
#include <thread>
#include <memory>

class Client {
 public:
  Client(const std::string& ip, const int& port);
  virtual ~Client();

  bool GetSocket();
  bool InitEvent();
  void EventLoop();
  bool Init();

  void Loop();

 private:
  bool quit_ = false;
  int sock_fd_;
  std::string ip_;
  int port_;

  event_base* base_;
  event* listen_ev_;
  std::unique_ptr<std::thread> thread_;
};

#endif