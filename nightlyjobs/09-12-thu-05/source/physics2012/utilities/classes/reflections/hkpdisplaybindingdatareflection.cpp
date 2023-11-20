// File Line: 59
// RVA: 0x15D3260
void dynamic_initializer_for__hkpDisplayBindingDataRigidBodyClass__()
{
  hkClass::hkClass(
    &hkpDisplayBindingDataRigidBodyClass,
    "hkpDisplayBindingDataRigidBody",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpDisplayBindingData_RigidBodyClass_Members,
    3,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 62
// RVA: 0xE0AA40
hkClass *__fastcall hkpDisplayBindingData::RigidBody::staticClass()
{
  return &hkpDisplayBindingDataRigidBodyClass;
}

// File Line: 69
// RVA: 0xE0AA60
void __fastcall finishLoadedObjecthkpDisplayBindingDataRigidBody(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpDisplayBindingData::RigidBody::`vftable';
}

// File Line: 75
// RVA: 0xE0AA80
void __fastcall cleanupLoadedObjecthkpDisplayBindingDataRigidBody(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 79
// RVA: 0xE0AA90
void **__fastcall getVtablehkpDisplayBindingDataRigidBody()
{
  return &hkpDisplayBindingData::RigidBody::`vftable';
}

// File Line: 101
// RVA: 0x15D32D0
void **dynamic_initializer_for__hkpDisplayBindingDataRigidBodyTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDisplayBindingDataRigidBody();
  hkpDisplayBindingDataRigidBodyTypeInfo.m_size = 96i64;
  hkpDisplayBindingDataRigidBodyTypeInfo.m_typeName = "hkpDisplayBindingDataRigidBody";
  hkpDisplayBindingDataRigidBodyTypeInfo.m_vtable = result;
  hkpDisplayBindingDataRigidBodyTypeInfo.m_scopedName = "!hkpDisplayBindingData::RigidBody";
  hkpDisplayBindingDataRigidBodyTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpDisplayBindingDataRigidBody;
  hkpDisplayBindingDataRigidBodyTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpDisplayBindingDataRigidBody;
  return result;
}

// File Line: 127
// RVA: 0x15D3190
void dynamic_initializer_for__hkpDisplayBindingDataPhysicsSystemClass__()
{
  hkClass::hkClass(
    &hkpDisplayBindingDataPhysicsSystemClass,
    "hkpDisplayBindingDataPhysicsSystem",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpDisplayBindingData_PhysicsSystemClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 130
// RVA: 0xE0AA50
hkClass *__fastcall hkpDisplayBindingData::PhysicsSystem::staticClass()
{
  return &hkpDisplayBindingDataPhysicsSystemClass;
}

// File Line: 137
// RVA: 0xE0AAA0
void __fastcall finishLoadedObjecthkpDisplayBindingDataPhysicsSystem(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpDisplayBindingData::PhysicsSystem::`vftable';
}

// File Line: 143
// RVA: 0xE0AAC0
void __fastcall cleanupLoadedObjecthkpDisplayBindingDataPhysicsSystem(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 147
// RVA: 0xE0AAD0
void **__fastcall getVtablehkpDisplayBindingDataPhysicsSystem()
{
  return &hkpDisplayBindingData::PhysicsSystem::`vftable';
}

// File Line: 169
// RVA: 0x15D3200
void **dynamic_initializer_for__hkpDisplayBindingDataPhysicsSystemTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDisplayBindingDataPhysicsSystem();
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_size = 40i64;
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_typeName = "hkpDisplayBindingDataPhysicsSystem";
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_vtable = result;
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_scopedName = "!hkpDisplayBindingData::PhysicsSystem";
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpDisplayBindingDataPhysicsSystem;
  hkpDisplayBindingDataPhysicsSystemTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpDisplayBindingDataPhysicsSystem;
  return result;
}

// File Line: 196
// RVA: 0x15D3120
void dynamic_initializer_for__hkpDisplayBindingDataClass__()
{
  hkClass::hkClass(
    &hkpDisplayBindingDataClass,
    "hkpDisplayBindingData",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpDisplayBindingDataClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 199
// RVA: 0xE0AA30
hkClass *__fastcall hkpDisplayBindingData::staticClass()
{
  return &hkpDisplayBindingDataClass;
}

// File Line: 206
// RVA: 0xE0AAE0
void __fastcall finishLoadedObjecthkpDisplayBindingData(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpDisplayBindingData::`vftable';
}

// File Line: 212
// RVA: 0xE0AB00
void __fastcall cleanupLoadedObjecthkpDisplayBindingData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 216
// RVA: 0xE0AB10
void **__fastcall getVtablehkpDisplayBindingData()
{
  return &hkpDisplayBindingData::`vftable';
}

// File Line: 238
// RVA: 0x15D3330
void **dynamic_initializer_for__hkpDisplayBindingDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDisplayBindingData();
  hkpDisplayBindingDataTypeInfo.m_size = 48i64;
  hkpDisplayBindingDataTypeInfo.m_typeName = "hkpDisplayBindingData";
  hkpDisplayBindingDataTypeInfo.m_vtable = result;
  hkpDisplayBindingDataTypeInfo.m_scopedName = "!hkpDisplayBindingData";
  hkpDisplayBindingDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpDisplayBindingData;
  hkpDisplayBindingDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpDisplayBindingData;
  return result;
}

