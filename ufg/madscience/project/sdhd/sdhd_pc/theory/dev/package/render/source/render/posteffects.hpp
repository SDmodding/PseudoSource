// File Line: 47
// RVA: 0x5F610
UFG::ComponentIDDesc *__fastcall UFG::DamagePostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::DamagePostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::DamagePostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::DamagePostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::DamagePostEffect::_TypeIDesc.mChildren = 0;
    UFG::DamagePostEffect::_DescInit = 1;
    UFG::DamagePostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::DamagePostEffect::_DamagePostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::DamagePostEffect::_TypeIDesc;
}

// File Line: 72
// RVA: 0x5F730
UFG::ComponentIDDesc *__fastcall UFG::GunRecoilPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::GunRecoilPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::GunRecoilPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::GunRecoilPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::GunRecoilPostEffect::_TypeIDesc.mChildren = 0;
    UFG::GunRecoilPostEffect::_DescInit = 1;
    UFG::GunRecoilPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::GunRecoilPostEffect::_GunRecoilPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::GunRecoilPostEffect::_TypeIDesc;
}

// File Line: 120
// RVA: 0x5F7C0
UFG::ComponentIDDesc *__fastcall UFG::VisualTreatmentPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::VisualTreatmentPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::VisualTreatmentPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::VisualTreatmentPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::VisualTreatmentPostEffect::_TypeIDesc.mChildren = 0;
    UFG::VisualTreatmentPostEffect::_DescInit = 1;
    UFG::VisualTreatmentPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::VisualTreatmentPostEffect::_VisualTreatmentPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::VisualTreatmentPostEffect::_TypeIDesc;
}

// File Line: 167
// RVA: 0x5F580
UFG::ComponentIDDesc *__fastcall UFG::AccumulationBufferPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AccumulationBufferPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AccumulationBufferPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AccumulationBufferPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::AccumulationBufferPostEffect::_TypeIDesc.mChildren = 0;
    UFG::AccumulationBufferPostEffect::_DescInit = 1;
    UFG::AccumulationBufferPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AccumulationBufferPostEffect::_AccumulationBufferPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AccumulationBufferPostEffect::_TypeIDesc;
}

// File Line: 188
// RVA: 0x5F6A0
UFG::ComponentIDDesc *__fastcall UFG::FrontEndPauseEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::FrontEndPauseEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::FrontEndPauseEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::FrontEndPauseEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::FrontEndPauseEffect::_TypeIDesc.mChildren = 0;
    UFG::FrontEndPauseEffect::_DescInit = 1;
    UFG::FrontEndPauseEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::FrontEndPauseEffect::_FrontEndPauseEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::FrontEndPauseEffect::_TypeIDesc;
}

