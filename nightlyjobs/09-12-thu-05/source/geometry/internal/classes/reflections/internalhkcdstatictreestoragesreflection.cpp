// File Line: 65
// RVA: 0x15C9000
void dynamic_initializer_for__hkcdStaticTreeDynamicStorage4Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStorage4Class,
    "hkcdStaticTreeDynamicStorage4",
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4Class,
    16,
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

// File Line: 68
// RVA: 0xC8F020
hkClass *__fastcall hkcdStaticTree::DynamicStorage4::staticClass()
{
  return &hkcdStaticTreeDynamicStorage4Class;
}

// File Line: 75
// RVA: 0xC8F060
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStorage4(void *p, int finishing)
{
  ;
}

// File Line: 81
// RVA: 0xC8F070
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStorage4(_DWORD *p)
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

// File Line: 115
// RVA: 0x15C9060
void dynamic_initializer_for__hkcdStaticTreeDynamicStorage5Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStorage5Class,
    "hkcdStaticTreeDynamicStorage5",
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5Class,
    16,
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

// File Line: 118
// RVA: 0xC8F030
hkClass *__fastcall hkcdStaticTree::DynamicStorage5::staticClass()
{
  return &hkcdStaticTreeDynamicStorage5Class;
}

// File Line: 125
// RVA: 0xC8F0E0
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStorage5(void *p, int finishing)
{
  ;
}

// File Line: 131
// RVA: 0xC8F0F0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStorage5(_DWORD *p)
{
  int v1; // eax

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      5 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 165
// RVA: 0x15C90C0
void dynamic_initializer_for__hkcdStaticTreeDynamicStorage6Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStorage6Class,
    "hkcdStaticTreeDynamicStorage6",
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6Class,
    16,
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

// File Line: 168
// RVA: 0xC8F040
hkClass *__fastcall hkcdStaticTree::DynamicStorage6::staticClass()
{
  return &hkcdStaticTreeDynamicStorage6Class;
}

// File Line: 175
// RVA: 0xC8F160
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStorage6(void *p, int finishing)
{
  ;
}

// File Line: 181
// RVA: 0xC8F170
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStorage6(_DWORD *p)
{
  int v1; // eax

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      6 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 215
// RVA: 0x15C8FA0
void dynamic_initializer_for__hkcdStaticTreeDynamicStorage32Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStorage32Class,
    "hkcdStaticTreeDynamicStorage32",
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRawClass,
    16,
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

// File Line: 218
// RVA: 0xC8F050
hkClass *__fastcall hkcdStaticTree::DynamicStorage32::staticClass()
{
  return &hkcdStaticTreeDynamicStorage32Class;
}

// File Line: 225
// RVA: 0xC8F1E0
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStorage32(void *p, int finishing)
{
  ;
}

// File Line: 231
// RVA: 0xC8F1F0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStorage32(_DWORD *p)
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 32 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 270
// RVA: 0x15C9120
void dynamic_initializer_for__hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4Class,
    "hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 276
// RVA: 0xC8F260
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4(void *p, int finishing)
{
  ;
}

// File Line: 282
// RVA: 0xC8F270
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis4(_DWORD *p)
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

// File Line: 321
// RVA: 0x15C9180
void dynamic_initializer_for__hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5Class,
    "hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 327
// RVA: 0xC8F2E0
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5(void *p, int finishing)
{
  ;
}

// File Line: 333
// RVA: 0xC8F2F0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis5(_DWORD *p)
{
  int v1; // eax

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      5 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 372
// RVA: 0x15C91E0
void dynamic_initializer_for__hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6Class,
    "hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 378
// RVA: 0xC8F360
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6(void *p, int finishing)
{
  ;
}

// File Line: 384
// RVA: 0xC8F370
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodec3Axis6(_DWORD *p)
{
  int v1; // eax

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      6 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 423
// RVA: 0x15C9240
void dynamic_initializer_for__hkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRawClass__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRawClass,
    "hkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRaw",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRaw_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 429
// RVA: 0xC8F3E0
void __fastcall finishLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRaw(void *p, int finishing)
{
  ;
}

// File Line: 435
// RVA: 0xC8F3F0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDynamicStoragehkcdStaticTreeCodecRaw(_DWORD *p)
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 32 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

