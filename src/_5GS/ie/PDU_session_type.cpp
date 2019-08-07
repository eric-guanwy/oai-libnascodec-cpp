#include <_5GS/ie/PDU_session_type.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

const std::string PDU_session_type::name = "PDU session type";

PDU_session_type::PDU_session_type()
{
}

PDU_session_type::PDU_session_type(Value value)
{
    this->set(value);
}

void PDU_session_type::set(PDU_session_type::Value value)
{
    this->m_present = true;
    this->m_value = value;
}

PDU_session_type::Value PDU_session_type::get() const
{
    this->raise_exception_if_not_present(className(this));
    return this->m_value;
}

int PDU_session_type::code_TV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    this->raise_exception_if_not_present(className(this));

    uint8_t c, v;
    v = static_cast<uint8_t>(this->m_value);
    c = (iei & 0xf0) | v;
    data.push_back(c);
    return 1;
}

int PDU_session_type::decode_TV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    uint8_t v;
    if (data.size() == 0)
    {
        throw std::runtime_error(
            std::string("No data to decode") +
            std::string(__PRETTY_FUNCTION__));
    }

    if ((iei & 0x0f) != 0)
    {
        throw std::runtime_error(
            std::string("Invalid IEI") +
            std::string(__PRETTY_FUNCTION__));
    }

    v = data[0] & 0x0f;
    switch (v)
    {
    case static_cast<uint8_t>(PDU_session_type::Value::Ethernet):
        this->m_value = PDU_session_type::Value::Ethernet;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv4):
        this->m_value = PDU_session_type::Value::IPv4;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv6):
        this->m_value = PDU_session_type::Value::IPv6;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv4v6):
        this->m_value = PDU_session_type::Value::IPv4v6;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::Unstructured):
        this->m_value = PDU_session_type::Value::Unstructured;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::reserved):
        this->m_value = PDU_session_type::Value::reserved;
        break;
    default:
        throw std::runtime_error(
            std::string(__PRETTY_FUNCTION__) +
            std::string(" Invalid data:\n") +
            dump_wireshark(data));
    }
    this->m_present = true;
    return 1;
}

std::string PDU_session_type::to_string() const
{
    if (not this->isSet())
    {
        return "-";
    }
    return PDU_session_type::value_to_string(this->m_value);
}

std::string PDU_session_type::value_to_string(const PDU_session_type::Value value)
{
    switch (value)
    {
    case PDU_session_type::Value::IPv4:
        return "IPv4";
    case PDU_session_type::Value::IPv6:
        return "IPv6";
    case PDU_session_type::Value::IPv4v6:
        return "IPv4v6";
    case PDU_session_type::Value::Unstructured:
        return "Unstructured";
    case PDU_session_type::Value::Ethernet:
        return "Ethernet";
    case PDU_session_type::Value::reserved:
        return "reserved";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS
