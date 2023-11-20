// File Line: 56
// RVA: 0x15C15B0
void dynamic_initializer_for__hkaiMaterialPainterClass__()
{
  hkClass::hkClass(
    &hkaiMaterialPainterClass,
    "hkaiMaterialPainter",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiMaterialPainter::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xBB6920
hkClass *__fastcall hkaiMaterialPainter::staticClass()
{
  return &hkaiMaterialPainterClass;
}

// File Line: 66
// RVA: 0xBB6930
void __fastcall finishLoadedObjecthkaiMaterialPainter(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiMaterialPainter::hkaiMaterialPainter);
}

// File Line: 72
// RVA: 0xBB6950
void __fastcall cleanupLoadedObjecthkaiMaterialPainter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xBB6960
hkBaseObjectVtbl *__fastcall getVtablehkaiMaterialPainter()
{
  hkaiMaterialPainter v1; // [rsp+20h] [rbp-28h]

  hkaiMaterialPainter::hkaiMaterialPainter(&v1, 0);
  return v1.vfptr;
}

// File Line: 98
// RVA: 0x15C1620
hkBaseObjectVtbl *dynamic_initializer_for__hkaiMaterialPainterTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiMaterialPainter();
  hkaiMaterialPainterTypeInfo.m_size = 32i64;
  hkaiMaterialPainterTypeInfo.m_typeName = "hkaiMaterialPainter";
  hkaiMaterialPainterTypeInfo.m_vtable = result;
  hkaiMaterialPainterTypeInfo.m_scopedName = "!hkaiMaterialPainter";
  hkaiMaterialPainterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiMaterialPainter;
  hkaiMaterialPainterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiMaterialPainter;
  return result;
}

