
#include "Client.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cassert>
#include <cstring>
#include <iostream>

static const int BUF_SIZE = 1024;
static const std::string ip("127.0.0.1");
static const int port = 9999;

static void OnRead(int fd, short what, void* arg) {}

Client::Client(const std::string& ip, const int& port)
    : base_(nullptr), listen_ev_(nullptr) {
  assert(!ip.empty());

  ip_.assign(ip);
  port_ = port;
}

Client::~Client() {
  if (listen_ev_ != nullptr) {
    event_free(listen_ev_);
  }

  if (base_ != nullptr) {
    event_base_free(base_);
  }
}

bool Client::GetSocket() {
  sock_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == sock_fd_) {
    std::cout << "Error on producing socket" << std::endl;
    return false;
  }

  std::cout << "ServerIP:Port= " << ip_ << ":" << port_ << std::endl;
  std::cout << "fd= " << sock_fd_ << std::endl;

  struct sockaddr_in remote_addr;
  memset(&remote_addr, 0, sizeof(struct sockaddr_in));
  remote_addr.sin_family = AF_INET;
  remote_addr.sin_addr.s_addr = inet_addr(ip_.c_str());
  remote_addr.sin_port = htons(port_);
  if (0 > connect(sock_fd_, (struct sockaddr*)&remote_addr,
                  sizeof(struct sockaddr))) {
    std::cout << "Connect Error!" << std::endl;
    close(sock_fd_);
    return false;
  }

  return true;
}

bool Client::InitEvent() {
  base_ = event_base_new();
  listen_ev_ =
      event_new(base_, sock_fd_, EV_READ | EV_PERSIST, OnRead, (void*)this);
  if (nullptr == listen_ev_) {
    std::cout << "Event create error!" << std::endl;
    event_base_free(base_);
    return false;
  }

  event_add(listen_ev_, NULL);
  return true;
}

bool Client::Init() {
  if (GetSocket() < 0) {
    std::cout << "GetSocket Error!" << std::endl;
    return false;
  }

  if (InitEvent() < 0) {
    std::cout << "InitEvent Error!" << std::endl;
    return false;
  }

  thread_.reset(new std::thread(&Client::EventLoop, this));
  thread_->detach();

  return true;
}

void Client::EventLoop() {
  event_base_dispatch(base_);
  std::cout << "EventLoop Exit!" << std::endl;
}

void Client::Loop() {
  char buffer[BUF_SIZE];
  while (!quit_) {
    std::cout << "Input your data to server(\'q\' or \"quit\" to exit)"
              << std::endl;
    std::cin >> buffer;
    if (strcmp("q", buffer) == 0 || strcmp("quit", buffer) == 0) {
      quit_ = true;
      event_base_loopexit(base_, 0);
      event_del(listen_ev_);
      close(sock_fd_);
      sleep(1);
      std::cout << "Loop Break!" << std::endl;
      break;
    }

    int num = write(sock_fd_, buffer, strlen(buffer));
    std::cout << num << " ch are written" << std::endl;
    sleep(2);
  }

}

int main(int argc, char** argv) {
  Client* client = new Client(ip, port);
  if (!client->Init()) {
    std::cout << "Client Init Failed!" << std::endl;
    return -1;
  }

  client->Loop();

  return 0;
}