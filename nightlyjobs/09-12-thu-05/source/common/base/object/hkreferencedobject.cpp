// File Line: 12
// RVA: 0xC55A40
void __fastcall finishLoadedObjecthkBaseObject(void *__formal, int a2)
{
  ;
}

// File Line: 15
// RVA: 0xC55A50
void __fastcall cleanupLoadedObjecthkBaseObject(void *__formal)
{
  ;
}

// File Line: 18
// RVA: 0xC55A60
void **__fastcall getVtablehkBaseObject()
{
  return &hkBaseObject::`vftable;
}

// File Line: 28
// RVA: 0x15C72B0
void **dynamic_initializer_for__hkBaseObjectTypeInfo__()
{
  void **result; // rax

  result = getVtablehkBaseObject();
  hkBaseObjectTypeInfo.m_size = 16i64;
  hkBaseObjectTypeInfo.m_typeName = "hkBaseObject";
  hkBaseObjectTypeInfo.m_vtable = result;
  hkBaseObjectTypeInfo.m_scopedName = "!hkBaseObject";
  hkBaseObjectTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkBaseObject;
  hkBaseObjectTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkBaseObject;
  return result;
}

// File Line: 34
// RVA: 0xC55A30
hkClass *__fastcall hkReferencedObject::getClassType(hkReferencedObject *this)
{
  return 0i64;
}

// File Line: 50
// RVA: 0xC55A70
void __fastcall hkReferencedObjectLock::hkReferencedObjectLock(hkReferencedObjectLock *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObjectLock::`vftable;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 4000);
  this->m_lockMode = LOCK_MODE_AUTO;
  hkMultiThreadCheck::enableChecks(&this->m_multiThreadCheck);
  this->m_lockCount = 0;
}

// File Line: 97
// RVA: 0x15C7310
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkReferencedObjectLock__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkReferencedObjectLock.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkReferencedObjectLock;
  hkSingletonInitList = &hkSingletonRegisterhkReferencedObjectLock;
  return result;
}

// File Line: 100
// RVA: 0xC559A0
void hkReferencedObject::initializeLock(void)
{
  _QWORD **Value; // rax
  hkReferencedObjectLock *v1; // rax
  hkReferencedObjectLock *v2; // rax
  hkReferencedObjectLock *v3; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (hkReferencedObjectLock *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v1 )
  {
    hkReferencedObjectLock::hkReferencedObjectLock(v1);
    v3 = v2;
  }
  else
  {
    v3 = 0i64;
  }
  if ( hkSingleton<hkReferencedObjectLock>::s_instance )
    hkReferencedObject::removeReferenceLockUnchecked(hkSingleton<hkReferencedObjectLock>::s_instance);
  hkSingleton<hkReferencedObjectLock>::s_instance = v3;
}

// File Line: 105
// RVA: 0xC55A00
void hkReferencedObject::deinitializeLock(void)
{
  if ( hkSingleton<hkReferencedObjectLock>::s_instance )
    hkReferencedObject::removeReferenceLockUnchecked(hkSingleton<hkReferencedObjectLock>::s_instance);
  hkSingleton<hkReferencedObjectLock>::s_instance = 0i64;
}

// File Line: 110
// RVA: 0xC55810
void __fastcall hkReferencedObject::setLockMode(hkReferencedObject::LockMode mode)
{
  hkSingleton<hkReferencedObjectLock>::s_instance->m_lockMode = mode;
}

// File Line: 116
// RVA: 0xC55920
void __fastcall hkReferencedObject::lockInit(hkReferencedObject::LockMode lockMode)
{
  _QWORD **Value; // rax
  hkReferencedObjectLock *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rbx

  if ( hkSingleton<hkReferencedObjectLock>::s_instance )
  {
    hkSingleton<hkReferencedObjectLock>::s_instance->m_lockMode = lockMode;
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (hkReferencedObjectLock *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    if ( v3 )
    {
      hkReferencedObjectLock::hkReferencedObjectLock(v3);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    *(_DWORD *)(v5 + 16) = lockMode;
    if ( hkSingleton<hkReferencedObjectLock>::s_instance )
      hkReferencedObject::removeReferenceLockUnchecked(hkSingleton<hkReferencedObjectLock>::s_instance);
    hkSingleton<hkReferencedObjectLock>::s_instance = (hkReferencedObjectLock *)v5;
  }
}

// File Line: 131
// RVA: 0xC55830
__int64 __fastcall hkReferencedObject::getLockMode()
{
  return (unsigned int)hkSingleton<hkReferencedObjectLock>::s_instance->m_lockMode;
}

// File Line: 137
// RVA: 0xC55850
void hkReferencedObject::lockAll(void)
{
  hkReferencedObjectLock *v0; // rbx
  _DWORD *Value; // rdi

  v0 = hkSingleton<hkReferencedObjectLock>::s_instance;
  Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( Value[30] == 601834836 )
  {
    ++v0->m_lockCount;
  }
  else
  {
    EnterCriticalSection(&v0->m_criticalSection.m_section);
    v0->m_lockCount = 1;
    Value[30] = 601834836;
  }
}

// File Line: 143
// RVA: 0xC558B0
void hkReferencedObject::unlockAll(void)
{
  hkReferencedObjectLock *v0; // rbx
  _DWORD *Value; // rax

  v0 = hkSingleton<hkReferencedObjectLock>::s_instance;
  Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( --v0->m_lockCount <= 0 )
  {
    Value[30] = 0;
    LeaveCriticalSection(&v0->m_criticalSection.m_section);
  }
}

// File Line: 159
// RVA: 0xC55420
void __fastcall hkReferencedObject::addReference(hkReferencedObject *this)
{
  hkReferencedObjectLock *v2; // rbx
  _DWORD *Value; // rax
  _DWORD *v4; // rsi
  _DWORD *v5; // rax

  if ( this->m_memSizeAndFlags )
  {
    v2 = hkSingleton<hkReferencedObjectLock>::s_instance;
    Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v2->m_lockMode != LOCK_MODE_AUTO || Value[30] == 601834836 )
    {
      ++this->m_referenceCount;
    }
    else
    {
      v4 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      if ( v4[30] == 601834836 )
      {
        ++v2->m_lockCount;
      }
      else
      {
        EnterCriticalSection(&v2->m_criticalSection.m_section);
        v2->m_lockCount = 1;
        v4[30] = 601834836;
      }
      ++this->m_referenceCount;
      v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      if ( --v2->m_lockCount <= 0 )
      {
        v5[30] = 0;
        LeaveCriticalSection(&v2->m_criticalSection.m_section);
      }
    }
  }
}

// File Line: 186
// RVA: 0xC554F0
void __fastcall hkReferencedObject::removeReference(hkReferencedObject *this)
{
  hkReferencedObjectLock *v2; // rdi
  _DWORD *Value; // rax
  _DWORD *v4; // rsi
  int v5; // esi
  _DWORD *v6; // rax

  if ( this->m_memSizeAndFlags )
  {
    if ( this->m_referenceCount == 1 )
    {
      this->m_referenceCount = 0;
      this->vfptr->__vecDelDtor(this, 1i64);
    }
    else
    {
      v2 = hkSingleton<hkReferencedObjectLock>::s_instance;
      Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      if ( v2->m_lockMode != LOCK_MODE_AUTO || Value[30] == 601834836 )
      {
        v5 = this->m_referenceCount--;
      }
      else
      {
        v4 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v4[30] == 601834836 )
        {
          ++v2->m_lockCount;
        }
        else
        {
          EnterCriticalSection(&v2->m_criticalSection.m_section);
          v2->m_lockCount = 1;
          v4[30] = 601834836;
        }
        v5 = this->m_referenceCount--;
        v6 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( --v2->m_lockCount <= 0 )
        {
          v6[30] = 0;
          LeaveCriticalSection(&v2->m_criticalSection.m_section);
        }
      }
      if ( v5 == 1 )
        this->vfptr->__vecDelDtor(this, 1i64);
    }
  }
}

// File Line: 237
// RVA: 0xC555F0
void __fastcall hkReferencedObject::addReferenceLockUnchecked(hkReferencedObject *this)
{
  if ( this->m_memSizeAndFlags )
    ++this->m_referenceCount;
}

// File Line: 247
// RVA: 0xC55610
void __fastcall hkReferencedObject::removeReferenceLockUnchecked(hkReferencedObject *this)
{
  if ( this->m_memSizeAndFlags )
  {
    if ( this->m_referenceCount-- == 1 )
      this->vfptr->__vecDelDtor(this, 1i64);
  }
}

// File Line: 261
// RVA: 0xC55630
void __fastcall hkReferencedObject::addReferences(
        hkReferencedObject **objects,
        unsigned int numObjects,
        int pointerStriding)
{
  hkReferencedObjectLock *v3; // rsi
  __int64 v5; // rbp
  __int64 v6; // rdi
  _DWORD *Value; // rax
  _DWORD *v8; // r14
  _DWORD *v9; // rax

  v3 = hkSingleton<hkReferencedObjectLock>::s_instance;
  v5 = pointerStriding;
  v6 = numObjects;
  Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v3->m_lockMode == LOCK_MODE_NONE || Value[30] == 601834836 )
  {
    if ( (int)v6 > 0 )
    {
      do
      {
        hkReferencedObject::addReferenceLockUnchecked(*objects);
        objects = (hkReferencedObject **)((char *)objects + v5);
        --v6;
      }
      while ( v6 );
    }
  }
  else
  {
    v8 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v8[30] == 601834836 )
    {
      ++v3->m_lockCount;
    }
    else
    {
      EnterCriticalSection(&v3->m_criticalSection.m_section);
      v3->m_lockCount = 1;
      v8[30] = 601834836;
    }
    if ( (int)v6 > 0 )
    {
      do
      {
        hkReferencedObject::addReferenceLockUnchecked(*objects);
        objects = (hkReferencedObject **)((char *)objects + v5);
        --v6;
      }
      while ( v6 );
    }
    v9 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( --v3->m_lockCount <= 0 )
    {
      v9[30] = 0;
      LeaveCriticalSection(&v3->m_criticalSection.m_section);
    }
  }
}

// File Line: 285
// RVA: 0xC55720
void __fastcall hkReferencedObject::removeReferences(
        hkReferencedObject **objects,
        unsigned int numObjects,
        int pointerStriding)
{
  hkReferencedObjectLock *v3; // rsi
  __int64 v5; // rbp
  __int64 v6; // rdi
  _DWORD *Value; // rax
  _DWORD *v8; // r14
  _DWORD *v9; // rax

  v3 = hkSingleton<hkReferencedObjectLock>::s_instance;
  v5 = pointerStriding;
  v6 = numObjects;
  Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v3->m_lockMode == LOCK_MODE_NONE || Value[30] == 601834836 )
  {
    if ( (int)v6 > 0 )
    {
      do
      {
        hkReferencedObject::removeReferenceLockUnchecked(*objects);
        objects = (hkReferencedObject **)((char *)objects + v5);
        --v6;
      }
      while ( v6 );
    }
  }
  else
  {
    v8 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v8[30] == 601834836 )
    {
      ++v3->m_lockCount;
    }
    else
    {
      EnterCriticalSection(&v3->m_criticalSection.m_section);
      v3->m_lockCount = 1;
      v8[30] = 601834836;
    }
    if ( (int)v6 > 0 )
    {
      do
      {
        hkReferencedObject::removeReferenceLockUnchecked(*objects);
        objects = (hkReferencedObject **)((char *)objects + v5);
        --v6;
      }
      while ( v6 );
    }
    v9 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( --v3->m_lockCount <= 0 )
    {
      v9[30] = 0;
      LeaveCriticalSection(&v3->m_criticalSection.m_section);
    }
  }
}

// File Line: 312
// RVA: 0xC55900
hkCriticalSection *__fastcall hkReferencedObject::getLockCriticalSection()
{
  return &hkSingleton<hkReferencedObjectLock>::s_instance->m_criticalSection;
}

