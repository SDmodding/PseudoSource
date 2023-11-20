// File Line: 32
// RVA: 0xACC150
void __fastcall AkFXTailHandler::HandleTail(AkFXTailHandler *this, AkAudioBuffer *io_pBuffer, unsigned int in_uTotalTailFrames)
{
  AkAudioBuffer *v3; // rdi
  AkFXTailHandler *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  v3 = io_pBuffer;
  v4 = this;
  if ( io_pBuffer->eState == 17 )
  {
    v5 = this->uTailFramesRemaining;
    if ( this->uTailFramesRemaining )
    {
      if ( v5 == -1 )
      {
        this->uTailFramesRemaining = in_uTotalTailFrames;
        this->uTotalTailFrames = in_uTotalTailFrames;
      }
      else
      {
        v6 = this->uTotalTailFrames;
        if ( in_uTotalTailFrames > v6 )
        {
          v4->uTotalTailFrames = in_uTotalTailFrames;
          v4->uTailFramesRemaining = in_uTotalTailFrames + v5 - v6;
        }
      }
      v7 = io_pBuffer->uMaxFrames - io_pBuffer->uValidFrames;
      if ( v4->uTailFramesRemaining < v7 )
        v7 = v4->uTailFramesRemaining;
      v4->uTailFramesRemaining -= v7;
      AkAudioBuffer::ZeroPadToMaxFrames(io_pBuffer);
      if ( v4->uTailFramesRemaining )
        v3->eState = 45;
    }
  }
  else
  {
    this->uTailFramesRemaining = -1;
  }
}

