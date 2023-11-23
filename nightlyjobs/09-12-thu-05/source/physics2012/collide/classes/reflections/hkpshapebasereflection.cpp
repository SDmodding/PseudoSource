// File Line: 48
// RVA: 0x15CA960
void dynamic_initializer_for__hkpShapeBaseClass__()
{
  hkClass::hkClass(&hkpShapeBaseClass, "hkpShapeBase", &hkcdShapeClass, 24, 0i64, 0, 0i64, 0, 0i64, 0, 0i64, 0i64, 0, 0);
}

// File Line: 51
// RVA: 0xCEBCB0
hkClass *__fastcall hkpShapeBase::staticClass()
{
  return &hkpShapeBaseClass;
}

// File Line: 58
// RVA: 0xCEBCC0
void __fastcall finishLoadedObjecthkpShapeBase(hkpShapeBase *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpShapeBase::hkpShapeBase(p, finishing);
}

// File Line: 64
// RVA: 0xCEBCE0
void __fastcall cleanupLoadedObjecthkpShapeBase(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xCEBCF0
hkBaseObjectVtbl *__fastcall getVtablehkpShapeBase()
{
  hkpShapeBase v1; // [rsp+20h] [rbp-28h] BYREF

  hkpShapeBase::hkpShapeBase(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15CA9C0
hkBaseObjectVtbl *dynamic_initializer_for__hkpShapeBaseTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpShapeBase();
  hkpShapeBaseTypeInfo.m_size = 24i64;
  hkpShapeBaseTypeInfo.m_typeName = "hkpShapeBase";
  hkpShapeBaseTypeInfo.m_vtable = result;
  hkpShapeBaseTypeInfo.m_scopedName = "!hkpShapeBase";
  hkpShapeBaseTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpShapeBase;
  hkpShapeBaseTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpShapeBase;
  return result;
}

