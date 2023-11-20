// File Line: 53
// RVA: 0x15CFB00
void dynamic_initializer_for__hkpSimpleShapePhantomCollisionDetailClass__()
{
  hkClass::hkClass(
    &hkpSimpleShapePhantomCollisionDetailClass,
    "hkpSimpleShapePhantomCollisionDetail",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkpSimpleShapePhantom_CollisionDetailClass_Members,
    1,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 56
// RVA: 0xD4F6B0
hkClass *__fastcall hkpSimpleShapePhantom::CollisionDetail::staticClass()
{
  return &hkpSimpleShapePhantomCollisionDetailClass;
}

// File Line: 63
// RVA: 0xD4F6C0
void __fastcall cleanupLoadedObjecthkpSimpleShapePhantomCollisionDetail(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15CFA90
void dynamic_initializer_for__hkpSimpleShapePhantomClass__()
{
  hkClass::hkClass(
    &hkpSimpleShapePhantomClass,
    "hkpSimpleShapePhantom",
    &hkpShapePhantomClass,
    448,
    0i64,
    0,
    0i64,
    0,
    &hkpSimpleShapePhantom::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xD4F6A0
hkClass *__fastcall hkpSimpleShapePhantom::staticClass()
{
  return &hkpSimpleShapePhantomClass;
}

// File Line: 112
// RVA: 0xD4F6D0
void __fastcall finishLoadedObjecthkpSimpleShapePhantom(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpSimpleShapePhantom::hkpSimpleShapePhantom);
}

// File Line: 118
// RVA: 0xD4F6F0
void __fastcall cleanupLoadedObjecthkpSimpleShapePhantom(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 122
// RVA: 0xD4F700
hkBaseObjectVtbl *__fastcall getVtablehkpSimpleShapePhantom()
{
  hkpSimpleShapePhantom v1; // [rsp+20h] [rbp-1C8h]

  hkpSimpleShapePhantom::hkpSimpleShapePhantom(&v1, 0);
  return v1.vfptr;
}

// File Line: 144
// RVA: 0x15CFB70
hkBaseObjectVtbl *dynamic_initializer_for__hkpSimpleShapePhantomTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpSimpleShapePhantom();
  hkpSimpleShapePhantomTypeInfo.m_size = 448i64;
  hkpSimpleShapePhantomTypeInfo.m_typeName = "hkpSimpleShapePhantom";
  hkpSimpleShapePhantomTypeInfo.m_vtable = result;
  hkpSimpleShapePhantomTypeInfo.m_scopedName = "!hkpSimpleShapePhantom";
  hkpSimpleShapePhantomTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpSimpleShapePhantom;
  hkpSimpleShapePhantomTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpSimpleShapePhantom;
  return result;
}

