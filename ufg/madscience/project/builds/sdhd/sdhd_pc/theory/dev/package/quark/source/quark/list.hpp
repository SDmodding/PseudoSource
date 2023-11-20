// File Line: 326
// RVA: 0x66BEE0
void __fastcall UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>::~qNode<UFG::DoorComponent,UFG::DoorComponent>(UFG::qNode<UFG::qString,UFG::qString> *this)
{
  UFG::qNode<UFG::qString,UFG::qString> *v1; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rax

  v1 = this->mPrev;
  v2 = this->mNext;
  v1->mNext = v2;
  v2->mPrev = v1;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 384
// RVA: 0x333220
void __fastcall UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>(UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *this)
{
  UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *v1; // r8
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **v2; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **v3; // r9
  _QWORD *v4; // rdx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v5; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v6; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v7; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v8; // rax

  v1 = this;
  v2 = &this->mNode.mNext[-3].mNext;
  v3 = &this[-3].mNode.mNext;
  if ( v2 != &this[-3].mNode.mNext )
  {
    do
    {
      v4 = v2 + 5;
      v5 = v2[5];
      v6 = v2[6];
      v5->mNext = v6;
      v6->mPrev = v5;
      *v4 = v4;
      v4[1] = v4;
      v2 = &v1->mNode.mNext[-3].mNext;
    }
    while ( v2 != v3 );
  }
  v7 = v1->mNode.mPrev;
  v8 = v1->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 404
// RVA: 0xA6E80
void __fastcall UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v1; // rbx
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v2; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v3; // r8
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v4; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v5; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v6; // rcx

  v1 = this;
  v2 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this->mNode.mNext;
  if ( v2 != this )
  {
    do
    {
      v3 = v2->mNode.mPrev;
      v4 = v2->mNode.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mNode.mPrev = &v2->mNode;
      v2->mNode.mNext = &v2->mNode;
      v5 = v2->mNode.mPrev;
      v6 = v2->mNode.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v2->mNode.mPrev = &v2->mNode;
      v2->mNode.mNext = &v2->mNode;
      operator delete[](v2);
      v2 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v1->mNode.mNext;
    }
    while ( v2 != v1 );
  }
}

