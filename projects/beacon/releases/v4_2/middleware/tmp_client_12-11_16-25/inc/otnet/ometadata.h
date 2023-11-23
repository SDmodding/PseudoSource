// File Line: 121
// RVA: 0xED37BC
char __fastcall OSuite::ZOMetadata::ClassMatch(OSuite::ZOMetadata *this, int nClassId)
{
  bool v2; // al
  char v3; // cl

  if ( OSuite::ZOMetadata::s_nClassId == nClassId )
    return 1;
  v2 = OSuite::ZAtomBase::ClassMatch(this, nClassId);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}

