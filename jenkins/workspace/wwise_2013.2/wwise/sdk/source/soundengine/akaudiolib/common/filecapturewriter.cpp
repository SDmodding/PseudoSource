// File Line: 33
// RVA: 0xA9E5A0
__int64 __fastcall FileCaptureWriter::StartCapture(
        FileCaptureWriter *this,
        const wchar_t *in_CaptureFileName,
        AkWAVEFileHeader *in_pHeader)
{
  AK::IAkStdStream **p_m_pCaptureStream; // rbx
  __int64 result; // rax
  __int64 v6; // r9
  unsigned int v7; // edi
  int v8; // [rsp+20h] [rbp-48h]
  char v9; // [rsp+28h] [rbp-40h]
  int v10; // [rsp+40h] [rbp-28h] BYREF
  __int64 v11; // [rsp+44h] [rbp-24h]
  __int64 v12; // [rsp+50h] [rbp-18h]
  __int16 v13; // [rsp+58h] [rbp-10h]
  int v14; // [rsp+5Ch] [rbp-Ch]
  char v15; // [rsp+70h] [rbp+8h] BYREF

  p_m_pCaptureStream = &this->m_pCaptureStream;
  if ( this->m_pCaptureStream )
    return 1i64;
  v14 = -1;
  v11 = 1i64;
  v10 = 0;
  v13 = 0;
  v12 = 0i64;
  v9 = 1;
  result = ((__int64 (__fastcall *)(AK::IAkStreamMgr *, const wchar_t *, int *, __int64, AK::IAkStdStream **, char))AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd)(
             AK::IAkStreamMgr::m_pStreamMgr,
             in_CaptureFileName,
             &v10,
             2i64,
             p_m_pCaptureStream,
             v9);
  if ( (_DWORD)result == 1 )
  {
    LOBYTE(v6) = 1;
    LOBYTE(v8) = 100;
    v7 = ((__int64 (__fastcall *)(AK::IAkStdStream *, AkWAVEFileHeader *, __int64, __int64, int, _DWORD, char *))(*p_m_pCaptureStream)->vfptr->Write)(
           *p_m_pCaptureStream,
           in_pHeader,
           46i64,
           v6,
           v8,
           0,
           &v15);
    if ( v7 != 1 )
    {
      (*(void (__fastcall **)(AK::IAkStdStream *))(*p_m_pCaptureStream)->vfptr->gap8)(*p_m_pCaptureStream);
      *p_m_pCaptureStream = 0i64;
    }
    return v7;
  }
  return result;
}

// File Line: 68
// RVA: 0xA9E670
__int64 __fastcall FileCaptureWriter::StopCapture(FileCaptureWriter *this, AkWAVEFileHeader *in_pHeader)
{
  AK::IAkStdStream *m_pCaptureStream; // rcx
  AKRESULT v6; // edi
  char v7; // [rsp+50h] [rbp+8h] BYREF

  m_pCaptureStream = this->m_pCaptureStream;
  if ( !m_pCaptureStream )
    return 2i64;
  v6 = m_pCaptureStream->vfptr->SetPosition(m_pCaptureStream, 0i64, AK_MoveBegin, 0i64);
  if ( v6 == AK_Success )
    v6 = ((unsigned int (__fastcall *)(AK::IAkStdStream *, AkWAVEFileHeader *, __int64, __int64, _BYTE, _DWORD, char *))this->m_pCaptureStream->vfptr->Write)(
           this->m_pCaptureStream,
           in_pHeader,
           46i64,
           1i64,
           0,
           0,
           &v7);
  (*(void (__fastcall **)(AK::IAkStdStream *))this->m_pCaptureStream->vfptr->gap8)(this->m_pCaptureStream);
  this->m_pCaptureStream = 0i64;
  return (unsigned int)v6;
}

// File Line: 87
// RVA: 0xA9E560
__int64 __fastcall FileCaptureWriter::PassSampleData(FileCaptureWriter *this, void *in_pData, __int64 in_size)
{
  char *v3; // r9
  char v5; // [rsp+20h] [rbp-28h]
  char v6; // [rsp+50h] [rbp+8h] BYREF

  v3 = &v6;
  LOBYTE(v3) = 1;
  v5 = 0;
  return ((__int64 (__fastcall *)(AK::IAkStdStream *, void *, __int64, char *, char, _DWORD, char *))this->m_pCaptureStream->vfptr->Write)(
           this->m_pCaptureStream,
           in_pData,
           in_size,
           v3,
           v5,
           0,
           &v6);
}

// File Line: 95
// RVA: 0xA9E4D0
void __fastcall FileCaptureWriter::Destroy(FileCaptureWriter *this)
{
  int v1; // edi
  AK::IAkStdStream *m_pCaptureStream; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    this->vfptr = (IAkCaptureWriterVtbl *)&FileCaptureWriter::`vftable;
    m_pCaptureStream = this->m_pCaptureStream;
    if ( m_pCaptureStream )
    {
      (*(void (__fastcall **)(AK::IAkStdStream *))m_pCaptureStream->vfptr->gap8)(m_pCaptureStream);
      this->m_pCaptureStream = 0i64;
    }
    AK::MemoryMgr::Free(v1, this);
  }
}

// File Line: 100
// RVA: 0xA9E530
FileCaptureWriterFactory *__fastcall FileCaptureWriterFactory::Instance()
{
  if ( (_S1_36 & 1) == 0 )
  {
    _S1_36 |= 1u;
    g_Factory.vfptr = (IAkCaptureWriterFactoryVtbl *)&FileCaptureWriterFactory::`vftable;
  }
  return &g_Factory;
}

// File Line: 106
// RVA: 0xA9E490
IAkCaptureWriter *__fastcall FileCaptureWriterFactory::CreateWriter(FileCaptureWriterFactory *this)
{
  IAkCaptureWriter *result; // rax

  result = (IAkCaptureWriter *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x218ui64);
  if ( result )
  {
    result[66].vfptr = 0i64;
    result->vfptr = (IAkCaptureWriterVtbl *)&FileCaptureWriter::`vftable;
  }
  return result;
}

