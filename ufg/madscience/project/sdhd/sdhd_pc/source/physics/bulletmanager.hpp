// File Line: 56
// RVA: 0x448990
void __fastcall UFG::BulletImpactDamageSphereEvent::BulletImpactDamageSphereEvent(UFG::BulletImpactDamageSphereEvent *this)
{
  unsigned int v1; // edx
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rax
  UFG::ProjectileInfo *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // [rsp+28h] [rbp+10h]

  v1 = UFG::gBulletImpactDamageSphereEventChannel.mUID;
  v2 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_EventUID = v1;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::BulletImpactDamageSphereEvent::`vftable';
  v6 = &this->weaponOwnerSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->weaponOwnerSimObject.m_pPointer = 0i64;
  v3 = &this->projectileInfo;
  v3->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
  v3->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
  this->projectileInfo.m_pSOWPC.m_pPointer = 0i64;
  if ( this->projectileInfo.m_pSOWPC.m_pPointer )
  {
    v4 = v3->m_pSOWPC.mPrev;
    v5 = v3->m_pSOWPC.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
    v3->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
  }
  v3->m_pSOWPC.m_pPointer = 0i64;
  v3->m_pSubTargetingLocation = 0i64;
  *(_WORD *)&v3->m_bIsFullyAccurate = 0;
}

// File Line: 72
// RVA: 0x4520A0
void __fastcall UFG::Bullet::operator delete(void *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::Bullet::mAllocator.mFreeListHead;
  --UFG::Bullet::mAllocator.mNumSlotsAllocated;
  UFG::Bullet::mAllocator.mFreeListHead = (char *)ptr;
}

