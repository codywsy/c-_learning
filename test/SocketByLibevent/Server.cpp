#include "Server.h"

#include <iostream>
#include <iomanip>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

static const int BUF_SIZE = 1024;

static void OnAccept(int sock_fd, short event, void *ctx)
{
  Server *server = (Server *)ctx;
  server->OnEvent(sock_fd, event);
}

static void OnConnRead(bufferevent *bev, void *ctx)
{
  Server *server = (Server *)ctx;
  server->OnRead(bev);
}

static void OnConnWrite(bufferevent *bev, void *ctx)
{
  Server *server = (Server *)ctx;
  server->OnWrite(bev);
}

static void OnConnError(bufferevent *bev, short what, void *ctx)
{
  Server *server = (Server *)ctx;
  server->OnError(bev, what);
}

Server::Server() : base_(nullptr), buff_ev_(nullptr), quit_(false)
{
}

Server::~Server()
{
  event_del(listen_ev_);
  event_base_free(base_);
  if (base_ != nullptr)
  {
    base_ = nullptr;
  }
}

bool Server::InitSocket()
{
  sock_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == sock_fd_)
  {
    std::cout << "Error, fd is -1" << std::endl;
    return false;
  }

  struct sockaddr_in local_addr;
  memset(&local_addr, 0, sizeof(local_addr));
  local_addr.sin_family = AF_INET;
  local_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  local_addr.sin_port = htons(9999);
  int bind_result = bind(sock_fd_, (struct sockaddr *)&local_addr, sizeof(struct sockaddr));
  if (bind_result < 0)
  {
    std::cout << "Bind Error in main()" << std::endl;
    return false;
  }

  std::cout << "bind_result=" << bind_result << std::endl;
  listen(sock_fd_, 10);

  std::cout << "Server::InitSocket is finish" << std::endl;
  return true;
}

bool Server::InitEvent()
{
  base_ = event_base_new();

  // todo use event_new and event_add instead
  listen_ev_ = event_new(base_, sock_fd_, EV_READ | EV_PERSIST, OnAccept, this);

  if (0 != event_add(listen_ev_, NULL))
  {
    std::cout << "event_add failed!" << std::endl;
    return false;
  }

  thread_.reset(new std::thread(&Server::Start, this));

  std::cout << "Server::InitEvent is finish" << std::endl;
  return true;
}

bool Server::Init()
{
  if (!InitSocket())
  {
    std::cout << "InitSocket Error!" << std::endl;
    return false;
  }

  if (!InitEvent())
  {
    std::cout << "InitSocket Error!" << std::endl;
    return false;
  }

  return true;
}

void Server::OnEvent(int sock_fd, short event)
{
  struct sockaddr_in remote_addr;
  int sin_size = sizeof(struct sockaddr_in);
  int new_fd = accept(sock_fd_, (struct sockaddr *)&remote_addr, (socklen_t *)&sin_size);
  if (new_fd < 0)
  {
    std::cout << "Accept error in on_accept()" << std::endl;
    return;
  }
  std::cout << "new_fd accpted is " << new_fd << std::endl;

  // init bufferev
  buff_ev_ = bufferevent_socket_new(base_, -1, BEV_OPT_CLOSE_ON_FREE);
  bufferevent_setfd(buff_ev_, new_fd);
  bufferevent_setcb(buff_ev_, OnConnRead, OnConnWrite, OnConnError, this);
  bufferevent_enable(buff_ev_, EV_READ | EV_WRITE | EV_PERSIST);

  std::cout << "build connection from client " << inet_ntoa(remote_addr.sin_addr) << ":" << ntohs(remote_addr.sin_port) << std::endl;
}

void Server::OnRead(bufferevent *bev)
{
  std::cout << "Get in Server::OnRead" << std::endl;
  data_.clear();
  char recv_msg[BUF_SIZE]={0};
  int n = bufferevent_read(bev, &recv_msg, BUF_SIZE);
  if (n <= 0)
  {
    return;
  }

  data_.assign(recv_msg);
  memset(&recv_msg, '\0',  BUF_SIZE);
  std::cout << "recv data: " << data_ << std::endl;
}

void Server::OnWrite(bufferevent *bev)
{
  std::cout << "Get in Server::OnWrite" << std::endl;
}

void Server::OnError(bufferevent *bev, short what)
{
  std::cout << "Get in Server::OnError, what=0x" << std::hex << what << std::endl;
  if (what & BEV_EVENT_CONNECTED)
  {
    std::cout << "Connection Established" << std::endl;
    return;
  }

  if (what & BEV_EVENT_EOF || what & BEV_EVENT_ERROR)
  {
    std::cout << "Some Error and Free event_base" << std::endl;

    bufferevent_free(buff_ev_);
    return;
  }
}

bool Server::Start()
{
  std::cout << "Server::Start()" << std::endl;
  event_base_dispatch(base_);
}


int main(int argc, char **argv)
{
  Server *server = new Server();
  server->Init();

  while (true)
  {
    sleep(10);
  }

  return 0;
}
