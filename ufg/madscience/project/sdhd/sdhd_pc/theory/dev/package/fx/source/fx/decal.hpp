// File Line: 208
// RVA: 0x1D62B0
void __fastcall Render::DecalObjectLink::Set(Render::DecalObjectLink *this, const unsigned int index, void *bind_ptr, Render::IDecalScenery *scenery)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->mIndex = index;
  this->mScenery = scenery;
  if ( this->mComponentPtr.m_pPointer )
  {
    v4 = this->mComponentPtr.mPrev;
    v5 = this->mComponentPtr.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    this->mComponentPtr.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mComponentPtr.mPrev;
    this->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mComponentPtr.mPrev;
  }
  this->mComponentPtr.m_pPointer = (UFG::SimComponent *)bind_ptr;
  if ( bind_ptr )
  {
    v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)*((_QWORD *)bind_ptr + 1);
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mComponentPtr.mPrev;
    this->mComponentPtr.mPrev = v6;
    this->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)bind_ptr + 8);
    *((_QWORD *)bind_ptr + 1) = this;
  }
}

