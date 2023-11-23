// File Line: 48
// RVA: 0x15D14F0
void dynamic_initializer_for__hkpRigidBodyClass__()
{
  hkClass::hkClass(
    &hkpRigidBodyClass,
    "hkpRigidBody",
    &hkpEntityClass,
    720,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 51
// RVA: 0xD51040
hkClass *__fastcall hkpRigidBody::staticClass()
{
  return &hkpRigidBodyClass;
}

// File Line: 58
// RVA: 0xD51050
void __fastcall finishLoadedObjecthkpRigidBody(hkpRigidBody *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpRigidBody::hkpRigidBody(p, finishing);
}

// File Line: 64
// RVA: 0xD51070
void __fastcall cleanupLoadedObjecthkpRigidBody(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD51080
hkBaseObjectVtbl *__fastcall getVtablehkpRigidBody()
{
  hkpRigidBody v1; // [rsp+20h] [rbp-2D8h] BYREF

  hkpRigidBody::hkpRigidBody(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15D1550
hkBaseObjectVtbl *dynamic_initializer_for__hkpRigidBodyTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpRigidBody();
  hkpRigidBodyTypeInfo.m_size = 720i64;
  hkpRigidBodyTypeInfo.m_typeName = "hkpRigidBody";
  hkpRigidBodyTypeInfo.m_vtable = result;
  hkpRigidBodyTypeInfo.m_scopedName = "!hkpRigidBody";
  hkpRigidBodyTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpRigidBody;
  hkpRigidBodyTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpRigidBody;
  return result;
}

