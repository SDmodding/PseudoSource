// File Line: 83
// RVA: 0x15C1F10
void dynamic_initializer_for__hkaiNavVolumeCellClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeCellClass,
    "hkaiNavVolumeCell",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolume_CellClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 86
// RVA: 0xBB6DE0
hkClass *__fastcall hkaiNavVolume::Cell::staticClass()
{
  return &hkaiNavVolumeCellClass;
}

// File Line: 93
// RVA: 0xBB6E00
void __fastcall cleanupLoadedObjecthkaiNavVolumeCell(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15C20C0
hkClassEnum *dynamic_initializer_for__hkaiNavVolume_EdgeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavVolumeCellEdgeFlagBitsEnum;
  hkaiNavVolume_EdgeClass_Members.m_enum = hkaiNavVolumeCellEdgeFlagBitsEnum;
  return result;
}

// File Line: 129
// RVA: 0x15C1FF0
void dynamic_initializer_for__hkaiNavVolumeEdgeClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeEdgeClass,
    "hkaiNavVolumeEdge",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolume_EdgeClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 132
// RVA: 0xBB6DF0
hkClass *__fastcall hkaiNavVolume::Edge::staticClass()
{
  return &hkaiNavVolumeEdgeClass;
}

// File Line: 139
// RVA: 0xBB6E10
void __fastcall cleanupLoadedObjecthkaiNavVolumeEdge(void *p)
{
  ;
}

// File Line: 204
// RVA: 0x15C1F70
void dynamic_initializer_for__hkaiNavVolumeClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeClass,
    "hkaiNavVolume",
    &hkReferencedObjectClass,
    160,
    0i64,
    0,
    &hkaiNavVolumeEnums,
    2,
    &hkaiNavVolume::Members,
    8,
    &hkaiNavVolume_Default,
    0i64,
    0,
    0xAu);
}

// File Line: 207
// RVA: 0xBB6DD0
hkClass *__fastcall hkaiNavVolume::staticClass()
{
  return &hkaiNavVolumeClass;
}

// File Line: 214
// RVA: 0xBB6E20
void __fastcall finishLoadedObjecthkaiNavVolume(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavVolume::hkaiNavVolume);
}

// File Line: 220
// RVA: 0xBB6E40
void __fastcall cleanupLoadedObjecthkaiNavVolume(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 224
// RVA: 0xBB6E50
hkBaseObjectVtbl *__fastcall getVtablehkaiNavVolume()
{
  hkaiNavVolume v1; // [rsp+20h] [rbp-A8h]

  hkaiNavVolume::hkaiNavVolume(&v1, 0);
  return v1.vfptr;
}

// File Line: 246
// RVA: 0x15C2060
hkBaseObjectVtbl *dynamic_initializer_for__hkaiNavVolumeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiNavVolume();
  hkaiNavVolumeTypeInfo.m_size = 160i64;
  hkaiNavVolumeTypeInfo.m_typeName = "hkaiNavVolume";
  hkaiNavVolumeTypeInfo.m_vtable = result;
  hkaiNavVolumeTypeInfo.m_scopedName = "!hkaiNavVolume";
  hkaiNavVolumeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiNavVolume;
  hkaiNavVolumeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiNavVolume;
  return result;
}

