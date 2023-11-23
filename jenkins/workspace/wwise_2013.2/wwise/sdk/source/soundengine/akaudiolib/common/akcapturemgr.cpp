// File Line: 22
// RVA: 0xA939B0
AkCaptureMgr *__fastcall AkCaptureMgr::Instance()
{
  if ( (_S1_34 & 1) == 0 )
  {
    sTheCaptureMgr.m_pWriterFactory = 0i64;
    _S1_34 |= 1u;
    atexit(AkCaptureMgr::Instance_::_2_::_dynamic_atexit_destructor_for__sTheCaptureMgr__);
  }
  return &sTheCaptureMgr;
}

// File Line: 53
// RVA: 0xA93AC0
AkCaptureFile *__fastcall AkCaptureMgr::StartCapture(
        AkCaptureMgr *this,
        const wchar_t *in_CaptureFileName,
        unsigned int in_uNumChannels,
        unsigned int in_uSampleRate,
        unsigned int in_uBitsPerSample,
        AkCaptureFile::FormatTag in_formatTag)
{
  IAkCaptureWriter *v10; // rdi
  AkCaptureFile *v11; // rax
  AkCaptureFile *v12; // rbx

  if ( !this->m_pWriterFactory )
    this->m_pWriterFactory = FileCaptureWriterFactory::Instance();
  v10 = this->m_pWriterFactory->vfptr->CreateWriter(this->m_pWriterFactory);
  if ( !v10 )
    return 0i64;
  v11 = (AkCaptureFile *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v12 = v11;
  if ( !v11 )
  {
    v10->vfptr->Destroy(v10);
    return 0i64;
  }
  v11->m_uDataSize = 0;
  v11->m_pWriter = v10;
  v11->m_Header.RIFF = 0i64;
  *(_QWORD *)&v11->m_Header.uWAVE = 0i64;
  *(_QWORD *)&v11->m_Header.fmt.dwChunkSize = 0i64;
  *(_QWORD *)&v11->m_Header.fmtHeader.nSamplesPerSec = 0i64;
  *(_QWORD *)&v11->m_Header.fmtHeader.nBlockAlign = 0i64;
  *(unsigned int *)((char *)&v11->m_Header.data.ChunkId + 2) = 0;
  HIWORD(v11->m_Header.data.dwChunkSize) = 0;
  if ( (unsigned int)AkCaptureFile::StartCapture(
                       v11,
                       in_CaptureFileName,
                       in_uNumChannels,
                       in_uSampleRate,
                       in_uBitsPerSample,
                       in_formatTag) != 1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v12);
    v10->vfptr->Destroy(v10);
    return 0i64;
  }
  return v12;
}

// File Line: 93
// RVA: 0xA93A30
__int64 __fastcall AkCaptureFile::StartCapture(
        AkCaptureFile *this,
        const wchar_t *in_Name,
        unsigned int in_uNumChannels,
        unsigned int in_uSampleRate,
        unsigned int in_uBitsPerSample,
        AkCaptureFile::FormatTag in_formatTag)
{
  unsigned int v6; // r11d

  this->m_Header.fmtHeader.nChannels = in_uNumChannels;
  this->m_Header.fmtHeader.wFormatTag = in_formatTag;
  this->m_Header.RIFF.ChunkId = 1179011410;
  this->m_Header.RIFF.dwChunkSize = -1;
  this->m_Header.uWAVE = 1163280727;
  v6 = (in_uBitsPerSample * in_uNumChannels) >> 3;
  this->m_Header.fmt.ChunkId = 544501094;
  this->m_Header.fmt.dwChunkSize = 18;
  this->m_Header.fmtHeader.nSamplesPerSec = in_uSampleRate;
  this->m_Header.fmtHeader.wBitsPerSample = in_uBitsPerSample;
  this->m_Header.fmtHeader.nBlockAlign = v6;
  this->m_Header.data.ChunkId = 1635017060;
  this->m_Header.data.dwChunkSize = -1;
  this->m_Header.fmtHeader.nAvgBytesPerSec = in_uSampleRate * v6;
  this->m_Header.fmtHeader.cbSize = 0;
  return ((__int64 (__fastcall *)(IAkCaptureWriter *, const wchar_t *, AkCaptureFile *))this->m_pWriter->vfptr->StartCapture)(
           this->m_pWriter,
           in_Name,
           this);
}

// File Line: 114
// RVA: 0xA93BC0
__int64 __fastcall AkCaptureFile::StopCapture(AkCaptureFile *this)
{
  IAkCaptureWriter *m_pWriter; // rcx
  unsigned int m_uDataSize; // edx
  AKRESULT v5; // ebx

  m_pWriter = this->m_pWriter;
  if ( !m_pWriter )
    return 1i64;
  m_uDataSize = this->m_uDataSize;
  this->m_Header.data.dwChunkSize = m_uDataSize;
  this->m_Header.RIFF.dwChunkSize = m_uDataSize + 38;
  v5 = m_pWriter->vfptr->StopCapture(m_pWriter, &this->m_Header);
  this->m_pWriter->vfptr->Destroy(this->m_pWriter);
  this->m_pWriter = 0i64;
  AK::MemoryMgr::Free(g_DefaultPoolId, this);
  return (unsigned int)v5;
}

// File Line: 129
// RVA: 0xA939F0
__int64 __fastcall AkCaptureFile::PassSampleData(AkCaptureFile *this, void *in_pData, unsigned int in_size)
{
  IAkCaptureWriter *m_pWriter; // rcx
  __int64 result; // rax

  m_pWriter = this->m_pWriter;
  if ( !m_pWriter )
    return 2i64;
  result = ((__int64 (__fastcall *)(IAkCaptureWriter *, void *))m_pWriter->vfptr->PassSampleData)(m_pWriter, in_pData);
  if ( (_DWORD)result == 1 )
    this->m_uDataSize += in_size;
  return result;
}

