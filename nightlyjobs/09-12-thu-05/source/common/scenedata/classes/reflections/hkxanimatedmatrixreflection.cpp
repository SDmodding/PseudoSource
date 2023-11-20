// File Line: 39
// RVA: 0x15D6110
hkClassEnum *dynamic_initializer_for__hkxAnimatedMatrixClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxAttributeHintEnum;
  unk_142114D58 = hkxAttributeHintEnum;
  return result;
}

// File Line: 56
// RVA: 0x15D60A0
void dynamic_initializer_for__hkxAnimatedMatrixClass__()
{
  hkClass::hkClass(
    &hkxAnimatedMatrixClass,
    "hkxAnimatedMatrix",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkxAnimatedMatrixClass_Members,
    2,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 59
// RVA: 0xE316F0
hkClass *__fastcall hkxAnimatedMatrix::staticClass()
{
  return &hkxAnimatedMatrixClass;
}

// File Line: 66
// RVA: 0xE31700
void __fastcall finishLoadedObjecthkxAnimatedMatrix(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxAnimatedMatrix::`vftable;
}

// File Line: 72
// RVA: 0xE31720
void __fastcall cleanupLoadedObjecthkxAnimatedMatrix(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE31730
void **__fastcall getVtablehkxAnimatedMatrix()
{
  return &hkxAnimatedMatrix::`vftable;
}

// File Line: 98
// RVA: 0x15D6120
void **dynamic_initializer_for__hkxAnimatedMatrixTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxAnimatedMatrix();
  hkxAnimatedMatrixTypeInfo.m_size = 40i64;
  hkxAnimatedMatrixTypeInfo.m_typeName = "hkxAnimatedMatrix";
  hkxAnimatedMatrixTypeInfo.m_vtable = result;
  hkxAnimatedMatrixTypeInfo.m_scopedName = "!hkxAnimatedMatrix";
  hkxAnimatedMatrixTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxAnimatedMatrix;
  hkxAnimatedMatrixTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxAnimatedMatrix;
  return result;
}

