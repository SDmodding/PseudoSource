// File Line: 125
// RVA: 0x405130
void __fastcall UFG::PlayerStatData2::PlayerStatData2(UFG::PlayerStatData2 *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+60h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PlayerStatData2,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PlayerStatData2::`vftable;
  `eh vector constructor iterator(
    this->mGangMembers,
    0x48ui64,
    10,
    (void (__fastcall *)(void *))UFG::GangMemberStatData2::GangMemberStatData2);
}

// File Line: 281
// RVA: 0x405770
void __fastcall UFG::UpgradeType::UpgradeType(UFG::UpgradeType *this, MemImageLoadFlag f)
{
  UFG::UpgradeType *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::UpgradeType,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::UpgradeType::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mStatModifier);
  v2->mDependencies.mData.mFlags = 2;
}

// File Line: 330
// RVA: 0x4052B0
void __fastcall UFG::RacketCoreLevel::RacketCoreLevel(UFG::RacketCoreLevel *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+30h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RacketCoreLevel,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RacketCoreLevel::`vftable;
  this->mInteriorVariants.mData.mFlags = 2;
  this->mInteriorPropsVariants.mData.mFlags = 2;
  this->mInteriorDoorsVariants.mData.mFlags = 2;
  this->mExteriorVariants.mData.mFlags = 2;
  this->mExteriorPropsVariants.mData.mFlags = 2;
  this->mExteriorDoorsVariants.mData.mFlags = 2;
  this->mDecalsVariants.mData.mFlags = 2;
}

// File Line: 385
// RVA: 0x4053A0
void __fastcall UFG::RacketType::RacketType(UFG::RacketType *this, MemImageLoadFlag f)
{
  UFG::RacketType *v2; // rdi
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qReflectHandle<UFG::CommodityType> *v5; // rbx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v6; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v6 = &this->mHandles;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RacketType::`vftable;
  v5 = &this->mOutput;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mOutput.mPrev);
  v5->mTypeUID = UFG::qStringHash64("UFG::CommodityType", 0xFFFFFFFFFFFFFFFFui64);
  v2->mLevels.mData.mFlags = 2;
  v2->mCaption.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mCorePrefabs);
}

// File Line: 421
// RVA: 0x4054B0
void __fastcall UFG::SafehouseBlock::SafehouseBlock(UFG::SafehouseBlock *this, MemImageLoadFlag f)
{
  UFG::SafehouseBlock *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::SafehouseBlock,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::SafehouseBlock::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mSafehouse);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mGarageRacket);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mWarehouseRacket);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mTriadTempleRacket);
}

// File Line: 467
// RVA: 0x4056C0
void __fastcall UFG::TurfTemplate::TurfTemplate(UFG::TurfTemplate *this, MemImageLoadFlag f)
{
  UFG::TurfTemplate *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::TurfTemplate::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mSafehouseBlock);
  v2->mTurfBlocks.mData.mFlags = 2;
  v2->mPrimaryRoad.mData.mFlags = 2;
  v2->mSecondaryRoad.mData.mFlags = 2;
}

// File Line: 515
// RVA: 0x404BF0
void __fastcall UFG::ContactType::ContactType(UFG::ContactType *this, MemImageLoadFlag f)
{
  UFG::ContactType *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ContactType,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ContactType::`vftable;
  this->mDisplayName.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mIcon);
  v2->mStatModifiers.mData.mFlags = 2;
}

// File Line: 608
// RVA: 0x405070
void __fastcall UFG::PlayerInstanceData2::PlayerInstanceData2(UFG::PlayerInstanceData2 *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  unsigned int fa; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  fa = f.flag;
  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PlayerInstanceData2,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PlayerInstanceData2::`vftable;
  this->Name.mText.mData.mFlags = 2;
  this->Informants.mData.mFlags = 2;
  this->Contacts.mData.mFlags = 2;
  this->Upgrades.mData.mFlags = 2;
  this->Turfs.mData.mFlags = 2;
  UFG::PlayerStatData2::PlayerStatData2(&this->Stats, (MemImageLoadFlag)fa);
}

