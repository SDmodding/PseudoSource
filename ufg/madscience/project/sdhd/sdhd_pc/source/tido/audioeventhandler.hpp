// File Line: 126
// RVA: 0x593070
void __fastcall UFG::CollisionAudioData::CollisionAudioData(UFG::CollisionAudioData *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->a.audioProperty = 0;
  this->a.obj.mPrev = &this->a.obj;
  this->a.obj.mNext = &this->a.obj;
  this->a.obj.m_pPointer = 0i64;
  this->a.objProperties = 0i64;
  this->b.audioProperty = 0;
  this->b.obj.mPrev = &this->b.obj;
  this->b.obj.mNext = &this->b.obj;
  this->b.obj.m_pPointer = 0i64;
  this->b.objProperties = 0i64;
  *(_WORD *)&this->setVelocity = 0;
  this->playEvent = 1;
  *(_QWORD *)&this->mappedVelocity = 0i64;
  *(_QWORD *)&this->totalVelocity = 0i64;
  this->instanceCount = 1;
  *(_QWORD *)&this->position.x = 0i64;
  this->position.z = 0.0;
}

// File Line: 146
// RVA: 0x5934E0
void __fastcall UFG::PersistentEventItem::PersistentEventItem(
        UFG::PersistentEventItem *this,
        UFG::SimObject *obj,
        UFG::qVector3 *position)
{
  UFG::OneShotHandle *p_m_pOneShot; // rcx

  this->mPrev = this;
  this->mNext = this;
  this->m_pObj = obj;
  p_m_pOneShot = &this->m_pOneShot;
  p_m_pOneShot->m_pOneShot = 0i64;
  UFG::OneShotPool::GetOneShotHandle(p_m_pOneShot, position);
}

// File Line: 195
// RVA: 0x598870
void UFG::AudioEventHandler::ClearCollisionEventList(void)
{
  UFG::CollisionAudioData *i; // rbx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *mPrev; // rcx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *mNext; // rax

  for ( i = (UFG::CollisionAudioData *)UFG::AudioEventHandler::m_collisionList.mNode.mNext;
        (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext != &UFG::AudioEventHandler::m_collisionList;
        i = (UFG::CollisionAudioData *)UFG::AudioEventHandler::m_collisionList.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::CollisionAudioData::~CollisionAudioData(i);
    operator delete[](i);
  }
}

