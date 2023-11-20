// File Line: 74
// RVA: 0x2987A0
void __fastcall NISNode::NISNode(NISNode *this, MemImageLoadFlag flag)
{
  NISNode *v2; // rbx
  signed __int64 v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rax

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v3 = 0i64;
  v2->mResourceOwner = 0i64;
  v2->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  v2->mLightGroupObject = 0i64;
  v4 = v2->mTracksAction.mOffset;
  if ( v4 && (UFG::qOffset64<TrackGroup *> *)((char *)&v2->mTracksAction + v4) )
  {
    v5 = v2->mTracksAction.mOffset;
    if ( v5 )
      v3 = (signed __int64)&v2->mTracksAction + v5;
    (*(void (__fastcall **)(signed __int64, NISNode *))(*(_QWORD *)v3 + 64i64))(v3, v2);
  }
}

// File Line: 86
// RVA: 0x2C1B90
const char *__fastcall NISNode::GetClassname(NISNode *this)
{
  return NISNode::sClassName;
}

// File Line: 98
// RVA: 0x2DCBC0
void __fastcall NISNode::SetName(NISNode *this, const char *namestr)
{
  const char *v2; // rdi
  NISNode *v3; // rbx

  v2 = namestr;
  v3 = this;
  ActionNode::SetName((ActionNode *)&this->vfptr, namestr);
  BinString::Set(&v3->mNISName, v2);
}

// File Line: 289
// RVA: 0x2986C0
void __fastcall NISActorNode::NISActorNode(NISActorNode *this, MemImageLoadFlag flag)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISActorNode::`vftable;
  v2 = &this->mRightHandEquipSlot;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mRightHandEquipSlot.m_pPointer = 0i64;
  v3 = &this->mLeftHandEquipSlot;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mLeftHandEquipSlot.m_pPointer = 0i64;
  v4 = &this->mHatEquipSlot;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mHatEquipSlot.m_pPointer = 0i64;
  v5 = &this->mGlassesEquipSlot;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->mGlassesEquipSlot.m_pPointer = 0i64;
  v6 = &this->mStowed1HSlot;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->mStowed1HSlot.m_pPointer = 0i64;
  v7 = &this->mStowed2HSlot;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  this->mStowed2HSlot.m_pPointer = 0i64;
}

// File Line: 292
// RVA: 0x2BEEB0
__int64 __fastcall NISActorNode::GetClassNameUID(NISActorNode *this)
{
  return NISActorNode::sClassNameUID;
}

