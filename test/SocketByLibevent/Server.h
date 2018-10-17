#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include <functional>
#include <vector>
#include <cassert>
#include <thread>
#include <event.h>


class Server
{
  public:

    Server();
    virtual ~Server();

    bool Start();
    bool Init();
    bool InitSocket();
    bool InitEvent();

    void Connect();

    void OnEvent(int sock_fd, short event);
    void OnRead(bufferevent* bev);
    void OnWrite(bufferevent* bev);
    void OnError(bufferevent* bev, short what);

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