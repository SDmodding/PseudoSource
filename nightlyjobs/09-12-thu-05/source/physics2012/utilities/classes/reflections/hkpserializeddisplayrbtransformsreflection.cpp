// File Line: 54
// RVA: 0x15D4130
void dynamic_initializer_for__hkpSerializedDisplayRbTransformsDisplayTransformPairClass__()
{
  hkClass::hkClass(
    &hkpSerializedDisplayRbTransformsDisplayTransformPairClass,
    "hkpSerializedDisplayRbTransformsDisplayTransformPair",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedDisplayRbTransforms_DisplayTransformPairClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE0BAF0
hkClass *__fastcall hkpSerializedDisplayRbTransforms::DisplayTransformPair::staticClass()
{
  return &hkpSerializedDisplayRbTransformsDisplayTransformPairClass;
}

// File Line: 64
// RVA: 0xE0BB00
void __fastcall cleanupLoadedObjecthkpSerializedDisplayRbTransformsDisplayTransformPair(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15D40C0
void dynamic_initializer_for__hkpSerializedDisplayRbTransformsClass__()
{
  hkClass::hkClass(
    &hkpSerializedDisplayRbTransformsClass,
    "hkpSerializedDisplayRbTransforms",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedDisplayRbTransformsClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xE0BAE0
hkClass *__fastcall hkpSerializedDisplayRbTransforms::staticClass()
{
  return &hkpSerializedDisplayRbTransformsClass;
}

// File Line: 112
// RVA: 0xE0BB10
void __fastcall finishLoadedObjecthkpSerializedDisplayRbTransforms(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSerializedDisplayRbTransforms::`vftable;
}

// File Line: 118
// RVA: 0xE0BB30
void __fastcall cleanupLoadedObjecthkpSerializedDisplayRbTransforms(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 122
// RVA: 0xE0BB40
void **__fastcall getVtablehkpSerializedDisplayRbTransforms()
{
  return &hkpSerializedDisplayRbTransforms::`vftable;
}

// File Line: 144
// RVA: 0x15D4190
void **dynamic_initializer_for__hkpSerializedDisplayRbTransformsTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSerializedDisplayRbTransforms();
  hkpSerializedDisplayRbTransformsTypeInfo.m_size = 32i64;
  hkpSerializedDisplayRbTransformsTypeInfo.m_typeName = "hkpSerializedDisplayRbTransforms";
  hkpSerializedDisplayRbTransformsTypeInfo.m_vtable = result;
  hkpSerializedDisplayRbTransformsTypeInfo.m_scopedName = "!hkpSerializedDisplayRbTransforms";
  hkpSerializedDisplayRbTransformsTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSerializedDisplayRbTransforms;
  hkpSerializedDisplayRbTransformsTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSerializedDisplayRbTransforms;
  return result;
}

