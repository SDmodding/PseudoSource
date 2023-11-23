// File Line: 208
// RVA: 0x1D62B0
void __fastcall Render::DecalObjectLink::Set(
        Render::DecalObjectLink *this,
        unsigned int index,
        UFG::SimComponent *bind_ptr,
        Render::IDecalScenery *scenery)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->mIndex = index;
  this->mScenery = scenery;
  if ( this->mComponentPtr.m_pPointer )
  {
    mPrev = this->mComponentPtr.mPrev;
    mNext = this->mComponentPtr.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mComponentPtr.mPrev = &this->mComponentPtr;
    this->mComponentPtr.mNext = &this->mComponentPtr;
  }
  this->mComponentPtr.m_pPointer = bind_ptr;
  if ( bind_ptr )
  {
    v6 = bind_ptr->m_SafePointerList.mNode.mPrev;
    v6->mNext = &this->mComponentPtr;
    this->mComponentPtr.mPrev = v6;
    this->mComponentPtr.mNext = &bind_ptr->m_SafePointerList.mNode;
    bind_ptr->m_SafePointerList.mNode.mPrev = &this->mComponentPtr;
  }
}

