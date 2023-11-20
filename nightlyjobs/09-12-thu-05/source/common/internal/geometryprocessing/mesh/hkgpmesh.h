// File Line: 268
// RVA: 0xCDC130
__int64 __fastcall hkgpMesh::IConvexOverlap::IConvexShape::getMaxIndex(hkgpMesh::IConvexOverlap::IConvexShape *this)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v2, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v2.vfptr, "Not implemented");
  if ( (unsigned int)hkError::messageError(
                       -811081780,
                       &buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Mesh/hkgpMesh.h",
                       268) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v2.vfptr);
  return 0i64;
}

