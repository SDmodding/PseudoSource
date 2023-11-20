// File Line: 22
// RVA: 0xA939B0
AkCaptureMgr *__fastcall AkCaptureMgr::Instance()
{
  if ( !(_S1_34 & 1) )
  {
    sTheCaptureMgr.m_pWriterFactory = 0i64;
    _S1_34 |= 1u;
    atexit(AkCaptureMgr::Instance_::_2_::_dynamic_atexit_destructor_for__sTheCaptureMgr__);
  }
  return &sTheCaptureMgr;
}

// File Line: 53
// RVA: 0xA93AC0
AkCaptureFile *__fastcall AkCaptureMgr::StartCapture(AkCaptureMgr *this, const wchar_t *in_CaptureFileName, unsigned int in_uNumChannels, unsigned int in_uSampleRate, unsigned int in_uBitsPerSample, AkCaptureFile::FormatTag in_formatTag)
{
  unsigned int v6; // esi
  unsigned int v7; // ebp
  const wchar_t *v8; // r14
  AkCaptureMgr *v9; // rbx
  __int64 v10; // rdi
  AkCaptureFile *v11; // rax
  AkCaptureFile *v12; // rbx

  v6 = in_uSampleRate;
  v7 = in_uNumChannels;
  v8 = in_CaptureFileName;
  v9 = this;
  if ( !this->m_pWriterFactory )
    this->m_pWriterFactory = (IAkCaptureWriterFactory *)FileCaptureWriterFactory::Instance();
  v10 = ((__int64 (*)(void))v9->m_pWriterFactory->vfptr->CreateWriter)();
  if ( !v10 )
    return 0i64;
  v11 = (AkCaptureFile *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v12 = v11;
  if ( !v11 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 24i64))(v10);
    return 0i64;
  }
  v11->m_uDataSize = 0;
  v11->m_pWriter = (IAkCaptureWriter *)v10;
  v11->m_Header.RIFF = 0i64;
  *(_QWORD *)&v11->m_Header.uWAVE = 0i64;
  *(_QWORD *)&v11->m_Header.fmt.dwChunkSize = 0i64;
  *(_QWORD *)&v11->m_Header.fmtHeader.nSamplesPerSec = 0i64;
  *(_QWORD *)&v11->m_Header.fmtHeader.nBlockAlign = 0i64;
  *(unsigned int *)((char *)&v11->m_Header.data.ChunkId + 2) = 0;
  HIWORD(v11->m_Header.data.dwChunkSize) = 0;
  if ( (unsigned int)AkCaptureFile::StartCapture(v11, v8, v7, v6, in_uBitsPerSample, in_formatTag) != 1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v12);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 24i64))(v10);
    v12 = 0i64;
  }
  return v12;
}

// File Line: 93
// RVA: 0xA93A30
__int64 __fastcall AkCaptureFile::StartCapture(AkCaptureFile *this, const wchar_t *in_Name, unsigned int in_uNumChannels, unsigned int in_uSampleRate, unsigned int in_uBitsPerSample, AkCaptureFile::FormatTag in_formatTag)
{
  unsigned int v6; // er11

  this->m_Header.fmtHeader.nChannels = in_uNumChannels;
  this->m_Header.fmtHeader.wFormatTag = in_formatTag;
  this->m_Header.RIFF.ChunkId = 1179011410;
  this->m_Header.RIFF.dwChunkSize = -1;
  this->m_Header.uWAVE = 1163280727;
  v6 = in_uBitsPerSample * in_uNumChannels >> 3;
  this->m_Header.fmt.ChunkId = 544501094;
  this->m_Header.fmt.dwChunkSize = 18;
  this->m_Header.fmtHeader.nSamplesPerSec = in_uSampleRate;
  this->m_Header.fmtHeader.wBitsPerSample = in_uBitsPerSample;
  this->m_Header.fmtHeader.nBlockAlign = v6;
  this->m_Header.data.ChunkId = 1635017060;
  this->m_Header.data.dwChunkSize = -1;
  this->m_Header.fmtHeader.nAvgBytesPerSec = in_uSampleRate * v6;
  this->m_Header.fmtHeader.cbSize = 0;
  return this->m_pWriter->vfptr->StartCapture(this->m_pWriter, in_Name, (AkWAVEFileHeader *)this);
}

// File Line: 114
// RVA: 0xA93BC0
signed __int64 __fastcall AkCaptureFile::StopCapture(AkCaptureFile *this)
{
  AkCaptureFile *v1; // rdi
  IAkCaptureWriter *v2; // rcx
  unsigned int v4; // edx
  AKRESULT v5; // ebx

  v1 = this;
  v2 = this->m_pWriter;
  if ( !v2 )
    return 1i64;
  v4 = v1->m_uDataSize;
  v1->m_Header.data.dwChunkSize = v4;
  v1->m_Header.RIFF.dwChunkSize = v4 + 38;
  v5 = (unsigned int)v2->vfptr->StopCapture(v2, &v1->m_Header);
  ((void (*)(void))v1->m_pWriter->vfptr->Destroy)();
  v1->m_pWriter = 0i64;
  AK::MemoryMgr::Free(g_DefaultPoolId, v1);
  return (unsigned int)v5;
}

// File Line: 129
// RVA: 0xA939F0
__int64 __fastcall AkCaptureFile::PassSampleData(AkCaptureFile *this, void *in_pData, unsigned int in_size)
{
  AkCaptureFile *v3; // rbx
  IAkCaptureWriter *v4; // rcx
  unsigned int v5; // edi
  __int64 result; // rax

  v3 = this;
  v4 = this->m_pWriter;
  v5 = in_size;
  if ( !v4 )
    return 2i64;
  result = ((__int64 (__fastcall *)(IAkCaptureWriter *, void *))v4->vfptr->PassSampleData)(v4, in_pData);
  if ( (_DWORD)result == 1 )
    v3->m_uDataSize += v5;
  return result;
}

