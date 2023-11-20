// File Line: 149
// RVA: 0x405360
void __fastcall UFG::RacketInstanceData::RacketInstanceData(UFG::RacketInstanceData *this)
{
  UFG::RacketInstanceData *v1; // rbx

  v1 = this;
  UFG::qString::qString(&this->type);
  *(_QWORD *)&v1->id = 0i64;
  *(_QWORD *)&v1->type_id = 0i64;
  *(_QWORD *)&v1->num_staff = 0i64;
  *(_QWORD *)&v1->status = 0i64;
  v1->local_storage = 0.0;
}

// File Line: 157
// RVA: 0x404D00
void __fastcall UFG::GangMemberStatData::GangMemberStatData(UFG::GangMemberStatData *this)
{
  UFG::GangMemberStatData *v1; // rbx
  UFG::qReflectString *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::GangMemberStatData::`vftable;
  v2 = &v1->type;
  *(_QWORD *)&v2->mText.mData.mNumItems = 0i64;
  v2->mText.mData.mItems = 0i64;
}

// File Line: 175
// RVA: 0x405480
void __fastcall UFG::RangedWeaponStatData::RangedWeaponStatData(UFG::RangedWeaponStatData *this)
{
  UFG::RangedWeaponStatData *v1; // rbx

  v1 = this;
  UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RangedWeaponStatData::`vftable;
}

// File Line: 188
// RVA: 0x405690
void __fastcall UFG::ThrownWeaponStatData::ThrownWeaponStatData(UFG::ThrownWeaponStatData *this)
{
  UFG::ThrownWeaponStatData *v1; // rbx

  v1 = this;
  UFG::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ThrownWeaponStatData::`vftable;
}

// File Line: 199
// RVA: 0x404D90
void __fastcall UFG::MeleeWeaponStatData::MeleeWeaponStatData(UFG::MeleeWeaponStatData *this)
{
  UFG::MeleeWeaponStatData *v1; // rbx

  v1 = this;
  UFG::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::MeleeWeaponStatData::`vftable;
}

// File Line: 222
// RVA: 0x405900
void __fastcall UFG::WeaponStatData::WeaponStatData(UFG::WeaponStatData *this)
{
  UFG::WeaponStatData *v1; // rbx

  v1 = this;
  UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WeaponStatData::`vftable;
  `eh vector constructor iterator(
    v1->meleeWeapons,
    0x60ui64,
    4,
    (void (__fastcall *)(void *))UFG::MeleeWeaponStatData::MeleeWeaponStatData);
  `eh vector constructor iterator(
    v1->rangedWeapons,
    0x60ui64,
    6,
    (void (__fastcall *)(void *))UFG::RangedWeaponStatData::RangedWeaponStatData);
  `eh vector constructor iterator(
    v1->thrownWeapons,
    0x60ui64,
    5,
    (void (__fastcall *)(void *))UFG::ThrownWeaponStatData::ThrownWeaponStatData);
}

// File Line: 225
// RVA: 0x405810
void __fastcall UFG::WeaponStatData::WeaponStatData(UFG::WeaponStatData *this, MemImageLoadFlag f)
{
  UFG::WeaponStatData *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+60h] [rbp+18h]

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WeaponStatData::`vftable;
  `eh vector constructor iterator(
    this->meleeWeapons,
    0x60ui64,
    4,
    (void (__fastcall *)(void *))UFG::MeleeWeaponStatData::MeleeWeaponStatData);
  `eh vector constructor iterator(
    v2->rangedWeapons,
    0x60ui64,
    6,
    (void (__fastcall *)(void *))UFG::RangedWeaponStatData::RangedWeaponStatData);
  `eh vector constructor iterator(
    v2->thrownWeapons,
    0x60ui64,
    5,
    (void (__fastcall *)(void *))UFG::ThrownWeaponStatData::ThrownWeaponStatData);
}

// File Line: 249
// RVA: 0x4051D0
void __fastcall UFG::PlayerStatData::PlayerStatData(UFG::PlayerStatData *this, MemImageLoadFlag f)
{
  UFG::PlayerStatData *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+60h] [rbp+18h]

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PlayerStatData::`vftable;
  this->name.mText.mData.mFlags = 2;
  `eh vector constructor iterator(
    this->weaponStats,
    0x5F0ui64,
    2,
    (void (__fastcall *)(void *))UFG::WeaponStatData::WeaponStatData);
  `eh vector constructor iterator(
    v2->gangMembers,
    0xA0ui64,
    10,
    (void (__fastcall *)(void *))UFG::GangMemberStatData::GangMemberStatData);
}

