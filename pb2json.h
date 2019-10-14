#pragma once
#include <string>
#include <istream>

namespace google{namespace protobuf{ class Message;}}
bool json_file2pb(google::protobuf::Message& msg, const std::string& json_file_path);
bool json2pb(google::protobuf::Message& msg, std::istream& is);
bool json2pb(google::protobuf::Message& msg, const std::string& json_value);
std::string pb2json(const google::protobuf::Message& msg, bool style = false);


