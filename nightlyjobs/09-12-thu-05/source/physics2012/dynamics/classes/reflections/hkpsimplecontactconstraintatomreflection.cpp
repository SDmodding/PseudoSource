// File Line: 62
// RVA: 0x15D1E40
void dynamic_initializer_for__hkpSimpleContactConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpSimpleContactConstraintAtomClass,
    "hkpSimpleContactConstraintAtom",
    &hkpConstraintAtomClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpSimpleContactConstraintAtomClass_Members,
    8,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xD514F0
hkClass *__fastcall hkpSimpleContactConstraintAtom::staticClass()
{
  return &hkpSimpleContactConstraintAtomClass;
}

// File Line: 72
// RVA: 0xD51500
void __fastcall finishLoadedObjecthkpSimpleContactConstraintAtom(
        hkpSimpleContactConstraintAtom *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpSimpleContactConstraintAtom::hkpSimpleContactConstraintAtom(p, finishing);
}

// File Line: 78
// RVA: 0xD51520
void __fastcall cleanupLoadedObjecthkpSimpleContactConstraintAtom(void *p)
{
  ;
}

