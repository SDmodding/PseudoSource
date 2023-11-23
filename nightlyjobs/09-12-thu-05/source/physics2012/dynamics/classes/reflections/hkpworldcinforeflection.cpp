// File Line: 120
// RVA: 0x15CFEB0
hkClassEnum *dynamic_initializer_for__hkpWorldCinfoClass_Members__()
{
  hkClassEnum *result; // rax

  unk_1421109D8 = hkpWorldCinfoBroadPhaseTypeEnum;
  unk_142110A00 = hkpWorldCinfoBroadPhaseBorderBehaviourEnum;
  unk_142110BB8 = hkpWorldCinfoContactPointGenerationEnum;
  result = hkpWorldCinfoSimulationTypeEnum;
  unk_1421110B8 = hkpWorldCinfoSimulationTypeEnum;
  return result;
}

// File Line: 238
// RVA: 0x15CFE30
void dynamic_initializer_for__hkpWorldCinfoClass__()
{
  hkClass::hkClass(
    &hkpWorldCinfoClass,
    "hkpWorldCinfo",
    &hkReferencedObjectClass,
    256,
    0i64,
    0,
    &hkpWorldCinfoEnums,
    5,
    &hkpWorldCinfoClass_Members,
    54,
    &hkpWorldCinfo_Default,
    0i64,
    0,
    18);
}

// File Line: 241
// RVA: 0xD4FCE0
hkClass *__fastcall hkpWorldCinfo::staticClass()
{
  return &hkpWorldCinfoClass;
}

// File Line: 248
// RVA: 0xD4FCF0
void __fastcall finishLoadedObjecthkpWorldCinfo(hkpWorldCinfo *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpWorldCinfo::hkpWorldCinfo(p, finishing);
}

// File Line: 254
// RVA: 0xD4FD10
void __fastcall cleanupLoadedObjecthkpWorldCinfo(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 258
// RVA: 0xD4FD20
hkBaseObjectVtbl *__fastcall getVtablehkpWorldCinfo()
{
  hkpWorldCinfo v1; // [rsp+20h] [rbp-108h] BYREF

  hkpWorldCinfo::hkpWorldCinfo(&v1, 0);
  return v1.vfptr;
}

// File Line: 280
// RVA: 0x15CFEF0
hkBaseObjectVtbl *dynamic_initializer_for__hkpWorldCinfoTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpWorldCinfo();
  hkpWorldCinfoTypeInfo.m_size = 256i64;
  hkpWorldCinfoTypeInfo.m_typeName = "hkpWorldCinfo";
  hkpWorldCinfoTypeInfo.m_vtable = result;
  hkpWorldCinfoTypeInfo.m_scopedName = "!hkpWorldCinfo";
  hkpWorldCinfoTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpWorldCinfo;
  hkpWorldCinfoTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpWorldCinfo;
  return result;
}

