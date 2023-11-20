// File Line: 126
// RVA: 0x593070
void __fastcall UFG::CollisionAudioData::CollisionAudioData(UFG::CollisionAudioData *this)
{
  UFG::CollisionAudioObjectData *v1; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+30h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // [rsp+30h] [rbp+18h]

  this->mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&this->mPrev;
  this->a.audioProperty = 0;
  v2 = &this->a.obj;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->a.obj.m_pPointer = 0i64;
  this->a.objProperties = 0i64;
  v1 = &this->b;
  v1->audioProperty = 0;
  v3 = &this->b.obj;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->obj.m_pPointer = 0i64;
  v1->objProperties = 0i64;
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
void __fastcall UFG::PersistentEventItem::PersistentEventItem(UFG::PersistentEventItem *this, UFG::SimObject *obj, UFG::qVector3 *position)
{
  UFG::OneShotHandle *v3; // rcx

  this->mPrev = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&this->mPrev;
  this->m_pObj = obj;
  v3 = &this->m_pOneShot;
  v3->m_pOneShot = 0i64;
  UFG::OneShotPool::GetOneShotHandle(v3, position);
}

// File Line: 195
// RVA: 0x598870
void UFG::AudioEventHandler::ClearCollisionEventList(void)
{
  UFG::CollisionAudioData *i; // rbx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v1; // rcx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v2; // rax

  for ( i = (UFG::CollisionAudioData *)UFG::AudioEventHandler::m_collisionList.mNode.mNext;
        (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext != &UFG::AudioEventHandler::m_collisionList;
        i = (UFG::CollisionAudioData *)UFG::AudioEventHandler::m_collisionList.mNode.mNext )
  {
    v1 = i->mPrev;
    v2 = i->mNext;
    v1->mNext = v2;
    v2->mPrev = v1;
    i->mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&i->mPrev;
    UFG::CollisionAudioData::~CollisionAudioData(i);
    operator delete[](i);
  }
}

