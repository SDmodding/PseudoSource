// File Line: 219
// RVA: 0x57EA80
UFG::ComponentIDDesc *__fastcall UFG::InterestPoint::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::InterestPoint::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::InterestPoint::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::InterestPoint::_TypeIDesc.mChildBitMask = v1;
    UFG::InterestPoint::_TypeIDesc.mChildren = 0;
    UFG::InterestPoint::_DescInit = 1;
    UFG::InterestPoint::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::InterestPoint::_InterestPointTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::InterestPoint::_TypeIDesc;
}

// File Line: 333
// RVA: 0x58B910
void __fastcall UFG::InterestPoint::SetLinkObject(UFG::InterestPoint *this, UFG::SimObject *pLinkObject)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mLinkObject = &this->mLinkObject;
  if ( this->mLinkObject.m_pPointer )
  {
    mPrev = p_mLinkObject->mPrev;
    mNext = p_mLinkObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLinkObject->mPrev = p_mLinkObject;
    p_mLinkObject->mNext = p_mLinkObject;
  }
  p_mLinkObject->m_pPointer = pLinkObject;
  if ( pLinkObject )
  {
    v5 = pLinkObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mLinkObject;
    p_mLinkObject->mPrev = v5;
    p_mLinkObject->mNext = &pLinkObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pLinkObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLinkObject;
  }
}

// File Line: 369
// RVA: 0x582960
__int64 __fastcall Scaleform::GFx::FontResource::GetResourceTypeCode(UFG::InterestPoint *this)
{
  return 512i64;
}

