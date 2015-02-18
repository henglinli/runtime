// -*-coding:utf-8-unix;-*-
#include <iostream>
#include "tree.hh"

class Session
    : public ::base::SplayEntry<Session> {
 public:
  void Set(int fd) {
    fd_ = fd;
  }

  int Compare(Session * other) {
    if (fd_ < other->fd_) {
      return -1;
    } else if (fd_ > other->fd_) {
      return 1;
    } else {
      return 0;
    }
  }

  void Debug() {
    std::cout << fd_ << std::endl;
  }
  
 private:
  int fd_;
};

int main() {
  ::base::SplayTree<Session> header;
  header.Empty();
  Session sessions[10];
  for (size_t i(0); i < sizeof(sessions)/sizeof(sessions[0]) ; ++i) {
    sessions[i].Set(i);
    header.Insert(sessions + i);
  }
  header.Empty();
  auto remove = header.Remove(sessions + 7);
  if (remove) {
    remove->Debug();
  }
  auto find = header.Find(sessions + 7);
  if (find) {
    find->Debug();
  }
  return 0;
}