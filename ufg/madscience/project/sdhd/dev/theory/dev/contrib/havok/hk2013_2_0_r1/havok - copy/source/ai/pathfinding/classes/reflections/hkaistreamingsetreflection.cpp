// File Line: 81
// RVA: 0x15C3FD0
void dynamic_initializer_for__hkaiStreamingSetNavMeshConnectionClass__()
{
  hkClass::hkClass(
    &hkaiStreamingSetNavMeshConnectionClass,
    "hkaiStreamingSetNavMeshConnection",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingSet_NavMeshConnectionClass_Members,
    4,
    &hkaiStreamingSetNavMeshConnection_Default,
    0i64,
    0,
    0);
}

// File Line: 84
// RVA: 0xBB8150
hkClass *__fastcall hkaiStreamingSet::NavMeshConnection::staticClass()
{
  return &hkaiStreamingSetNavMeshConnectionClass;
}

// File Line: 91
// RVA: 0xBB8180
void __fastcall cleanupLoadedObjecthkaiStreamingSetNavMeshConnection(void *p)
{
  ;
}

// File Line: 151
// RVA: 0x15C3F60
void dynamic_initializer_for__hkaiStreamingSetGraphConnectionClass__()
{
  hkClass::hkClass(
    &hkaiStreamingSetGraphConnectionClass,
    "hkaiStreamingSetGraphConnection",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingSet_GraphConnectionClass_Members,
    4,
    &hkaiStreamingSetGraphConnection_Default,
    0i64,
    0,
    3u);
}

// File Line: 154
// RVA: 0xBB8160
hkClass *__fastcall hkaiStreamingSet::GraphConnection::staticClass()
{
  return &hkaiStreamingSetGraphConnectionClass;
}

// File Line: 161
// RVA: 0xBB8190
void __fastcall cleanupLoadedObjecthkaiStreamingSetGraphConnection(void *p)
{
  ;
}

// File Line: 219
// RVA: 0x15C4040
void dynamic_initializer_for__hkaiStreamingSetVolumeConnectionClass__()
{
  hkClass::hkClass(
    &hkaiStreamingSetVolumeConnectionClass,
    "hkaiStreamingSetVolumeConnection",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingSet_VolumeConnectionClass_Members,
    2,
    &hkaiStreamingSetVolumeConnection_Default,
    0i64,
    0,
    0);
}

// File Line: 222
// RVA: 0xBB8170
hkClass *__fastcall hkaiStreamingSet::VolumeConnection::staticClass()
{
  return &hkaiStreamingSetVolumeConnectionClass;
}

// File Line: 229
// RVA: 0xBB81A0
void __fastcall cleanupLoadedObjecthkaiStreamingSetVolumeConnection(void *p)
{
  ;
}

// File Line: 291
// RVA: 0x15C3EF0
void dynamic_initializer_for__hkaiStreamingSetClass__()
{
  hkClass::hkClass(
    &hkaiStreamingSetClass,
    "hkaiStreamingSet",
    0i64,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingSetClass_Members,
    5,
    &hkaiStreamingSet_Default,
    0i64,
    0,
    0);
}

// File Line: 294
// RVA: 0xBB8140
hkClass *__fastcall hkaiStreamingSet::staticClass()
{
  return &hkaiStreamingSetClass;
}

// File Line: 301
// RVA: 0xBB81B0
void __fastcall finishLoadedObjecthkaiStreamingSet(void *p, int finishing)
{
  ;
}

// File Line: 307
// RVA: 0xBB81C0
void __fastcall cleanupLoadedObjecthkaiStreamingSet(void *p)
{
  hkaiStreamingSet::~hkaiStreamingSet((hkaiStreamingSet *)p);
}

