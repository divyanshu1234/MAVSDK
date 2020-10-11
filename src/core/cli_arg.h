#pragma once

#include <string>

namespace mavsdk {

class CliArg {
public:
    enum class Protocol { None, Udp, Tcp, Serial };

    bool parse(const std::string& uri);

    Protocol get_protocol() { return _protocol; }

    int get_port() const { return _port; }

    int get_baudrate() const { return _baudrate; }

    bool get_flow_control() const { return _flow_control_enabled; }

    std::string get_path() const { return _path; }

    bool get_serial_from_fd() const { return _serial_from_fd; }

    int get_fd() const { return _fd; }

private:
    void reset();
    bool find_protocol(std::string& rest);
    bool find_path(std::string& rest);
    bool find_port(std::string& rest);
    bool find_baudrate(std::string& rest);
    bool find_fd(std::string& rest);

    Protocol _protocol{Protocol::None};
    std::string _path{};
    int _port{0};
    int _baudrate{0};
    bool _flow_control_enabled{false};
    bool _serial_from_fd{false};
    int _fd{-1};
};

} // namespace mavsdk
