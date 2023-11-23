// File Line: 56
// RVA: 0x15C9A60
void dynamic_initializer_for__hkpLinkedCollidableClass__()
{
  hkClass::hkClass(
    &hkpLinkedCollidableClass,
    "hkpLinkedCollidable",
    &hkpCollidableClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpLinkedCollidable::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xCEAFD0
hkClass *__fastcall hkpLinkedCollidable::staticClass()
{
  return &hkpLinkedCollidableClass;
}

// File Line: 66
// RVA: 0xCEAFE0
void __fastcall finishLoadedObjecthkpLinkedCollidable(_DWORD *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      p[20] = 0;
      *((_QWORD *)p + 11) = 0i64;
      *((_QWORD *)p + 12) = 0i64;
      p[12] = 1;
      p[16] = 0;
      *((_BYTE *)p + 41) = -36;
    }
    *((_QWORD *)p + 14) = 0i64;
    p[30] = 0;
    p[31] = 0x80000000;
  }
}

// File Line: 72
// RVA: 0xCEB030
void __fastcall cleanupLoadedObjecthkpLinkedCollidable(_DWORD *p)
{
  int v1; // r8d

  v1 = p[31];
  p[30] = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 14) = 0i64;
    p[31] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 14),
      16 * v1);
    *((_QWORD *)p + 14) = 0i64;
    p[31] = 0x80000000;
  }
}

