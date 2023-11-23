// File Line: 68
// RVA: 0x15D4420
hkClassEnum *dynamic_initializer_for__hkpTriggerVolume_EventInfoClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpTriggerVolumeOperationEnum;
  unk_142114210 = hkpTriggerVolumeOperationEnum;
  return result;
}

// File Line: 84
// RVA: 0x15D4360
void dynamic_initializer_for__hkpTriggerVolumeEventInfoClass__()
{
  hkClass::hkClass(
    &hkpTriggerVolumeEventInfoClass,
    "hkpTriggerVolumeEventInfo",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkpTriggerVolume_EventInfoClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 87
// RVA: 0xE0BC50
hkClass *__fastcall hkpTriggerVolume::EventInfo::staticClass()
{
  return &hkpTriggerVolumeEventInfoClass;
}

// File Line: 94
// RVA: 0xE0BC60
void __fastcall cleanupLoadedObjecthkpTriggerVolumeEventInfo(void *p)
{
  ;
}

// File Line: 137
// RVA: 0x15D42F0
void dynamic_initializer_for__hkpTriggerVolumeClass__()
{
  hkClass::hkClass(
    &hkpTriggerVolumeClass,
    "hkpTriggerVolume",
    &hkReferencedObjectClass,
    104,
    0i64,
    3,
    &hkpTriggerVolumeEnums,
    2,
    &hkpTriggerVolume::Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 140
// RVA: 0xE0BC40
hkClass *__fastcall hkpTriggerVolume::staticClass()
{
  return &hkpTriggerVolumeClass;
}

// File Line: 147
// RVA: 0xE0BC70
void __fastcall finishLoadedObjecthkpTriggerVolume(hkpTriggerVolume *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpTriggerVolume::hkpTriggerVolume(p, finishing);
}

// File Line: 153
// RVA: 0xE0BC90
void __fastcall cleanupLoadedObjecthkpTriggerVolume(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 157
// RVA: 0xE0BCA0
hkBaseObjectVtbl *__fastcall getVtablehkpTriggerVolume()
{
  hkpTriggerVolume v1; // [rsp+20h] [rbp-78h] BYREF

  hkpTriggerVolume::hkpTriggerVolume(&v1, 0);
  return v1.hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 179
// RVA: 0x15D43C0
hkBaseObjectVtbl *dynamic_initializer_for__hkpTriggerVolumeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpTriggerVolume();
  hkpTriggerVolumeTypeInfo.m_size = 104i64;
  hkpTriggerVolumeTypeInfo.m_typeName = "hkpTriggerVolume";
  hkpTriggerVolumeTypeInfo.m_vtable = result;
  hkpTriggerVolumeTypeInfo.m_scopedName = "!hkpTriggerVolume";
  hkpTriggerVolumeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpTriggerVolume;
  hkpTriggerVolumeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpTriggerVolume;
  return result;
}

