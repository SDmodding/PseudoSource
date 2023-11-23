// File Line: 109
// RVA: 0x15C0680
hkClassEnum *dynamic_initializer_for__hkaiCharacter::Members__()
{
  hkClassEnum *result; // rax

  unk_142104190 = hkaiCharacterAvoidanceEnabledMaskBitsEnum;
  result = hkaiCharacterStateEnum;
  unk_1421041B8 = hkaiCharacterStateEnum;
  return result;
}

// File Line: 152
// RVA: 0x15C06A0
void dynamic_initializer_for__hkaiCharacterClass__()
{
  hkClass::hkClass(
    &hkaiCharacterClass,
    "hkaiCharacter",
    &hkReferencedObjectClass,
    192,
    0i64,
    0,
    &hkaiCharacterEnums,
    3,
    &hkaiCharacter::Members,
    21,
    &hkaiCharacter_Default,
    0i64,
    0,
    28);
}

// File Line: 155
// RVA: 0xBB60C0
hkClass *__fastcall hkaiCharacter::staticClass()
{
  return &hkaiCharacterClass;
}

// File Line: 162
// RVA: 0xBB60D0
void __fastcall finishLoadedObjecthkaiCharacter(hkaiCharacter *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiCharacter::hkaiCharacter(p, finishing);
}

// File Line: 168
// RVA: 0xBB60F0
void __fastcall cleanupLoadedObjecthkaiCharacter(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 172
// RVA: 0xBB6100
hkBaseObjectVtbl *__fastcall getVtablehkaiCharacter()
{
  hkaiCharacter v1; // [rsp+20h] [rbp-C8h] BYREF

  hkaiCharacter::hkaiCharacter(&v1, 0);
  return v1.vfptr;
}

// File Line: 194
// RVA: 0x15C0720
hkBaseObjectVtbl *dynamic_initializer_for__hkaiCharacterTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiCharacter();
  hkaiCharacterTypeInfo.m_size = 192i64;
  hkaiCharacterTypeInfo.m_typeName = "hkaiCharacter";
  hkaiCharacterTypeInfo.m_vtable = result;
  hkaiCharacterTypeInfo.m_scopedName = "!hkaiCharacter";
  hkaiCharacterTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiCharacter;
  hkaiCharacterTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiCharacter;
  return result;
}

