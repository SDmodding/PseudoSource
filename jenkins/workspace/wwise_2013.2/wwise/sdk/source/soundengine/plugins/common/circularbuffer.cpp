// File Line: 23
// RVA: 0xAEE940
__int64 __fastcall DSP::CAkCircularBuffer::Init(DSP::CAkCircularBuffer *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uSize)
{
  DSP::CAkCircularBuffer *v3; // rbx
  float *v4; // rax
  unsigned int v5; // ecx

  this->m_uSize = in_uSize;
  *(_QWORD *)&this->m_uReadOffset = 0i64;
  this->m_uWriteOffset = 0;
  v3 = this;
  v4 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * in_uSize);
  v5 = 1;
  v3->m_pfData = v4;
  if ( !v4 )
    v5 = 52;
  return v5;
}

// File Line: 42
// RVA: 0xAEE990
void __fastcall DSP::CAkCircularBuffer::Term(DSP::CAkCircularBuffer *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::CAkCircularBuffer *v2; // rbx

  v2 = this;
  if ( this->m_pfData )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->m_pfData = 0i64;
    v2->m_uFramesReady = 0;
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
  DSP::CAkCircularBuffer *v1; // rbx
  float *v2; // rcx

  v1 = this;
  v2 = this->m_pfData;
  if ( v2 )
    memset(v2, 0, 4 * v1->m_uSize);
  *(_QWORD *)&v1->m_uReadOffset = 0i64;
  v1->m_uWriteOffset = 0;
}

// File Line: 67
// RVA: 0xAEEA40
unsigned int __fastcall DSP::CAkCircularBuffer::PushFrames(DSP::CAkCircularBuffer *this, float *in_pfBuffer, unsigned int in_NumFrames)
{
  return DSP::CAkCircularBuffer::PushFrames(this, in_pfBuffer, in_NumFrames, this->m_pfData);
}

// File Line: 77
// RVA: 0xAEEA50
unsigned int __fastcall DSP::CAkCircularBuffer::PopFrames(DSP::CAkCircularBuffer *this, float *out_pfBuffer, unsigned int in_RequestedFrames)
{
  return DSP::CAkCircularBuffer::PopFrames(this, out_pfBuffer, in_RequestedFrames, this->m_pfData);
}

// File Line: 87
// RVA: 0xAEEA60
bool __fastcall DSP::CAkCircularBuffer::ReadFrameBlock(DSP::CAkCircularBuffer *this, float *out_pfBuffer, unsigned int in_uBlockSize, bool in_bNoMoreInputData)
{
  return DSP::CAkCircularBuffer::ReadFrameBlock(this, out_pfBuffer, in_uBlockSize, in_bNoMoreInputData, this->m_pfData);
}

// File Line: 97
// RVA: 0xAEEA10
__int64 __fastcall DSP::CAkCircularBuffer::AdvanceFrames(DSP::CAkCircularBuffer *this, unsigned int in_uNumFrames)
{
  unsigned int v2; // er9
  unsigned int v3; // er8
  unsigned int v4; // edx
  __int64 result; // rax

  v2 = this->m_uFramesReady;
  v3 = this->m_uFramesReady;
  if ( in_uNumFrames < v2 )
    v3 = in_uNumFrames;
  v4 = (v3 + this->m_uReadOffset) % this->m_uSize;
  this->m_uFramesReady = v2 - v3;
  result = v3;
  this->m_uReadOffset = v4;
  return result;
}

// File Line: 113
// RVA: 0xAEEA80
__int64 __fastcall DSP::CAkCircularBuffer::PushFrames(DSP::CAkCircularBuffer *this, float *in_pfBuffer, unsigned int in_NumFrames, float *io_pfData)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  float *v6; // r15
  float *v7; // r14
  DSP::CAkCircularBuffer *v8; // rsi
  __int64 v9; // rcx
  __int64 v10; // rdi
  unsigned int v11; // edx
  __int64 result; // rax

  v4 = this->m_uSize;
  v5 = in_NumFrames;
  v6 = io_pfData;
  v7 = in_pfBuffer;
  v8 = this;
  if ( this->m_uSize - this->m_uFramesReady < in_NumFrames )
    v5 = this->m_uSize - this->m_uFramesReady;
  if ( !in_pfBuffer || !v5 )
    return 0i64;
  v9 = this->m_uWriteOffset;
  v10 = v4 - (unsigned int)v9;
  if ( v5 < (unsigned int)v10 )
    v10 = v5;
  if ( (_DWORD)v10 )
    memmove(&io_pfData[v9], in_pfBuffer, (unsigned int)(4 * v10));
  if ( v5 != (_DWORD)v10 )
    memmove(v6, &v7[v10], 4 * (v5 - (unsigned int)v10));
  v11 = (v5 + v8->m_uWriteOffset) % v8->m_uSize;
  v8->m_uFramesReady += v5;
  result = v5;
  v8->m_uWriteOffset = v11;
  return result;
}

// File Line: 139
// RVA: 0xAEEB30
__int64 __fastcall DSP::CAkCircularBuffer::PopFrames(DSP::CAkCircularBuffer *this, float *out_pfBuffer, unsigned int in_RequestedFrames, float *io_pfData)
{
  unsigned int v4; // ebx
  float *v5; // r15
  float *v6; // r14
  DSP::CAkCircularBuffer *v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rsi
  unsigned int v10; // edx
  __int64 result; // rax

  v4 = in_RequestedFrames;
  v5 = io_pfData;
  if ( this->m_uFramesReady < in_RequestedFrames )
    v4 = this->m_uFramesReady;
  v6 = out_pfBuffer;
  v7 = this;
  if ( !out_pfBuffer || !v4 )
    return 0i64;
  v8 = this->m_uReadOffset;
  v9 = (unsigned int)(v7->m_uSize - v8);
  if ( v4 < (unsigned int)v9 )
    v9 = v4;
  memmove(out_pfBuffer, &io_pfData[v8], (unsigned int)(4 * v9));
  if ( v4 != (_DWORD)v9 )
    memmove(&v6[v9], v5, 4 * (v4 - (unsigned int)v9));
  v10 = (v4 + v7->m_uReadOffset) % v7->m_uSize;
  v7->m_uFramesReady -= v4;
  result = v4;
  v7->m_uReadOffset = v10;
  return result;
}

// File Line: 164
// RVA: 0xAEEBE0
char __fastcall DSP::CAkCircularBuffer::ReadFrameBlock(DSP::CAkCircularBuffer *this, float *out_pfBuffer, unsigned int in_uBlockSize, bool in_bNoMoreInputData, float *io_pfData)
{
  unsigned int v5; // ebx
  float *v6; // rsi
  DSP::CAkCircularBuffer *v7; // rdi
  unsigned int v9; // eax
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rdi
  int v13; // ebx

  v5 = in_uBlockSize;
  v6 = out_pfBuffer;
  v7 = this;
  if ( !out_pfBuffer || !in_uBlockSize )
    return 0;
  if ( in_bNoMoreInputData )
  {
    v9 = this->m_uFramesReady;
    if ( !v9 )
      return 0;
    v10 = in_uBlockSize;
    if ( v9 < in_uBlockSize )
      v10 = v9;
    if ( in_uBlockSize != (_DWORD)v10 )
      memset(&out_pfBuffer[v10], 0, 4 * (in_uBlockSize - (unsigned int)v10));
  }
  else if ( this->m_uFramesReady < in_uBlockSize )
  {
    return 0;
  }
  v11 = v7->m_uReadOffset;
  v12 = (unsigned int)(v7->m_uSize - v11);
  if ( v5 < (unsigned int)v12 )
    v12 = v5;
  memmove(v6, &io_pfData[v11], (unsigned int)(4 * v12));
  v13 = v5 - v12;
  if ( v13 )
    memmove(&v6[v12], io_pfData, (unsigned int)(4 * v13));
  return 1;
}

