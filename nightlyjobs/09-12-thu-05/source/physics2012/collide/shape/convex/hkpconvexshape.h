// File Line: 83
// RVA: 0xC30B90
__int64 __fastcall hkpConvexShape::getSize(hkpConvexShape *this)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v2, buf, 512);
  hkOstream::operator<<(&v2, "Not implemented");
  if ( hkError::messageError(
         -1745931428,
         buf,
         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Collide/Shape/Convex/hkpConvexShape.h",
         83) )
  {
    __debugbreak();
  }
  hkOstream::~hkOstream(&v2);
  return 0i64;
}

