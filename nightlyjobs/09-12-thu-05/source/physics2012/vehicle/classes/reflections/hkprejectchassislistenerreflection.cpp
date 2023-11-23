// File Line: 55
// RVA: 0x15D4A80
void dynamic_initializer_for__hkpRejectChassisListenerClass__()
{
  hkClass::hkClass(
    &hkpRejectChassisListenerClass,
    "hkpRejectChassisListener",
    &hkReferencedObjectClass,
    32,
    0i64,
    1,
    0i64,
    0,
    &hkpRejectChassisListenerClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 58
// RVA: 0xE24F40
hkClass *__fastcall hkpRejectChassisListener::staticClass()
{
  return &hkpRejectChassisListenerClass;
}

// File Line: 65
// RVA: 0xE24F50
void __fastcall finishLoadedObjecthkpRejectChassisListener(_QWORD *p, int finishing)
{
  if ( p )
  {
    *p = &hkpRejectChassisListener::`vftable{for `hkReferencedObject};
    p[2] = &hkpRejectChassisListener::`vftable{for `hkpPhantomOverlapListener};
  }
}

// File Line: 71
// RVA: 0xE24F80
void __fastcall cleanupLoadedObjecthkpRejectChassisListener(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE24F90
void **__fastcall getVtablehkpRejectChassisListener()
{
  return &hkpRejectChassisListener::`vftable{for `hkReferencedObject};
}

// File Line: 97
// RVA: 0x15D4AF0
void **dynamic_initializer_for__hkpRejectChassisListenerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpRejectChassisListener();
  hkpRejectChassisListenerTypeInfo.m_size = 32i64;
  hkpRejectChassisListenerTypeInfo.m_typeName = "hkpRejectChassisListener";
  hkpRejectChassisListenerTypeInfo.m_vtable = result;
  hkpRejectChassisListenerTypeInfo.m_scopedName = "!hkpRejectChassisListener";
  hkpRejectChassisListenerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpRejectChassisListener;
  hkpRejectChassisListenerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpRejectChassisListener;
  return result;
}

