// File Line: 20
// RVA: 0xC614A0
void __fastcall hkTypeInfo::finishLoadedObject(hkTypeInfo *this, void *ptr, int finishFlag)
{
  void (__fastcall *v3)(void *, int); // rax

  v3 = this->m_finishLoadedObjectFunction;
  if ( v3 )
    v3(ptr, finishFlag);
}

// File Line: 42
// RVA: 0xC614C0
void __fastcall hkTypeInfo::finishLoadedObjectWithoutTracker(hkTypeInfo *this, void *ptr, int finishFlag)
{
  void (__fastcall *v3)(void *, int); // rax

  v3 = this->m_finishLoadedObjectFunction;
  if ( v3 )
    v3(ptr, finishFlag);
}

// File Line: 50
// RVA: 0xC61480
void __fastcall hkTypeInfo::cleanupLoadedObject(hkTypeInfo *this, void *ptr)
{
  void (__fastcall *v2)(void *); // rax

  v2 = this->m_cleanupLoadedObjectFunction;
  if ( v2 )
    v2(ptr);
}

