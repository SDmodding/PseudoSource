// File Line: 86
// RVA: 0x15D8460
hkClassEnum *dynamic_initializer_for__hkxVertexDescription_ElementDeclClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142115EE8 = hkxVertexDescriptionDataTypeEnum;
  unk_142115F10 = hkxVertexDescriptionDataUsageEnum;
  result = hkxVertexDescriptionDataHintEnum;
  unk_142115F88 = hkxVertexDescriptionDataHintEnum;
  return result;
}

// File Line: 106
// RVA: 0x15D83F0
void dynamic_initializer_for__hkxVertexDescriptionElementDeclClass__()
{
  hkClass::hkClass(
    &hkxVertexDescriptionElementDeclClass,
    "hkxVertexDescriptionElementDecl",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexDescription_ElementDeclClass_Members,
    6,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 109
// RVA: 0xE33CB0
hkClass *__fastcall hkxVertexDescription::ElementDecl::staticClass()
{
  return &hkxVertexDescriptionElementDeclClass;
}

// File Line: 116
// RVA: 0xE33CC0
void __fastcall cleanupLoadedObjecthkxVertexDescriptionElementDecl(void *p)
{
  ;
}

// File Line: 152
// RVA: 0x15D8380
void dynamic_initializer_for__hkxVertexDescriptionClass__()
{
  hkClass::hkClass(
    &hkxVertexDescriptionClass,
    "hkxVertexDescription",
    0i64,
    16,
    0i64,
    0,
    &hkxVertexDescriptionEnums,
    3,
    &hkxVertexDescriptionClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 155
// RVA: 0xE33CA0
hkClass *__fastcall hkxVertexDescription::staticClass()
{
  return &hkxVertexDescriptionClass;
}

// File Line: 162
// RVA: 0xE33CD0
void __fastcall finishLoadedObjecthkxVertexDescription(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkxVertexDescription::hkxVertexDescription);
}

// File Line: 168
// RVA: 0xE33CF0
void __fastcall cleanupLoadedObjecthkxVertexDescription(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      16 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

