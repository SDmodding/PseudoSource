// File Line: 66
// RVA: 0x15CBF70
void dynamic_initializer_for__hkpTriSampledHeightFieldCollectionClass__()
{
  hkClass::hkClass(
    &hkpTriSampledHeightFieldCollectionClass,
    "hkpTriSampledHeightFieldCollection",
    &hkpShapeCollectionClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpTriSampledHeightFieldCollection::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 69
// RVA: 0xCECB70
hkClass *__fastcall hkpTriSampledHeightFieldCollection::staticClass()
{
  return &hkpTriSampledHeightFieldCollectionClass;
}

// File Line: 76
// RVA: 0xCECB80
void __fastcall finishLoadedObjecthkpTriSampledHeightFieldCollection(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection);
}

// File Line: 82
// RVA: 0xCECBA0
void __fastcall cleanupLoadedObjecthkpTriSampledHeightFieldCollection(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 86
// RVA: 0xCECBB0
hkBaseObjectVtbl *__fastcall getVtablehkpTriSampledHeightFieldCollection()
{
  hkpTriSampledHeightFieldCollection v1; // [rsp+20h] [rbp-68h]

  hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(&v1, 0);
  return v1.vfptr;
}

// File Line: 108
// RVA: 0x15CBFE0
hkBaseObjectVtbl *dynamic_initializer_for__hkpTriSampledHeightFieldCollectionTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpTriSampledHeightFieldCollection();
  hkpTriSampledHeightFieldCollectionTypeInfo.m_size = 96i64;
  hkpTriSampledHeightFieldCollectionTypeInfo.m_typeName = "hkpTriSampledHeightFieldCollection";
  hkpTriSampledHeightFieldCollectionTypeInfo.m_vtable = result;
  hkpTriSampledHeightFieldCollectionTypeInfo.m_scopedName = "!hkpTriSampledHeightFieldCollection";
  hkpTriSampledHeightFieldCollectionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpTriSampledHeightFieldCollection;
  hkpTriSampledHeightFieldCollectionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpTriSampledHeightFieldCollection;
  return result;
}

