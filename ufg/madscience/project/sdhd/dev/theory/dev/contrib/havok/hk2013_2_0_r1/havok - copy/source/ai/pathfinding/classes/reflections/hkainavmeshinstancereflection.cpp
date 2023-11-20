// File Line: 133
// RVA: 0x15C1AD0
void dynamic_initializer_for__hkaiNavMeshInstanceClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshInstanceClass,
    "hkaiNavMeshInstance",
    &hkReferencedObjectClass,
    480,
    0i64,
    0,
    &hkaiNavMeshInstanceEnums,
    2,
    &hkaiNavMeshInstance::Members,
    28,
    &hkaiNavMeshInstance_Default,
    0i64,
    0,
    4u);
}

// File Line: 136
// RVA: 0xBB6B80
hkClass *__fastcall hkaiNavMeshInstance::staticClass()
{
  return &hkaiNavMeshInstanceClass;
}

// File Line: 143
// RVA: 0xBB6B90
void __fastcall finishLoadedObjecthkaiNavMeshInstance(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshInstance::hkaiNavMeshInstance);
}

// File Line: 149
// RVA: 0xBB6BB0
void __fastcall cleanupLoadedObjecthkaiNavMeshInstance(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 153
// RVA: 0xBB6BC0
hkBaseObjectVtbl *__fastcall getVtablehkaiNavMeshInstance()
{
  hkaiNavMeshInstance v1; // [rsp+20h] [rbp-1E8h]

  hkaiNavMeshInstance::hkaiNavMeshInstance(&v1, 0);
  return v1.vfptr;
}

// File Line: 175
// RVA: 0x15C1B50
hkBaseObjectVtbl *dynamic_initializer_for__hkaiNavMeshInstanceTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiNavMeshInstance();
  hkaiNavMeshInstanceTypeInfo.m_size = 480i64;
  hkaiNavMeshInstanceTypeInfo.m_typeName = "hkaiNavMeshInstance";
  hkaiNavMeshInstanceTypeInfo.m_vtable = result;
  hkaiNavMeshInstanceTypeInfo.m_scopedName = "!hkaiNavMeshInstance";
  hkaiNavMeshInstanceTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiNavMeshInstance;
  hkaiNavMeshInstanceTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiNavMeshInstance;
  return result;
}

