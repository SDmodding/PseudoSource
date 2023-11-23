// File Line: 20
// RVA: 0xC614A0
void __fastcall hkTypeInfo::finishLoadedObject(hkTypeInfo *this, void *ptr, unsigned int finishFlag)
{
  void (__fastcall *m_finishLoadedObjectFunction)(void *, int); // rax

  m_finishLoadedObjectFunction = this->m_finishLoadedObjectFunction;
  if ( m_finishLoadedObjectFunction )
    m_finishLoadedObjectFunction(ptr, finishFlag);
}

// File Line: 42
// RVA: 0xC614C0
void __fastcall hkTypeInfo::finishLoadedObjectWithoutTracker(hkTypeInfo *this, void *ptr, unsigned int finishFlag)
{
  void (__fastcall *m_finishLoadedObjectFunction)(void *, int); // rax

  m_finishLoadedObjectFunction = this->m_finishLoadedObjectFunction;
  if ( m_finishLoadedObjectFunction )
    m_finishLoadedObjectFunction(ptr, finishFlag);
}

// File Line: 50
// RVA: 0xC61480
void __fastcall hkTypeInfo::cleanupLoadedObject(hkTypeInfo *this, void *ptr)
{
  void (__fastcall *m_cleanupLoadedObjectFunction)(void *); // rax

  m_cleanupLoadedObjectFunction = this->m_cleanupLoadedObjectFunction;
  if ( m_cleanupLoadedObjectFunction )
    m_cleanupLoadedObjectFunction(ptr);
}

