#include "user.hpp"
#include <chrono>
#include <grpcpp/support/status.h>

void User::updateLastLoginTime() {
  _last_login_time = std::chrono::system_clock::now();
}


