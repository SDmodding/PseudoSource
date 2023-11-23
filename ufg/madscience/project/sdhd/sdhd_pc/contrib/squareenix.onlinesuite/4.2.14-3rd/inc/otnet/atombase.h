// File Line: 43
// RVA: 0x427440
OSuite::ZOEntry *__fastcall OSuite::ZAtomBase::Cast<OSuite::ZOEntry>(OSuite::ZAtomBase *this)
{
  char v2; // al
  __int64 v3; // rdx

  v2 = (char)this->vfptr[1].__vecDelDtor(this, (unsigned int)OSuite::ZOEntry::s_nClassId);
  v3 = 0i64;
  if ( v2 )
    return (OSuite::ZOEntry *)this;
  return (OSuite::ZOEntry *)v3;
}

