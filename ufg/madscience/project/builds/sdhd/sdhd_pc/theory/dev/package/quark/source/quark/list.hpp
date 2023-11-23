// File Line: 326
// RVA: 0x66BEE0
void __fastcall UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>::~qNode<UFG::DoorComponent,UFG::DoorComponent>(
        UFG::qNode<UFG::qString,UFG::qString> *this)
{
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 384
// RVA: 0x333220
void __fastcall UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>(
        UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *this)
{
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **p_mNext; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **i; // r9
  _QWORD *v4; // rdx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v5; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v6; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *mPrev; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *mNext; // rax

  p_mNext = &this->mNode.mNext[-3].mNext;
  for ( i = &this[-3].mNode.mNext; p_mNext != i; p_mNext = &this->mNode.mNext[-3].mNext )
  {
    v4 = p_mNext + 5;
    v5 = p_mNext[5];
    v6 = p_mNext[6];
    v5->mNext = v6;
    v6->mPrev = v5;
    *v4 = v4;
    v4[1] = v4;
  }
  mPrev = this->mNode.mPrev;
  mNext = this->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mNode.mPrev = &this->mNode;
  this->mNode.mNext = &this->mNode;
}

// File Line: 404
// RVA: 0xA6E80
void __fastcall UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(
        UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *i; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // r8
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v5; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v6; // rcx

  for ( i = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this->mNode.mNext;
        i != this;
        i = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this->mNode.mNext )
  {
    mPrev = i->mNode.mPrev;
    mNext = i->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    v5 = i->mNode.mPrev;
    v6 = i->mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    operator delete[](i);
  }
}

