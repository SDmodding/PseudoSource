// File Line: 78
// RVA: 0x15C95F0
void dynamic_initializer_for__hkpCollidableBoundingVolumeDataClass__()
{
  hkClass::hkClass(
    &hkpCollidableBoundingVolumeDataClass,
    "hkpCollidableBoundingVolumeData",
    0i64,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpCollidable_BoundingVolumeDataClass_Members,
    10,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 81
// RVA: 0xCEAE20
hkClass *__fastcall hkpCollidable::BoundingVolumeData::staticClass()
{
  return &hkpCollidableBoundingVolumeDataClass;
}

// File Line: 88
// RVA: 0xCEAE30
void __fastcall finishLoadedObjecthkpCollidableBoundingVolumeData(void *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      *((_DWORD *)p + 8) = 0;
      *((_QWORD *)p + 5) = 0i64;
      *((_QWORD *)p + 6) = 0i64;
      *(_DWORD *)p = 1;
      *((_DWORD *)p + 4) = 0;
    }
  }
}

// File Line: 94
// RVA: 0xCEAE60
void __fastcall cleanupLoadedObjecthkpCollidableBoundingVolumeData(void *p)
{
  ;
}

// File Line: 137
// RVA: 0x15C9660
void dynamic_initializer_for__hkpCollidableClass__()
{
  hkClass::hkClass(
    &hkpCollidableClass,
    "hkpCollidable",
    &hkpCdBodyClass,
    112,
    0i64,
    0,
    &hkpCollidableEnums,
    1,
    &hkpCollidable::Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 140
// RVA: 0xCEAE10
hkClass *__fastcall hkpCollidable::staticClass()
{
  return &hkpCollidableClass;
}

// File Line: 147
// RVA: 0xCEAE70
void __fastcall finishLoadedObjecthkpCollidable(void *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      *((_DWORD *)p + 20) = 0;
      *((_QWORD *)p + 11) = 0i64;
      *((_QWORD *)p + 12) = 0i64;
      *((_DWORD *)p + 16) = 0;
      *((_DWORD *)p + 12) = 1;
      *((_BYTE *)p + 41) = -36;
    }
  }
}

// File Line: 153
// RVA: 0xCEAEB0
void __fastcall cleanupLoadedObjecthkpCollidable(void *p)
{
  ;
}

