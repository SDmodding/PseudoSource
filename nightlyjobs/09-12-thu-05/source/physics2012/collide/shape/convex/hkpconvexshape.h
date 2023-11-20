// File Line: 83
// RVA: 0xC30B90
__int64 __fastcall hkpConvexShape::getSize(hkpConvexShape *this)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v2, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v2.vfptr, "Not implemented");
  if ( hkError::messageError(
         -1745931428,
         &buf,
         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Collide/Shape/Convex/hkpConvexShape.h",
         83) )
  {
    __debugbreak();
  }
  hkOstream::~hkOstream((hkOstream *)&v2.vfptr);
  return 0i64;
}

