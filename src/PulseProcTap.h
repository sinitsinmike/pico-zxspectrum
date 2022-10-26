#pragma once

#include <pico/stdlib.h>
#include "PulseProc.h"
#include "PulseProcTone.h"
#include "PulseProcStdHeader.h"
#include "PulseProcStdByteStream.h"
#include "PulseProcStdByte.h"
#include "PulseProcPauseMillis.h"

class PulseProcTap : public PulseProc {
private:

  PulseProcStdHeader* _header;
  PulseProcStdByte* _byte;
  PulseProcStdByteStream* _data;
  PulseProcTone* _end;
  PulseProcPauseMillis* _pause;
  uint32_t _pauseMillis;
  uint32_t _tsPerMs;

public:

  PulseProcTap(
    PulseProcStdHeader* header,
    PulseProcStdByte* byte,
    PulseProcStdByteStream* data,
    PulseProcTone* end,
    PulseProcPauseMillis* pause
  );
  
  void init(
    PulseProc *nxt,
    uint32_t pauseMillis,
    uint32_t tsPerMs
  );
  
  virtual int32_t __not_in_flash_func(advance)(
    InputStream *is,
    bool *pstate,
    PulseProc **top
  );
};
