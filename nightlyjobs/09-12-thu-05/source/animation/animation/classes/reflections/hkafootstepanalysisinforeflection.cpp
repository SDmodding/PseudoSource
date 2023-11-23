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
    1);
}

// File Line: 70
// RVA: 0xB1D460
hkClass *__fastcall hkaFootstepAnalysisInfo::staticClass()
{
  return &hkaFootstepAnalysisInfoClass;
}

// File Line: 77
// RVA: 0xB1D480
void __fastcall finishLoadedObjecthkaFootstepAnalysisInfo(
        hkaFootstepAnalysisInfo *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo(p, finishing);
}

// File Line: 83
// RVA: 0xB1D4A0
void __fastcall cleanupLoadedObjecthkaFootstepAnalysisInfo(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 87
// RVA: 0xB1D4B0
hkBaseObjectVtbl *__fastcall getVtablehkaFootstepAnalysisInfo()
{
  hkaFootstepAnalysisInfo v1; // [rsp+20h] [rbp-D8h] BYREF

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
  hkaFootstepAnalysisInfoTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaFootstepAnalysisInfo;
  hkaFootstepAnalysisInfoTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaFootstepAnalysisInfo;
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
    1);
}

// File Line: 138
// RVA: 0xB1D470
hkClass *__fastcall hkaFootstepAnalysisInfoContainer::staticClass()
{
  return &hkaFootstepAnalysisInfoContainerClass;
}

// File Line: 145
// RVA: 0xB1D4E0
void __fastcall finishLoadedObjecthkaFootstepAnalysisInfoContainer(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaFootstepAnalysisInfoContainer::`vftable;
}

// File Line: 151
// RVA: 0xB1D500
void __fastcall cleanupLoadedObjecthkaFootstepAnalysisInfoContainer(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
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
  hkaFootstepAnalysisInfoContainerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaFootstepAnalysisInfoContainer;
  hkaFootstepAnalysisInfoContainerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaFootstepAnalysisInfoContainer;
  return result;
}

