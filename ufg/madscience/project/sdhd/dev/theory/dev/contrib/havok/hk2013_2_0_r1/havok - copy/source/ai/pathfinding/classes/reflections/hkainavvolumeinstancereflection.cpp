// File Line: 56
// RVA: 0x15C20D0
void dynamic_initializer_for__hkaiNavVolumeInstanceCellInstanceClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeInstanceCellInstanceClass,
    "hkaiNavVolumeInstanceCellInstance",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeInstance_CellInstanceClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xBB6E80
hkClass *__fastcall hkaiNavVolumeInstance::CellInstance::staticClass()
{
  return &hkaiNavVolumeInstanceCellInstanceClass;
}

// File Line: 66
// RVA: 0xBB6E90
void __fastcall cleanupLoadedObjecthkaiNavVolumeInstanceCellInstance(void *p)
{
  ;
}

// File Line: 132
// RVA: 0x15C2130
void dynamic_initializer_for__hkaiNavVolumeInstanceClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeInstanceClass,
    "hkaiNavVolumeInstance",
    &hkReferencedObjectClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeInstance::Members,
    9,
    &hkaiNavVolumeInstance_Default,
    0i64,
    0,
    0);
}

// File Line: 135
// RVA: 0xBB6E70
hkClass *__fastcall hkaiNavVolumeInstance::staticClass()
{
  return &hkaiNavVolumeInstanceClass;
}

// File Line: 142
// RVA: 0xBB6EA0
void __fastcall finishLoadedObjecthkaiNavVolumeInstance(hkaiNavVolumeInstance *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavVolumeInstance::hkaiNavVolumeInstance(p, finishing);
}

// File Line: 148
// RVA: 0xBB6EC0
void __fastcall cleanupLoadedObjecthkaiNavVolumeInstance(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 152
// RVA: 0xBB6ED0
hkBaseObjectVtbl *__fastcall getVtablehkaiNavVolumeInstance()
{
  hkaiNavVolumeInstance v1; // [rsp+20h] [rbp-88h] BYREF

  hkaiNavVolumeInstance::hkaiNavVolumeInstance(&v1, 0);
  return v1.vfptr;
}

// File Line: 174
// RVA: 0x15C21A0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiNavVolumeInstanceTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiNavVolumeInstance();
  hkaiNavVolumeInstanceTypeInfo.m_size = 128i64;
  hkaiNavVolumeInstanceTypeInfo.m_typeName = "hkaiNavVolumeInstance";
  hkaiNavVolumeInstanceTypeInfo.m_vtable = result;
  hkaiNavVolumeInstanceTypeInfo.m_scopedName = "!hkaiNavVolumeInstance";
  hkaiNavVolumeInstanceTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiNavVolumeInstance;
  hkaiNavVolumeInstanceTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiNavVolumeInstance;
  return result;
}

