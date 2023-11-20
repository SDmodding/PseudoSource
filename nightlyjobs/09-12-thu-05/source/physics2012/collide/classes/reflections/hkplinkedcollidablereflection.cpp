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
void __fastcall finishLoadedObjecthkpLinkedCollidable(void *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      *((_DWORD *)p + 20) = 0;
      *((_QWORD *)p + 11) = 0i64;
      *((_QWORD *)p + 12) = 0i64;
      *((_DWORD *)p + 12) = 1;
      *((_DWORD *)p + 16) = 0;
      *((_BYTE *)p + 41) = -36;
    }
    *((_QWORD *)p + 14) = 0i64;
    *((_DWORD *)p + 30) = 0;
    *((_DWORD *)p + 31) = 2147483648;
  }
}

// File Line: 72
// RVA: 0xCEB030
void __fastcall cleanupLoadedObjecthkpLinkedCollidable(void *p)
{
  int v1; // er8
  _QWORD *v2; // rbx

  v1 = *((_DWORD *)p + 31);
  v2 = p;
  *((_DWORD *)p + 30) = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 14) = 0i64;
    *((_DWORD *)p + 31) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 14),
      16 * v1);
    v2[14] = 0i64;
    *((_DWORD *)v2 + 31) = 2147483648;
  }
}

