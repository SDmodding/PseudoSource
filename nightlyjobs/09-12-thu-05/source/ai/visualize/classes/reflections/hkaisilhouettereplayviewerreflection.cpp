// File Line: 70
// RVA: 0x15C52A0
hkClassEnum *dynamic_initializer_for__hkaiSilhouetteRecorder_ReplayEventClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiSilhouetteRecorderReplayEventReplayEventTypeEnum;
  hkaiSilhouetteRecorder_ReplayEventClass_Members.m_enum = hkaiSilhouetteRecorderReplayEventReplayEventTypeEnum;
  return result;
}

// File Line: 87
// RVA: 0x15C4E90
void dynamic_initializer_for__hkaiSilhouetteRecorderReplayEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderReplayEventClass,
    "hkaiSilhouetteRecorderReplayEvent",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    &hkaiSilhouetteRecorderReplayEventEnums,
    1,
    &hkaiSilhouetteRecorder_ReplayEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 90
// RVA: 0xC3DD90
hkClass *__fastcall hkaiSilhouetteRecorder::ReplayEvent::staticClass()
{
  return &hkaiSilhouetteRecorderReplayEventClass;
}

// File Line: 97
// RVA: 0xC3DE20
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderReplayEvent(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSilhouetteRecorder::ReplayEvent::`vftable';
}

// File Line: 103
// RVA: 0xC3DE40
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderReplayEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 107
// RVA: 0xC3DE50
void **__fastcall getVtablehkaiSilhouetteRecorderReplayEvent()
{
  return &hkaiSilhouetteRecorder::ReplayEvent::`vftable';
}

// File Line: 129
// RVA: 0x15C4F00
void **dynamic_initializer_for__hkaiSilhouetteRecorderReplayEventTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSilhouetteRecorderReplayEvent();
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_size = 24i64;
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderReplayEvent";
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::ReplayEvent";
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderReplayEvent;
  hkaiSilhouetteRecorderReplayEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderReplayEvent;
  return result;
}

// File Line: 155
// RVA: 0x15C51D0
void dynamic_initializer_for__hkaiSilhouetteRecorderWorldConnectedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderWorldConnectedEventClass,
    "hkaiSilhouetteRecorderWorldConnectedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_WorldConnectedEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 158
// RVA: 0xC3DDA0
hkClass *__fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderWorldConnectedEventClass;
}

// File Line: 165
// RVA: 0xC3DE60
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderWorldConnectedEvent(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent);
}

// File Line: 171
// RVA: 0xC3DE80
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderWorldConnectedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 175
// RVA: 0xC3DE90
hkBaseObjectVtbl *__fastcall getVtablehkaiSilhouetteRecorderWorldConnectedEvent()
{
  hkaiSilhouetteRecorder::WorldConnectedEvent v1; // [rsp+20h] [rbp-28h]

  hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(&v1, 0);
  return v1.vfptr;
}

// File Line: 197
// RVA: 0x15C5240
hkBaseObjectVtbl *dynamic_initializer_for__hkaiSilhouetteRecorderWorldConnectedEventTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiSilhouetteRecorderWorldConnectedEvent();
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_size = 32i64;
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderWorldConnectedEvent";
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::WorldConnectedEvent";
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderWorldConnectedEvent;
  hkaiSilhouetteRecorderWorldConnectedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderWorldConnectedEvent;
  return result;
}

// File Line: 225
// RVA: 0x15C4CF0
void dynamic_initializer_for__hkaiSilhouetteRecorderInstanceLoadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderInstanceLoadedEventClass,
    "hkaiSilhouetteRecorderInstanceLoadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_InstanceLoadedEventClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 228
// RVA: 0xC3DDB0
hkClass *__fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderInstanceLoadedEventClass;
}

// File Line: 235
// RVA: 0xC3DEB0
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderInstanceLoadedEvent(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent);
}

// File Line: 241
// RVA: 0xC3DED0
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderInstanceLoadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 245
// RVA: 0xC3DEE0
hkBaseObjectVtbl *__fastcall getVtablehkaiSilhouetteRecorderInstanceLoadedEvent()
{
  hkaiSilhouetteRecorder::InstanceLoadedEvent v1; // [rsp+20h] [rbp-38h]

  hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(&v1, 0);
  return v1.vfptr;
}

// File Line: 267
// RVA: 0x15C4D60
hkBaseObjectVtbl *dynamic_initializer_for__hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiSilhouetteRecorderInstanceLoadedEvent();
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_size = 48i64;
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderInstanceLoadedEvent";
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::InstanceLoadedEvent";
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderInstanceLoadedEvent;
  hkaiSilhouetteRecorderInstanceLoadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderInstanceLoadedEvent;
  return result;
}

// File Line: 276
// RVA: 0x15C52B0
hkClassEnum *dynamic_initializer_for__hkaiSilhouetteRecorder_SilhouettesSteppedEventClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiWorldStepThreadingEnum;
  hkaiSilhouetteRecorder_SilhouettesSteppedEventClass_Members.m_enum = hkaiWorldStepThreadingEnum;
  return result;
}

// File Line: 318
// RVA: 0x15C4F60
void dynamic_initializer_for__hkaiSilhouetteRecorderSilhouettesSteppedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderSilhouettesSteppedEventClass,
    "hkaiSilhouetteRecorderSilhouettesSteppedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    104,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_SilhouettesSteppedEventClass_Members,
    5,
    &hkaiSilhouetteRecorderSilhouettesSteppedEvent_Default,
    0i64,
    0,
    3u);
}

// File Line: 321
// RVA: 0xC3DDC0
hkClass *__fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderSilhouettesSteppedEventClass;
}

// File Line: 328
// RVA: 0xC3DF00
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderSilhouettesSteppedEvent(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent);
}

// File Line: 334
// RVA: 0xC3DF20
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderSilhouettesSteppedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 338
// RVA: 0xC3DF30
hkBaseObjectVtbl *__fastcall getVtablehkaiSilhouetteRecorderSilhouettesSteppedEvent()
{
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent v1; // [rsp+20h] [rbp-78h]

  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(&v1, 0);
  return v1.vfptr;
}

// File Line: 360
// RVA: 0x15C4FD0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiSilhouetteRecorderSilhouettesSteppedEvent();
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_size = 104i64;
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderSilhouettesSteppedEvent";
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::SilhouettesSteppedEvent";
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderSilhouettesSteppedEvent;
  hkaiSilhouetteRecorderSilhouettesSteppedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderSilhouettesSteppedEvent;
  return result;
}

// File Line: 386
// RVA: 0x15C4DC0
void dynamic_initializer_for__hkaiSilhouetteRecorderInstanceUnloadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderInstanceUnloadedEventClass,
    "hkaiSilhouetteRecorderInstanceUnloadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_InstanceUnloadedEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 389
// RVA: 0xC3DDD0
hkClass *__fastcall hkaiSilhouetteRecorder::InstanceUnloadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderInstanceUnloadedEventClass;
}

// File Line: 396
// RVA: 0xC3DF60
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderInstanceUnloadedEvent(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSilhouetteRecorder::InstanceUnloadedEvent::`vftable';
}

// File Line: 402
// RVA: 0xC3DF80
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderInstanceUnloadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 406
// RVA: 0xC3DF90
void **__fastcall getVtablehkaiSilhouetteRecorderInstanceUnloadedEvent()
{
  return &hkaiSilhouetteRecorder::InstanceUnloadedEvent::`vftable';
}

// File Line: 428
// RVA: 0x15C4E30
void **dynamic_initializer_for__hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSilhouetteRecorderInstanceUnloadedEvent();
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_size = 32i64;
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderInstanceUnloadedEvent";
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::InstanceUnloadedEvent";
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderInstanceUnloadedEvent;
  hkaiSilhouetteRecorderInstanceUnloadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderInstanceUnloadedEvent;
  return result;
}

// File Line: 455
// RVA: 0x15C5030
void dynamic_initializer_for__hkaiSilhouetteRecorderVolumeLoadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderVolumeLoadedEventClass,
    "hkaiSilhouetteRecorderVolumeLoadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_VolumeLoadedEventClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 458
// RVA: 0xC3DDE0
hkClass *__fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderVolumeLoadedEventClass;
}

// File Line: 465
// RVA: 0xC3DFA0
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderVolumeLoadedEvent(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent);
}

// File Line: 471
// RVA: 0xC3DFC0
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderVolumeLoadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 475
// RVA: 0xC3DFD0
hkBaseObjectVtbl *__fastcall getVtablehkaiSilhouetteRecorderVolumeLoadedEvent()
{
  hkaiSilhouetteRecorder::VolumeLoadedEvent v1; // [rsp+20h] [rbp-38h]

  hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(&v1, 0);
  return v1.vfptr;
}

// File Line: 497
// RVA: 0x15C50A0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiSilhouetteRecorderVolumeLoadedEvent();
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_size = 40i64;
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderVolumeLoadedEvent";
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::VolumeLoadedEvent";
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderVolumeLoadedEvent;
  hkaiSilhouetteRecorderVolumeLoadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderVolumeLoadedEvent;
  return result;
}

// File Line: 523
// RVA: 0x15C5100
void dynamic_initializer_for__hkaiSilhouetteRecorderVolumeUnloadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderVolumeUnloadedEventClass,
    "hkaiSilhouetteRecorderVolumeUnloadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_VolumeUnloadedEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 526
// RVA: 0xC3DDF0
hkClass *__fastcall hkaiSilhouetteRecorder::VolumeUnloadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderVolumeUnloadedEventClass;
}

// File Line: 533
// RVA: 0xC3DFF0
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderVolumeUnloadedEvent(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSilhouetteRecorder::VolumeUnloadedEvent::`vftable';
}

// File Line: 539
// RVA: 0xC3E010
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderVolumeUnloadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 543
// RVA: 0xC3E020
void **__fastcall getVtablehkaiSilhouetteRecorderVolumeUnloadedEvent()
{
  return &hkaiSilhouetteRecorder::VolumeUnloadedEvent::`vftable';
}

// File Line: 565
// RVA: 0x15C5170
void **dynamic_initializer_for__hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSilhouetteRecorderVolumeUnloadedEvent();
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_size = 32i64;
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderVolumeUnloadedEvent";
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::VolumeUnloadedEvent";
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderVolumeUnloadedEvent;
  hkaiSilhouetteRecorderVolumeUnloadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderVolumeUnloadedEvent;
  return result;
}

// File Line: 591
// RVA: 0x15C4B50
void dynamic_initializer_for__hkaiSilhouetteRecorderGraphLoadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderGraphLoadedEventClass,
    "hkaiSilhouetteRecorderGraphLoadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_GraphLoadedEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 594
// RVA: 0xC3DE00
hkClass *__fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderGraphLoadedEventClass;
}

// File Line: 601
// RVA: 0xC3E030
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderGraphLoadedEvent(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent);
}

// File Line: 607
// RVA: 0xC3E050
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderGraphLoadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 611
// RVA: 0xC3E060
hkBaseObjectVtbl *__fastcall getVtablehkaiSilhouetteRecorderGraphLoadedEvent()
{
  hkaiSilhouetteRecorder::GraphLoadedEvent v1; // [rsp+20h] [rbp-28h]

  hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(&v1, 0);
  return v1.vfptr;
}

// File Line: 633
// RVA: 0x15C4BC0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiSilhouetteRecorderGraphLoadedEventTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiSilhouetteRecorderGraphLoadedEvent();
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_size = 32i64;
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderGraphLoadedEvent";
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::GraphLoadedEvent";
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderGraphLoadedEvent;
  hkaiSilhouetteRecorderGraphLoadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderGraphLoadedEvent;
  return result;
}

// File Line: 659
// RVA: 0x15C4C20
void dynamic_initializer_for__hkaiSilhouetteRecorderGraphUnloadedEventClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteRecorderGraphUnloadedEventClass,
    "hkaiSilhouetteRecorderGraphUnloadedEvent",
    &hkaiSilhouetteRecorderReplayEventClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteRecorder_GraphUnloadedEventClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 662
// RVA: 0xC3DE10
hkClass *__fastcall hkaiSilhouetteRecorder::GraphUnloadedEvent::staticClass()
{
  return &hkaiSilhouetteRecorderGraphUnloadedEventClass;
}

// File Line: 669
// RVA: 0xC3E080
void __fastcall finishLoadedObjecthkaiSilhouetteRecorderGraphUnloadedEvent(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSilhouetteRecorder::GraphUnloadedEvent::`vftable';
}

// File Line: 675
// RVA: 0xC3E0A0
void __fastcall cleanupLoadedObjecthkaiSilhouetteRecorderGraphUnloadedEvent(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 679
// RVA: 0xC3E0B0
void **__fastcall getVtablehkaiSilhouetteRecorderGraphUnloadedEvent()
{
  return &hkaiSilhouetteRecorder::GraphUnloadedEvent::`vftable';
}

// File Line: 701
// RVA: 0x15C4C90
void **dynamic_initializer_for__hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSilhouetteRecorderGraphUnloadedEvent();
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_size = 32i64;
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_typeName = "hkaiSilhouetteRecorderGraphUnloadedEvent";
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_vtable = result;
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_scopedName = "!hkaiSilhouetteRecorder::GraphUnloadedEvent";
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteRecorderGraphUnloadedEvent;
  hkaiSilhouetteRecorderGraphUnloadedEventTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteRecorderGraphUnloadedEvent;
  return result;
}

