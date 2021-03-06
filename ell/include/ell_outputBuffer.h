#pragma once

#include "ell_log.h"
#include "ell_message.pb.h"
#include "ell_socketOps.h"
#include <cstring>
#include <string>
#include <vector>

class ell_outputBuffer {
    const static int kBUFFERSIZE = 1024;

    char input_data_[kBUFFERSIZE];

    int oWriteIdx_ = 0;
    int oReadIdx_ = 0;

public:
    ell_outputBuffer();
    ~ell_outputBuffer();

    ell_outputBuffer(const ell_outputBuffer &) = delete;
    ell_outputBuffer &operator=(const ell_outputBuffer &) = delete;

    // call by input buffer
    void send(int fd);
    void writeMessage(ell::ell_message &message);
};

