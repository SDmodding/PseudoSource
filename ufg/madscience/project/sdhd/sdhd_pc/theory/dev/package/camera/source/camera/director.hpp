// File Line: 24
// RVA: 0xB9980
UFG::ComponentIDDesc *__fastcall UFG::Director::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::Director::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::Director::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::Director::_TypeIDesc.mChildren = v0->mChildren;
    UFG::Director::_DescInit = 1;
    UFG::Director::_TypeUID = UFG::Director::_TypeIDesc.mChildBitMask | (UFG::Director::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::Director::_DirectorTypeUID = UFG::Director::_TypeIDesc.mChildBitMask | (UFG::Director::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::Director::_TypeIDesc;
}

