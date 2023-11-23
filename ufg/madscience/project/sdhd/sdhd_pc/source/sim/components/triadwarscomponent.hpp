// File Line: 22
// RVA: 0x51FD50
UFG::ComponentIDDesc *__fastcall UFG::TriadWarsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::TriadWarsComponent::_DescInit )
  {
    UFG::TriadWarsComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::TriadWarsComponent::_DescInit = 1;
    UFG::TriadWarsComponent::_TypeUID = UFG::TriadWarsComponent::_TypeIDesc.mChildBitMask | (UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TriadWarsComponent::_TriadWarsComponentTypeUID = UFG::TriadWarsComponent::_TypeIDesc.mChildBitMask | (UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TriadWarsComponent::_TypeIDesc;
}

