// File Line: 26
// RVA: 0x15D8500
__int64 hkHavokCurrentClasses::_dynamic_initializer_for__hkHavokDefaultClassRegistry__()
{
  hkStaticClassNameRegistry::hkStaticClassNameRegistry(
    &hkHavokCurrentClasses::hkHavokDefaultClassRegistry,
    hkBuiltinTypeRegistry::StaticLinkedClasses,
    -1,
    "hk_2013.2.0-r1");
  return atexit(hkHavokCurrentClasses::_dynamic_atexit_destructor_for__hkHavokDefaultClassRegistry__);
}

// File Line: 30
// RVA: 0xE38740
void __fastcall hkBuiltinTypeRegistry::addType(hkBuiltinTypeRegistry *this, hkTypeInfo *info, hkClass *klass)
{
  hkDefaultClassNameRegistry *v3; // rbx
  hkClass *v4; // rsi
  hkBaseObjectVtbl *v5; // rdi
  hkTypeInfo *v6; // rbp
  const char *v7; // rax

  v3 = hkSingleton<hkDefaultClassNameRegistry>::s_instance;
  v4 = klass;
  v5 = hkSingleton<hkDefaultClassNameRegistry>::s_instance->vfptr;
  v6 = info;
  v7 = hkClass::getName(klass);
  ((void (__fastcall *)(hkDefaultClassNameRegistry *, hkClass *, const char *))v5[3].__first_virtual_table_function__)(
    v3,
    v4,
    v7);
  ((void (__fastcall *)(hkTypeInfoRegistry *, hkTypeInfo *))hkSingleton<hkTypeInfoRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
    hkSingleton<hkTypeInfoRegistry>::s_instance,
    v6);
  if ( (signed int)hkClass::getNumInterfaces(v4) > 0 )
    ((void (__fastcall *)(hkVtableClassRegistry *, const void *, hkClass *))hkSingleton<hkVtableClassRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
      hkSingleton<hkVtableClassRegistry>::s_instance,
      v6->m_vtable,
      v4);
}

// File Line: 49
// RVA: 0xE38BE0
void __fastcall hkDefaultBuiltinTypeRegistry::init(hkDefaultBuiltinTypeRegistry *this)
{
  hkTypeInfo *v1; // rcx
  hkTypeInfoRegistry *v2; // rdi
  hkTypeInfo *const *v3; // rbx

  ((void (__fastcall *)(hkDefaultClassNameRegistry *, hkStaticClassNameRegistry *))hkSingleton<hkDefaultClassNameRegistry>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkDefaultClassNameRegistry>::s_instance,
    &hkHavokCurrentClasses::hkHavokDefaultClassRegistry);
  v1 = hkBuiltinTypeRegistry::StaticLinkedTypeInfos[0];
  v2 = hkSingleton<hkTypeInfoRegistry>::s_instance;
  v3 = hkBuiltinTypeRegistry::StaticLinkedTypeInfos;
  if ( hkBuiltinTypeRegistry::StaticLinkedTypeInfos[0] )
  {
    do
    {
      ((void (__fastcall *)(hkTypeInfoRegistry *, hkTypeInfo *))v2->vfptr[1].__first_virtual_table_function__)(v2, v1);
      v1 = (hkTypeInfo *)*((_QWORD *)v3 + 1);
      ++v3;
    }
    while ( v1 );
  }
  hkVtableClassRegistry::registerList(
    hkSingleton<hkVtableClassRegistry>::s_instance,
    hkBuiltinTypeRegistry::StaticLinkedTypeInfos,
    hkBuiltinTypeRegistry::StaticLinkedClasses);
}

// File Line: 56
// RVA: 0xE38BC0
hkTypeInfoRegistry *__fastcall hkDefaultBuiltinTypeRegistry::getTypeInfoRegistry(hkDefaultBuiltinTypeRegistry *this)
{
  return hkSingleton<hkTypeInfoRegistry>::s_instance;
}

// File Line: 61
// RVA: 0xE38A00
hkDefaultClassNameRegistry *__fastcall hkDefaultBuiltinTypeRegistry::getClassNameRegistry(hkDefaultBuiltinTypeRegistry *this)
{
  return hkSingleton<hkDefaultClassNameRegistry>::s_instance;
}

// File Line: 66
// RVA: 0xE38BD0
hkVtableClassRegistry *__fastcall hkDefaultBuiltinTypeRegistry::getVtableClassRegistry(hkDefaultBuiltinTypeRegistry *this)
{
  return hkSingleton<hkVtableClassRegistry>::s_instance;
}

// File Line: 71
// RVA: 0xE38E40
void __fastcall hkDefaultBuiltinTypeRegistry::reinitialize(hkDefaultBuiltinTypeRegistry *this)
{
  hkDefaultBuiltinTypeRegistry *v1; // rdi
  _QWORD **v2; // rax
  __int64 v3; // rax
  hkDefaultClassNameRegistry *v4; // rbx
  _QWORD **v5; // rax
  __int64 v6; // rax
  hkTypeInfoRegistry *v7; // rbx
  _QWORD **v8; // rax
  __int64 v9; // rax
  hkVtableClassRegistry *v10; // rbx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 56i64);
  v4 = (hkDefaultClassNameRegistry *)v3;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkDynamicClassNameRegistry::`vftable';
    *(_QWORD *)(v3 + 16) = "hk_2013.2.0-r1";
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(v3 + 24),
      0);
    v4->vfptr = (hkBaseObjectVtbl *)&hkDefaultClassNameRegistry::`vftable';
  }
  else
  {
    v4 = 0i64;
  }
  if ( hkSingleton<hkDefaultClassNameRegistry>::s_instance )
    hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkDefaultClassNameRegistry>::s_instance->vfptr);
  hkSingleton<hkDefaultClassNameRegistry>::s_instance = v4;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 48i64);
  v7 = (hkTypeInfoRegistry *)v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = 0x1FFFF;
    *(_QWORD *)v6 = &hkTypeInfoRegistry::`vftable';
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(v6 + 16),
      0);
    v7->m_finishFlag = 1;
    v7->m_informMemoryTracker = 1;
  }
  else
  {
    v7 = 0i64;
  }
  if ( hkSingleton<hkTypeInfoRegistry>::s_instance )
    hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkTypeInfoRegistry>::s_instance->vfptr);
  hkSingleton<hkTypeInfoRegistry>::s_instance = v7;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
  v10 = (hkVtableClassRegistry *)v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)v9 = &hkVtableClassRegistry::`vftable';
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = -1;
  }
  else
  {
    v10 = 0i64;
  }
  if ( hkSingleton<hkVtableClassRegistry>::s_instance )
    hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkVtableClassRegistry>::s_instance->vfptr);
  hkSingleton<hkVtableClassRegistry>::s_instance = v10;
  hkDefaultBuiltinTypeRegistry::init(v1);
}

// File Line: 81
// RVA: 0xE387D0
hkReferencedObject *__fastcall hkCreateBuiltInTypeRegistry()
{
  _QWORD **v0; // rax
  __int64 v1; // rax
  __int64 v2; // rbx

  if ( !hkSingleton<hkVtableClassRegistry>::s_instance
    || !hkSingleton<hkDefaultClassNameRegistry>::s_instance
    || !hkSingleton<hkTypeInfoRegistry>::s_instance )
  {
    return 0i64;
  }
  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 16i64);
  v2 = v1;
  if ( !v1 )
    return 0i64;
  *(_DWORD *)(v1 + 8) = 0x1FFFF;
  *(_QWORD *)v1 = &hkDefaultBuiltinTypeRegistry::`vftable';
  hkDefaultBuiltinTypeRegistry::init((hkDefaultBuiltinTypeRegistry *)v1);
  return (hkReferencedObject *)v2;
}

// File Line: 92
// RVA: 0x15D8540
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkBuiltinTypeRegistry__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkBuiltinTypeRegistry.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkBuiltinTypeRegistry;
  hkSingletonInitList = &hkSingletonRegisterhkBuiltinTypeRegistry;
  return result;
}

