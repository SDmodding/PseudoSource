// File Line: 26
// RVA: 0xC65A30
void __fastcall hkJobThreadPool::processWorkLoad(hkJobThreadPool *this, void *workLoad)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v2, &buf, 512);
  hkOstream::operator<<(
    (hkOstream *)&v2.vfptr,
    "Make sure you call processAllJobs on job thread pools instead of processWorkLoad");
  if ( hkError::messageError(
         451629525,
         &buf,
         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Base/Thread/Job/ThreadPool/hkJobThreadPool.h",
         26) )
  {
    __debugbreak();
  }
  hkOstream::~hkOstream((hkOstream *)&v2.vfptr);
}

