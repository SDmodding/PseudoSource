// File Line: 67
// RVA: 0x15BED20
void dynamic_initializer_for__hkaFootstepAnalysisInfoClass__()
{
  hkClass::hkClass(
    &hkaFootstepAnalysisInfoClass,
    "hkaFootstepAnalysisInfo",
    &hkReferencedObjectClass,
    208,
    0i64,
    0,
    0i64,
    0,
    &hkaFootstepAnalysisInfoClass_Members,
    14,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 70
// RVA: 0xB1D460
hkClass *__fastcall hkaFootstepAnalysisInfo::staticClass()
{
  return &hkaFootstepAnalysisInfoClass;
}

// File Line: 77
// RVA: 0xB1D480
void __fastcall finishLoadedObjecthkaFootstepAnalysisInfo(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo);
}

// File Line: 83
// RVA: 0xB1D4A0
void __fastcall cleanupLoadedObjecthkaFootstepAnalysisInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 87
// RVA: 0xB1D4B0
hkBaseObjectVtbl *__fastcall getVtablehkaFootstepAnalysisInfo()
{
  hkaFootstepAnalysisInfo v1; // [rsp+20h] [rbp-D8h]

  hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo(&v1, 0);
  return v1.vfptr;
}

// File Line: 109
// RVA: 0x15BEE60
hkBaseObjectVtbl *dynamic_initializer_for__hkaFootstepAnalysisInfoTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaFootstepAnalysisInfo();
  hkaFootstepAnalysisInfoTypeInfo.m_size = 208i64;
  hkaFootstepAnalysisInfoTypeInfo.m_typeName = "hkaFootstepAnalysisInfo";
  hkaFootstepAnalysisInfoTypeInfo.m_vtable = result;
  hkaFootstepAnalysisInfoTypeInfo.m_scopedName = "!hkaFootstepAnalysisInfo";
  hkaFootstepAnalysisInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaFootstepAnalysisInfo;
  hkaFootstepAnalysisInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaFootstepAnalysisInfo;
  return result;
}

// File Line: 135
// RVA: 0x15BED90
void dynamic_initializer_for__hkaFootstepAnalysisInfoContainerClass__()
{
  hkClass::hkClass(
    &hkaFootstepAnalysisInfoContainerClass,
    "hkaFootstepAnalysisInfoContainer",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaFootstepAnalysisInfoContainerClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 138
// RVA: 0xB1D470
hkClass *__fastcall hkaFootstepAnalysisInfoContainer::staticClass()
{
  return &hkaFootstepAnalysisInfoContainerClass;
}

// File Line: 145
// RVA: 0xB1D4E0
void __fastcall finishLoadedObjecthkaFootstepAnalysisInfoContainer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaFootstepAnalysisInfoContainer::`vftable;
}

// File Line: 151
// RVA: 0xB1D500
void __fastcall cleanupLoadedObjecthkaFootstepAnalysisInfoContainer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 155
// RVA: 0xB1D510
void **__fastcall getVtablehkaFootstepAnalysisInfoContainer()
{
  return &hkaFootstepAnalysisInfoContainer::`vftable;
}

// File Line: 177
// RVA: 0x15BEE00
void **dynamic_initializer_for__hkaFootstepAnalysisInfoContainerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaFootstepAnalysisInfoContainer();
  hkaFootstepAnalysisInfoContainerTypeInfo.m_size = 32i64;
  hkaFootstepAnalysisInfoContainerTypeInfo.m_typeName = "hkaFootstepAnalysisInfoContainer";
  hkaFootstepAnalysisInfoContainerTypeInfo.m_vtable = result;
  hkaFootstepAnalysisInfoContainerTypeInfo.m_scopedName = "!hkaFootstepAnalysisInfoContainer";
  hkaFootstepAnalysisInfoContainerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaFootstepAnalysisInfoContainer;
  hkaFootstepAnalysisInfoContainerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaFootstepAnalysisInfoContainer;
  return result;
}

