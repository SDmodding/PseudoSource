// File Line: 60
// RVA: 0x15D29B0
void dynamic_initializer_for__hkpBvCompressedMeshShapeTreeDataRunClass__()
{
  hkClass::hkClass(
    &hkpBvCompressedMeshShapeTreeDataRunClass,
    "hkpBvCompressedMeshShapeTreeDataRun",
    &hkcdStaticMeshTreeBasePrimitiveDataRunBaseunsignedintClass,
    8,
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

// File Line: 63
// RVA: 0xD99460
hkClass *__fastcall hkpBvCompressedMeshShapeTreeDataRun::staticClass()
{
  return &hkpBvCompressedMeshShapeTreeDataRunClass;
}

// File Line: 70
// RVA: 0xD99480
void __fastcall cleanupLoadedObjecthkpBvCompressedMeshShapeTreeDataRun(void *p)
{
  ;
}

// File Line: 104
// RVA: 0x15D2950
void dynamic_initializer_for__hkpBvCompressedMeshShapeTreeClass__()
{
  hkClass::hkClass(
    &hkpBvCompressedMeshShapeTreeClass,
    "hkpBvCompressedMeshShapeTree",
    &hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hkpBvCompressedMeshShapeTreeDataRunClass,
    160,
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

// File Line: 107
// RVA: 0xD99470
hkClass *__fastcall hkpBvCompressedMeshShapeTree::staticClass()
{
  return &hkpBvCompressedMeshShapeTreeClass;
}

// File Line: 114
// RVA: 0xD99490
void __fastcall finishLoadedObjecthkpBvCompressedMeshShapeTree(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkcdStaticMeshTreeBase::hkcdStaticMeshTreeBase);
}

// File Line: 120
// RVA: 0xD994B0
void __fastcall cleanupLoadedObjecthkpBvCompressedMeshShapeTree(void *p)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::~hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>((hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)p);
}

