// File Line: 37
// RVA: 0xEE3C00
void __fastcall OSuite::ZLog::ZLog(OSuite::ZLog *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZLog::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_FileMutex);
  this->m_pLogFile = 0i64;
  this->m_logDelegate.m_Closure.m_pFunction = 0i64;
  this->m_logDelegate.m_Closure.m_pthis = 0i64;
}

// File Line: 44
// RVA: 0xEE3C34
void __fastcall OSuite::ZLog::~ZLog(OSuite::ZLog *this)
{
  OSuite::ZFileWriter *m_pLogFile; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZLog::`vftable;
  m_pLogFile = this->m_pLogFile;
  if ( m_pLogFile )
  {
    m_pLogFile->OSuite::ZObject::vfptr->__vecDelDtor(m_pLogFile, 1u);
    this->m_pLogFile = 0i64;
  }
  OSuite::ZMutex::~ZMutex(&this->m_FileMutex);
}

// File Line: 104
// RVA: 0xEE3CA0
void __fastcall OSuite::ZLog::SetLogDelegate(
        OSuite::ZLog *this,
        OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void> *logDelegate)
{
  this->m_logDelegate = *logDelegate;
}

