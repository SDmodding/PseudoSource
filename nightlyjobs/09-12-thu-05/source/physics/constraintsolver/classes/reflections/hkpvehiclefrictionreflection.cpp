// File Line: 62
// RVA: 0x15CF4B0
void dynamic_initializer_for__hkpVehicleFrictionDescriptionAxisDescriptionClass__()
{
  hkClass::hkClass(
    &hkpVehicleFrictionDescriptionAxisDescriptionClass,
    "hkpVehicleFrictionDescriptionAxisDescription",
    0i64,
    100,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleFrictionDescription_AxisDescriptionClass_Members,
    10,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xD4E200
hkClass *__fastcall hkpVehicleFrictionDescription::AxisDescription::staticClass()
{
  return &hkpVehicleFrictionDescriptionAxisDescriptionClass;
}

// File Line: 72
// RVA: 0xD4E230
void __fastcall cleanupLoadedObjecthkpVehicleFrictionDescriptionAxisDescription(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15CF510
void dynamic_initializer_for__hkpVehicleFrictionDescriptionClass__()
{
  hkClass::hkClass(
    &hkpVehicleFrictionDescriptionClass,
    "hkpVehicleFrictionDescription",
    &hkReferencedObjectClass,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleFrictionDescriptionClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 115
// RVA: 0xD4E1F0
hkClass *__fastcall hkpVehicleFrictionDescription::staticClass()
{
  return &hkpVehicleFrictionDescriptionClass;
}

// File Line: 122
// RVA: 0xD4E240
void __fastcall finishLoadedObjecthkpVehicleFrictionDescription(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleFrictionDescription::`vftable;
}

// File Line: 128
// RVA: 0xD4E260
void __fastcall cleanupLoadedObjecthkpVehicleFrictionDescription(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 132
// RVA: 0xD4E270
void **__fastcall getVtablehkpVehicleFrictionDescription()
{
  return &hkpVehicleFrictionDescription::`vftable;
}

// File Line: 154
// RVA: 0x15CF580
void **dynamic_initializer_for__hkpVehicleFrictionDescriptionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleFrictionDescription();
  hkpVehicleFrictionDescriptionTypeInfo.m_size = 224i64;
  hkpVehicleFrictionDescriptionTypeInfo.m_typeName = "hkpVehicleFrictionDescription";
  hkpVehicleFrictionDescriptionTypeInfo.m_vtable = result;
  hkpVehicleFrictionDescriptionTypeInfo.m_scopedName = "!hkpVehicleFrictionDescription";
  hkpVehicleFrictionDescriptionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleFrictionDescription;
  hkpVehicleFrictionDescriptionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleFrictionDescription;
  return result;
}

// File Line: 186
// RVA: 0x15CF5E0
void dynamic_initializer_for__hkpVehicleFrictionStatusAxisStatusClass__()
{
  hkClass::hkClass(
    &hkpVehicleFrictionStatusAxisStatusClass,
    "hkpVehicleFrictionStatusAxisStatus",
    0i64,
    36,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleFrictionStatus_AxisStatusClass_Members,
    9,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 189
// RVA: 0xD4E220
hkClass *__fastcall hkpVehicleFrictionStatus::AxisStatus::staticClass()
{
  return &hkpVehicleFrictionStatusAxisStatusClass;
}

// File Line: 196
// RVA: 0xD4E280
void __fastcall finishLoadedObjecthkpVehicleFrictionStatusAxisStatus(void *p, int finishing)
{
  ;
}

// File Line: 202
// RVA: 0xD4E290
void __fastcall cleanupLoadedObjecthkpVehicleFrictionStatusAxisStatus(void *p)
{
  ;
}

// File Line: 238
// RVA: 0x15CF640
void dynamic_initializer_for__hkpVehicleFrictionStatusClass__()
{
  hkClass::hkClass(
    &hkpVehicleFrictionStatusClass,
    "hkpVehicleFrictionStatus",
    0i64,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleFrictionStatusClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 241
// RVA: 0xD4E210
hkClass *__fastcall hkpVehicleFrictionStatus::staticClass()
{
  return &hkpVehicleFrictionStatusClass;
}

// File Line: 248
// RVA: 0xD4E2A0
void __fastcall finishLoadedObjecthkpVehicleFrictionStatus(void *p, int finishing)
{
  ;
}

// File Line: 254
// RVA: 0xD4E2B0
void __fastcall cleanupLoadedObjecthkpVehicleFrictionStatus(void *p)
{
  ;
}

