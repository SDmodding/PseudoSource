// File Line: 26
// RVA: 0xC65A30
void __fastcall hkJobThreadPool::processWorkLoad(hkJobThreadPool *this, void *workLoad)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v2, buf, 512);
  hkOstream::operator<<(&v2, "Make sure you call processAllJobs on job thread pools instead of processWorkLoad");
  if ( hkError::messageError(
         451629525,
         buf,
         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Base/Thread/Job/ThreadPool/hkJobThreadPool.h",
         26) )
  {
    __debugbreak();
  }
  hkOstream::~hkOstream(&v2);
}

