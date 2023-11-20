// File Line: 219
// RVA: 0x57EA80
UFG::ComponentIDDesc *__fastcall UFG::InterestPoint::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::InterestPoint::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::InterestPoint::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::InterestPoint::_TypeIDesc.mChildBitMask = v1;
    UFG::InterestPoint::_TypeIDesc.mChildren = 0;
    UFG::InterestPoint::_DescInit = 1;
    UFG::InterestPoint::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::InterestPoint::_InterestPointTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::InterestPoint::_TypeIDesc;
}

// File Line: 333
// RVA: 0x58B910
void __fastcall UFG::InterestPoint::SetLinkObject(UFG::InterestPoint *this, UFG::SimObject *pLinkObject)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mLinkObject.mPrev;
  if ( this->mLinkObject.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)pLinkObject;
  if ( pLinkObject )
  {
    v5 = pLinkObject->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &pLinkObject->m_SafePointerList.mNode;
    pLinkObject->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 369
// RVA: 0x582960
signed __int64 __fastcall Scaleform::GFx::FontResource::GetResourceTypeCode(UFG::InterestPoint *this)
{
  return 512i64;
}

