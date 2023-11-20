// File Line: 58
// RVA: 0x15C3DD0
void dynamic_initializer_for__hkaiSilhouetteGeneratorSectionContextClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteGeneratorSectionContextClass,
    "hkaiSilhouetteGeneratorSectionContext",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteGeneratorSectionContext::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xBB8030
hkClass *__fastcall hkaiSilhouetteGeneratorSectionContext::staticClass()
{
  return &hkaiSilhouetteGeneratorSectionContextClass;
}

// File Line: 68
// RVA: 0xBB8040
void __fastcall finishLoadedObjecthkaiSilhouetteGeneratorSectionContext(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xBB8050
void __fastcall cleanupLoadedObjecthkaiSilhouetteGeneratorSectionContext(void *p)
{
  _DWORD *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = p;
  v2 = (hkReferencedObject *)*((_QWORD *)p + 4);
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1[10] = 0;
  *((_QWORD *)v1 + 4) = 0i64;
}

