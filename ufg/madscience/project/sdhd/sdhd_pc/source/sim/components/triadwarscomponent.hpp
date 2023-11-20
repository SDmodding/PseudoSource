// File Line: 22
// RVA: 0x51FD50
UFG::ComponentIDDesc *__fastcall UFG::TriadWarsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::TriadWarsComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::TriadWarsComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::TriadWarsComponent::_DescInit = 1;
    UFG::TriadWarsComponent::_TypeUID = UFG::TriadWarsComponent::_TypeIDesc.mChildBitMask | (UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TriadWarsComponent::_TriadWarsComponentTypeUID = UFG::TriadWarsComponent::_TypeIDesc.mChildBitMask | (UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TriadWarsComponent::_TypeIDesc;
}

