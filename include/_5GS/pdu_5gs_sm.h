#pragma once

#include <_5GS/pdu_5gs.h>

#include <_5GS/ie/PDU_session_identity.h>
#include <_5GS/ie/Procedure_transaction_identity.h>

namespace _5GS
{
class Pdu5gsSm : public Pdu5gs
{

public:
    // for SM messages
    IE::PDU_session_identity pdu_session_identity;
    IE::Procedure_transaction_identity procedure_transaction_identity;

    int codeSMHeader(std::vector<uint8_t> &data) const;
};
} // namespace _5GS
