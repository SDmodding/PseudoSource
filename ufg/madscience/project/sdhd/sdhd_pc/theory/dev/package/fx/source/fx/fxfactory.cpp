// File Line: 574
// RVA: 0x1C6850
void __fastcall Render::FXSettingsInventoryTemplate<Render::DynamicLightSettings,3603788052,2366538547>::Add(
        SimpleXML::XMLFileInventory *this,
        UFG::qResourceData *resource_data)
{
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 583
// RVA: 0x1D25B0
void __fastcall Render::FXSettingsInventoryTemplate<Render::ParticleEmitterSettings,1005461980,3495651702>::Remove(
        Render::FXSettingsInventoryTemplate<Render::ParticleEmitterSettings,1005461980,3495651702> *this,
        Render::ParticleEmitterSettings *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  Render::ParticleEmitterSettings::~ParticleEmitterSettings(resource_data);
}

// File Line: 590
// RVA: 0x146B270
__int64 Render::_dynamic_initializer_for__gDecalSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gDecalSettingsInventory,
    "DecalSettingsInventory",
    0xAE323146,
    0xDCAEC503,
    0,
    0);
  Render::gDecalSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::DecalSettings,2922524998,3702441219>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDecalSettingsInventory__);
}

// File Line: 591
// RVA: 0x146B0B0
__int64 Render::_dynamic_initializer_for__gBeamSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gBeamSettingsInventory,
    "BeamSettingsInventory",
    0xA0AAE10F,
    0x80EF0B08,
    0,
    0);
  Render::gBeamSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::BeamSettings,2695553295,2163149576>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gBeamSettingsInventory__);
}

// File Line: 592
// RVA: 0x146B3B0
__int64 Render::_dynamic_initializer_for__gEffectEmitterSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gEffectEmitterSettingsInventory,
    "EffectEmitterSettingsInventory",
    0xFF1F2832,
    0xD9B10F14,
    0,
    0);
  Render::gEffectEmitterSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::EffectEmitterSettings,4280231986,3652259604>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gEffectEmitterSettingsInventory__);
}

// File Line: 593
// RVA: 0x146B7C0
__int64 Render::_dynamic_initializer_for__gParticleSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gParticleSettingsInventory,
    "ParticleEmitterSettingsInventory",
    0x3BEE21DCu,
    0xD05B6976,
    0,
    0);
  Render::gParticleSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::ParticleEmitterSettings,1005461980,3495651702>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gParticleSettingsInventory__);
}

// File Line: 594
// RVA: 0x146B5F0
__int64 Render::_dynamic_initializer_for__gFlareSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gFlareSettingsInventory,
    "FlareSettingsInventory",
    0xA6535FBB,
    0x83574C18,
    0,
    0);
  Render::gFlareSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::FlareSettings,2790481851,2203536408>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFlareSettingsInventory__);
}

// File Line: 595
// RVA: 0x146B530
__int64 Render::_dynamic_initializer_for__gFXSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gFXSettingsInventory,
    "FXSettingsInventory",
    0xED341A8D,
    0x12289ADBu,
    0,
    0);
  Render::gFXSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::FXSettings,3979614861,304650971>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFXSettingsInventory__);
}

// File Line: 596
// RVA: 0x146AFE0
__int64 Render::_dynamic_initializer_for__gAudioFXSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gAudioFXSettingsInventory,
    "AudioFXSettingsInventory",
    0xD77CCEB2,
    0xAF8870AB,
    0,
    0);
  Render::gAudioFXSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::AudioFXSettings,3615280818,2944954539>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gAudioFXSettingsInventory__);
}

// File Line: 597
// RVA: 0x146B1B0
__int64 Render::_dynamic_initializer_for__gCoronaFlareSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gCoronaFlareSettingsInventory,
    "CoronaFlareSettingsInventory",
    0xB76CCFB8,
    0x9D6378CC,
    0,
    0);
  Render::gCoronaFlareSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::CoronaFlareSettings,3077361592,2640541900>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCoronaFlareSettingsInventory__);
}

// File Line: 598
// RVA: 0x146B350
__int64 Render::_dynamic_initializer_for__gDynamicLightSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gDynamicLightSettingsInventory,
    "DynamicLightSettingsInventory",
    0xD6CD7114,
    0x8D0E8333,
    0,
    0);
  Render::gDynamicLightSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::DynamicLightSettings,3603788052,2366538547>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDynamicLightSettingsInventory__);
}

// File Line: 599
// RVA: 0x146B2D0
__int64 Render::_dynamic_initializer_for__gDynamicLightGroupSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gDynamicLightGroupSettingsInventory,
    "DynamicLightGroupSettingsInventory",
    0x19B59D34u,
    0x230C8A9Cu,
    0,
    0);
  Render::gDynamicLightGroupSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::DynamicLightGroupSettings,431332660,588024476>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDynamicLightGroupSettingsInventory__);
}

// File Line: 600
// RVA: 0x146B410
__int64 Render::_dynamic_initializer_for__gFXForceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gFXForceInventory,
    "FXForceSettingsInventory",
    0x433ED8DFu,
    0x77554FC5u,
    0,
    0);
  Render::gFXForceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::FXForceSettings,1128192223,2002079685>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFXForceInventory__);
}

// File Line: 601
// RVA: 0x146B900
__int64 Render::_dynamic_initializer_for__gScreenParticleSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gScreenParticleSettingsInventory,
    "ScreenParticleEmitterSettingsInventory",
    0x354C3CDCu,
    0x657192D6u,
    0,
    0);
  Render::gScreenParticleSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::ScreenParticleEmitterSettings,894188764,1701941974>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gScreenParticleSettingsInventory__);
}

// File Line: 602
// RVA: 0x146B6D0
__int64 Render::_dynamic_initializer_for__gLightningInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gLightningInventory,
    "LightningSettingsInventory",
    0x21AE1C64u,
    0xB4AEE124,
    0,
    0);
  Render::gLightningInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::LightningSettings,565058660,3031359780>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gLightningInventory__);
}

// File Line: 603
// RVA: 0x146B9E0
__int64 Render::_dynamic_initializer_for__gVolumetricEffectSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gVolumetricEffectSettingsInventory,
    "VolumetricEffectSettingsInventory",
    0xE4B8F46A,
    0xA8EB0D0C,
    0,
    0);
  Render::gVolumetricEffectSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FXSettingsInventoryTemplate<Render::VolumetricEffectSettings,3837326442,2833976588>::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gVolumetricEffectSettingsInventory__);
}

