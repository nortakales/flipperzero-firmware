#include "_protocols.h"

const Protocol* protocols[] = {
    &protocol_continuity,
    &protocol_easysetup,
    &protocol_fastpair,
};

const size_t protocols_count = COUNT_OF(protocols);
