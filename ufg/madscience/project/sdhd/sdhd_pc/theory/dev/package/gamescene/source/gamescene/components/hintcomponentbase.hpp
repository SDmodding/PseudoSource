// File Line: 42
// RVA: 0x239010
UFG::ComponentIDDesc *__fastcall UFG::HintComponentBase::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HintComponentBase::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HintComponentBase::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HintComponentBase::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HintComponentBase::_DescInit = 1;
    UFG::HintComponentBase::_TypeUID = UFG::HintComponentBase::_TypeIDesc.mChildBitMask | (UFG::HintComponentBase::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HintComponentBase::_HintComponentBaseTypeUID = UFG::HintComponentBase::_TypeIDesc.mChildBitMask | (UFG::HintComponentBase::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HintComponentBase::_TypeIDesc;
}

