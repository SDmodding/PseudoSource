// File Line: 59
// RVA: 0x15D3EC0
void dynamic_initializer_for__hkpSerializedTrack1nInfoClass__()
{
  hkClass::hkClass(
    &hkpSerializedTrack1nInfoClass,
    "hkpSerializedTrack1nInfo",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedTrack1nInfoClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xE0B7F0
hkClass *__fastcall hkpSerializedTrack1nInfo::staticClass()
{
  return &hkpSerializedTrack1nInfoClass;
}

// File Line: 69
// RVA: 0xE0B820
void __fastcall finishLoadedObjecthkpSerializedTrack1nInfo(void *p, int finishing)
{
  ;
}

// File Line: 75
// RVA: 0xE0B830
// attributes: thunk
void __fastcall cleanupLoadedObjecthkpSerializedTrack1nInfo(hkpSerializedTrack1nInfo *p)
{
  hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(p);
}

// File Line: 112
// RVA: 0x15D3E50
void dynamic_initializer_for__hkpSerializedSubTrack1nInfoClass__()
{
  hkClass::hkClass(
    &hkpSerializedSubTrack1nInfoClass,
    "hkpSerializedSubTrack1nInfo",
    &hkpSerializedTrack1nInfoClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedSubTrack1nInfoClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 115
// RVA: 0xE0B800
hkClass *__fastcall hkpSerializedSubTrack1nInfo::staticClass()
{
  return &hkpSerializedSubTrack1nInfoClass;
}

// File Line: 122
// RVA: 0xE0B840
void __fastcall finishLoadedObjecthkpSerializedSubTrack1nInfo(void *p, int finishing)
{
  ;
}

// File Line: 128
// RVA: 0xE0B850
// attributes: thunk
void __fastcall cleanupLoadedObjecthkpSerializedSubTrack1nInfo(hkpSerializedTrack1nInfo *p)
{
  hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(p);
}

// File Line: 175
// RVA: 0x15D3DE0
hkClassEnum *dynamic_initializer_for__hkpSerializedAgentNnEntryClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpSerializedAgentNnEntrySerializedAgentTypeEnum;
  unk_142113DA8 = hkpSerializedAgentNnEntrySerializedAgentTypeEnum;
  return result;
}

// File Line: 200
// RVA: 0x15D3D60
void dynamic_initializer_for__hkpSerializedAgentNnEntryClass__()
{
  hkClass::hkClass(
    &hkpSerializedAgentNnEntryClass,
    "hkpSerializedAgentNnEntry",
    &hkReferencedObjectClass,
    400,
    0i64,
    0,
    &hkpSerializedAgentNnEntryEnums,
    1,
    &hkpSerializedAgentNnEntryClass_Members,
    14,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 203
// RVA: 0xE0B810
hkClass *__fastcall hkpSerializedAgentNnEntry::staticClass()
{
  return &hkpSerializedAgentNnEntryClass;
}

// File Line: 210
// RVA: 0xE0B860
void __fastcall finishLoadedObjecthkpSerializedAgentNnEntry(char *p, hkFinishLoadedObjectFlag finishing)
{
  hkpSimpleContactConstraintAtom *v2; // rcx

  if ( p )
  {
    v2 = (hkpSimpleContactConstraintAtom *)(p + 64);
    *(_QWORD *)v2[-2].m_info.m_data = &hkpSerializedAgentNnEntry::`vftable;
    hkpSimpleContactConstraintAtom::hkpSimpleContactConstraintAtom(v2, finishing);
  }
}

// File Line: 216
// RVA: 0xE0B890
void __fastcall cleanupLoadedObjecthkpSerializedAgentNnEntry(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 220
// RVA: 0xE0B8A0
void **__fastcall getVtablehkpSerializedAgentNnEntry()
{
  hkpSimpleContactConstraintAtom v1; // [rsp+60h] [rbp-158h] BYREF

  hkpSimpleContactConstraintAtom::hkpSimpleContactConstraintAtom(&v1, 0);
  return &hkpSerializedAgentNnEntry::`vftable;
}

// File Line: 242
// RVA: 0x15D3DF0
void **dynamic_initializer_for__hkpSerializedAgentNnEntryTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSerializedAgentNnEntry();
  hkpSerializedAgentNnEntryTypeInfo.m_size = 400i64;
  hkpSerializedAgentNnEntryTypeInfo.m_typeName = "hkpSerializedAgentNnEntry";
  hkpSerializedAgentNnEntryTypeInfo.m_vtable = result;
  hkpSerializedAgentNnEntryTypeInfo.m_scopedName = "!hkpSerializedAgentNnEntry";
  hkpSerializedAgentNnEntryTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSerializedAgentNnEntry;
  hkpSerializedAgentNnEntryTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSerializedAgentNnEntry;
  return result;
}

