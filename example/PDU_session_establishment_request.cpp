#include <stdio.h>
#include <vector>

#include <helpers.h>
#include <_5GS/PDU_session_establishment_request.h>
//#include <_5GS/ie/PDU_session_identity.h>
//#include <_5GS/ie/PDU_session_type.h>
//#include <nas.h>
//#include <information_element.h>

using namespace _5GS;

void example_with_PDU()
{
   //PDU_session_establishment_request pdu;
 }

int example_with_ie()
{
    // IE examples

    IE::PDU_session_identity session_id;
    std::vector<uint8_t> data1;

    session_id.set(IE::PDU_session_identity::Value::PDU_session_identity_value_3);

    if (session_id.code(data1, InformationElement::Format::V) < 0)
    {
        std::cerr << "Error coding PDU session identity";
        return -1;
    }

    IE::PDU_session_type session_type;
    std::vector<uint8_t> data2;

    session_type.set(IE::PDU_session_type::Value::IPv6);

    if (session_type.code(data2, InformationElement::Format::TV) < 0)
    {
        std::cerr << "Error coding PDU session type";
        return -1;
    }

    std::cout << data1 << data2;
    return 0;
}

int main()
{
    return example_with_ie();
}