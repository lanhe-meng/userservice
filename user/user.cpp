#include "user.hpp"
#include <chrono>

void User::updateLastLoginTime() {
  _last_login_time = std::chrono::system_clock::now();
}
