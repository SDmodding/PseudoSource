// File Line: 37
// RVA: 0xEE3C00
void __fastcall OSuite::ZLog::ZLog(OSuite::ZLog *this)
{
  OSuite::ZLog *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZLog::`vftable';
  OSuite::ZMutex::ZMutex(&this->m_FileMutex);
  v1->m_pLogFile = 0i64;
  v1->m_logDelegate.m_Closure.m_pFunction = 0i64;
  v1->m_logDelegate.m_Closure.m_pthis = 0i64;
}

// File Line: 44
// RVA: 0xEE3C34
void __fastcall OSuite::ZLog::~ZLog(OSuite::ZLog *this)
{
  OSuite::ZLog *v1; // rbx
  OSuite::ZFileWriter *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZLog::`vftable';
  v2 = this->m_pLogFile;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
    v1->m_pLogFile = 0i64;
  }
  OSuite::ZMutex::~ZMutex(&v1->m_FileMutex);
}

// File Line: 104
// RVA: 0xEE3CA0
void __fastcall OSuite::ZLog::SetLogDelegate(OSuite::ZLog *this, OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void> *logDelegate)
{
  this->m_logDelegate = *logDelegate;
}

