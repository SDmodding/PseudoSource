// File Line: 55
// RVA: 0x15C4AF0
void dynamic_initializer_for__hkaiIntervalPartitionLibraryPartitionRecordClass__()
{
  hkClass::hkClass(
    &hkaiIntervalPartitionLibraryPartitionRecordClass,
    "hkaiIntervalPartitionLibraryPartitionRecord",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiIntervalPartitionLibrary_PartitionRecordClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xC32640
hkClass *__fastcall hkaiIntervalPartitionLibrary::PartitionRecord::staticClass()
{
  return &hkaiIntervalPartitionLibraryPartitionRecordClass;
}

// File Line: 65
// RVA: 0xC32650
void __fastcall cleanupLoadedObjecthkaiIntervalPartitionLibraryPartitionRecord(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15C4A90
void dynamic_initializer_for__hkaiIntervalPartitionLibraryClass__()
{
  hkClass::hkClass(
    &hkaiIntervalPartitionLibraryClass,
    "hkaiIntervalPartitionLibrary",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiIntervalPartitionLibrary::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xC32630
hkClass *__fastcall hkaiIntervalPartitionLibrary::staticClass()
{
  return &hkaiIntervalPartitionLibraryClass;
}

// File Line: 112
// RVA: 0xC32660
void __fastcall finishLoadedObjecthkaiIntervalPartitionLibrary(void *p, int finishing)
{
  ;
}

// File Line: 118
// RVA: 0xC32670
void __fastcall cleanupLoadedObjecthkaiIntervalPartitionLibrary(void *p)
{
  hkaiIntervalPartitionLibrary::~hkaiIntervalPartitionLibrary((hkaiIntervalPartitionLibrary *)p);
}

