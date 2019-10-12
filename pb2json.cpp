#include <string>
#include <fstream>
#include <google/protobuf/message.h>
#include "json.hpp"
#include "byReflection/pb2json.h"

using namespace std;
using Json =  nlohmann::json;
using PbMessage = google::protobuf::Message;

bool json2pb(google::protobuf::Message& msg, istream& is)
{
    Json json;
    is>>json;
    // auto jobj = Json::parse(str);
    return Pb2Json::Json2Message(json, msg, true);
}
bool json_file2pb(PbMessage& msg, const string& json_file_path)
{
    ifstream ifs(json_file_path);
    if(!ifs.is_open())
    {
        return false;
    } 
    return json2pb(msg, ifs);
    // auto size = ifs.tellg();
    // string str(size, '\0'); // 构造 string 为流大小
    // ifs.seekg(0);
    // if(!ifs.read(str.data(), size))
    // {
    //     return false;
    // }
    // auto json = Json::parse(str);
    // return Pb2Json::Json2Message(json, msg);

}

bool json2pb(google::protobuf::Message& msg, const std::string& json_value)
{
    auto json = Json::parse(json_value);
    return Pb2Json::Json2Message(json, msg, true);
}
string pb2json(const PbMessage& msg, bool style)
{
    Json json;
    Pb2Json::Message2Json(msg,json);

    ostringstream oss;
    if(style)
        oss<<std::setw(4);
    oss<<json;
    return oss.str();

}