// File Line: 33
// RVA: 0xA9E5A0
signed __int64 __fastcall FileCaptureWriter::StartCapture(FileCaptureWriter *this, const wchar_t *in_CaptureFileName, AkWAVEFileHeader *in_pHeader)
{
  AK::IAkStdStream **v3; // rbx
  AkWAVEFileHeader *v4; // rdi
  signed __int64 result; // rax
  bool v6; // ST28_1
  __int64 v7; // r9
  unsigned int v8; // edi
  __int64 v9; // [rsp+20h] [rbp-48h]
  __int64 v10; // [rsp+28h] [rbp-40h]
  int v11; // [rsp+40h] [rbp-28h]
  __int64 v12; // [rsp+44h] [rbp-24h]
  __int64 v13; // [rsp+50h] [rbp-18h]
  __int16 v14; // [rsp+58h] [rbp-10h]
  int v15; // [rsp+5Ch] [rbp-Ch]
  char v16; // [rsp+70h] [rbp+8h]

  v3 = &this->m_pCaptureStream;
  v4 = in_pHeader;
  if ( this->m_pCaptureStream )
    return 1i64;
  v15 = -1;
  v12 = 1i64;
  v11 = 0;
  v14 = 0;
  v13 = 0i64;
  v6 = 1;
  result = AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
             AK::IAkStreamMgr::m_pStreamMgr,
             in_CaptureFileName,
             (AkFileSystemFlags *)&v11,
             AK_OpenModeWriteOvrwr,
             v3,
             v6);
  if ( (_DWORD)result == 1 )
  {
    LODWORD(v10) = 0;
    LOBYTE(v7) = 1;
    LOBYTE(v9) = 100;
    v8 = ((__int64 (__fastcall *)(AK::IAkStdStream *, AkWAVEFileHeader *, signed __int64, __int64, __int64, __int64, char *))(*v3)->vfptr->Write)(
           *v3,
           v4,
           46i64,
           v7,
           v9,
           v10,
           &v16);
    if ( v8 != 1 )
    {
      (*(void (**)(void))(*v3)->vfptr->gap8)();
      *v3 = 0i64;
    }
    result = v8;
  }
  return result;
}

// File Line: 68
// RVA: 0xA9E670
signed __int64 __fastcall FileCaptureWriter::StopCapture(FileCaptureWriter *this, AkWAVEFileHeader *in_pHeader)
{
  FileCaptureWriter *v2; // rbx
  AK::IAkStdStream *v3; // rcx
  AkWAVEFileHeader *v4; // rsi
  AKRESULT v6; // edi
  char v7; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = this->m_pCaptureStream;
  v4 = in_pHeader;
  if ( !v3 )
    return 2i64;
  v6 = (unsigned int)v3->vfptr->SetPosition(v3, 0i64, 0i64, 0i64);
  if ( v6 == 1 )
    v6 = ((unsigned int (__fastcall *)(AK::IAkStdStream *, AkWAVEFileHeader *, signed __int64, signed __int64, _BYTE, _DWORD, char *))v2->m_pCaptureStream->vfptr->Write)(
           v2->m_pCaptureStream,
           v4,
           46i64,
           1i64,
           0,
           0,
           &v7);
  (*(void (**)(void))v2->m_pCaptureStream->vfptr->gap8)();
  v2->m_pCaptureStream = 0i64;
  return (unsigned int)v6;
}

// File Line: 87
// RVA: 0xA9E560
__int64 __fastcall FileCaptureWriter::PassSampleData(FileCaptureWriter *this, void *in_pData, __int64 in_size)
{
  char *v3; // r9
  int v4; // ST28_4
  char v5; // ST20_1
  char v7; // [rsp+50h] [rbp+8h]

  v3 = &v7;
  LOBYTE(v3) = 1;
  v4 = 0;
  v5 = 0;
  return ((__int64 (__fastcall *)(AK::IAkStdStream *, void *, __int64, char *, char, int, char *))this->m_pCaptureStream->vfptr->Write)(
           this->m_pCaptureStream,
           in_pData,
           in_size,
           v3,
           v5,
           v4,
           &v7);
}

// File Line: 95
// RVA: 0xA9E4D0
void __fastcall FileCaptureWriter::Destroy(FileCaptureWriter *this)
{
  int v1; // edi
  FileCaptureWriter *v2; // rbx
  AK::IAkStdStream *v3; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    v2 = this;
    this->vfptr = (IAkCaptureWriterVtbl *)&FileCaptureWriter::`vftable;
    v3 = this->m_pCaptureStream;
    if ( v3 )
    {
      (*(void (**)(void))v3->vfptr->gap8)();
      v2->m_pCaptureStream = 0i64;
    }
    AK::MemoryMgr::Free(v1, v2);
  }
}

// File Line: 100
// RVA: 0xA9E530
FileCaptureWriterFactory *__fastcall FileCaptureWriterFactory::Instance()
{
  if ( !(_S1_36 & 1) )
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

