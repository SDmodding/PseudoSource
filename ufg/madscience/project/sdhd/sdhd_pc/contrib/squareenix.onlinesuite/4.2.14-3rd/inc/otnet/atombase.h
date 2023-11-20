// File Line: 43
// RVA: 0x427440
OSuite::ZAtomBase *__fastcall OSuite::ZAtomBase::Cast<OSuite::ZOEntry>(OSuite::ZAtomBase *this)
{
  OSuite::ZAtomBase *v1; // rbx
  char v2; // al
  OSuite::ZAtomBase *v3; // rdx

  v1 = this;
  v2 = (__int64)this->vfptr[1].__vecDelDtor((OSuite::ZObject *)this, OSuite::ZOEntry::s_nClassId);
  v3 = 0i64;
  if ( v2 )
    v3 = v1;
  return v3;
}

