// File Line: 39
// RVA: 0x15D7E10
hkClassEnum *dynamic_initializer_for__hkxVertexAnimation_UsageMapClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxVertexDescriptionDataUsageEnum;
  hkxVertexAnimation_UsageMapClass_Members.m_enum = hkxVertexDescriptionDataUsageEnum;
  return result;
}

// File Line: 57
// RVA: 0x15D7DB0
void dynamic_initializer_for__hkxVertexAnimationUsageMapClass__()
{
  hkClass::hkClass(
    &hkxVertexAnimationUsageMapClass,
    "hkxVertexAnimationUsageMap",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexAnimation_UsageMapClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xE336E0
hkClass *__fastcall hkxVertexAnimation::UsageMap::staticClass()
{
  return &hkxVertexAnimationUsageMapClass;
}

// File Line: 67
// RVA: 0xE336F0
void __fastcall cleanupLoadedObjecthkxVertexAnimationUsageMap(void *p)
{
  ;
}

// File Line: 108
// RVA: 0x15D7CE0
void dynamic_initializer_for__hkxVertexAnimationClass__()
{
  hkClass::hkClass(
    &hkxVertexAnimationClass,
    "hkxVertexAnimation",
    &hkReferencedObjectClass,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexAnimationClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 111
// RVA: 0xE336D0
hkClass *__fastcall hkxVertexAnimation::staticClass()
{
  return &hkxVertexAnimationClass;
}

// File Line: 118
// RVA: 0xE33700
void __fastcall finishLoadedObjecthkxVertexAnimation(void *p, int finishing)
{
  hkxVertexBuffer *v2; // rcx

  if ( p )
  {
    v2 = (hkxVertexBuffer *)((char *)p + 24);
    *(_QWORD *)&v2[-1].m_data.m_uint16Stride = &hkxVertexAnimation::`vftable';
    hkxVertexBuffer::hkxVertexBuffer(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 124
// RVA: 0xE33730
void __fastcall cleanupLoadedObjecthkxVertexAnimation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 128
// RVA: 0xE33740
void **__fastcall getVtablehkxVertexAnimation()
{
  hkxVertexBuffer v1; // [rsp+38h] [rbp-B0h]

  hkxVertexBuffer::hkxVertexBuffer(&v1, 0);
  return &hkxVertexAnimation::`vftable';
}

// File Line: 150
// RVA: 0x15D7D50
void **dynamic_initializer_for__hkxVertexAnimationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxVertexAnimation();
  hkxVertexAnimationTypeInfo.m_size = 192i64;
  hkxVertexAnimationTypeInfo.m_typeName = "hkxVertexAnimation";
  hkxVertexAnimationTypeInfo.m_vtable = result;
  hkxVertexAnimationTypeInfo.m_scopedName = "!hkxVertexAnimation";
  hkxVertexAnimationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxVertexAnimation;
  hkxVertexAnimationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxVertexAnimation;
  return result;
}

