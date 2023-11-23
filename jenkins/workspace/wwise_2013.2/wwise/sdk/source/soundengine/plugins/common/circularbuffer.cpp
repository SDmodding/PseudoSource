// File Line: 23
// RVA: 0xAEE940
__int64 __fastcall DSP::CAkCircularBuffer::Init(
        DSP::CAkCircularBuffer *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uSize)
{
  float *v4; // rax
  unsigned int v5; // ecx

  this->m_uSize = in_uSize;
  *(_QWORD *)&this->m_uReadOffset = 0i64;
  this->m_uWriteOffset = 0;
  v4 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * in_uSize);
  v5 = 1;
  this->m_pfData = v4;
  if ( !v4 )
    return 52;
  return v5;
}

// File Line: 42
// RVA: 0xAEE990
void __fastcall DSP::CAkCircularBuffer::Term(DSP::CAkCircularBuffer *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfData )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfData = 0i64;
    this->m_uFramesReady = 0;
  }
  else
  {
    this->m_uFramesReady = 0;
  }
}

// File Line: 52
// RVA: 0xAEE9D0
void __fastcall DSP::CAkCircularBuffer::Reset(DSP::CAkCircularBuffer *this)
{
  float *m_pfData; // rcx

  m_pfData = this->m_pfData;
  if ( m_pfData )
    memset(m_pfData, 0, 4 * this->m_uSize);
  *(_QWORD *)&this->m_uReadOffset = 0i64;
  this->m_uWriteOffset = 0;
}

// File Line: 67
// RVA: 0xAEEA40
unsigned int __fastcall DSP::CAkCircularBuffer::PushFrames(
        DSP::CAkCircularBuffer *this,
        float *in_pfBuffer,
        unsigned int in_NumFrames)
{
  return DSP::CAkCircularBuffer::PushFrames(this, in_pfBuffer, in_NumFrames, this->m_pfData);
}

// File Line: 77
// RVA: 0xAEEA50
unsigned int __fastcall DSP::CAkCircularBuffer::PopFrames(
        DSP::CAkCircularBuffer *this,
        float *out_pfBuffer,
        unsigned int in_RequestedFrames)
{
  return DSP::CAkCircularBuffer::PopFrames(this, out_pfBuffer, in_RequestedFrames, this->m_pfData);
}

// File Line: 87
// RVA: 0xAEEA60
bool __fastcall DSP::CAkCircularBuffer::ReadFrameBlock(
        DSP::CAkCircularBuffer *this,
        float *out_pfBuffer,
        unsigned int in_uBlockSize,
        bool in_bNoMoreInputData)
{
  return DSP::CAkCircularBuffer::ReadFrameBlock(this, out_pfBuffer, in_uBlockSize, in_bNoMoreInputData, this->m_pfData);
}

// File Line: 97
// RVA: 0xAEEA10
__int64 __fastcall DSP::CAkCircularBuffer::AdvanceFrames(DSP::CAkCircularBuffer *this, unsigned int in_uNumFrames)
{
  unsigned int m_uFramesReady; // r9d
  unsigned int v3; // r8d
  unsigned int v4; // edx
  __int64 result; // rax

  m_uFramesReady = this->m_uFramesReady;
  v3 = m_uFramesReady;
  if ( in_uNumFrames < m_uFramesReady )
    v3 = in_uNumFrames;
  v4 = (v3 + this->m_uReadOffset) % this->m_uSize;
  this->m_uFramesReady = m_uFramesReady - v3;
  result = v3;
  this->m_uReadOffset = v4;
  return result;
}

// File Line: 113
// RVA: 0xAEEA80
__int64 __fastcall DSP::CAkCircularBuffer::PushFrames(
        DSP::CAkCircularBuffer *this,
        float *in_pfBuffer,
        unsigned int in_NumFrames,
        float *io_pfData)
{
  unsigned int m_uSize; // edi
  unsigned int v5; // ebx
  __int64 m_uWriteOffset; // rcx
  __int64 v10; // rdi
  unsigned int v11; // edx
  __int64 result; // rax

  m_uSize = this->m_uSize;
  v5 = in_NumFrames;
  if ( this->m_uSize - this->m_uFramesReady < in_NumFrames )
    v5 = this->m_uSize - this->m_uFramesReady;
  if ( !in_pfBuffer || !v5 )
    return 0i64;
  m_uWriteOffset = this->m_uWriteOffset;
  v10 = m_uSize - (unsigned int)m_uWriteOffset;
  if ( v5 < (unsigned int)v10 )
    v10 = v5;
  if ( (_DWORD)v10 )
    memmove(&io_pfData[m_uWriteOffset], in_pfBuffer, (unsigned int)(4 * v10));
  if ( v5 != (_DWORD)v10 )
    memmove(io_pfData, &in_pfBuffer[v10], 4 * (v5 - (unsigned int)v10));
  v11 = (v5 + this->m_uWriteOffset) % this->m_uSize;
  this->m_uFramesReady += v5;
  result = v5;
  this->m_uWriteOffset = v11;
  return result;
}

// File Line: 139
// RVA: 0xAEEB30
__int64 __fastcall DSP::CAkCircularBuffer::PopFrames(
        DSP::CAkCircularBuffer *this,
        float *out_pfBuffer,
        unsigned int in_RequestedFrames,
        float *io_pfData)
{
  unsigned int m_uFramesReady; // ebx
  __int64 m_uReadOffset; // rcx
  __int64 v9; // rsi
  unsigned int v10; // edx
  __int64 result; // rax

  m_uFramesReady = in_RequestedFrames;
  if ( this->m_uFramesReady < in_RequestedFrames )
    m_uFramesReady = this->m_uFramesReady;
  if ( !out_pfBuffer || !m_uFramesReady )
    return 0i64;
  m_uReadOffset = this->m_uReadOffset;
  v9 = (unsigned int)(this->m_uSize - m_uReadOffset);
  if ( m_uFramesReady < (unsigned int)v9 )
    v9 = m_uFramesReady;
  memmove(out_pfBuffer, &io_pfData[m_uReadOffset], (unsigned int)(4 * v9));
  if ( m_uFramesReady != (_DWORD)v9 )
    memmove(&out_pfBuffer[v9], io_pfData, 4 * (m_uFramesReady - (unsigned int)v9));
  v10 = (m_uFramesReady + this->m_uReadOffset) % this->m_uSize;
  this->m_uFramesReady -= m_uFramesReady;
  result = m_uFramesReady;
  this->m_uReadOffset = v10;
  return result;
}

// File Line: 164
// RVA: 0xAEEBE0
char __fastcall DSP::CAkCircularBuffer::ReadFrameBlock(
        DSP::CAkCircularBuffer *this,
        float *out_pfBuffer,
        unsigned int in_uBlockSize,
        bool in_bNoMoreInputData,
        float *io_pfData)
{
  unsigned int m_uFramesReady; // eax
  __int64 v10; // rcx
  __int64 m_uReadOffset; // rcx
  __int64 v12; // rdi
  int v13; // ebx

  if ( !out_pfBuffer || !in_uBlockSize )
    return 0;
  if ( in_bNoMoreInputData )
  {
    m_uFramesReady = this->m_uFramesReady;
    if ( !m_uFramesReady )
      return 0;
    v10 = in_uBlockSize;
    if ( m_uFramesReady < in_uBlockSize )
      v10 = m_uFramesReady;
    if ( in_uBlockSize != (_DWORD)v10 )
      memset(&out_pfBuffer[v10], 0, 4 * (in_uBlockSize - (unsigned int)v10));
  }
  else if ( this->m_uFramesReady < in_uBlockSize )
  {
    return 0;
  }
  m_uReadOffset = this->m_uReadOffset;
  v12 = (unsigned int)(this->m_uSize - m_uReadOffset);
  if ( in_uBlockSize < (unsigned int)v12 )
    v12 = in_uBlockSize;
  memmove(out_pfBuffer, &io_pfData[m_uReadOffset], (unsigned int)(4 * v12));
  v13 = in_uBlockSize - v12;
  if ( v13 )
    memmove(&out_pfBuffer[v12], io_pfData, (unsigned int)(4 * v13));
  return 1;
}

