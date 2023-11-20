// File Line: 121
// RVA: 0xED37BC
char __fastcall OSuite::ZOMetadata::ClassMatch(OSuite::ZOMetadata *this, int nClassId)
{
  bool v2; // al
  char v3; // cl

  if ( OSuite::ZOMetadata::s_nClassId == nClassId
    || (v2 = OSuite::ZAtomBase::ClassMatch((OSuite::ZAtomBase *)&this->vfptr, nClassId), v3 = 0, v2) )
  {
    v3 = 1;
  }
  return v3;
}

