// File Line: 130
// RVA: 0x15CF880
void dynamic_initializer_for__hkpConstraintInstanceSmallArraySerializeOverrideTypeClass__()
{
  hkClass::hkClass(
    &hkpConstraintInstanceSmallArraySerializeOverrideTypeClass,
    "hkpConstraintInstanceSmallArraySerializeOverrideType",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpConstraintInstance_SmallArraySerializeOverrideTypeClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 133
// RVA: 0xD4F510
hkClass *__fastcall hkpConstraintInstance::SmallArraySerializeOverrideType::staticClass()
{
  return &hkpConstraintInstanceSmallArraySerializeOverrideTypeClass;
}

// File Line: 140
// RVA: 0xD4F520
void __fastcall cleanupLoadedObjecthkpConstraintInstanceSmallArraySerializeOverrideType(void *p)
{
  ;
}

// File Line: 165
// RVA: 0x15CF7E0
hkClassEnum *dynamic_initializer_for__hkpConstraintInstance::Members__()
{
  hkClassEnum *result; // rax

  unk_1421105F0 = hkpConstraintInstanceConstraintPriorityEnum;
  result = hkpConstraintInstanceOnDestructionRemapInfoEnum;
  unk_142110640 = hkpConstraintInstanceOnDestructionRemapInfoEnum;
  return result;
}

// File Line: 208
// RVA: 0x15CF800
void dynamic_initializer_for__hkpConstraintInstanceClass__()
{
  hkClass::hkClass(
    &hkpConstraintInstanceClass,
    "hkpConstraintInstance",
    &hkReferencedObjectClass,
    112,
    0i64,
    0,
    &hkpConstraintInstanceEnums,
    5,
    &hkpConstraintInstance::Members,
    12,
    &hkpConstraintInstance_Default,
    0i64,
    0,
    1);
}

// File Line: 211
// RVA: 0xD4F500
hkClass *__fastcall hkpConstraintInstance::staticClass()
{
  return &hkpConstraintInstanceClass;
}

// File Line: 218
// RVA: 0xD4F530
void __fastcall finishLoadedObjecthkpConstraintInstance(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 10;
    v3[-10].m_stringAndFlag = (const char *)&hkpConstraintInstance::`vftable;
    LODWORD(v3[-1].m_stringAndFlag) = 0x80000000;
    v3[-2].m_stringAndFlag = 0i64;
    hkStringPtr::hkStringPtr(v3, finishing);
    LODWORD(p[13].m_stringAndFlag) = -16;
  }
}

// File Line: 224
// RVA: 0xD4F580
void __fastcall cleanupLoadedObjecthkpConstraintInstance(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 228
// RVA: 0xD4F590
void **__fastcall getVtablehkpConstraintInstance()
{
  hkStringPtr v1; // [rsp+70h] [rbp-28h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpConstraintInstance::`vftable;
}

// File Line: 250
// RVA: 0x15CF8F0
void **dynamic_initializer_for__hkpConstraintInstanceTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConstraintInstance();
  hkpConstraintInstanceTypeInfo.m_size = 112i64;
  hkpConstraintInstanceTypeInfo.m_typeName = "hkpConstraintInstance";
  hkpConstraintInstanceTypeInfo.m_vtable = result;
  hkpConstraintInstanceTypeInfo.m_scopedName = "!hkpConstraintInstance";
  hkpConstraintInstanceTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpConstraintInstance;
  hkpConstraintInstanceTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpConstraintInstance;
  return result;
}

