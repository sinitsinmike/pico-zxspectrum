#pragma once

#include <pico/stdlib.h>
#include "PulseProc.h"
#include "PulseProcTone.h"
#include "PulseProcStdHeader.h"
#include "PulseProcStdByteStream.h"
#include "PulseProcStdByte.h"
#include "PulseProcPauseMillis.h"

class PulseProcTzxTurbo : public PulseProc {
private:

  PulseProcStdHeader* _header;
  PulseProcStdByteStream* _data;
  PulseProcTone* _end;
  PulseProcPauseMillis* _pause;
  uint32_t _tsPerMs;

public:

  PulseProcTzxTurbo(
    PulseProcStdHeader* header,
    PulseProcStdByteStream* data,
    PulseProcTone* end,
    PulseProcPauseMillis* pause
  );
  
  void init(
    PulseProc *nxt,
    uint32_t tsPerMs
  );
  
  virtual int32_t __not_in_flash_func(advance)(
    InputStream *is,
    bool *pstate,
    PulseProc **top
  );
};