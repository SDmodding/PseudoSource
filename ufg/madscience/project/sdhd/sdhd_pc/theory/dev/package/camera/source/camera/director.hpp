// File Line: 24
// RVA: 0xB9980
UFG::ComponentIDDesc *__fastcall UFG::Director::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::Director::_DescInit )
  {
    UFG::Director::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::Director::_DescInit = 1;
    UFG::Director::_TypeUID = UFG::Director::_TypeIDesc.mChildBitMask | (UFG::Director::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::Director::_DirectorTypeUID = UFG::Director::_TypeIDesc.mChildBitMask | (UFG::Director::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::Director::_TypeIDesc;
}

