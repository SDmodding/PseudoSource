// File Line: 55
// RVA: 0x15C10B0
void dynamic_initializer_for__hkaiDirectedGraphInstanceFreeBlockListClass__()
{
  hkClass::hkClass(
    &hkaiDirectedGraphInstanceFreeBlockListClass,
    "hkaiDirectedGraphInstanceFreeBlockList",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiDirectedGraphInstance_FreeBlockListClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xBB65F0
hkClass *__fastcall hkaiDirectedGraphInstance::FreeBlockList::staticClass()
{
  return &hkaiDirectedGraphInstanceFreeBlockListClass;
}

// File Line: 65
// RVA: 0xBB6600
void __fastcall finishLoadedObjecthkaiDirectedGraphInstanceFreeBlockList(void *p, int finishing)
{
  ;
}

// File Line: 71
// RVA: 0xBB6610
void __fastcall cleanupLoadedObjecthkaiDirectedGraphInstanceFreeBlockList(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 4 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 147
// RVA: 0x15C1040
void dynamic_initializer_for__hkaiDirectedGraphInstanceClass__()
{
  hkClass::hkClass(
    &hkaiDirectedGraphInstanceClass,
    "hkaiDirectedGraphInstance",
    &hkReferencedObjectClass,
    272,
    0i64,
    0,
    0i64,
    0,
    &hkaiDirectedGraphInstance::Members,
    17,
    &hkaiDirectedGraphInstance_Default,
    0i64,
    0,
    1);
}

// File Line: 150
// RVA: 0xBB65E0
hkClass *__fastcall hkaiDirectedGraphInstance::staticClass()
{
  return &hkaiDirectedGraphInstanceClass;
}

// File Line: 157
// RVA: 0xBB6680
void __fastcall finishLoadedObjecthkaiDirectedGraphInstance(
        hkaiDirectedGraphInstance *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(p, finishing);
}

// File Line: 163
// RVA: 0xBB66A0
void __fastcall cleanupLoadedObjecthkaiDirectedGraphInstance(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 167
// RVA: 0xBB66B0
hkBaseObjectVtbl *__fastcall getVtablehkaiDirectedGraphInstance()
{
  hkaiDirectedGraphInstance v1; // [rsp+20h] [rbp-118h] BYREF

  hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v1, 0);
  return v1.vfptr;
}

// File Line: 189
// RVA: 0x15C1110
hkBaseObjectVtbl *dynamic_initializer_for__hkaiDirectedGraphInstanceTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiDirectedGraphInstance();
  hkaiDirectedGraphInstanceTypeInfo.m_size = 272i64;
  hkaiDirectedGraphInstanceTypeInfo.m_typeName = "hkaiDirectedGraphInstance";
  hkaiDirectedGraphInstanceTypeInfo.m_vtable = result;
  hkaiDirectedGraphInstanceTypeInfo.m_scopedName = "!hkaiDirectedGraphInstance";
  hkaiDirectedGraphInstanceTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDirectedGraphInstance;
  hkaiDirectedGraphInstanceTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDirectedGraphInstance;
  return result;
}

