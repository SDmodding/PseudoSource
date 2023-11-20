// File Line: 62
// RVA: 0x15C8CC0
void dynamic_initializer_for__hkcdStaticTreeDefaultTreeStorage4Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDefaultTreeStorage4Class,
    "hkcdStaticTreeDefaultTreeStorage4",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4Class,
    48,
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

// File Line: 65
// RVA: 0xC8EB70
hkClass *__fastcall hkcdStaticTree::DefaultTreeStorage4::staticClass()
{
  return &hkcdStaticTreeDefaultTreeStorage4Class;
}

// File Line: 72
// RVA: 0xC8EBB0
void __fastcall finishLoadedObjecthkcdStaticTreeDefaultTreeStorage4(void *p, int finishing)
{
  ;
}

// File Line: 78
// RVA: 0xC8EBC0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDefaultTreeStorage4(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      4 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 112
// RVA: 0x15C8D20
void dynamic_initializer_for__hkcdStaticTreeDefaultTreeStorage5Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDefaultTreeStorage5Class,
    "hkcdStaticTreeDefaultTreeStorage5",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5Class,
    48,
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

// File Line: 115
// RVA: 0xC8EB80
hkClass *__fastcall hkcdStaticTree::DefaultTreeStorage5::staticClass()
{
  return &hkcdStaticTreeDefaultTreeStorage5Class;
}

// File Line: 122
// RVA: 0xC8EC30
void __fastcall finishLoadedObjecthkcdStaticTreeDefaultTreeStorage5(void *p, int finishing)
{
  ;
}

// File Line: 128
// RVA: 0xC8EC40
void __fastcall cleanupLoadedObjecthkcdStaticTreeDefaultTreeStorage5(void *p)
{
  int v1; // eax
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      5 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 162
// RVA: 0x15C8D80
void dynamic_initializer_for__hkcdStaticTreeDefaultTreeStorage6Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDefaultTreeStorage6Class,
    "hkcdStaticTreeDefaultTreeStorage6",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage6Class,
    48,
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

// File Line: 165
// RVA: 0xC8EB90
hkClass *__fastcall hkcdStaticTree::DefaultTreeStorage6::staticClass()
{
  return &hkcdStaticTreeDefaultTreeStorage6Class;
}

// File Line: 172
// RVA: 0xC8ECB0
void __fastcall finishLoadedObjecthkcdStaticTreeDefaultTreeStorage6(void *p, int finishing)
{
  ;
}

// File Line: 178
// RVA: 0xC8ECC0
void __fastcall cleanupLoadedObjecthkcdStaticTreeDefaultTreeStorage6(void *p)
{
  int v1; // eax
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      6 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 212
// RVA: 0x15C8C60
void dynamic_initializer_for__hkcdStaticTreeDefaultTreeStorage32Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeDefaultTreeStorage32Class,
    "hkcdStaticTreeDefaultTreeStorage32",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage32Class,
    48,
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

// File Line: 215
// RVA: 0xC8EBA0
hkClass *__fastcall hkcdStaticTree::DefaultTreeStorage32::staticClass()
{
  return &hkcdStaticTreeDefaultTreeStorage32Class;
}

// File Line: 222
// RVA: 0xC8ED30
void __fastcall finishLoadedObjecthkcdStaticTreeDefaultTreeStorage32(void *p, int finishing)
{
  ;
}

// File Line: 228
// RVA: 0xC8ED40
void __fastcall cleanupLoadedObjecthkcdStaticTreeDefaultTreeStorage32(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      32 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 269
// RVA: 0x15C8E50
void dynamic_initializer_for__hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4Class,
    "hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4",
    &hkcdStaticTreeDynamicStorage4Class,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 275
// RVA: 0xC8EDB0
void __fastcall finishLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage4(void *p, int finishing)
{
  ;
}

// File Line: 281
// RVA: 0xC8EDC0
void __fastcall cleanupLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage4(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      4 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 322
// RVA: 0x15C8EC0
void dynamic_initializer_for__hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5Class,
    "hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5",
    &hkcdStaticTreeDynamicStorage5Class,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 328
// RVA: 0xC8EE30
void __fastcall finishLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage5(void *p, int finishing)
{
  ;
}

// File Line: 334
// RVA: 0xC8EE40
void __fastcall cleanupLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage5(void *p)
{
  int v1; // eax
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      5 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 375
// RVA: 0x15C8F30
void dynamic_initializer_for__hkcdStaticTreeTreehkcdStaticTreeDynamicStorage6Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage6Class,
    "hkcdStaticTreeTreehkcdStaticTreeDynamicStorage6",
    &hkcdStaticTreeDynamicStorage6Class,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage6_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 381
// RVA: 0xC8EEB0
void __fastcall finishLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage6(void *p, int finishing)
{
  ;
}

// File Line: 387
// RVA: 0xC8EEC0
void __fastcall cleanupLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage6(void *p)
{
  int v1; // eax
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      6 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 428
// RVA: 0x15C8DE0
void dynamic_initializer_for__hkcdStaticTreeTreehkcdStaticTreeDynamicStorage32Class__()
{
  hkClass::hkClass(
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage32Class,
    "hkcdStaticTreeTreehkcdStaticTreeDynamicStorage32",
    &hkcdStaticTreeDynamicStorage32Class,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage32_typenameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 434
// RVA: 0xC8EF30
void __fastcall finishLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage32(void *p, int finishing)
{
  ;
}

// File Line: 440
// RVA: 0xC8EF40
void __fastcall cleanupLoadedObjecthkcdStaticTreeTreehkcdStaticTreeDynamicStorage32(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      32 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

