#pragma once
#ifndef MESSMER_FSPP_FSINTERFACE_CONTEXT_H_
#define MESSMER_FSPP_FSINTERFACE_CONTEXT_H_

#include <cstdint>

namespace fspp {

enum class TimestampUpdateBehavior : uint8_t {
    // currently only relatime and noatime supported
    RELATIME,
    NOATIME
    // TODO STRICTATIME
};

class Context final {
public:
    explicit Context(TimestampUpdateBehavior timestampUpdateBehavior)
    : _timestampUpdateBehavior(timestampUpdateBehavior) {}

    TimestampUpdateBehavior timestampUpdateBehavior() const {
        return _timestampUpdateBehavior;
    }

    void setTimestampUpdateBehavior(TimestampUpdateBehavior value) {
        _timestampUpdateBehavior = value;
    }

private:
    TimestampUpdateBehavior _timestampUpdateBehavior;
};

}

#endif
