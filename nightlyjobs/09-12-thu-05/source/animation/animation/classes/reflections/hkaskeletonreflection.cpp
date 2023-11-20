// File Line: 58
// RVA: 0x15BE4D0
void dynamic_initializer_for__hkaSkeletonLocalFrameOnBoneClass__()
{
  hkClass::hkClass(
    &hkaSkeletonLocalFrameOnBoneClass,
    "hkaSkeletonLocalFrameOnBone",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeleton_LocalFrameOnBoneClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xB1C820
hkClass *__fastcall hkaSkeleton::LocalFrameOnBone::staticClass()
{
  return &hkaSkeletonLocalFrameOnBoneClass;
}

// File Line: 68
// RVA: 0xB1C840
void __fastcall finishLoadedObjecthkaSkeletonLocalFrameOnBone(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xB1C850
void __fastcall cleanupLoadedObjecthkaSkeletonLocalFrameOnBone(void *p)
{
  _QWORD *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = p;
  v2 = *(hkReferencedObject **)p;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  *v1 = 0i64;
}

// File Line: 111
// RVA: 0x15BE530
void dynamic_initializer_for__hkaSkeletonPartitionClass__()
{
  hkClass::hkClass(
    &hkaSkeletonPartitionClass,
    "hkaSkeletonPartition",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeleton_PartitionClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 114
// RVA: 0xB1C830
hkClass *__fastcall hkaSkeleton::Partition::staticClass()
{
  return &hkaSkeletonPartitionClass;
}

// File Line: 121
// RVA: 0xB1C880
void __fastcall finishLoadedObjecthkaSkeletonPartition(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkStringPtr::hkStringPtr);
}

// File Line: 127
// RVA: 0xB1C8A0
void __fastcall cleanupLoadedObjecthkaSkeletonPartition(void *p)
{
  hkStringPtr::~hkStringPtr((hkStringPtr *)p);
}

// File Line: 172
// RVA: 0x15BE460
void dynamic_initializer_for__hkaSkeletonClass__()
{
  hkClass::hkClass(
    &hkaSkeletonClass,
    "hkaSkeleton",
    &hkReferencedObjectClass,
    136,
    0i64,
    0,
    0i64,
    0,
    &hkaSkeletonClass_Members,
    8,
    0i64,
    0i64,
    0,
    5u);
}

// File Line: 175
// RVA: 0xB1C810
hkClass *__fastcall hkaSkeleton::staticClass()
{
  return &hkaSkeletonClass;
}

// File Line: 182
// RVA: 0xB1C8B0
void __fastcall finishLoadedObjecthkaSkeleton(void *p, int finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = (hkStringPtr *)((char *)p + 16);
    v2[-2].m_stringAndFlag = (const char *)&hkaSkeleton::`vftable;
    hkStringPtr::hkStringPtr(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 188
// RVA: 0xB1C8E0
void __fastcall cleanupLoadedObjecthkaSkeleton(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 192
// RVA: 0xB1C8F0
void **__fastcall getVtablehkaSkeleton()
{
  hkStringPtr v1; // [rsp+30h] [rbp-88h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkaSkeleton::`vftable;
}

// File Line: 214
// RVA: 0x15BE5A0
void **dynamic_initializer_for__hkaSkeletonTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaSkeleton();
  hkaSkeletonTypeInfo.m_size = 136i64;
  hkaSkeletonTypeInfo.m_typeName = "hkaSkeleton";
  hkaSkeletonTypeInfo.m_vtable = result;
  hkaSkeletonTypeInfo.m_scopedName = "!hkaSkeleton";
  hkaSkeletonTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaSkeleton;
  hkaSkeletonTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaSkeleton;
  return result;
}

