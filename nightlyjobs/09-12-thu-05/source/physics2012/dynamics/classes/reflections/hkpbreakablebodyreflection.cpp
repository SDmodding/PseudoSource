// File Line: 76
// RVA: 0x15D0300
void dynamic_initializer_for__hkpBreakableBodyControllerClass__()
{
  hkClass::hkClass(
    &hkpBreakableBodyControllerClass,
    "hkpBreakableBodyController",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableBody::Controller::Members,
    1,
    &hkpBreakableBodyController_Default,
    0i64,
    0,
    0);
}

// File Line: 79
// RVA: 0xD4FF30
hkClass *__fastcall hkpBreakableBody::Controller::staticClass()
{
  return &hkpBreakableBodyControllerClass;
}

// File Line: 86
// RVA: 0xD4FF40
void __fastcall finishLoadedObjecthkpBreakableBodyController(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpBreakableBody::Controller::`vftable';
}

// File Line: 92
// RVA: 0xD4FF60
void __fastcall cleanupLoadedObjecthkpBreakableBodyController(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 96
// RVA: 0xD4FF70
void **__fastcall getVtablehkpBreakableBodyController()
{
  return &hkpBreakableBody::Controller::`vftable';
}

// File Line: 118
// RVA: 0x15D0370
void **dynamic_initializer_for__hkpBreakableBodyControllerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpBreakableBodyController();
  hkpBreakableBodyControllerTypeInfo.m_size = 24i64;
  hkpBreakableBodyControllerTypeInfo.m_typeName = "hkpBreakableBodyController";
  hkpBreakableBodyControllerTypeInfo.m_vtable = result;
  hkpBreakableBodyControllerTypeInfo.m_scopedName = "!hkpBreakableBody::Controller";
  hkpBreakableBodyControllerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpBreakableBodyController;
  hkpBreakableBodyControllerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpBreakableBodyController;
  return result;
}

// File Line: 167
// RVA: 0x15D0290
void dynamic_initializer_for__hkpBreakableBodyClass__()
{
  hkClass::hkClass(
    &hkpBreakableBodyClass,
    "hkpBreakableBody",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableBody::Members,
    4,
    &hkpBreakableBody_Default,
    0i64,
    0,
    1u);
}

// File Line: 170
// RVA: 0xD4FF20
hkClass *__fastcall hkpBreakableBody::staticClass()
{
  return &hkpBreakableBodyClass;
}

