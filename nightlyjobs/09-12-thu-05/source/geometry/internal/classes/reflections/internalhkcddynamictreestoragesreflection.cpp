// File Line: 65
// RVA: 0x15C8180
void dynamic_initializer_for__hkcdDynamicTreeDynamicStoragePtrClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStoragePtrClass,
    "hkcdDynamicTreeDynamicStoragePtr",
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlongClass,
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

// File Line: 68
// RVA: 0xC8DAF0
hkClass *__fastcall hkcdDynamicTree::DynamicStoragePtr::staticClass()
{
  return &hkcdDynamicTreeDynamicStoragePtrClass;
}

// File Line: 75
// RVA: 0xC8DB30
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStoragePtr(void *p, int finishing)
{
  ;
}

// File Line: 81
// RVA: 0xC8DB40
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStoragePtr(_DWORD *p)
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, v1 << 6);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 115
// RVA: 0x15C80C0
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage32Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage32Class,
    "hkcdDynamicTreeDynamicStorage32",
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUintClass,
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

// File Line: 118
// RVA: 0xC8DB00
hkClass *__fastcall hkcdDynamicTree::DynamicStorage32::staticClass()
{
  return &hkcdDynamicTreeDynamicStorage32Class;
}

// File Line: 125
// RVA: 0xC8DBB0
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage32(void *p, int finishing)
{
  ;
}

// File Line: 131
// RVA: 0xC8DBC0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage32(_DWORD *p)
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
      48 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 165
// RVA: 0x15C8060
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage16Class,
    "hkcdDynamicTreeDynamicStorage16",
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32Class,
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

// File Line: 168
// RVA: 0xC8DB10
hkClass *__fastcall hkcdDynamicTree::DynamicStorage16::staticClass()
{
  return &hkcdDynamicTreeDynamicStorage16Class;
}

// File Line: 175
// RVA: 0xC8DC30
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage16(void *p, int finishing)
{
  ;
}

// File Line: 181
// RVA: 0xC8DC40
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage16(_DWORD *p)
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

// File Line: 215
// RVA: 0x15C8120
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorageInt16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorageInt16Class,
    "hkcdDynamicTreeDynamicStorageInt16",
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16Class,
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

// File Line: 218
// RVA: 0xC8DB20
hkClass *__fastcall hkcdDynamicTree::DynamicStorageInt16::staticClass()
{
  return &hkcdDynamicTreeDynamicStorageInt16Class;
}

// File Line: 225
// RVA: 0xC8DCB0
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorageInt16(void *p, int finishing)
{
  ;
}

// File Line: 231
// RVA: 0xC8DCC0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorageInt16(_DWORD *p)
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

// File Line: 274
// RVA: 0x15C7FF0
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlongClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlongClass,
    "hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlong",
    &hkcdDynamicTreeAnisotropicMetricClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlong_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 280
// RVA: 0xC8DD30
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlong(
        void *p,
        int finishing)
{
  ;
}

// File Line: 286
// RVA: 0xC8DD40
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlong(
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, v1 << 6);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 322
// RVA: 0x15C7E40
void dynamic_initializer_for__hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlongClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlongClass,
    "hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlong",
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUlongClass,
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

// File Line: 328
// RVA: 0xC8DDB0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlong(
        void *p,
        int finishing)
{
  ;
}

// File Line: 334
// RVA: 0xC8DDC0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlong(_DWORD *p)
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, v1 << 6);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 376
// RVA: 0x15C7F80
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUintClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUintClass,
    "hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUint",
    &hkcdDynamicTreeAnisotropicMetricClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUint_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 382
// RVA: 0xC8DE30
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUint(
        void *p,
        int finishing)
{
  ;
}

// File Line: 388
// RVA: 0xC8DE40
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUint(
        _DWORD *p)
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
      48 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 424
// RVA: 0x15C7DE0
void dynamic_initializer_for__hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUintClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUintClass,
    "hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUint",
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecRawUintClass,
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

// File Line: 430
// RVA: 0xC8DEB0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUint(
        void *p,
        int finishing)
{
  ;
}

// File Line: 436
// RVA: 0xC8DEC0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUint(_DWORD *p)
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
      48 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 478
// RVA: 0x15C7EA0
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32Class,
    "hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32",
    &hkcdDynamicTreeAnisotropicMetricClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 484
// RVA: 0xC8DF30
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32(
        void *p,
        int finishing)
{
  ;
}

// File Line: 490
// RVA: 0xC8DF40
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32(
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 32 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 526
// RVA: 0x15C7D20
void dynamic_initializer_for__hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32Class,
    "hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32",
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodec32Class,
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

// File Line: 532
// RVA: 0xC8DFB0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32(void *p, int finishing)
{
  ;
}

// File Line: 538
// RVA: 0xC8DFC0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodec32(_DWORD *p)
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

// File Line: 580
// RVA: 0x15C7F10
void dynamic_initializer_for__hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16Class,
    "hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16",
    &hkcdDynamicTreeAnisotropicMetricClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16_typenameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 586
// RVA: 0xC8E030
void __fastcall finishLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16(
        void *p,
        int finishing)
{
  ;
}

// File Line: 592
// RVA: 0xC8E040
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16(
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)p, 32 * v1);
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

// File Line: 628
// RVA: 0x15C7D80
void dynamic_initializer_for__hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16Class,
    "hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16",
    &hkcdDynamicTreeDynamicStorage0hkcdDynamicTreeAnisotropicMetrichkcdDynamicTreeCodecInt16Class,
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

// File Line: 634
// RVA: 0xC8E0B0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16(void *p, int finishing)
{
  ;
}

// File Line: 640
// RVA: 0xC8E0C0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecInt16(_DWORD *p)
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

