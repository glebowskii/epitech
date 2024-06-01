#ifndef MESSAGETYPE_HPP
#define MESSAGETYPE_HPP

#include <map>
#include <string>

class IpcMessageType {
public:
    enum Value : uint8_t {
        UNKNOWN,
        CLOSE_KITCHEN_SIGNAL,
        GET_KITCHEN_STATUS_REQUEST,
        GET_KITCHEN_STATUS_RESPONSE,
    };

    IpcMessageType(Value value);
    ~IpcMessageType() = default;

    IpcMessageType::Value getValue() const;
    std::string toString() const;
    static std::string toString(IpcMessageType::Value value);
    static IpcMessageType::Value fromString(const std::string& value);
private:
    Value value;
    static const std::string valueToString[];
    static const std::map<std::string, IpcMessageType::Value> stringToValue;
};

#endif //MESSAGETYPE_HPP
