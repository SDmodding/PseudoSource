// File Line: 51
// RVA: 0x15C6E70
void dynamic_initializer_for__hkSetUint32Class__()
{
  hkClass::hkClass(
    &hkSetUint32Class,
    "hkSetUint32",
    &hkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedintClass,
    24,
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

// File Line: 54
// RVA: 0xC55080
hkClass *__fastcall hkSetUint32::staticClass()
{
  return &hkSetUint32Class;
}

// File Line: 61
// RVA: 0xC550B0
void __fastcall finishLoadedObjecthkSetUint32(void *p, int finishing)
{
  ;
}

// File Line: 67
// RVA: 0xC550C0
void __fastcall cleanupLoadedObjecthkSetUint32(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 4 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 103
// RVA: 0x15C6DB0
void dynamic_initializer_for__hkIntRealPairClass__()
{
  hkClass::hkClass(
    &hkIntRealPairClass,
    "hkIntRealPair",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkIntRealPairClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 106
// RVA: 0xC55090
hkClass *__fastcall hkIntRealPair::staticClass()
{
  return &hkIntRealPairClass;
}

// File Line: 113
// RVA: 0xC55130
void __fastcall finishLoadedObjecthkIntRealPair(void *p, int finishing)
{
  ;
}

// File Line: 119
// RVA: 0xC55140
void __fastcall cleanupLoadedObjecthkIntRealPair(void *p)
{
  ;
}

// File Line: 153
// RVA: 0x15C6E10
void dynamic_initializer_for__hkSetIntFloatPairClass__()
{
  hkClass::hkClass(
    &hkSetIntFloatPairClass,
    "hkSetIntFloatPair",
    &hkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPairClass,
    24,
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

// File Line: 156
// RVA: 0xC550A0
hkClass *__fastcall hkSetIntFloatPair::staticClass()
{
  return &hkSetIntFloatPairClass;
}

// File Line: 163
// RVA: 0xC55150
void __fastcall finishLoadedObjecthkSetIntFloatPair(void *p, int finishing)
{
  ;
}

// File Line: 169
// RVA: 0xC55160
void __fastcall cleanupLoadedObjecthkSetIntFloatPair(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 8 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 210
// RVA: 0x15C6F30
void dynamic_initializer_for__hkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedintClass__()
{
  hkClass::hkClass(
    &hkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedintClass,
    "hkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedint",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 216
// RVA: 0xC551D0
void __fastcall finishLoadedObjecthkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedint(
        void *p,
        int finishing)
{
  ;
}

// File Line: 222
// RVA: 0xC551E0
void __fastcall cleanupLoadedObjecthkSetunsignedinthkContainerHeapAllocatorhkMapOperationsunsignedint(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 4 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 263
// RVA: 0x15C6ED0
void dynamic_initializer_for__hkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPairClass__()
{
  hkClass::hkClass(
    &hkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPairClass,
    "hkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPair",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 269
// RVA: 0xC55250
void __fastcall finishLoadedObjecthkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPair(
        void *p,
        int finishing)
{
  ;
}

// File Line: 275
// RVA: 0xC55260
void __fastcall cleanupLoadedObjecthkSethkIntRealPairhkContainerHeapAllocatorhkMapOperationshkIntRealPair(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 8 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

