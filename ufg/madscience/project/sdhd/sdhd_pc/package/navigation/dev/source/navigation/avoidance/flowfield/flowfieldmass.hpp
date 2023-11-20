// File Line: 33
// RVA: 0xFBE20
void __fastcall UFG::FlowfieldMass::~FlowfieldMass(UFG::FlowfieldMass *this)
{
  UFG::FlowfieldMass *v1; // rdx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v2; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v3; // rax

  v1 = this;
  if ( this->mActive )
    this->mActive = 0;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v1->mPrev;
}

