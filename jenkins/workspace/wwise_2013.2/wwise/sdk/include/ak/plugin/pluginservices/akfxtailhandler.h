// File Line: 32
// RVA: 0xACC150
void __fastcall AkFXTailHandler::HandleTail(
        AkFXTailHandler *this,
        AkAudioBuffer *io_pBuffer,
        unsigned int in_uTotalTailFrames)
{
  unsigned int uTailFramesRemaining; // eax
  unsigned int uTotalTailFrames; // ecx
  unsigned int v7; // ecx

  if ( io_pBuffer->eState == AK_NoMoreData )
  {
    uTailFramesRemaining = this->uTailFramesRemaining;
    if ( this->uTailFramesRemaining )
    {
      if ( uTailFramesRemaining == -1 )
      {
        this->uTailFramesRemaining = in_uTotalTailFrames;
        this->uTotalTailFrames = in_uTotalTailFrames;
      }
      else
      {
        uTotalTailFrames = this->uTotalTailFrames;
        if ( in_uTotalTailFrames > uTotalTailFrames )
        {
          this->uTotalTailFrames = in_uTotalTailFrames;
          this->uTailFramesRemaining = in_uTotalTailFrames + uTailFramesRemaining - uTotalTailFrames;
        }
      }
      v7 = io_pBuffer->uMaxFrames - io_pBuffer->uValidFrames;
      if ( this->uTailFramesRemaining < v7 )
        v7 = this->uTailFramesRemaining;
      this->uTailFramesRemaining -= v7;
      AkAudioBuffer::ZeroPadToMaxFrames(io_pBuffer);
      if ( this->uTailFramesRemaining )
        io_pBuffer->eState = AK_DataReady;
    }
  }
  else
  {
    this->uTailFramesRemaining = -1;
  }
}

