// File Line: 49
// RVA: 0x595B20
UFG::ComponentIDDesc *__fastcall UFG::AudioEmitterMarker::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AudioEmitterMarker::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AudioEmitterMarker::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AudioEmitterMarker::_TypeIDesc.mChildBitMask = v1;
    UFG::AudioEmitterMarker::_TypeIDesc.mChildren = 0;
    UFG::AudioEmitterMarker::_DescInit = 1;
    UFG::AudioEmitterMarker::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AudioEmitterMarker::_AudioEmitterMarkerTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AudioEmitterMarker::_TypeIDesc;
}

// File Line: 128
// RVA: 0x597590
bool __fastcall UFG::VehicleAudioComponent::ImpactEntity::CanApplyEnvironment(
        UFG::AudioEmitterMarker *this,
        UFG::qWiseSymbol *envType)
{
  return envType->mUID == UFG::WwiseEnvironment::sm_SFX.mUID || envType->mUID == UFG::WwiseEnvironment::sm_All.mUID;
}

