// File Line: 33
// RVA: 0xFBE20
void __fastcall UFG::FlowfieldMass::~FlowfieldMass(UFG::FlowfieldMass *this)
{
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *mPrev; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *mNext; // rax

  if ( this->mActive )
    this->mActive = 0;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

