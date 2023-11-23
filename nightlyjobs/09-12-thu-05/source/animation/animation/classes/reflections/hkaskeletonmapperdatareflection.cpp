// File Line: 71
// RVA: 0x15BE400
void dynamic_initializer_for__hkaSkeletonMapperDataSimpleMappingClass__()
{
  hkClass::hkClass(
    &hkaSkeletonMapperDataSimpleMappingClass,
    "hkaSkeletonMapperDataSimpleMapping",
    0i64,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeletonMapperData_SimpleMappingClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 74
// RVA: 0xB1C780
hkClass *__fastcall hkaSkeletonMapperData::SimpleMapping::staticClass()
{
  return &hkaSkeletonMapperDataSimpleMappingClass;
}

// File Line: 81
// RVA: 0xB1C7B0
void __fastcall cleanupLoadedObjecthkaSkeletonMapperDataSimpleMapping(void *p)
{
  ;
}

// File Line: 121
// RVA: 0x15BE2B0
void dynamic_initializer_for__hkaSkeletonMapperDataChainMappingClass__()
{
  hkClass::hkClass(
    &hkaSkeletonMapperDataChainMappingClass,
    "hkaSkeletonMapperDataChainMapping",
    0i64,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeletonMapperData_ChainMappingClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 124
// RVA: 0xB1C790
hkClass *__fastcall hkaSkeletonMapperData::ChainMapping::staticClass()
{
  return &hkaSkeletonMapperDataChainMappingClass;
}

// File Line: 131
// RVA: 0xB1C7C0
void __fastcall cleanupLoadedObjecthkaSkeletonMapperDataChainMapping(void *p)
{
  ;
}

// File Line: 167
// RVA: 0x15BE3A0
void dynamic_initializer_for__hkaSkeletonMapperDataPartitionMappingRangeClass__()
{
  hkClass::hkClass(
    &hkaSkeletonMapperDataPartitionMappingRangeClass,
    "hkaSkeletonMapperDataPartitionMappingRange",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeletonMapperData_PartitionMappingRangeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 170
// RVA: 0xB1C7A0
hkClass *__fastcall hkaSkeletonMapperData::PartitionMappingRange::staticClass()
{
  return &hkaSkeletonMapperDataPartitionMappingRangeClass;
}

// File Line: 177
// RVA: 0xB1C7D0
void __fastcall cleanupLoadedObjecthkaSkeletonMapperDataPartitionMappingRange(void *p)
{
  ;
}

// File Line: 206
// RVA: 0x15BE390
hkClassEnum *dynamic_initializer_for__hkaSkeletonMapperDataClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaSkeletonMapperDataMappingTypeEnum;
  unk_142100F90 = hkaSkeletonMapperDataMappingTypeEnum;
  return result;
}

// File Line: 243
// RVA: 0x15BE310
void dynamic_initializer_for__hkaSkeletonMapperDataClass__()
{
  hkClass::hkClass(
    &hkaSkeletonMapperDataClass,
    "hkaSkeletonMapperData",
    0i64,
    176,
    0i64,
    0,
    &hkaSkeletonMapperDataEnums,
    1,
    &hkaSkeletonMapperDataClass_Members,
    11,
    &hkaSkeletonMapperData_Default,
    0i64,
    0,
    2);
}

// File Line: 246
// RVA: 0xB1C770
hkClass *__fastcall hkaSkeletonMapperData::staticClass()
{
  return &hkaSkeletonMapperDataClass;
}

// File Line: 253
// RVA: 0xB1C7E0
void __fastcall finishLoadedObjecthkaSkeletonMapperData(hkaSkeletonMapperData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaSkeletonMapperData::hkaSkeletonMapperData(p, finishing);
}

// File Line: 259
// RVA: 0xB1C800
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaSkeletonMapperData(hkaSkeletonMapperData *p)
{
  hkaSkeletonMapperData::~hkaSkeletonMapperData(p);
}

