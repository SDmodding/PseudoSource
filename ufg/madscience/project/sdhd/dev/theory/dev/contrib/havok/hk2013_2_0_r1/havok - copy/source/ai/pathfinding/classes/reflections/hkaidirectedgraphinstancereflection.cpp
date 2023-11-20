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
void __fastcall cleanupLoadedObjecthkaiDirectedGraphInstanceFreeBlockList(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      4 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
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
    1u);
}

// File Line: 150
// RVA: 0xBB65E0
hkClass *__fastcall hkaiDirectedGraphInstance::staticClass()
{
  return &hkaiDirectedGraphInstanceClass;
}

// File Line: 157
// RVA: 0xBB6680
void __fastcall finishLoadedObjecthkaiDirectedGraphInstance(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiDirectedGraphInstance::hkaiDirectedGraphInstance);
}

// File Line: 163
// RVA: 0xBB66A0
void __fastcall cleanupLoadedObjecthkaiDirectedGraphInstance(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 167
// RVA: 0xBB66B0
hkBaseObjectVtbl *__fastcall getVtablehkaiDirectedGraphInstance()
{
  hkaiDirectedGraphInstance v1; // [rsp+20h] [rbp-118h]

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
  hkaiDirectedGraphInstanceTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiDirectedGraphInstance;
  hkaiDirectedGraphInstanceTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiDirectedGraphInstance;
  return result;
}

