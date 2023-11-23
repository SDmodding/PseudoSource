// File Line: 268
// RVA: 0xCDC130
__int64 __fastcall hkgpMesh::IConvexOverlap::IConvexShape::getMaxIndex(hkgpMesh::IConvexOverlap::IConvexShape *this)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v2, buf, 512);
  hkOstream::operator<<(&v2, "Not implemented");
  if ( (unsigned int)hkError::messageError(
                       0xCFA7DFCC,
                       buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Mesh/hkgpMesh.h",
                       268) )
    __debugbreak();
  hkOstream::~hkOstream(&v2);
  return 0i64;
}

