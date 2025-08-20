#include <chrono>
#include <ctime>
#include <string>
#include <utility>

class User {
public:
  User(std::string &username) : _username(username) {}
  User(std::string &username, std::string &password)
      : _username(username), _password(password) {}

  void updateLastLoginTime();
  template <typename Str> void updateLastLoginIp(Str &&ip) {
    _last_login_ip = std::forward<Str>(ip);
  }
  template <typename Str> void updateNickname(Str &&nickname) {
    _nickname = std::forward<Str>(nickname);
  }

  User(User &user) = delete;
  User operator=(User &user) = delete;

private:
  std::string _username;
  std::string _password;
  std::string _nickname;
  std::chrono::system_clock::time_point _last_login_time;
  std::string _last_login_ip;
};

class UserService {
    
};
