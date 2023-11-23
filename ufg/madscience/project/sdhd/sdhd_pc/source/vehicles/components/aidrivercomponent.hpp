// File Line: 43
// RVA: 0x6443F0
UFG::ComponentIDDesc *__fastcall UFG::AiDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AiDriverComponent::_DescInit )
  {
    v0 = UFG::VehicleDriverInterface::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AiDriverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AiDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AiDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::AiDriverComponent::_DescInit = 1;
    UFG::AiDriverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AiDriverComponent::_AiDriverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AiDriverComponent::_TypeIDesc;
}

// File Line: 437
// RVA: 0x651A30
_BOOL8 __fastcall UFG::AiDriverComponent::IsAmbient(UFG::AiDriverComponent *this)
{
  return this->m_IsAmbient;
}

