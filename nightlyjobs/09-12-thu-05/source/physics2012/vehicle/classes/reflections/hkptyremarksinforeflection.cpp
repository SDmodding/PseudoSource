// File Line: 54
// RVA: 0x15D4B50
void dynamic_initializer_for__hkpTyremarkPointClass__()
{
  hkClass::hkClass(
    &hkpTyremarkPointClass,
    "hkpTyremarkPoint",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpTyremarkPointClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE25010
hkClass *__fastcall hkpTyremarkPoint::staticClass()
{
  return &hkpTyremarkPointClass;
}

// File Line: 64
// RVA: 0xE25040
void __fastcall finishLoadedObjecthkpTyremarkPoint(void *p, int finishing)
{
  ;
}

// File Line: 70
// RVA: 0xE25050
void __fastcall cleanupLoadedObjecthkpTyremarkPoint(void *p)
{
  ;
}

// File Line: 109
// RVA: 0x15D4C80
void dynamic_initializer_for__hkpTyremarksWheelClass__()
{
  hkClass::hkClass(
    &hkpTyremarksWheelClass,
    "hkpTyremarksWheel",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpTyremarksWheelClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 112
// RVA: 0xE25020
hkClass *__fastcall hkpTyremarksWheel::staticClass()
{
  return &hkpTyremarksWheelClass;
}

// File Line: 119
// RVA: 0xE25060
void __fastcall finishLoadedObjecthkpTyremarksWheel(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpTyremarksWheel::`vftable;
}

// File Line: 125
// RVA: 0xE25080
void __fastcall cleanupLoadedObjecthkpTyremarksWheel(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 129
// RVA: 0xE25090
void **__fastcall getVtablehkpTyremarksWheel()
{
  return &hkpTyremarksWheel::`vftable;
}

// File Line: 151
// RVA: 0x15D4CF0
void **dynamic_initializer_for__hkpTyremarksWheelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpTyremarksWheel();
  hkpTyremarksWheelTypeInfo.m_size = 40i64;
  hkpTyremarksWheelTypeInfo.m_typeName = "hkpTyremarksWheel";
  hkpTyremarksWheelTypeInfo.m_vtable = result;
  hkpTyremarksWheelTypeInfo.m_scopedName = "!hkpTyremarksWheel";
  hkpTyremarksWheelTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpTyremarksWheel;
  hkpTyremarksWheelTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpTyremarksWheel;
  return result;
}

// File Line: 179
// RVA: 0x15D4BB0
void dynamic_initializer_for__hkpTyremarksInfoClass__()
{
  hkClass::hkClass(
    &hkpTyremarksInfoClass,
    "hkpTyremarksInfo",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpTyremarksInfoClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 182
// RVA: 0xE25030
hkClass *__fastcall hkpTyremarksInfo::staticClass()
{
  return &hkpTyremarksInfoClass;
}

// File Line: 189
// RVA: 0xE250A0
void __fastcall finishLoadedObjecthkpTyremarksInfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpTyremarksInfo::`vftable;
}

// File Line: 195
// RVA: 0xE250C0
void __fastcall cleanupLoadedObjecthkpTyremarksInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 199
// RVA: 0xE250D0
void **__fastcall getVtablehkpTyremarksInfo()
{
  return &hkpTyremarksInfo::`vftable;
}

// File Line: 221
// RVA: 0x15D4C20
void **dynamic_initializer_for__hkpTyremarksInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpTyremarksInfo();
  hkpTyremarksInfoTypeInfo.m_size = 40i64;
  hkpTyremarksInfoTypeInfo.m_typeName = "hkpTyremarksInfo";
  hkpTyremarksInfoTypeInfo.m_vtable = result;
  hkpTyremarksInfoTypeInfo.m_scopedName = "!hkpTyremarksInfo";
  hkpTyremarksInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpTyremarksInfo;
  hkpTyremarksInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpTyremarksInfo;
  return result;
}

