// File Line: 17
// RVA: 0xEDEBE8
void __fastcall OSuite::ZHttpWriter::ZHttpWriter(OSuite::ZHttpWriter *this)
{
  unsigned __int64 clock; // [rsp+30h] [rbp+8h] BYREF

  clock = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::ZObject};
  this->OSuite::IWriter::vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::IWriter};
  OSuite::ZClock::ZClock(&this->m_nNextSendTime, &clock);
  this->m_nBytesWritten = 0i64;
  this->m_nTotalLength = 0i64;
  this->m_nMaxBytesPerSecond = 0i64;
  *(_WORD *)&this->m_bTransferChunked = 0;
}

// File Line: 38
// RVA: 0xEDEC38
void __fastcall OSuite::ZHttpWriter::~ZHttpWriter(OSuite::ZHttpWriter *this)
{
  OSuite::ZClock *p_m_nNextSendTime; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpWriter::`vftable{for `OSuite::ZObject};
  p_m_nNextSendTime = &this->m_nNextSendTime;
  p_m_nNextSendTime[-2].m_clock = (unsigned __int64)&OSuite::ZHttpWriter::`vftable{for `OSuite::IWriter};
  OSuite::ZOEdmBase::CleanTempData((int)p_m_nNextSendTime);
}

// File Line: 42
// RVA: 0xEDED48
void __fastcall OSuite::ZHttpWriter::Init(OSuite::ZHttpWriter *this)
{
  OSuite::ZClock v2; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 clock; // [rsp+38h] [rbp+10h] BYREF

  this->m_nTotalLength = 0i64;
  clock = 0i64;
  OSuite::ZClock::ZClock(&v2, &clock);
  this->m_nNextSendTime = v2;
  OSuite::ZOEdmBase::CleanTempData((int)&v2);
  this->m_nMaxBytesPerSecond = 0i64;
  this->m_nBytesWritten = 0i64;
  this->m_bTransferChunked = 0;
}

// File Line: 51
// RVA: 0xEDEFB4
void __fastcall OSuite::ZHttpWriter::Reset(
        OSuite::ZHttpWriter *this,
        unsigned __int64 nTotalLength,
        bool bTransferChunked,
        unsigned __int64 nMaxBytesPerSecond)
{
  OSuite::ZClock v7; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 clock; // [rsp+38h] [rbp+10h] BYREF

  if ( !nTotalLength && bTransferChunked )
    nTotalLength = -1i64;
  clock = 0i64;
  this->m_nTotalLength = nTotalLength;
  OSuite::ZClock::ZClock(&v7, &clock);
  this->m_nNextSendTime = v7;
  OSuite::ZOEdmBase::CleanTempData((int)&v7);
  this->m_nBytesWritten = 0i64;
  this->m_nMaxBytesPerSecond = nMaxBytesPerSecond;
  this->m_bTransferChunked = bTransferChunked;
}

// File Line: 68
// RVA: 0xEDF02C
__int64 __fastcall OSuite::ZHttpWriter::Write(OSuite::ZHttpWriter *this, char nChar)
{
  OSuite::ZObjectVtbl *vfptr; // rax
  char v4[8]; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->OSuite::ZObject::vfptr;
  v4[0] = nChar;
  return ((__int64 (__fastcall *)(OSuite::ZHttpWriter *, char *, __int64))vfptr[2].__vecDelDtor)(this, v4, 1i64);
}

// File Line: 73
// RVA: 0xEDF068
char __fastcall OSuite::ZHttpWriter::WriteBuffer(
        OSuite::ZHttpWriter *this,
        const void *pData,
        unsigned __int64 nLength)
{
  return OSuite::ZHttpWriter::InternalWriteBuffer((OSuite::ZHttpWriter *)((char *)this - 8), pData, nLength);
}

// File Line: 78
// RVA: 0xEDF074
bool __fastcall OSuite::ZHttpWriter::WriteLastChunk(OSuite::ZHttpWriter *this)
{
  if ( !this->m_bTransferChunked )
    return 0;
  if ( this->m_bLastChunkSent )
    return 1;
  if ( ((((__int64 (__fastcall *)(OSuite::ZHttpWriter *))this->OSuite::ZObject::vfptr[4].__vecDelDtor)(this) + 1) & 0xFFFFFFFFFFFFFFFEui64) == 0 )
    this->m_bLastChunkSent = (bool)this->OSuite::ZObject::vfptr[7].__vecDelDtor(this, 0i64);
  return this->m_bLastChunkSent;
}

// File Line: 93
// RVA: 0xEDF024
unsigned __int64 __fastcall OSuite::ZHttpWriter::Size(OSuite::ZHttpWriter *this)
{
  return this->m_nBytesWritten;
}

// File Line: 98
// RVA: 0xEDED94
char __fastcall OSuite::ZHttpWriter::InternalWriteBuffer(
        OSuite::ZHttpWriter *this,
        const void *pData,
        unsigned __int64 nLength)
{
  int v7; // eax
  unsigned __int64 m_nMaxBytesPerSecond; // rsi
  unsigned __int64 v9; // [rsp+20h] [rbp-39h] BYREF
  unsigned __int64 v10; // [rsp+28h] [rbp-31h] BYREF
  OSuite::ZClock v11; // [rsp+30h] [rbp-29h] BYREF
  OSuite::ZClock v12; // [rsp+38h] [rbp-21h] BYREF
  OSuite::ZClock v13; // [rsp+40h] [rbp-19h] BYREF
  OSuite::ZClock v14; // [rsp+48h] [rbp-11h] BYREF
  OSuite::ZClock v15; // [rsp+50h] [rbp-9h] BYREF
  OSuite::ZClock v16; // [rsp+58h] [rbp-1h] BYREF
  unsigned __int64 clock; // [rsp+60h] [rbp+7h] BYREF
  unsigned __int64 v18; // [rsp+68h] [rbp+Fh] BYREF
  unsigned __int64 v19; // [rsp+70h] [rbp+17h] BYREF
  OSuite::ZClock v20; // [rsp+78h] [rbp+1Fh] BYREF

  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZHttpWriter *))this->OSuite::ZObject::vfptr[5].__vecDelDtor)(this)
    || nLength > this->m_nTotalLength - this->m_nBytesWritten )
  {
    return 0;
  }
  if ( !this->m_nMaxBytesPerSecond )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::ZHttpWriter *, const void *, unsigned __int64))this->OSuite::ZObject::vfptr[6].__vecDelDtor)(
           this,
           pData,
           nLength) )
    {
      this->m_nBytesWritten += nLength;
      return 1;
    }
    return 0;
  }
  if ( nLength )
  {
    while ( 1 )
    {
      clock = OSuite::ZClock::_GetClock();
      OSuite::ZClock::ZClock(&v20, &clock);
      while ( v20.m_clock < this->m_nNextSendTime.m_clock )
      {
        v18 = 1i64;
        OSuite::ZClock::ZClock(&v14, &v18);
        v10 = this->m_nNextSendTime.m_clock - v20.m_clock;
        OSuite::ZClock::ZClock(&v13, &v10);
        v9 = v14.m_clock + v13.m_clock;
        OSuite::ZClock::ZClock(&v16, &v9);
        v7 = OSuite::ZClock::_ClockToTime(v16.m_clock, UNIT_CLOCK);
        OSuite::ZThread::ClockSleep(v7);
        OSuite::ZOEdmBase::CleanTempData((int)&v16);
        OSuite::ZOEdmBase::CleanTempData((int)&v13);
        OSuite::ZOEdmBase::CleanTempData((int)&v14);
        v19 = OSuite::ZClock::_GetClock();
        OSuite::ZClock::ZClock(&v15, &v19);
        v20.m_clock = v15.m_clock;
        OSuite::ZOEdmBase::CleanTempData((int)&v15);
      }
      m_nMaxBytesPerSecond = 256i64;
      if ( nLength < 0x100 )
        m_nMaxBytesPerSecond = nLength;
      if ( m_nMaxBytesPerSecond > this->m_nMaxBytesPerSecond )
        m_nMaxBytesPerSecond = this->m_nMaxBytesPerSecond;
      v9 = (int)(1000 * m_nMaxBytesPerSecond / this->m_nMaxBytesPerSecond);
      OSuite::ZClock::ZClock(&v12, &v9);
      v10 = v12.m_clock + v20.m_clock;
      OSuite::ZClock::ZClock(&v11, &v10);
      this->m_nNextSendTime = v11;
      OSuite::ZOEdmBase::CleanTempData((int)&v11);
      OSuite::ZOEdmBase::CleanTempData((int)&v12);
      if ( !((unsigned __int8 (__fastcall *)(OSuite::ZHttpWriter *, const void *, unsigned __int64))this->OSuite::ZObject::vfptr[6].__vecDelDtor)(
              this,
              pData,
              nLength) )
        break;
      this->m_nBytesWritten += m_nMaxBytesPerSecond;
      OSuite::ZOEdmBase::CleanTempData((int)&v20);
      nLength -= m_nMaxBytesPerSecond;
      if ( !nLength )
        return 1;
    }
    OSuite::ZOEdmBase::CleanTempData((int)&v20);
    return 0;
  }
  return 1;
}

