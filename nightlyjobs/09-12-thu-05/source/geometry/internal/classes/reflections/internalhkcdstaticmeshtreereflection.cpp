// File Line: 97
// RVA: 0x15C88D0
void dynamic_initializer_for__hkcdStaticMeshTreeBaseSectionSharedVerticesClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBaseSectionSharedVerticesClass,
    "hkcdStaticMeshTreeBaseSectionSharedVertices",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticMeshTreeBase::Section::SharedVertices::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 100
// RVA: 0xC8E6D0
hkClass *__fastcall hkcdStaticMeshTreeBase::Section::SharedVertices::staticClass()
{
  return &hkcdStaticMeshTreeBaseSectionSharedVerticesClass;
}

// File Line: 107
// RVA: 0xC8E720
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBaseSectionSharedVertices(void *p)
{
  ;
}

// File Line: 142
// RVA: 0x15C8870
void dynamic_initializer_for__hkcdStaticMeshTreeBaseSectionPrimitivesClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBaseSectionPrimitivesClass,
    "hkcdStaticMeshTreeBaseSectionPrimitives",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticMeshTreeBase::Section::Primitives::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 145
// RVA: 0xC8E6E0
hkClass *__fastcall hkcdStaticMeshTreeBase::Section::Primitives::staticClass()
{
  return &hkcdStaticMeshTreeBaseSectionPrimitivesClass;
}

// File Line: 152
// RVA: 0xC8E730
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBaseSectionPrimitives(void *p)
{
  ;
}

// File Line: 187
// RVA: 0x15C8810
void dynamic_initializer_for__hkcdStaticMeshTreeBaseSectionDataRunsClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBaseSectionDataRunsClass,
    "hkcdStaticMeshTreeBaseSectionDataRuns",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticMeshTreeBase::Section::DataRuns::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 190
// RVA: 0xC8E6F0
hkClass *__fastcall hkcdStaticMeshTreeBase::Section::DataRuns::staticClass()
{
  return &hkcdStaticMeshTreeBaseSectionDataRunsClass;
}

// File Line: 197
// RVA: 0xC8E740
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBaseSectionDataRuns(void *p)
{
  ;
}

// File Line: 245
// RVA: 0x15C87A0
void dynamic_initializer_for__hkcdStaticMeshTreeBaseSectionClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBaseSectionClass,
    "hkcdStaticMeshTreeBaseSection",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage4Class,
    96,
    0i64,
    0,
    &hkcdStaticMeshTreeBaseSectionEnums,
    1,
    &hkcdStaticMeshTreeBase_SectionClass_Members,
    12,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 248
// RVA: 0xC8E6C0
hkClass *__fastcall hkcdStaticMeshTreeBase::Section::staticClass()
{
  return &hkcdStaticMeshTreeBaseSectionClass;
}

// File Line: 255
// RVA: 0xC8E750
void __fastcall finishLoadedObjecthkcdStaticMeshTreeBaseSection(void *p, int finishing)
{
  ;
}

// File Line: 261
// RVA: 0xC8E760
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBaseSection(void *p)
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

// File Line: 312
// RVA: 0x15C86D0
void dynamic_initializer_for__hkcdStaticMeshTreeBasePrimitiveClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBasePrimitiveClass,
    "hkcdStaticMeshTreeBasePrimitive",
    0i64,
    4,
    0i64,
    0,
    &hkcdStaticMeshTreeBasePrimitiveEnums,
    1,
    &hkcdStaticMeshTreeBase_PrimitiveClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 315
// RVA: 0xC8E700
hkClass *__fastcall hkcdStaticMeshTreeBase::Primitive::staticClass()
{
  return &hkcdStaticMeshTreeBasePrimitiveClass;
}

// File Line: 322
// RVA: 0xC8E7D0
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBasePrimitive(void *p)
{
  ;
}

// File Line: 365
// RVA: 0x15C8660
void dynamic_initializer_for__hkcdStaticMeshTreeBaseClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBaseClass,
    "hkcdStaticMeshTreeBase",
    &hkcdStaticTreeTreehkcdStaticTreeDynamicStorage5Class,
    112,
    0i64,
    0,
    &hkcdStaticMeshTreeBaseEnums,
    1,
    &hkcdStaticMeshTreeBaseClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 368
// RVA: 0xC8E6B0
hkClass *__fastcall hkcdStaticMeshTreeBase::staticClass()
{
  return &hkcdStaticMeshTreeBaseClass;
}

// File Line: 375
// RVA: 0xC8E7E0
void __fastcall finishLoadedObjecthkcdStaticMeshTreeBase(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkcdStaticMeshTreeBase::hkcdStaticMeshTreeBase);
}

// File Line: 381
// RVA: 0xC8E800
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBase(void *p)
{
  hkcdStaticMeshTreeBase::~hkcdStaticMeshTreeBase((hkcdStaticMeshTreeBase *)p);
}

// File Line: 415
// RVA: 0x15C8930
void dynamic_initializer_for__hkcdStaticMeshTreeDefaultDataRunClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeDefaultDataRunClass,
    "hkcdStaticMeshTreeDefaultDataRun",
    &hkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedshortClass,
    4,
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

// File Line: 418
// RVA: 0xC8E710
hkClass *__fastcall hkcdStaticMeshTreeDefaultDataRun::staticClass()
{
  return &hkcdStaticMeshTreeDefaultDataRunClass;
}

// File Line: 425
// RVA: 0xC8E810
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeDefaultDataRun(void *p)
{
  ;
}

// File Line: 467
// RVA: 0x15C8740
void dynamic_initializer_for__hkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedshortClass__()
{
  hkClass::hkClass(
    &hkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedshortClass,
    "hkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedshort",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticMeshTreeBase::PrimitiveDataRunBase<unsigned short>::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 473
// RVA: 0xC8E820
void __fastcall cleanupLoadedObjecthkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedshort(void *p)
{
  ;
}

