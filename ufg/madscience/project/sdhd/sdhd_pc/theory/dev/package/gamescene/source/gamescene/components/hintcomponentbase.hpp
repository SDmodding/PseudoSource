// File Line: 42
// RVA: 0x239010
UFG::ComponentIDDesc *__fastcall UFG::HintComponentBase::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HintComponentBase::_DescInit )
  {
    UFG::HintComponentBase::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HintComponentBase::_DescInit = 1;
    UFG::HintComponentBase::_TypeUID = UFG::HintComponentBase::_TypeIDesc.mChildBitMask | (UFG::HintComponentBase::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HintComponentBase::_HintComponentBaseTypeUID = UFG::HintComponentBase::_TypeIDesc.mChildBitMask | (UFG::HintComponentBase::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HintComponentBase::_TypeIDesc;
}

