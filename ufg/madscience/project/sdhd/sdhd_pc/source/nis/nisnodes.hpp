// File Line: 74
// RVA: 0x2987A0
void __fastcall NISNode::NISNode(NISNode *this, MemImageLoadFlag flag)
{
  char *v3; // rcx
  __int64 mOffset; // rax
  __int64 v5; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v3 = 0i64;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  this->mLightGroupObject = 0i64;
  mOffset = this->mTracksAction.mOffset;
  if ( mOffset && (UFG::qOffset64<TrackGroup *> *)((char *)&this->mTracksAction + mOffset) )
  {
    v5 = this->mTracksAction.mOffset;
    if ( v5 )
      v3 = (char *)&this->mTracksAction + v5;
    (*(void (__fastcall **)(char *, NISNode *))(*(_QWORD *)v3 + 64i64))(v3, this);
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
void __fastcall NISNode::SetName(NISNode *this, char *namestr)
{
  ActionNode::SetName(this, namestr);
  BinString::Set(&this->mNISName, namestr);
}

// File Line: 289
// RVA: 0x2986C0
void __fastcall NISActorNode::NISActorNode(NISActorNode *this, MemImageLoadFlag flag)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISActorNode::`vftable;
  this->mRightHandEquipSlot.mPrev = &this->mRightHandEquipSlot;
  this->mRightHandEquipSlot.mNext = &this->mRightHandEquipSlot;
  this->mRightHandEquipSlot.m_pPointer = 0i64;
  this->mLeftHandEquipSlot.mPrev = &this->mLeftHandEquipSlot;
  this->mLeftHandEquipSlot.mNext = &this->mLeftHandEquipSlot;
  this->mLeftHandEquipSlot.m_pPointer = 0i64;
  this->mHatEquipSlot.mPrev = &this->mHatEquipSlot;
  this->mHatEquipSlot.mNext = &this->mHatEquipSlot;
  this->mHatEquipSlot.m_pPointer = 0i64;
  this->mGlassesEquipSlot.mPrev = &this->mGlassesEquipSlot;
  this->mGlassesEquipSlot.mNext = &this->mGlassesEquipSlot;
  this->mGlassesEquipSlot.m_pPointer = 0i64;
  this->mStowed1HSlot.mPrev = &this->mStowed1HSlot;
  this->mStowed1HSlot.mNext = &this->mStowed1HSlot;
  this->mStowed1HSlot.m_pPointer = 0i64;
  this->mStowed2HSlot.mPrev = &this->mStowed2HSlot;
  this->mStowed2HSlot.mNext = &this->mStowed2HSlot;
  this->mStowed2HSlot.m_pPointer = 0i64;
}

// File Line: 292
// RVA: 0x2BEEB0
__int64 __fastcall NISActorNode::GetClassNameUID(NISActorNode *this)
{
  return NISActorNode::sClassNameUID;
}

