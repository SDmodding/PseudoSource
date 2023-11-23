// File Line: 57
// RVA: 0x15CF350
void dynamic_initializer_for__hkpBridgeConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpBridgeConstraintAtomClass,
    "hkpBridgeConstraintAtom",
    &hkpConstraintAtomClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpBridgeConstraintAtomClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xD44F30
hkClass *__fastcall hkpBridgeConstraintAtom::staticClass()
{
  return &hkpBridgeConstraintAtomClass;
}

// File Line: 67
// RVA: 0xD44F50
void __fastcall finishLoadedObjecthkpBridgeConstraintAtom(hkpBridgeConstraintAtom *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
      hkpBridgeConstraintAtom::init(p, p->m_constraintData);
  }
}

// File Line: 73
// RVA: 0xD44F70
void __fastcall cleanupLoadedObjecthkpBridgeConstraintAtom(void *p)
{
  ;
}

// File Line: 109
// RVA: 0x15CF2F0
void dynamic_initializer_for__hkpBridgeAtomsClass__()
{
  hkClass::hkClass(
    &hkpBridgeAtomsClass,
    "hkpBridgeAtoms",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpBridgeAtomsClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 112
// RVA: 0xD44F40
hkClass *__fastcall hkpBridgeAtoms::staticClass()
{
  return &hkpBridgeAtomsClass;
}

// File Line: 119
// RVA: 0xD44F80
void __fastcall finishLoadedObjecthkpBridgeAtoms(hkpBridgeConstraintAtom *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
      hkpBridgeConstraintAtom::init(p, p->m_constraintData);
  }
}

// File Line: 125
// RVA: 0xD44FA0
void __fastcall cleanupLoadedObjecthkpBridgeAtoms(void *p)
{
  ;
}

