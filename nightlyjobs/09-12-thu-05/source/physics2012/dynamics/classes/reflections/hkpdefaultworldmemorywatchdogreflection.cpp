// File Line: 52
// RVA: 0x15D0DC0
void dynamic_initializer_for__hkpDefaultWorldMemoryWatchDogClass__()
{
  hkClass::hkClass(
    &hkpDefaultWorldMemoryWatchDogClass,
    "hkpDefaultWorldMemoryWatchDog",
    &hkWorldMemoryAvailableWatchDogClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkpDefaultWorldMemoryWatchDog::Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 55
// RVA: 0xD50BB0
hkClass *__fastcall hkpDefaultWorldMemoryWatchDog::staticClass()
{
  return &hkpDefaultWorldMemoryWatchDogClass;
}

// File Line: 62
// RVA: 0xD50BC0
void __fastcall finishLoadedObjecthkpDefaultWorldMemoryWatchDog(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpDefaultWorldMemoryWatchDog::`vftable;
}

// File Line: 68
// RVA: 0xD50BE0
void __fastcall cleanupLoadedObjecthkpDefaultWorldMemoryWatchDog(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 72
// RVA: 0xD50BF0
void **__fastcall getVtablehkpDefaultWorldMemoryWatchDog()
{
  return &hkpDefaultWorldMemoryWatchDog::`vftable;
}

// File Line: 94
// RVA: 0x15D0E30
void **dynamic_initializer_for__hkpDefaultWorldMemoryWatchDogTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDefaultWorldMemoryWatchDog();
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_size = 24i64;
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_typeName = "hkpDefaultWorldMemoryWatchDog";
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_vtable = result;
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_scopedName = "!hkpDefaultWorldMemoryWatchDog";
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpDefaultWorldMemoryWatchDog;
  hkpDefaultWorldMemoryWatchDogTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpDefaultWorldMemoryWatchDog;
  return result;
}

