// File Line: 53
// RVA: 0x15D27C0
void dynamic_initializer_for__hkpShapeKeyTableBlockClass__()
{
  hkClass::hkClass(
    &hkpShapeKeyTableBlockClass,
    "hkpShapeKeyTableBlock",
    0i64,
    272,
    0i64,
    0,
    0i64,
    0,
    &hkpShapeKeyTable_BlockClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xD99290
hkClass *__fastcall hkpShapeKeyTable::Block::staticClass()
{
  return &hkpShapeKeyTableBlockClass;
}

// File Line: 63
// RVA: 0xD992A0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkpShapeKeyTableBlock(hkpShapeKeyTable::Block *p)
{
  hkpShapeKeyTable::Block::~Block(p);
}

// File Line: 100
// RVA: 0x15D2820
void dynamic_initializer_for__hkpShapeKeyTableClass__()
{
  hkClass::hkClass(
    &hkpShapeKeyTableClass,
    "hkpShapeKeyTable",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpShapeKeyTable::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 103
// RVA: 0xD99280
hkClass *__fastcall hkpShapeKeyTable::staticClass()
{
  return &hkpShapeKeyTableClass;
}

// File Line: 110
// RVA: 0xD992B0
void __fastcall finishLoadedObjecthkpShapeKeyTable(hkpShapeKeyTable *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpShapeKeyTable::hkpShapeKeyTable(p, finishing);
}

// File Line: 116
// RVA: 0xD992D0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkpShapeKeyTable(hkpShapeKeyTable *p)
{
  hkpShapeKeyTable::~hkpShapeKeyTable(p);
}

