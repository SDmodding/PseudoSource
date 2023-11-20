// File Line: 76
// RVA: 0x15C8300
void dynamic_initializer_for__hkcdDynamicTreeDefaultTreePtrStorageClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultTreePtrStorageClass,
    "hkcdDynamicTreeDefaultTreePtrStorage",
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtrClass,
    40,
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

// File Line: 79
// RVA: 0xC8E120
hkClass *__fastcall hkcdDynamicTree::DefaultTreePtrStorage::staticClass()
{
  return &hkcdDynamicTreeDefaultTreePtrStorageClass;
}

// File Line: 86
// RVA: 0xC8E160
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultTreePtrStorage(void *p, int finishing)
{
  ;
}

// File Line: 92
// RVA: 0xC8E170
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultTreePtrStorage(void *p)
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
      v1 << 6);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 126
// RVA: 0x15C8240
void dynamic_initializer_for__hkcdDynamicTreeDefaultTree48StorageClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultTree48StorageClass,
    "hkcdDynamicTreeDefaultTree48Storage",
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32Class,
    40,
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

// File Line: 129
// RVA: 0xC8E130
hkClass *__fastcall hkcdDynamicTree::DefaultTree48Storage::staticClass()
{
  return &hkcdDynamicTreeDefaultTree48StorageClass;
}

// File Line: 136
// RVA: 0xC8E1E0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultTree48Storage(void *p, int finishing)
{
  ;
}

// File Line: 142
// RVA: 0xC8E1F0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultTree48Storage(void *p)
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
      48 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 176
// RVA: 0x15C81E0
void dynamic_initializer_for__hkcdDynamicTreeDefaultTree32StorageClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultTree32StorageClass,
    "hkcdDynamicTreeDefaultTree32Storage",
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16Class,
    40,
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

// File Line: 179
// RVA: 0xC8E140
hkClass *__fastcall hkcdDynamicTree::DefaultTree32Storage::staticClass()
{
  return &hkcdDynamicTreeDefaultTree32StorageClass;
}

// File Line: 186
// RVA: 0xC8E260
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultTree32Storage(void *p, int finishing)
{
  ;
}

// File Line: 192
// RVA: 0xC8E270
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultTree32Storage(void *p)
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

// File Line: 226
// RVA: 0x15C82A0
void dynamic_initializer_for__hkcdDynamicTreeDefaultTreeInt16StorageClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeDefaultTreeInt16StorageClass,
    "hkcdDynamicTreeDefaultTreeInt16Storage",
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16Class,
    40,
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

// File Line: 229
// RVA: 0xC8E150
hkClass *__fastcall hkcdDynamicTree::DefaultTreeInt16Storage::staticClass()
{
  return &hkcdDynamicTreeDefaultTreeInt16StorageClass;
}

// File Line: 236
// RVA: 0xC8E2E0
void __fastcall finishLoadedObjecthkcdDynamicTreeDefaultTreeInt16Storage(void *p, int finishing)
{
  ;
}

// File Line: 242
// RVA: 0xC8E2F0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeDefaultTreeInt16Storage(void *p)
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

// File Line: 285
// RVA: 0x15C84B0
void dynamic_initializer_for__hkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtrClass__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtrClass,
    "hkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtr",
    &hkcdDynamicTreeDynamicStoragePtrClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtr_typenameClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 291
// RVA: 0xC8E360
void __fastcall finishLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtr(void *p, int finishing)
{
  ;
}

// File Line: 297
// RVA: 0xC8E370
void __fastcall cleanupLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStoragePtr(void *p)
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
      v1 << 6);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 340
// RVA: 0x15C83D0
void dynamic_initializer_for__hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32Class,
    "hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32",
    &hkcdDynamicTreeDynamicStorage32Class,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32_typenameClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 346
// RVA: 0xC8E3E0
void __fastcall finishLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32(void *p, int finishing)
{
  ;
}

// File Line: 352
// RVA: 0xC8E3F0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage32(void *p)
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
      48 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 395
// RVA: 0x15C8360
void dynamic_initializer_for__hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16Class,
    "hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16",
    &hkcdDynamicTreeDynamicStorage16Class,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16_typenameClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 401
// RVA: 0xC8E460
void __fastcall finishLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16(void *p, int finishing)
{
  ;
}

// File Line: 407
// RVA: 0xC8E470
void __fastcall cleanupLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorage16(void *p)
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

// File Line: 450
// RVA: 0x15C8440
void dynamic_initializer_for__hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16Class__()
{
  hkClass::hkClass(
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16Class,
    "hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16",
    &hkcdDynamicTreeDynamicStorageInt16Class,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16_typenameClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 456
// RVA: 0xC8E4E0
void __fastcall finishLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16(void *p, int finishing)
{
  ;
}

// File Line: 462
// RVA: 0xC8E4F0
void __fastcall cleanupLoadedObjecthkcdDynamicTreeTreehkcdDynamicTreeDynamicStorageInt16(void *p)
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

