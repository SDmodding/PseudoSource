// File Line: 17
// RVA: 0xEDEBE8
void __fastcall OSuite::ZHttpWriter::ZHttpWriter(OSuite::ZHttpWriter *this)
{
  OSuite::ZHttpWriter *v1; // rbx
  unsigned __int64 clock; // [rsp+30h] [rbp+8h]

  clock = 0i64;
  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::IWriter};
  OSuite::ZClock::ZClock(&this->m_nNextSendTime, &clock);
  v1->m_nBytesWritten = 0i64;
  v1->m_nTotalLength = 0i64;
  v1->m_nMaxBytesPerSecond = 0i64;
  *(_WORD *)&v1->m_bTransferChunked = 0;
}

// File Line: 38
// RVA: 0xEDEC38
void __fastcall OSuite::ZHttpWriter::~ZHttpWriter(OSuite::ZHttpWriter *this)
{
  OSuite::ZClock *v1; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::ZObject};
  v1 = &this->m_nNextSendTime;
  v1[-2].m_clock = (unsigned __int64)&OSuite::ZHttpWriter::`vftable{for `OSuite::IWriter};
  OSuite::ZOEdmBase::CleanTempData((int)v1);
}

// File Line: 42
// RVA: 0xEDED48
void __fastcall OSuite::ZHttpWriter::Init(OSuite::ZHttpWriter *this)
{
  OSuite::ZHttpWriter *v1; // rbx
  OSuite::ZClock v2; // [rsp+30h] [rbp+8h]
  unsigned __int64 clock; // [rsp+38h] [rbp+10h]

  this->m_nTotalLength = 0i64;
  clock = 0i64;
  v1 = this;
  OSuite::ZClock::ZClock(&v2, &clock);
  v1->m_nNextSendTime = v2;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v2);
  v1->m_nMaxBytesPerSecond = 0i64;
  v1->m_nBytesWritten = 0i64;
  v1->m_bTransferChunked = 0;
}

// File Line: 51
// RVA: 0xEDEFB4
void __fastcall OSuite::ZHttpWriter::Reset(OSuite::ZHttpWriter *this, unsigned __int64 nTotalLength, bool bTransferChunked, unsigned __int64 nMaxBytesPerSecond)
{
  unsigned __int64 v4; // rsi
  bool v5; // di
  OSuite::ZHttpWriter *v6; // rbx
  OSuite::ZClock v7; // [rsp+30h] [rbp+8h]
  unsigned __int64 clock; // [rsp+38h] [rbp+10h]

  v4 = nMaxBytesPerSecond;
  v5 = bTransferChunked;
  v6 = this;
  if ( !nTotalLength && bTransferChunked )
    nTotalLength = -1i64;
  clock = 0i64;
  this->m_nTotalLength = nTotalLength;
  OSuite::ZClock::ZClock(&v7, &clock);
  v6->m_nNextSendTime = v7;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v7);
  v6->m_nBytesWritten = 0i64;
  v6->m_nMaxBytesPerSecond = v4;
  v6->m_bTransferChunked = v5;
}

// File Line: 68
// RVA: 0xEDF02C
__int64 __fastcall OSuite::ZHttpWriter::Write(OSuite::ZHttpWriter *this, char nChar)
{
  OSuite::ZObjectVtbl *v2; // rax
  char v4; // [rsp+20h] [rbp-18h]

  v2 = this->vfptr;
  v4 = nChar;
  return ((__int64 (__fastcall *)(OSuite::ZHttpWriter *, char *, signed __int64))v2[2].__vecDelDtor)(this, &v4, 1i64);
}

// File Line: 73
// RVA: 0xEDF068
char __fastcall OSuite::ZHttpWriter::WriteBuffer(OSuite::ZHttpWriter *this, const void *pData, unsigned __int64 nLength)
{
  return OSuite::ZHttpWriter::InternalWriteBuffer((OSuite::ZHttpWriter *)((char *)this - 8), pData, nLength);
}

// File Line: 78
// RVA: 0xEDF074
char __fastcall OSuite::ZHttpWriter::WriteLastChunk(OSuite::ZHttpWriter *this)
{
  OSuite::ZHttpWriter *v1; // rbx

  v1 = this;
  if ( !this->m_bTransferChunked )
    return 0;
  if ( this->m_bLastChunkSent )
    return 1;
  if ( !((((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() + 1) & 0xFFFFFFFFFFFFFFFEui64) )
    v1->m_bLastChunkSent = (__int64)v1->vfptr[7].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 0);
  return v1->m_bLastChunkSent;
}

// File Line: 93
// RVA: 0xEDF024
unsigned __int64 __fastcall OSuite::ZHttpWriter::Size(OSuite::ZHttpWriter *this)
{
  return this->m_nBytesWritten;
}

// File Line: 98
// RVA: 0xEDED94
char __fastcall OSuite::ZHttpWriter::InternalWriteBuffer(OSuite::ZHttpWriter *this, const void *pData, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  const void *v4; // r14
  OSuite::ZHttpWriter *v5; // rbx
  int v7; // eax
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // [rsp+20h] [rbp-39h]
  unsigned __int64 v10; // [rsp+28h] [rbp-31h]
  OSuite::ZClock v11; // [rsp+30h] [rbp-29h]
  OSuite::ZClock v12; // [rsp+38h] [rbp-21h]
  OSuite::ZClock v13; // [rsp+40h] [rbp-19h]
  OSuite::ZClock v14; // [rsp+48h] [rbp-11h]
  OSuite::ZClock v15; // [rsp+50h] [rbp-9h]
  OSuite::ZClock v16; // [rsp+58h] [rbp-1h]
  unsigned __int64 clock; // [rsp+60h] [rbp+7h]
  unsigned __int64 v18; // [rsp+68h] [rbp+Fh]
  unsigned __int64 v19; // [rsp+70h] [rbp+17h]
  OSuite::ZClock v20; // [rsp+78h] [rbp+1Fh]

  v3 = nLength;
  v4 = pData;
  v5 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[5].__vecDelDtor)() || v3 > v5->m_nTotalLength - v5->m_nBytesWritten )
    return 0;
  if ( !v5->m_nMaxBytesPerSecond )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::ZHttpWriter *, const void *, unsigned __int64))v5->vfptr[6].__vecDelDtor)(
           v5,
           v4,
           v3) )
    {
      v5->m_nBytesWritten += v3;
      return 1;
    }
    return 0;
  }
  if ( v3 )
  {
    while ( 1 )
    {
      clock = OSuite::ZClock::_GetClock();
      OSuite::ZClock::ZClock(&v20, &clock);
      while ( v20.m_clock < v5->m_nNextSendTime.m_clock )
      {
        v18 = 1i64;
        OSuite::ZClock::ZClock(&v14, &v18);
        v10 = v5->m_nNextSendTime.m_clock - v20.m_clock;
        OSuite::ZClock::ZClock(&v13, &v10);
        v9 = v14.m_clock + v13.m_clock;
        OSuite::ZClock::ZClock(&v16, &v9);
        v7 = OSuite::ZClock::_ClockToTime(v16.m_clock, UNIT_CLOCK);
        OSuite::ZThread::ClockSleep(v7);
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v16);
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v13);
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v14);
        v19 = OSuite::ZClock::_GetClock();
        OSuite::ZClock::ZClock(&v15, &v19);
        v20.m_clock = v15.m_clock;
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v15);
      }
      v8 = 256i64;
      if ( v3 < 0x100 )
        v8 = v3;
      if ( v8 > v5->m_nMaxBytesPerSecond )
        v8 = v5->m_nMaxBytesPerSecond;
      v9 = (signed int)(1000 * v8 / v5->m_nMaxBytesPerSecond);
      OSuite::ZClock::ZClock(&v12, &v9);
      v10 = v12.m_clock + v20.m_clock;
      OSuite::ZClock::ZClock(&v11, &v10);
      v5->m_nNextSendTime = v11;
      OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v11);
      OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v12);
      if ( !((unsigned __int8 (__fastcall *)(OSuite::ZHttpWriter *, const void *, unsigned __int64))v5->vfptr[6].__vecDelDtor)(
              v5,
              v4,
              v3) )
        break;
      v5->m_nBytesWritten += v8;
      OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v20);
      v3 -= v8;
      if ( !v3 )
        return 1;
    }
    OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v20);
    return 0;
  }
  return 1;
}

