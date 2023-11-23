// File Line: 149
// RVA: 0x405360
void __fastcall UFG::RacketInstanceData::RacketInstanceData(UFG::RacketInstanceData *this)
{
  UFG::qString::qString(&this->type);
  *(_QWORD *)&this->id = 0i64;
  *(_QWORD *)&this->type_id = 0i64;
  *(_QWORD *)&this->num_staff = 0i64;
  *(_QWORD *)&this->status = 0i64;
  this->local_storage = 0.0;
}

// File Line: 157
// RVA: 0x404D00
void __fastcall UFG::GangMemberStatData::GangMemberStatData(UFG::GangMemberStatData *this)
{
  UFG::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>::qReflectObjectType<UFG::GangMemberStatData,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::GangMemberStatData::`vftable;
  *(_QWORD *)&this->type.mText.mData.mNumItems = 0i64;
  this->type.mText.mData.mItems = 0i64;
}

// File Line: 175
// RVA: 0x405480
void __fastcall UFG::RangedWeaponStatData::RangedWeaponStatData(UFG::RangedWeaponStatData *this)
{
  UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RangedWeaponStatData::`vftable;
}

// File Line: 188
// RVA: 0x405690
void __fastcall UFG::ThrownWeaponStatData::ThrownWeaponStatData(UFG::ThrownWeaponStatData *this)
{
  UFG::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::ThrownWeaponStatData,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ThrownWeaponStatData::`vftable;
}

// File Line: 199
// RVA: 0x404D90
void __fastcall UFG::MeleeWeaponStatData::MeleeWeaponStatData(UFG::MeleeWeaponStatData *this)
{
  UFG::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::MeleeWeaponStatData,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::MeleeWeaponStatData::`vftable;
}

// File Line: 222
// RVA: 0x405900
void __fastcall UFG::WeaponStatData::WeaponStatData(UFG::WeaponStatData *this)
{
  UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WeaponStatData::`vftable;
  `eh vector constructor iterator(
    this->meleeWeapons,
    0x60ui64,
    4,
    (void (__fastcall *)(void *))UFG::MeleeWeaponStatData::MeleeWeaponStatData);
  `eh vector constructor iterator(
    this->rangedWeapons,
    0x60ui64,
    6,
    (void (__fastcall *)(void *))UFG::RangedWeaponStatData::RangedWeaponStatData);
  `eh vector constructor iterator(
    this->thrownWeapons,
    0x60ui64,
    5,
    (void (__fastcall *)(void *))UFG::ThrownWeaponStatData::ThrownWeaponStatData);
}

// File Line: 225
// RVA: 0x405810
void __fastcall UFG::WeaponStatData::WeaponStatData(UFG::WeaponStatData *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WeaponStatData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WeaponStatData::`vftable;
  `eh vector constructor iterator(
    this->meleeWeapons,
    0x60ui64,
    4,
    (void (__fastcall *)(void *))UFG::MeleeWeaponStatData::MeleeWeaponStatData);
  `eh vector constructor iterator(
    this->rangedWeapons,
    0x60ui64,
    6,
    (void (__fastcall *)(void *))UFG::RangedWeaponStatData::RangedWeaponStatData);
  `eh vector constructor iterator(
    this->thrownWeapons,
    0x60ui64,
    5,
    (void (__fastcall *)(void *))UFG::ThrownWeaponStatData::ThrownWeaponStatData);
}

// File Line: 249
// RVA: 0x4051D0
void __fastcall UFG::PlayerStatData::PlayerStatData(UFG::PlayerStatData *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PlayerStatData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PlayerStatData::`vftable;
  this->name.mText.mData.mFlags = 2;
  `eh vector constructor iterator(
    this->weaponStats,
    0x5F0ui64,
    2,
    (void (__fastcall *)(void *))UFG::WeaponStatData::WeaponStatData);
  `eh vector constructor iterator(
    this->gangMembers,
    0xA0ui64,
    10,
    (void (__fastcall *)(void *))UFG::GangMemberStatData::GangMemberStatData);
}

