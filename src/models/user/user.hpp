#include "../../../proto/userservice.grpc.pb.h"
#include "../../../proto/userservice.pb.h"
#include <chrono>
#include <ctime>
#include <grpcpp/support/status.h>
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

class UserDB {
  
};

class UserServiceImpl final : public user::UserService::Service {
public:
  grpc::Status CreateUser(grpc::ServerContext *context,
                          const user::CreateUserRequest *request,
                          user::CommonResponse *response) override;
  grpc::Status GetUser(grpc::ServerContext *context,
                       const ::user::UserName *request,
                       user::UserInfo *response) override;
  grpc::Status UpdateUser(grpc::ServerContext *context,
                          const ::user::UserInfo *request,
                          user::CommonResponse *response) override;
  grpc::Status DeleteUser(grpc::ServerContext *context,
                          const user::UserName *request,
                          user::CommonResponse *response) override;

private:

};
