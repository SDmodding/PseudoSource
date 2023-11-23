// File Line: 48
// RVA: 0x15C6260
void dynamic_initializer_for__hkBitFieldClass__()
{
  hkClass::hkClass(
    &hkBitFieldClass,
    "hkBitField",
    &hkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
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
    2);
}

// File Line: 51
// RVA: 0xC54A10
hkClass *__fastcall hkBitField::staticClass()
{
  return &hkBitFieldClass;
}

// File Line: 58
// RVA: 0xC54A30
void __fastcall finishLoadedObjecthkBitField(void *p, int finishing)
{
  ;
}

// File Line: 64
// RVA: 0xC54A40
void __fastcall cleanupLoadedObjecthkBitField(_DWORD *p)
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

// File Line: 98
// RVA: 0x15C6320
void dynamic_initializer_for__hkOffsetBitFieldClass__()
{
  hkClass::hkClass(
    &hkOffsetBitFieldClass,
    "hkOffsetBitField",
    &hkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
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

// File Line: 101
// RVA: 0xC54A20
hkClass *__fastcall hkOffsetBitField::staticClass()
{
  return &hkOffsetBitFieldClass;
}

// File Line: 108
// RVA: 0xC54AB0
void __fastcall finishLoadedObjecthkOffsetBitField(void *p, int finishing)
{
  ;
}

// File Line: 114
// RVA: 0xC54AC0
void __fastcall cleanupLoadedObjecthkOffsetBitField(_DWORD *p)
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

// File Line: 155
// RVA: 0x15C62C0
void dynamic_initializer_for__hkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass__()
{
  hkClass::hkClass(
    &hkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
    "hkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 161
// RVA: 0xC54B30
void __fastcall finishLoadedObjecthkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(void *p, int finishing)
{
  ;
}

// File Line: 167
// RVA: 0xC54B40
void __fastcall cleanupLoadedObjecthkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(_DWORD *p)
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

// File Line: 208
// RVA: 0x15C61A0
void dynamic_initializer_for__hkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass__()
{
  hkClass::hkClass(
    &hkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
    "hkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 214
// RVA: 0xC54BB0
void __fastcall finishLoadedObjecthkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(
        void *p,
        int finishing)
{
  ;
}

// File Line: 220
// RVA: 0xC54BC0
void __fastcall cleanupLoadedObjecthkBitFieldBasehkBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(_DWORD *p)
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

// File Line: 261
// RVA: 0x15C6380
void dynamic_initializer_for__hkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass__()
{
  hkClass::hkClass(
    &hkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
    "hkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 267
// RVA: 0xC54C30
void __fastcall finishLoadedObjecthkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(
        void *p,
        int finishing)
{
  ;
}

// File Line: 273
// RVA: 0xC54C40
void __fastcall cleanupLoadedObjecthkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(_DWORD *p)
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

// File Line: 314
// RVA: 0x15C6200
void dynamic_initializer_for__hkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass__()
{
  hkClass::hkClass(
    &hkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocatorClass,
    "hkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkBitFieldBase<hkOffsetBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 320
// RVA: 0xC54CB0
void __fastcall finishLoadedObjecthkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(
        void *p,
        int finishing)
{
  ;
}

// File Line: 326
// RVA: 0xC54CC0
void __fastcall cleanupLoadedObjecthkBitFieldBasehkOffsetBitFieldStoragehkArrayunsignedinthkContainerHeapAllocator(
        _DWORD *p)
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

