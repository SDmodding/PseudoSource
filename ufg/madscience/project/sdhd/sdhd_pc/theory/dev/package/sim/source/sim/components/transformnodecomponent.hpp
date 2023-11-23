// File Line: 101
// RVA: 0x18FF50
UFG::ComponentIDDesc *__fastcall UFG::TransformNodeComponent::AccessComponentDesc()
{
  int v1; // [rsp+8h] [rbp-20h]

  if ( !UFG::TransformNodeComponent::_DescInit )
  {
    if ( (_S1_22 & 1) == 0 )
    {
      _S1_22 |= 1u;
      word_14235C4B0 = 0;
      qword_14235C4B4 = 0i64;
    }
    ++HIDWORD(qword_14235C4B4);
    LOWORD(v1) = WORD2(qword_14235C4B4);
    *(_DWORD *)&UFG::TransformNodeComponent::_TypeIDesc.mBaseTypeIndex = v1;
    *(_QWORD *)&UFG::TransformNodeComponent::_TypeIDesc.mChildBitMask = 1i64;
    UFG::TransformNodeComponent::_TypeUID = (WORD2(qword_14235C4B4) << 25) | 1;
    UFG::TransformNodeComponent::_TransformNodeComponentTypeUID = (WORD2(qword_14235C4B4) << 25) | 1;
    UFG::TransformNodeComponent::_DescInit = 1;
  }
  return &UFG::TransformNodeComponent::_TypeIDesc;
}

