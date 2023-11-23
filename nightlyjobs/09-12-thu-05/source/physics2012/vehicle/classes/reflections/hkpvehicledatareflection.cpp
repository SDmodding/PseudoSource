// File Line: 61
// RVA: 0x15D4E20
void dynamic_initializer_for__hkpVehicleDataWheelComponentParamsClass__()
{
  hkClass::hkClass(
    &hkpVehicleDataWheelComponentParamsClass,
    "hkpVehicleDataWheelComponentParams",
    0i64,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleData_WheelComponentParamsClass_Members,
    10,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xE25200
hkClass *__fastcall hkpVehicleData::WheelComponentParams::staticClass()
{
  return &hkpVehicleDataWheelComponentParamsClass;
}

// File Line: 71
// RVA: 0xE25210
void __fastcall cleanupLoadedObjecthkpVehicleDataWheelComponentParams(void *p)
{
  ;
}

// File Line: 147
// RVA: 0x15D4D50
void dynamic_initializer_for__hkpVehicleDataClass__()
{
  hkClass::hkClass(
    &hkpVehicleDataClass,
    "hkpVehicleData",
    &hkReferencedObjectClass,
    208,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDataClass_Members,
    18,
    &hkpVehicleData_Default,
    0i64,
    0,
    2);
}

// File Line: 150
// RVA: 0xE251F0
hkClass *__fastcall hkpVehicleData::staticClass()
{
  return &hkpVehicleDataClass;
}

// File Line: 157
// RVA: 0xE25220
void __fastcall finishLoadedObjecthkpVehicleData(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleData::`vftable;
}

// File Line: 163
// RVA: 0xE25240
void __fastcall cleanupLoadedObjecthkpVehicleData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 167
// RVA: 0xE25250
void **__fastcall getVtablehkpVehicleData()
{
  return &hkpVehicleData::`vftable;
}

// File Line: 189
// RVA: 0x15D4DC0
void **dynamic_initializer_for__hkpVehicleDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleData();
  hkpVehicleDataTypeInfo.m_size = 208i64;
  hkpVehicleDataTypeInfo.m_typeName = "hkpVehicleData";
  hkpVehicleDataTypeInfo.m_vtable = result;
  hkpVehicleDataTypeInfo.m_scopedName = "!hkpVehicleData";
  hkpVehicleDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleData;
  hkpVehicleDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleData;
  return result;
}

