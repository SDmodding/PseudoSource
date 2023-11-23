// File Line: 60
// RVA: 0x15C5640
void dynamic_initializer_for__hkaRagdollInstanceClass__()
{
  hkClass::hkClass(
    &hkaRagdollInstanceClass,
    "hkaRagdollInstance",
    &hkReferencedObjectClass,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkaRagdollInstanceClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 63
// RVA: 0xC50100
hkClass *__fastcall hkaRagdollInstance::staticClass()
{
  return &hkaRagdollInstanceClass;
}

// File Line: 70
// RVA: 0xC50110
void __fastcall finishLoadedObjecthkaRagdollInstance(hkaRagdollInstance *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaRagdollInstance::hkaRagdollInstance(p, finishing);
}

// File Line: 76
// RVA: 0xC50130
void __fastcall cleanupLoadedObjecthkaRagdollInstance(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 80
// RVA: 0xC50140
hkBaseObjectVtbl *__fastcall getVtablehkaRagdollInstance()
{
  hkaRagdollInstance v1; // [rsp+20h] [rbp-58h] BYREF

  hkaRagdollInstance::hkaRagdollInstance(&v1, 0);
  return v1.vfptr;
}

// File Line: 102
// RVA: 0x15C56B0
hkBaseObjectVtbl *dynamic_initializer_for__hkaRagdollInstanceTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaRagdollInstance();
  hkaRagdollInstanceTypeInfo.m_size = 72i64;
  hkaRagdollInstanceTypeInfo.m_typeName = "hkaRagdollInstance";
  hkaRagdollInstanceTypeInfo.m_vtable = result;
  hkaRagdollInstanceTypeInfo.m_scopedName = "!hkaRagdollInstance";
  hkaRagdollInstanceTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaRagdollInstance;
  hkaRagdollInstanceTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaRagdollInstance;
  return result;
}

