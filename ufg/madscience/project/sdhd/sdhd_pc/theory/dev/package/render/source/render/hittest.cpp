// File Line: 40
// RVA: 0x6F6A0
UFG::ComponentIDDesc *__fastcall Render::HitTestComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !Render::HitTestComponent::_DescInit )
  {
    Render::HitTestComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    Render::HitTestComponent::_DescInit = 1;
    Render::HitTestComponent::_TypeUID = Render::HitTestComponent::_TypeIDesc.mChildBitMask | (Render::HitTestComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::HitTestComponent::_HitTestComponentTypeUID = Render::HitTestComponent::_TypeIDesc.mChildBitMask | (Render::HitTestComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::HitTestComponent::_TypeIDesc;
}

// File Line: 58
// RVA: 0x1457120
__int64 dynamic_initializer_for__Render::HitTestComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = Render::HitTestComponent::AccessComponentDesc();
  *(_DWORD *)&Render::HitTestComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  Render::HitTestComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  Render::HitTestComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 59
// RVA: 0x1457180
__int64 dynamic_initializer_for__Render::HitTestComponent::s_HitTestComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::HitTestComponent::s_HitTestComponentList__);
}

// File Line: 74
// RVA: 0x6F710
UFG::ComponentIDDesc *__fastcall Render::HitTestPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !Render::HitTestPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&Render::HitTestPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    Render::HitTestPostEffect::_TypeIDesc.mChildBitMask = v1;
    Render::HitTestPostEffect::_TypeIDesc.mChildren = 0;
    Render::HitTestPostEffect::_DescInit = 1;
    Render::HitTestPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    Render::HitTestPostEffect::_HitTestPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &Render::HitTestPostEffect::_TypeIDesc;
}

// File Line: 236
// RVA: 0x1457150
__int64 dynamic_initializer_for__Render::HitTestPostEffect::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = Render::HitTestPostEffect::AccessComponentDesc();
  *(_DWORD *)&Render::HitTestPostEffect::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  Render::HitTestPostEffect::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  Render::HitTestPostEffect::_TypeIDesc.mChildren = result;
  return result;
}

