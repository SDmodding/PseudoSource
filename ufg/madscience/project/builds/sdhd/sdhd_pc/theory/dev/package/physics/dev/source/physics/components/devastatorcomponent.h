// File Line: 153
// RVA: 0x9F940
UFG::ComponentIDDesc *__fastcall UFG::DevastatorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DevastatorComponent::_DescInit )
  {
    UFG::DevastatorComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DevastatorComponent::_DescInit = 1;
    UFG::DevastatorComponent::_TypeUID = UFG::DevastatorComponent::_TypeIDesc.mChildBitMask | (UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DevastatorComponent::_DevastatorComponentTypeUID = UFG::DevastatorComponent::_TypeIDesc.mChildBitMask | (UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DevastatorComponent::_TypeIDesc;
}

