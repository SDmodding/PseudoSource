// File Line: 23
// RVA: 0x51F7F0
UFG::ComponentIDDesc *__fastcall UFG::StoreBlipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::StoreBlipComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::StoreBlipComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::StoreBlipComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::StoreBlipComponent::_DescInit = 1;
    UFG::StoreBlipComponent::_TypeUID = UFG::StoreBlipComponent::_TypeIDesc.mChildBitMask | (UFG::StoreBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StoreBlipComponent::_StoreBlipComponentTypeUID = UFG::StoreBlipComponent::_TypeIDesc.mChildBitMask | (UFG::StoreBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StoreBlipComponent::_TypeIDesc;
}

