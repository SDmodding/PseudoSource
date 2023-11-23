// File Line: 56
// RVA: 0x448990
void __fastcall UFG::BulletImpactDamageSphereEvent::BulletImpactDamageSphereEvent(
        UFG::BulletImpactDamageSphereEvent *this)
{
  unsigned int mUID; // edx
  UFG::ProjectileInfo *p_projectileInfo; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  mUID = UFG::gBulletImpactDamageSphereEventChannel.mUID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = mUID;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::BulletImpactDamageSphereEvent::`vftable;
  this->weaponOwnerSimObject.mPrev = &this->weaponOwnerSimObject;
  this->weaponOwnerSimObject.mNext = &this->weaponOwnerSimObject;
  this->weaponOwnerSimObject.m_pPointer = 0i64;
  p_projectileInfo = &this->projectileInfo;
  this->projectileInfo.m_pSOWPC.mPrev = &this->projectileInfo.m_pSOWPC;
  this->projectileInfo.m_pSOWPC.mNext = &this->projectileInfo.m_pSOWPC;
  this->projectileInfo.m_pSOWPC.m_pPointer = 0i64;
  if ( this->projectileInfo.m_pSOWPC.m_pPointer )
  {
    mPrev = p_projectileInfo->m_pSOWPC.mPrev;
    mNext = p_projectileInfo->m_pSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_projectileInfo->m_pSOWPC.mPrev = &p_projectileInfo->m_pSOWPC;
    p_projectileInfo->m_pSOWPC.mNext = &p_projectileInfo->m_pSOWPC;
  }
  p_projectileInfo->m_pSOWPC.m_pPointer = 0i64;
  p_projectileInfo->m_pSubTargetingLocation = 0i64;
  *(_WORD *)&p_projectileInfo->m_bIsFullyAccurate = 0;
}

// File Line: 72
// RVA: 0x4520A0
void __fastcall UFG::Bullet::operator delete(char *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::Bullet::mAllocator.mFreeListHead;
  --UFG::Bullet::mAllocator.mNumSlotsAllocated;
  UFG::Bullet::mAllocator.mFreeListHead = ptr;
}

